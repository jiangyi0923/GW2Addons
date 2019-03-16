#include "MouseSquare.h"
#include <imgui.h>
#include <SettingsMenu.h>
namespace GW2Radial 
{
	DEFINE_SINGLETON(MouseSquare);

	MouseSquare::MouseSquare() : showKeybindMouseSquare_("show_MouseSquare", "Show MouseSquare", { VK_F9 }, false)
	{
		inputChangeCallback_ = [this](bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys) { return OnInputChange(changed, keys, changedKeys); };
		Input::i()->AddInputChangeCallback(&inputChangeCallback_);
	}
	MouseSquare::~MouseSquare()
	{
		if (auto i = Input::iNoInit(); i)
		{
			i->RemoveInputChangeCallback(&inputChangeCallback_);
		}
		
	}
	void MouseSquare::Draw()
	{
		ImGuiIO& io = ImGui::GetIO();
		if (isVisibleMouseSquare_)
		{
			ImGui::SetNextWindowPos(ImVec2(io.MousePos.x + 2, io.MousePos.y + 2), 0);
			ImGui::SetNextWindowSize(ImVec2(SettingsMenu::i()->shubiaoPOSX(), SettingsMenu::i()->shubiaoPOSY()));
			ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(SettingsMenu::i()->shubiaoRED(), SettingsMenu::i()->shubiaoGRE(), SettingsMenu::i()->shubiaoBLU(), SettingsMenu::i()->shubiaoALH()));
			ImGui::Begin(u8"¸úËæ", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoInputs);
			ImGui::End();
			ImGui::PopStyleColor(1);
		}
	}

	InputResponse MouseSquare::OnInputChange(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys)
	{
		const bool isMenuKeybindMouseSquare = keys == showKeybindMouseSquare_.keys();
		if (isMenuKeybindMouseSquare)
		{
			if (jishiqiMouseSquare)
			{
				isVisibleMouseSquare_ = true;
				jishiqiMouseSquare = false;
			}
			else
			{
				isVisibleMouseSquare_ = false;
				jishiqiMouseSquare = true;
			}
		}

		return isMenuKeybindMouseSquare ? InputResponse::PREVENT_ALL : InputResponse::PASS_TO_GAME;
	}

}
