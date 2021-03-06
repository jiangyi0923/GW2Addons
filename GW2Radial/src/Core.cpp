#include <Core.h>
#include <Direct3D9Hooks.h>
#include <imgui.h>
#include <examples/imgui_impl_dx9.h>
#include <examples/imgui_impl_win32.h>
#include <Input.h>
#include <ConfigurationFile.h>
#include <UnitQuad.h>
#include <Wheel.h>
#include <Mount.h>
#include <SettingsMenu.h>
#include <Utility.h>
#include <imgui/imgui_internal.h>
#include <Novelty.h>
#include <shellapi.h>
//#include <UpdateCheck.h>
#include <ImGuiPopup.h>
#include <Marker.h>
#include <MiscTab.h>
#include <MumbleLink.h>
#include <Effect_dx12.h>

namespace GW2Radial
{
DEFINE_SINGLETON(Core);

void Core::Init(HMODULE dll)
{
	MumbleLink::i();
	i()->dllModule_ = dll;
	i()->InternalInit();
}

void Core::Shutdown()
{
	i_.reset();

	// We'll just leak a bunch of things and let the driver/OS take care of it, since we have no clean exit point
	// and calling FreeLibrary in DllMain causes deadlocks
}

Core::~Core()
{
	ImGui::DestroyContext();

	if(auto i = Direct3D9Hooks::iNoInit(); i != nullptr)
	{
		i->preCreateDeviceCallback(nullptr);
		i->postCreateDeviceCallback(nullptr);
		
		i->preResetCallback(nullptr);
		i->postResetCallback(nullptr);
		
		i->drawOverCallback(nullptr);
		i->drawUnderCallback(nullptr);
	}
}

void Core::InternalInit()
{
	// Add an extra reference count to the library so it persists through GW2's load-unload routine
	// without which problems start arising with ReShade
	{
		TCHAR selfpath[MAX_PATH];
		GetModuleFileName(dllModule_, selfpath, MAX_PATH);
		LoadLibrary(selfpath);
	}
	
	Direct3D9Hooks::i()->preCreateDeviceCallback([this](HWND hWnd){ PreCreateDevice(hWnd); });
	Direct3D9Hooks::i()->postCreateDeviceCallback([this](IDirect3DDevice9* d, D3DPRESENT_PARAMETERS* pp){ PostCreateDevice(d, pp); });
	
	Direct3D9Hooks::i()->preResetCallback([this](){ PreReset(); });
	Direct3D9Hooks::i()->postResetCallback([this](IDirect3DDevice9* d, D3DPRESENT_PARAMETERS* pp){ PostReset(d, pp); });
	
	Direct3D9Hooks::i()->drawOverCallback([this](IDirect3DDevice9* d, bool frameDrawn, bool sceneEnded){ DrawOver(d, frameDrawn, sceneEnded); });
	Direct3D9Hooks::i()->drawUnderCallback([this](IDirect3DDevice9* d, bool frameDrawn, bool sceneEnded){ DrawUnder(d, frameDrawn, sceneEnded); });
	
	imguiContext_ = ImGui::CreateContext();
}

void Core::OnFocusLost()
{
	for (auto& wheel : wheels_)
		if (wheel)
			wheel->OnFocusLost();

	Input::i()->OnFocusLost();
}

LRESULT Core::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_KILLFOCUS)
		i()->OnFocusLost();
	else if(Input::i()->OnInput(msg, wParam, lParam))
		return 0;

	// Whatever's left should be sent to the game
	return CallWindowProc(i()->baseWndProc_, hWnd, msg, wParam, lParam);
}

void Core::PreCreateDevice(HWND hFocusWindow)
{
	gameWindow_ = hFocusWindow;

	// Hook WndProc
	if (!baseWndProc_)
	{
		baseWndProc_ = WNDPROC(GetWindowLongPtr(hFocusWindow, GWLP_WNDPROC));
		SetWindowLongPtr(hFocusWindow, GWLP_WNDPROC, LONG_PTR(&WndProc));
	}
}

void Core::PostCreateDevice(IDirect3DDevice9 *device, D3DPRESENT_PARAMETERS *presentationParameters)
{
	// Init ImGui
	auto &imio = ImGui::GetIO();
	imio.IniFilename = nullptr;
	imio.IniSavingRate = 1.0f;
	auto fontCfg = ImFontConfig();
	fontCfg.FontDataOwnedByAtlas = false;

	
	//font_ = imio.Fonts->AddFontFromFileTTF(".\\addons\\arcdps\\arcdps_font.ttf", MiscTab::i()->zitidaxiao(), &fontCfg, imio.Fonts->GetGlyphRangesChineseFull());
	font_ = imio.Fonts->AddFontFromFileTTF(".\\addons\\arcdps\\arcdps_font.ttf", MiscTab::i()->zitidaxiao(), NULL, imio.Fonts->GetGlyphRangesChineseFull());
	//fontBlack_ = imio.Fonts->AddFontFromFileTTF(".\\addons\\sct\\font\\arcdps_font.ttf", 80.0f, &fontCfg);
	void* fontPtr;
	size_t fontSize;
	//if (LoadFontResource(IDR_FONT, fontPtr, fontSize))
	//	font_ = imio.Fonts->AddFontFromMemoryTTF(fontPtr, int(fontSize), 25.f, &fontCfg);

	if (LoadFontResource(IDR_FONT, fontPtr, fontSize))
		fontBlack_ = imio.Fonts->AddFontFromMemoryTTF(fontPtr, int(fontSize), 36.0f, &fontCfg , imio.Fonts->GetGlyphRangesChineseFull());
	//fontBlack_ = imio.Fonts->AddFontFromFileTTF(".\\bin64\\d3d9_chainload_font.ttf", 36.0f, &fontCfg, imio.Fonts->GetGlyphRangesChineseFull());
	
	if (font_)
	{
		imio.FontDefault = font_;
	}
	//fontBlack_ = imio.Fonts->AddFontFromFileTTF(".\\addons\\arcdps\\arcdps_font.ttf", MiscTab::i()->zitidaxiao(), NULL, imio.Fonts->GetGlyphRangesChineseFull());
	//font_ = imio.Fonts->AddFontFromFileTTF(".\\addons\\arcdps\\arcdps_font.ttf", 21.0f, &fontCfg);

	ImGui_ImplWin32_Init(gameWindow_);
	
	firstMessageShown_ = std::make_unique<ConfigurationOption<bool>>("", "first_message_shown_v1", "Core", false);

	OnDeviceSet(device, presentationParameters);
}




void Core::OnDeviceSet(IDirect3DDevice9 *device, D3DPRESENT_PARAMETERS *presentationParameters)
{
	// Initialize graphics
	screenWidth_ = presentationParameters->BackBufferWidth;
	screenHeight_ = presentationParameters->BackBufferHeight;
	firstFrame_ = true;

	try { quad_ = std::make_unique<UnitQuad>(device); }
	catch (...) { quad_ = nullptr; }

	//megai2: check for d912pxy
	//D3DRS_ENABLE_D912PXY_API_HACKS == 220
	if (device->SetRenderState((D3DRENDERSTATETYPE)220, 1) == 343434)
		mainEffect_ = new Effect_dx12(device);
	else 
		mainEffect_ = new Effect(device);

	if (!mainEffect_->Load())
		abort();

	//UpdateCheck::i()->CheckForUpdates();BdMarker
	MiscTab::i();
	deviceout = device;
	wheels_.emplace_back(Wheel::Create<Mount>(IDR_BG, IDR_INK, "mounts", u8"坐骑", device));
	wheels_.emplace_back(Wheel::Create<Novelty>(IDR_BG, IDR_INK, "novelties", u8"新奇", device));
	wheels_.emplace_back(Wheel::Create<Marker>(IDR_BG, IDR_INK, "markers", u8"标记", device));
	wheels_.emplace_back(Wheel::Create<ObjectMarker>(IDR_BG, IDR_INK, "object_markers", u8"物品标记", device));
	wheels_.emplace_back(Wheel::Create<BdMarker>(IDR_BG, IDR_INK, "Bd_markers", u8"装备模版", device));
	MouseSquare_ = std::make_unique<MouseSquare>();//++必须加
	BossTime_ = std::make_unique<BossTime>();//++必须加
	LoopPrompt_ = std::make_unique<LoopPrompt>();//++必须加
	ImGui_ImplDX9_Init(device);
}

void Core::OnDeviceUnset()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	quad_.reset();
	wheels_.clear();
	MouseSquare_.reset();//++必须加
	BossTime_.reset();//++必须加
	LoopPrompt_.reset();//++必须加
	if (mainEffect_)
	{
		delete mainEffect_;
		mainEffect_ = NULL;
	}
}

void Core::PreReset()
{
	OnDeviceUnset();
}

void Core::PostReset(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS *presentationParameters)
{
	OnDeviceSet(device, presentationParameters);
}

void Core::DrawUnder(IDirect3DDevice9* device, bool frameDrawn, bool sceneEnded)
{
	if (!firstFrame_ && !frameDrawn)
	{
		if (sceneEnded)
			device->BeginScene();
		
		for (auto& wheel : wheels_)
			if (!wheel->drawOverUI())
				wheel->Draw(device, mainEffect_, quad_.get());

		if (sceneEnded)
			device->EndScene();
	}
}

void Core::DrawOver(IDirect3DDevice9* device, bool frameDrawn, bool sceneEnded)
{
	// This is the closest we have to a reliable "update" function, so use it as one
	Input::i()->OnUpdate();
	ConfigurationFile::i()->OnUpdate();

	//UpdateCheck::i()->CheckForUpdates();

	if (firstFrame_)
	{
		firstFrame_ = false;
	}
	else
	{
		// We have to use Present rather than hooking EndScene because the game seems to do final UI compositing after EndScene
		// This unfortunately means that we have to call Begin/EndScene before Present so we can render things, but thankfully for modern GPUs that doesn't cause bugs
		if (sceneEnded)
			device->BeginScene();

		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		
		for (auto& wheel : wheels_)
			if (wheel->drawOverUI() || !frameDrawn)
				wheel->Draw(device, mainEffect_, quad_.get());

		SettingsMenu::i()->Draw();
		MouseSquare::i()->Draw();//++必须加
		BossTime::i()->Draw();//++必须加
		LoopPrompt::i()->Draw();//++

		if (!firstMessageShown_->value())
			ImGuiPopup(u8"欢迎使用GW2Radial插件!").Position({ 0.5f, 0.45f }).Size({ 0.35f, 0.2f }).Display([&](const ImVec2& windowSize)
				{
					ImGui::TextWrapped(u8"欢迎使用GW2Radial!.\r\n "
						"快捷键 Shift+Alt+M 打开设置菜单并绑定你的按键.\r\n "
						"快捷键 F8 打开或关闭BOSS计时器.\r\n"
						"快捷键 F9 打开或关闭鼠标跟随方块.\r\n "
						"快捷键 F10 打开输出循环提示器设置面板.\r\n "
						"默认快捷键 F7 打开输出循环提示器.\r\n "
						"需要了解更多请访问项目网站,项目网站在这\r\n");

					ImGui::SetCursorPosX(windowSize.x * 0.1f);

					if (ImGui::Button("https://github.com/Friendly0Fire/GW2Radial", ImVec2(windowSize.x * 0.8f, ImGui::GetFontSize() * 1.3f)))
						ShellExecute(0, 0, L"https://github.com/Friendly0Fire/GW2Radial", 0, 0, SW_SHOW);
				}, [&]() { firstMessageShown_->value(true); });

		if (!ConfigurationFile::i()->lastSaveError().empty() && ConfigurationFile::i()->lastSaveErrorChanged())
			ImGuiPopup(u8"配置文件无法保存!").Position({ 0.5f, 0.45f }).Size({ 0.35f, 0.2f }).Display([&](const ImVec2&)
				{
					ImGui::Text(u8"配置文件无法保存,给出的原因是:");
					ImGui::TextWrapped(ConfigurationFile::i()->lastSaveError().c_str());
				}, []() { ConfigurationFile::i()->lastSaveErrorChanged(false); });

		//if(!firstMessageShown_->value())
		//	ImGuiPopup("Welcome to GW2Radial!").Position({0.5f, 0.45f}).Size({0.35f, 0.2f}).Display([&](const ImVec2& windowSize)
		//	{
		//		ImGui::TextWrapped("Welcome to GW2Radial! This small addon shows a convenient, customizable radial menu overlay to select a mount or novelty on the fly for Guild Wars 2: Path of Fire. "
		//		"To begin, use the shortcut Shift+Alt+M to open the settings menu and take a moment to bind your keys. If you ever need further assistance, please visit "
		//		"this project's website at");
		//		
		//		ImGui::SetCursorPosX(windowSize.x * 0.1f);

		//		if(ImGui::Button("https://github.com/Friendly0Fire/GW2Radial", ImVec2(windowSize.x * 0.8f, ImGui::GetFontSize() * 1.3f)))
		//			ShellExecute(0, 0, L"https://github.com/Friendly0Fire/GW2Radial", 0, 0 , SW_SHOW );
		//	}, [&]() { firstMessageShown_->value(true); });

		//if (!ConfigurationFile::i()->lastSaveError().empty() && ConfigurationFile::i()->lastSaveErrorChanged())
		//	ImGuiPopup("Configuration could not be saved!").Position({0.5f, 0.45f}).Size({0.35f, 0.2f}).Display([&](const ImVec2&)
		//	{
		//		ImGui::Text("Could not save addon configuration. Reason given was:");
		//		ImGui::TextWrapped(ConfigurationFile::i()->lastSaveError().c_str());
		//	}, []() { ConfigurationFile::i()->lastSaveErrorChanged(false); });

		//if(UpdateCheck::i()->updateAvailable() && !UpdateCheck::i()->updateDismissed())
		//	ImGuiPopup("Update available!").Position({0.5f, 0.45f}).Size({0.35f, 0.2f}).Display([&](const ImVec2& windowSize)
		//	{
		//		ImGui::TextWrapped("A new version of GW2Radial has been released! "
		//			"Please follow the link below to look at the changes and download the update. "
		//			"Remember that you can always disable this version check in the settings.");
		//		
		//		ImGui::SetCursorPosX(windowSize.x * 0.1f);

		//		if(ImGui::Button("https://github.com/Friendly0Fire/GW2Radial/releases/latest", ImVec2(windowSize.x * 0.8f, ImGui::GetFontSize() * 1.3f)))
		//			ShellExecute(0, 0, L"https://github.com/Friendly0Fire/GW2Radial/releases/latest", 0, 0 , SW_SHOW );
		//	}, []() { UpdateCheck::i()->updateDismissed(true); });

		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());	

		if (sceneEnded)
			device->EndScene();
	}
}

}
