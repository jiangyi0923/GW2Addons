#include <MiscTab.h>
#include <UpdateCheck.h>
#include <ImGuiExtensions.h>
#include <imgui/imgui.h>
#include <Utility.h>
#include <Input.h>

namespace GW2Radial
{
	DEFINE_SINGLETON(MiscTab);

	MiscTab::MiscTab() :
		SHOWBOSSTIMER_CK_("SHOWBOSSTIMER_CK", u8"BOSS计时器快捷键", { VK_F8 }, true),
		SHOWMOUSELOOP_CK_("SHOWMOUSELOOP_CK", u8"鼠标跟随方块快捷键", { VK_F9 }, true),
		SHOWLOOPTIMER_CK_("SHOWLOOPTIMER_CK", u8"输出循环提示器设置界面快捷键", { VK_F10 }, true),
		shubiaoPOSX_(u8"方块大小", "shubiaoPOSX", "shubiao", 50.0f),
		shubiaoPOSY_(u8"方块大小", "shubiaoPOSY", "shubiao", 50.0f),
		shubiaoRED_(u8"方块颜色", "shubiaoRED", "shubiao", 1.0f),
		shubiaoGRE_(u8"方块颜色", "shubiaoGRE", "shubiao", 0.0f),
		shubiaoBLU_(u8"方块颜色", "shubiaoBLU", "shubiao", 0.0f),
		shubiaoALH_(u8"方块颜色", "shubiaoALH", "shubiao", 1.0f),
		showboostime_(u8"总是显示BOSS计时器", "showboostime", "shubiao", true),
		getweb_(u8"获取网页日常", "getweb", "shubiao", true),
		showfankuai_(u8"总是显示鼠标跟随方块", "showfankuai_", "shubiao", false),
		jiemiandaxiao_(u8"界面大小", "jiemiandaxiao_", "shubiao", 1.0f),
		shubiaofankuaiyangshi_(u8"方块样式", "shubiaofankuaiyangshi_", "shubiao", 0),
		zhengtitoumingdu_(u8"透明度", "toumingdu_", "shubiao", 0.44f),
		uselooptool_(u8"启用输出循环提示器", "looptishiq_", "shubiao", true),
		jianyimoshi_(u8"简易模式(只显示前两行BOSS)", "showtwohang_", "shubiao", true)
	{
		inputChangeCallback_ = [this](bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys) { return OnInputChange(changed, keys, changedKeys); };
		Input::i()->AddInputChangeCallback(&inputChangeCallback_);
		SettingsMenu::i()->AddImplementer(this);
	}

	MiscTab::~MiscTab()
	{
		if (auto i = SettingsMenu::iNoInit(); i)
			i->RemoveImplementer(this);
		if (auto i = Input::iNoInit(); i)
		{
			i->RemoveInputChangeCallback(&inputChangeCallback_);
		}
	}

	void MiscTab::DrawMenu()
	{
		//if(auto uc = UpdateCheck::iNoInit(); uc)
		//	ImGuiConfigurationWrapper(ImGui::Checkbox, uc->checkEnabled_);
		if (auto i = Input::iNoInit(); i)
			ImGuiConfigurationWrapper(ImGui::Checkbox, i->distinguishLeftRight_);
		ImGui::Text(u8"鼠标跟随模块设置");

		setkeys(SHOWBOSSTIMER_CK_);
		std::vector<const char*> shubiaoyanhgsh(3);
		shubiaoyanhgsh[0] = u8"方块";
		shubiaoyanhgsh[1] = u8"十字";
		shubiaoyanhgsh[2] = u8"圆形";

		bool (*cmsb)(const char*, int*, const char* const*, int, int) = &ImGui::Combo;
		ImGuiConfigurationWrapper(cmsb, shubiaofankuaiyangshi_, shubiaoyanhgsh.data(), 3, -1);

		if (shubiaofankuaiyangshi_.value() == 2)
		{
			bool(*POS)(const char*, float*, float, float, const char*, float) = &ImGui::SliderFloat;
			ImGuiConfigurationWrapper(POS, u8"方块大小", shubiaoPOSX_, 20.0f, 100.0f, "%.F", 1.0f);
		}
		else
		{
			bool(*POS)(const char*, float*, float, float, const char*, float) = &ImGui::SliderFloat2;
			ImGuiConfigurationWrapper(POS, u8"方块大小", shubiaoPOSX_, shubiaoPOSY_, 5.0f, 200.0f, "%.F", 1.0f);
		}

		bool(*cl)(const char*, float*, ImGuiInputTextFlags) = &ImGui::ColorEdit4;
		ImGuiConfigurationWrapper(cl, u8"方块颜色", shubiaoRED_, shubiaoGRE_, shubiaoBLU_, shubiaoALH_, ImGuiColorEditFlags_AlphaBar);
		ImGuiConfigurationWrapper(&ImGui::Checkbox, showfankuai_);//总是现实鼠标方块
		ImGui::Text(u8"BOSS计时器设置");
		setkeys(SHOWMOUSELOOP_CK_);
		ImGuiConfigurationWrapper(&ImGui::SliderFloat, jiemiandaxiao_, 0.52f, 3.0f, "%.2f", 1.0f);
		ImGuiConfigurationWrapper(&ImGui::SliderFloat, zhengtitoumingdu_, 0.01f, 1.0f, "%.2f", 1.0f);
		ImGuiConfigurationWrapper(&ImGui::Checkbox, jianyimoshi_);//getmingtian_
		ImGuiConfigurationWrapper(&ImGui::Checkbox, showboostime_);//getmingtian_
		//ImGuiConfigurationWrapper(&ImGui::Checkbox, getmingtian_);
		ImGuiConfigurationWrapper(&ImGui::Checkbox, getweb_);
		ImGui::Text(u8"输出循环提示器启用设置");
		ImGuiConfigurationWrapper(&ImGui::Checkbox, uselooptool_);
		setkeys(SHOWLOOPTIMER_CK_);
		ImGui::PopItemWidth();

#if 0
		ImGui::Separator();

		ImGui::Text("Use these buttons to bind the respective key in your game's settings menu:");

		ImGui::InputInt("Virtual Key", reinterpret_cast<int*>(&vk_), 1, 100, ImGuiInputTextFlags_CharsHexadecimal);

		ImGui::Text(utf8_encode(GetKeyName(vk_)).c_str());

		if (ImGui::Button("Send"))
		{
			Input::i()->SendKeybind({ vk_ });
		}

#elif 0
		const auto btnWidth = ImGui::GetWindowWidth() * 0.25f - ImGui::GetStyle().FramePadding.x * 2;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				const uint vk = VK_F13 + i * 4 + j;
				if (ImGui::Button(utf8_encode(GetKeyName(vk)).c_str(), ImVec2(btnWidth, 0)))
				{
					Input::i()->SendKeybind({ vk });
				}

				if (j < 3)
					ImGui::SameLine();
			}
		}
#endif

	}

	void MiscTab::setkeys(Keybind& setting)
	{
		std::string suffix = "##" + setting.nickname();
		ImGui::Text(setting.displayName().c_str());
		ImGui::SameLine();
		if (setting.keys().empty())
		{
			ImGui::Text(u8"空");
		}
		else
		{
			ImGui::Text(setting.keysDisplayStringArray().data());
		}

		ImVec2 mix_(ImGui::GetItemRectMin().x - 3.0f, ImGui::GetItemRectMin().y - 1.0f);
		ImVec2 max_(ImGui::GetItemRectMax().x + 4.0f, ImGui::GetItemRectMax().y + 4.0f);
		ImGui::GetWindowDrawList()->AddRect(mix_, max_, IM_COL32(255, 255, 0, 255));

		ImGui::SameLine();
		if (!setting.isBeingModified() && ImGui::Button((u8"设置" + suffix).c_str()))
		{
			setting.isBeingModified(true);
			setting.keysDisplayStringArray().at(0) = '\0';
			shezianjian = true;
		}
		else if (setting.isBeingModified() && ImGui::Button((u8"清除" + suffix).c_str()))
		{
			setting.keys(std::set<uint>());
			shezianjian = false;
			setting.isBeingModified(false);
		}
		
		if (setting.keys().empty())
		{
			ImGui::SameLine();
			ImGui::Text(u8"没有给当前模块设置按键!");
		}
		else
		{
			ImGui::SameLine();
			ImGui::Text(u8"");
		}

		
	}

	void MiscTab::setkeysok(std::set<uint>& keys)
	{
		shezianjian = false;
		if (SHOWBOSSTIMER_CK_.isBeingModified())
		{
			SHOWBOSSTIMER_CK_.keys(keys);
			SHOWBOSSTIMER_CK_.isBeingModified(false);
		}
		if (SHOWMOUSELOOP_CK_.isBeingModified())
		{
			SHOWMOUSELOOP_CK_.keys(keys);
			SHOWMOUSELOOP_CK_.isBeingModified(false);
		}
		if (SHOWLOOPTIMER_CK_.isBeingModified())
		{
			SHOWLOOPTIMER_CK_.keys(keys);
			SHOWLOOPTIMER_CK_.isBeingModified(false);
		}
	}

	InputResponse MiscTab::OnInputChange(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys)
	{
		if (shezianjian)
		{
			auto fullKeybind = keys;
			fullKeybind.erase(VK_LBUTTON);
			fullKeybind.erase(VK_RBUTTON);
			for (const auto& ek : changedKeys)
			{
				if (ek.vk == VK_LBUTTON)
					continue;
				if (ek.vk == VK_RBUTTON)
					continue;
				if (!ek.down)
				{
					fullKeybind.insert(ek.vk);
					setkeysok(fullKeybind);
				}
			}
		}
		return shezianjian ? InputResponse::PREVENT_ALL : InputResponse::PASS_TO_GAME;
	}
}
