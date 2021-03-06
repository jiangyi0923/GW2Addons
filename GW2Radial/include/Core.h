#pragma once

#include <Main.h>
#include <Singleton.h>
#include <Wheel.h>
#include <UnitQuad.h>
#include <MouseSquare.h>//++鼠标跟随
#include <BossTime.h>//++boss计时器
#include <LoopPrompt.h>//++输出循环
namespace GW2Radial
{

class Core : public Singleton<Core>
{
public:
	static void Init(HMODULE dll);
	static void Shutdown();

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	Core() = default;
	~Core();

	HWND gameWindow() const { return gameWindow_; }
	HMODULE dllModule() const { return dllModule_; }
	WNDPROC baseWndProc() const { return baseWndProc_; }
	uint screenWidth() const { return screenWidth_; }
	uint screenHeight() const { return screenHeight_; }
	const std::unique_ptr<UnitQuad>& quad() const { return quad_; }
	Effect* mainEffect() const { return mainEffect_; }
	ImFont* font() const { return font_; }
	ImFont* fontBlack() const { return fontBlack_; }
	ImFont* fontItalic() const { return fontItalic_; }
	IDirect3DDevice9* getdevice() const { return deviceout; }

protected:
	void InternalInit();
	void OnFocusLost();

	void OnDeviceSet(IDirect3DDevice9 *device, D3DPRESENT_PARAMETERS *presentationParameters);
	void OnDeviceUnset();

	void PreCreateDevice(HWND hFocusWindow);
	void PostCreateDevice(IDirect3DDevice9 *device, D3DPRESENT_PARAMETERS *presentationParameters);

	void PreReset();
	void PostReset(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS *presentationParameters);
	
	void DrawUnder(IDirect3DDevice9* device, bool frameDrawn, bool sceneEnded);
	void DrawOver(IDirect3DDevice9* device, bool frameDrawn, bool sceneEnded);


	IDirect3DDevice9* deviceout = nullptr;
	HWND gameWindow_ = nullptr;
	HMODULE dllModule_ = nullptr;
	WNDPROC baseWndProc_ = nullptr;

	uint screenWidth_ = 0, screenHeight_ = 0;
	bool firstFrame_ = true;

	std::unique_ptr<UnitQuad> quad_;
	Effect* mainEffect_ = nullptr;

	ImFont *font_ = nullptr, *fontBlack_ = nullptr, *fontItalic_ = nullptr;

	std::vector<std::unique_ptr<Wheel>> wheels_;
	std::unique_ptr<MouseSquare> MouseSquare_;//++
	std::unique_ptr<BossTime> BossTime_;//++
	std::unique_ptr<LoopPrompt> LoopPrompt_;//++
	std::unique_ptr<ConfigurationOption<bool>> firstMessageShown_;
	//std::unique_ptr<ConfigurationOption<bool>> ignoreRTSS_;

	ImGuiContext* imguiContext_ = nullptr;
};
}
