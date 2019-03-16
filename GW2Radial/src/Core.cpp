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
#include <src/SkllsONE.h>
#include <src/SkllsTOW.h>


namespace GW2Radial
{
DEFINE_SINGLETON(Core);

void Core::Init(HMODULE dll)
{
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
	ImGui::StyleColorsClassic();//++
}

void Core::OnFocusLost()
{
	if(wheelMounts_) wheelMounts_->OnFocusLost();
	if(wheelNovelties_) wheelNovelties_->OnFocusLost();
	if (wheelSkllsONE_) wheelSkllsONE_->OnFocusLost();
	if (wheelSkllsTOW_) wheelSkllsTOW_->OnFocusLost();
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

	//void *fontPtr, *fontBlackPtr, *fontItalicPtr;
	//size_t fontSize, fontBlackSize, fontItalicSize;
	//if(LoadFontResource(IDR_FONT, fontPtr, fontSize))
	//	font_ = imio.Fonts->AddFontFromMemoryTTF(fontPtr, int(fontSize), 25.f, &fontCfg);
	//if(LoadFontResource(IDR_FONT_BLACK, fontBlackPtr, fontBlackSize))
	//	fontBlack_ = imio.Fonts->AddFontFromMemoryTTF(fontBlackPtr, int(fontBlackSize), 35.f, &fontCfg);
	//if(LoadFontResource(IDR_FONT_ITALIC, fontItalicPtr, fontItalicSize))
	//	fontItalic_ = imio.Fonts->AddFontFromMemoryTTF(fontItalicPtr, int(fontItalicSize), 25.f, &fontCfg);

	//if(font_)
	//	imio.FontDefault = font_;
	imio.Fonts->AddFontFromFileTTF(".\\addons\\arcdps\\arcdps_font.ttf", 14.0f, NULL, imio.Fonts->GetGlyphRangesChineseFull());

	ImGui_ImplWin32_Init(gameWindow_);

	firstMessageShown_ = std::make_unique<ConfigurationOption<bool>>("", "first_message_shown_v1", "Core", false);
	//ignoreRTSS_ = std::make_unique<ConfigurationOption<bool>>("", "ignore_rtss", "Core", false);

	//if(!ignoreRTSS_->value())
	//{
	//	const auto rtss = GetModuleHandleA("RTSSHooks64.dll");
	//	if(rtss)
	//	{
	//		const auto retval = MessageBox(nullptr, TEXT("WARNING: RivaTuner Statistics Server has been detected! GW2Radial is incompatible with RTSS, anomalous behavior may occur. Are you sure you want to continue? Continuing will prevent this message from showing again."), TEXT("RTSS Detected"), MB_ICONWARNING | MB_YESNO);
	//		if(retval == IDNO)
	//			exit(1);
	//		else if(retval == IDYES)
	//			ignoreRTSS_->value(true);
	//	}
	//}

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

	ID3DXBuffer *errorBuffer = nullptr;
	D3DXCreateEffectFromResource(device, dllModule_, MAKEINTRESOURCE(IDR_SHADER), nullptr, nullptr, 0, nullptr,
	                             &mainEffect_, &errorBuffer);
	COM_RELEASE(errorBuffer);

	//UpdateCheck::i()->CheckForUpdates();

	wheelMounts_ = std::make_unique<Wheel>(IDR_BG, IDR_INK, "mounts", u8"��������", device);
	Mount::AddAllMounts(wheelMounts_.get(), device);

	wheelNovelties_ = std::make_unique<Wheel>(IDR_BG, IDR_INK, "novelties", u8"��������", device);
	Novelty::AddAllNovelties(wheelNovelties_.get(), device);

	wheelSkllsONE_ = std::make_unique<Wheel>(IDR_BG, IDR_INK, "SkllsONE", u8"����1����", device);
	SkllsONE::AddAllNovelties(wheelSkllsONE_.get(), device);

	wheelSkllsTOW_ = std::make_unique<Wheel>(IDR_BG, IDR_INK, "SkllsTOW", u8"����2����", device);
	SkllsTOW::AddAllNovelties(wheelSkllsTOW_.get(), device);

	MouseSquare_ = std::make_unique<MouseSquare>();//++�����
	BossTime_ = std::make_unique<BossTime>();//++�����


	ImGui_ImplDX9_Init(device);
}

void Core::OnDeviceUnset()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
	quad_.reset();
	wheelMounts_.reset();
	wheelNovelties_.reset();
	wheelSkllsONE_.reset();
	wheelSkllsTOW_.reset();
	MouseSquare_.reset();//++�����
	BossTime_.reset();//++�����

	COM_RELEASE(mainEffect_);
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
		
		if(!wheelMounts_->drawOverUI()) wheelMounts_->Draw(device, mainEffect_, quad_.get());
		if(!wheelNovelties_->drawOverUI()) wheelNovelties_->Draw(device, mainEffect_, quad_.get());
		if (!wheelSkllsONE_->drawOverUI()) wheelSkllsONE_->Draw(device, mainEffect_, quad_.get());
		if (!wheelSkllsTOW_->drawOverUI()) wheelSkllsTOW_->Draw(device, mainEffect_, quad_.get());
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
		
		if(wheelMounts_->drawOverUI() || !frameDrawn) wheelMounts_->Draw(device, mainEffect_, quad_.get());
		if(wheelNovelties_->drawOverUI() || !frameDrawn) wheelNovelties_->Draw(device, mainEffect_, quad_.get());
		if (wheelSkllsONE_->drawOverUI() || !frameDrawn) wheelSkllsONE_->Draw(device, mainEffect_, quad_.get());
		if (wheelSkllsTOW_->drawOverUI() || !frameDrawn) wheelSkllsTOW_->Draw(device, mainEffect_, quad_.get());

		SettingsMenu::i()->Draw();
		MouseSquare::i()->Draw();//++�����
		BossTime::i()->Draw();//++�����
		if(!firstMessageShown_->value())
			ImGuiPopup(u8"��ӭʹ�ü�ս2������!").Position({0.5f, 0.45f}).Size({0.35f, 0.2f}).Display([&](const ImVec2& windowSize)
			{
				ImGui::TextWrapped(u8"��ӭʹ�ü�ս2������! ����by��ս2ӡ������ IDά��ү.7046\r\n"
				u8" Shift+Alt+M ���Դ�����\r\n "
				u8" F8�򿪻�ر�boss��ʱ��\r\n "
				u8" F9�򿪻�ر������淽��\r\n "
				u8"��Ŀ��ַ\r\n");
				
				ImGui::SetCursorPosX(windowSize.x * 0.1f);

				if(ImGui::Button("https://github.com/Friendly0Fire/GW2Radial", ImVec2(windowSize.x * 0.8f, ImGui::GetFontSize() * 1.3f)))
					ShellExecute(0, 0, L"https://github.com/Friendly0Fire/GW2Radial", 0, 0 , SW_SHOW );
			}, [&]() { firstMessageShown_->value(true); });

		if (!ConfigurationFile::i()->lastSaveError().empty() && ConfigurationFile::i()->lastSaveErrorChanged())
			ImGuiPopup("Configuration could not be saved!").Position({0.5f, 0.45f}).Size({0.35f, 0.2f}).Display([&](const ImVec2&)
			{
				ImGui::Text("Could not save addon configuration. Reason given was:");
				ImGui::TextWrapped(ConfigurationFile::i()->lastSaveError().c_str());
			}, []() { ConfigurationFile::i()->lastSaveErrorChanged(false); });

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
