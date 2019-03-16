#include <SettingsMenu.h>
#include <imgui.h>
#include <ImGuiExtensions.h>
//#include <UpdateCheck.h>

namespace GW2Radial
{
DEFINE_SINGLETON(SettingsMenu);

SettingsMenu::SettingsMenu()
	: showKeybind_("show_settings", "Show settings", { VK_SHIFT, VK_MENU, 'M' }, false),
	shubiaoPOSX_(u8"�����С", "shubiaoPOSX", "shubiao", 50.0f),
	shubiaoPOSY_(u8"�����С", "shubiaoPOSY", "shubiao", 50.0f),
	shubiaoRED_(u8"������ɫ", "shubiaoRED", "shubiao", 1.0f),
	shubiaoGRE_(u8"������ɫ", "shubiaoGRE", "shubiao", 0.0f),
	shubiaoBLU_(u8"������ɫ", "shubiaoBLU", "shubiao", 0.0f),
	shubiaoALH_(u8"������ɫ", "shubiaoALH", "shubiao", 1.0f),
	showboostime_(u8"������ʾBOSS��ʱ��", "showboostime", "shubiao", true),
	//getmingtian_(u8"��ȡ�������Ϸ�ճ�", "getmingtian", "shubiao", true)
	getweb_(u8"��ȡ��ҳ�ճ�", "getweb", "shubiao", true)
{
	inputChangeCallback_ = [this](bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys) { return OnInputChange(changed, keys, changedKeys); };
	Input::i()->AddInputChangeCallback(&inputChangeCallback_);
}
void SettingsMenu::Draw()
{
	if (isVisible_)
	{
		
		if(!ImGui::Begin(u8"��ս2������--����BY��սӡ�����;�", &isVisible_, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ImGui::End();
			return;
		}

		ImGui::PushItemWidth(-1);
		ImGui::BeginTabBar(u8"�ҵı�ǩ��", ImGuiTabBarFlags_None);//++
		for(const auto& i : implementers_)
			i->DrawMenu();
		if (ImGui::BeginTabItem(u8"���͹���"))//++
		{
			ImGui::PushItemWidth(0.8f * ImGui::GetWindowContentRegionWidth());
			ImGui::Text(u8"������ģ������");
			bool(*POS)(const char*, float*, float, float, const char*, float) = &ImGui::SliderFloat2;
			ImGuiConfigurationWrapper(POS, u8"�����С", shubiaoPOSX_, shubiaoPOSY_, 30.0f, 200.0f, "%.F", 1.0f);
			bool(*cl)(const char*, float*, ImGuiInputTextFlags) = &ImGui::ColorEdit4;
			ImGuiConfigurationWrapper(cl, u8"������ɫ", shubiaoRED_, shubiaoGRE_, shubiaoBLU_, shubiaoALH_, ImGuiColorEditFlags_AlphaBar);
			ImGui::Text(u8"BOSS��ʱ������");
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