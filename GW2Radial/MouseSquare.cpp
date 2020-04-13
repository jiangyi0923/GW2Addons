#include "MouseSquare.h"
#include <imgui.h>
#include <MiscTab.h>
namespace GW2Radial
{
	DEFINE_SINGLETON(MouseSquare);

	MouseSquare::MouseSquare() //: showKeybindMouseSquare_("show_MouseSquare", "Show MouseSquare", { VK_F9 }, false)
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

	bool MouseSquare::Doui(bool Do)
	{
		ImGuiIO& io = ImGui::GetIO();
		if (Do)
		{
			//ImGui::SetNextWindowPos(ImVec2(io.MousePos.x + 2, io.MousePos.y + 2), 0);
			//ImGui::SetNextWindowSize(ImVec2(MiscTab::i()->shubiaoPOSX(), MiscTab::i()->shubiaoPOSY()));
			//ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(MiscTab::i()->shubiaoRED(), MiscTab::i()->shubiaoGRE(), MiscTab::i()->shubiaoBLU(), MiscTab::i()->shubiaoALH()));
			////ImGui::SetNextWindowSize(ImVec2(30.0f, 30.0f));//²âÊÔ
			////ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.1f, 0.1f, 0.1f, 1.0f));//²âÊÔ
			//ImGui::Begin(u8"¸úËæ", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoInputs);
			//ImGui::End();
			//ImGui::PopStyleColor(1);

			if (MiscTab::i()->shubiaofankuaiyangshi()==0)//·½¿é
			{
				ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(io.MousePos.x, io.MousePos.y), ImVec2(io.MousePos.x + MiscTab::i()->shubiaoPOSX(), io.MousePos.y+ MiscTab::i()->shubiaoPOSY()), ImGui::GetColorU32(ImVec4(MiscTab::i()->shubiaoRED(), MiscTab::i()->shubiaoGRE(), MiscTab::i()->shubiaoBLU(), MiscTab::i()->shubiaoALH())), 10.0f);
			}
			if (MiscTab::i()->shubiaofankuaiyangshi() == 1)//Ê®×Ö¼Ü
			{
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(io.MousePos.x - MiscTab::i()->shubiaoPOSX(), io.MousePos.y), ImVec2(io.MousePos.x + MiscTab::i()->shubiaoPOSX(), io.MousePos.y), ImGui::GetColorU32(ImVec4(MiscTab::i()->shubiaoRED(), MiscTab::i()->shubiaoGRE(), MiscTab::i()->shubiaoBLU(), MiscTab::i()->shubiaoALH())), MiscTab::i()->shubiaoPOSY());//Ê®×Ö¼Ü
				ImGui::GetOverlayDrawList()->AddLine(ImVec2(io.MousePos.x, io.MousePos.y - MiscTab::i()->shubiaoPOSX()), ImVec2(io.MousePos.x, io.MousePos.y + MiscTab::i()->shubiaoPOSX()), ImGui::GetColorU32(ImVec4(MiscTab::i()->shubiaoRED(), MiscTab::i()->shubiaoGRE(), MiscTab::i()->shubiaoBLU(), MiscTab::i()->shubiaoALH())), MiscTab::i()->shubiaoPOSY());//Ê®×Ö¼Ü
			}

			if (MiscTab::i()->shubiaofankuaiyangshi() == 2)//Ô²ÐÎ
			{
				ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(io.MousePos.x , io.MousePos.y ), MiscTab::i()->shubiaoPOSX(),ImGui::GetColorU32(ImVec4(MiscTab::i()->shubiaoRED(), MiscTab::i()->shubiaoGRE(), MiscTab::i()->shubiaoBLU(), MiscTab::i()->shubiaoALH())), 32);
			}









		}
		return Do;
	}




	void MouseSquare::Draw()
	{
		//ImGuiIO& io = ImGui::GetIO();
		//if (isVisibleMouseSquare_)
		//{
		//	ImGui::SetNextWindowPos(ImVec2(io.MousePos.x + 2, io.MousePos.y + 2), 0);
		//	ImGui::SetNextWindowSize(ImVec2(MiscTab::i()->shubiaoPOSX(), MiscTab::i()->shubiaoPOSY()));
		//	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(MiscTab::i()->shubiaoRED(), MiscTab::i()->shubiaoGRE(), MiscTab::i()->shubiaoBLU(), MiscTab::i()->shubiaoALH()));
		//	//ImGui::SetNextWindowSize(ImVec2(30.0f, 30.0f));//²âÊÔ
		//	//ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.1f, 0.1f, 0.1f, 1.0f));//²âÊÔ
		//	ImGui::Begin(u8"¸úËæ", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoInputs);
		//	ImGui::End();
		//	ImGui::PopStyleColor(1);
		//}

		if (!isVisibleMouseSquare_ && jishiqiMouseSquare)
		{
			if (MiscTab::i()->showfankuai() && kput == 0)
			{
				isVisibleMouseSquare_ = true;
				jishiqiMouseSquare = false;
			}
		}
		if (isVisibleMouseSquare_)
		{
			kput = 1;
			if (!Doui(isVisibleMouseSquare_))
			{
				isVisibleMouseSquare_ = false;
				jishiqiMouseSquare = true;
			}
		}


	}

	InputResponse MouseSquare::OnInputChange(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys)
	{
		const bool isMenuKeybindMouseSquare = keys == MiscTab::i()->SHOWMOUSELOOP_CK().keys();
		if (isMenuKeybindMouseSquare)
		{
			kput = 1;
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
