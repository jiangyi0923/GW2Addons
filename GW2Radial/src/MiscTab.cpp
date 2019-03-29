#include <MiscTab.h>
//#include <UpdateCheck.h>
#include <ImGuiExtensions.h>
#include <imgui/imgui.h>
#include <Utility.h>
#include <Input.h>

namespace GW2Radial
{
DEFINE_SINGLETON(MiscTab);

MiscTab::MiscTab() :
	shubiaoPOSX_(u8"�����С", "shubiaoPOSX", "shubiao", 50.0f),
	shubiaoPOSY_(u8"�����С", "shubiaoPOSY", "shubiao", 50.0f),
	shubiaoRED_(u8"������ɫ", "shubiaoRED", "shubiao", 1.0f),
	shubiaoGRE_(u8"������ɫ", "shubiaoGRE", "shubiao", 0.0f),
	shubiaoBLU_(u8"������ɫ", "shubiaoBLU", "shubiao", 0.0f),
	shubiaoALH_(u8"������ɫ", "shubiaoALH", "shubiao", 1.0f),
	showboostime_(u8"������ʾBOSS��ʱ��", "showboostime", "shubiao", true),
	//getmingtian_(u8"��ȡ�������Ϸ�ճ�", "getmingtian", "shubiao", true)
	getweb_(u8"��ȡ��ҳ�ճ�", "getweb", "shubiao", true),
	showfankuai_(u8"������ʾ�����淽��", "showfankuai_", "shubiao", true),
	jiemiandaxiao_(u8"�����С", "jiemiandaxiao_", "shubiao", 1.0f)
{
	SettingsMenu::i()->AddImplementer(this);
}

MiscTab::~MiscTab()
{
	if(auto i = SettingsMenu::iNoInit(); i)
		i->RemoveImplementer(this);
}
void MiscTab::DrawMenu()
{
	//if(auto uc = UpdateCheck::iNoInit(); uc)
	//	ImGuiConfigurationWrapper(ImGui::Checkbox, "Automatically check for updates", uc->checkEnabled_);

	ImGui::PushItemWidth(0.8f * ImGui::GetWindowContentRegionWidth());
	if (auto i = Input::iNoInit(); i)
		ImGuiConfigurationWrapper(ImGui::Checkbox, u8"�������� SHIFT/CTRL/ALT", i->distinguishLeftRight_);

	ImGui::Text(u8"������ģ������");
	bool(*POS)(const char*, float*, float, float, const char*, float) = &ImGui::SliderFloat2;
	ImGuiConfigurationWrapper(POS, u8"�����С", shubiaoPOSX_, shubiaoPOSY_, 30.0f, 200.0f, "%.F", 1.0f);
	bool(*cl)(const char*, float*, ImGuiInputTextFlags) = &ImGui::ColorEdit4;
	ImGuiConfigurationWrapper(cl, u8"������ɫ", shubiaoRED_, shubiaoGRE_, shubiaoBLU_, shubiaoALH_, ImGuiColorEditFlags_AlphaBar);
	ImGuiConfigurationWrapper(&ImGui::Checkbox, showfankuai_);//������ʵ��귽��
	ImGui::Text(u8"BOSS��ʱ������");
	ImGuiConfigurationWrapper(&ImGui::SliderFloat, jiemiandaxiao_, 1.0f, 3.0f);
	ImGuiConfigurationWrapper(&ImGui::Checkbox, showboostime_);//getmingtian_
	//ImGuiConfigurationWrapper(&ImGui::Checkbox, getmingtian_);
	ImGuiConfigurationWrapper(&ImGui::Checkbox, getweb_);
	ImGui::PopItemWidth();





//#if 0
//	ImGui::Separator();
//
//	ImGui::Text("Use these buttons to bind the respective key in your game's settings menu:");
//
//	ImGui::InputInt("Virtual Key", reinterpret_cast<int*>(&vk_), 1, 100, ImGuiInputTextFlags_CharsHexadecimal);
//
//	ImGui::Text(utf8_encode(GetKeyName(vk_)).c_str());
//
//	if(ImGui::Button("Send"))
//	{
//		Input::i()->SendKeybind({ vk_ });
//	}
//#elif 0
//	const auto btnWidth = ImGui::GetWindowWidth() * 0.25f - ImGui::GetStyle().FramePadding.x * 2;
//
//	for(int i = 0; i < 3; i++)
//	{
//		for(int j = 0; j < 4; j++)
//		{
//			const uint vk = VK_F13 + i * 4 + j;
//			if(ImGui::Button(utf8_encode(GetKeyName(vk)).c_str(), ImVec2(btnWidth, 0)))
//			{
//				Input::i()->SendKeybind({ vk });
//			}
//
//			if(j < 3)
//				ImGui::SameLine();
//		}
//	}
//#endif
}

}
