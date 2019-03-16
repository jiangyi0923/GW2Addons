#include <SettingsMenu.h>
#include <imgui.h>
#include <ImGuiExtensions.h>
//#include <UpdateCheck.h>

namespace GW2Radial
{
DEFINE_SINGLETON(SettingsMenu);

SettingsMenu::SettingsMenu()
	: showKeybind_("show_settings", "Show settings", { VK_SHIFT, VK_MENU, 'M' }, false),
	shubiaoPOSX_(u8"方块大小", "shubiaoPOSX", "shubiao", 50.0f),
	shubiaoPOSY_(u8"方块大小", "shubiaoPOSY", "shubiao", 50.0f),
	shubiaoRED_(u8"方块颜色", "shubiaoRED", "shubiao", 1.0f),
	shubiaoGRE_(u8"方块颜色", "shubiaoGRE", "shubiao", 0.0f),
	shubiaoBLU_(u8"方块颜色", "shubiaoBLU", "shubiao", 0.0f),
	shubiaoALH_(u8"方块颜色", "shubiaoALH", "shubiao", 1.0f),
	showboostime_(u8"总是显示BOSS计时器", "showboostime", "shubiao", true),
	//getmingtian_(u8"获取明天的游戏日常", "getmingtian", "shubiao", true)
	getweb_(u8"获取网页日常", "getweb", "shubiao", true)
{
	inputChangeCallback_ = [this](bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys) { return OnInputChange(changed, keys, changedKeys); };
	Input::i()->AddInputChangeCallback(&inputChangeCallback_);
}
void SettingsMenu::Draw()
{
	if (isVisible_)
	{
		
		if(!ImGui::Begin(u8"激战2坐骑插件--汉化BY激战印度神油君", &isVisible_, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ImGui::End();
			return;
		}

		ImGui::PushItemWidth(-1);
		ImGui::BeginTabBar(u8"我的标签栏", ImGuiTabBarFlags_None);//++
		for(const auto& i : implementers_)
			i->DrawMenu();
		if (ImGui::BeginTabItem(u8"神油工具"))//++
		{
			ImGui::PushItemWidth(0.8f * ImGui::GetWindowContentRegionWidth());
			ImGui::Text(u8"鼠标跟随模块设置");
			bool(*POS)(const char*, float*, float, float, const char*, float) = &ImGui::SliderFloat2;
			ImGuiConfigurationWrapper(POS, u8"方块大小", shubiaoPOSX_, shubiaoPOSY_, 30.0f, 200.0f, "%.F", 1.0f);
			bool(*cl)(const char*, float*, ImGuiInputTextFlags) = &ImGui::ColorEdit4;
			ImGuiConfigurationWrapper(cl, u8"方块颜色", shubiaoRED_, shubiaoGRE_, shubiaoBLU_, shubiaoALH_, ImGuiColorEditFlags_AlphaBar);
			ImGui::Text(u8"BOSS计时器设置");
			ImGuiConfigurationWrapper(&ImGui::Checkbox, showboostime_);//getmingtian_
			//ImGuiConfigurationWrapper(&ImGui::Checkbox, getmingtian_);
			ImGuiConfigurationWrapper(&ImGui::Checkbox, getweb_);
			ImGui::PopItemWidth();
			ImGui::EndTabItem();//++
		};
		ImGui::EndTabBar();//++
		ImGui::PopItemWidth();

		ImGui::End();
	}
}

InputResponse SettingsMenu::OnInputChange(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys)
{
	const bool isMenuKeybind = keys == showKeybind_.keys();
	if(isMenuKeybind)
		isVisible_ = true;

	return isMenuKeybind ? InputResponse::PREVENT_ALL : InputResponse::PASS_TO_GAME;
}

}