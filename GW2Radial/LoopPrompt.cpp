#include "LoopPrompt.h"
#include <imgui.h>
#include <ImGuiExtensions.h>
#include <Wheel.h>
#include <Utility.h>
#include <Core.h>
namespace GW2Radial
{
	DEFINE_SINGLETON(LoopPrompt);

	int TMPdataitiems = 0;//存档数据变化依据
	int TMPbuttonitiems = 0;//按钮数量变化依据
	std::string* BTofTABE = nullptr;
	std::vector<std::string> BTofLOOP;
	bool schans = false;
	int anjiansunxu = 0;
	std::string danqiangbt = "";
	bool anjzq = false;

	LoopPrompt::LoopPrompt() : showKeybindLoopPrompt_("show_LoopPrompt", "Show LoopPrompt", { VK_F10 }, false),
		showkeybind_("show_LoopPromptUI", u8"呼出循环器", { VK_F7 }, true),
		tabekeybind_("tabekey", u8"切换"), pingbiwasd_(u8"屏蔽WASD方向键","pingbiwasd","loopavename",true), pingbiRK_(u8"屏蔽鼠标右键", "pingbiRK", "loopavename", true),
		fangunkeybind_("fangunkey", u8"翻滚"), LoopPromptA_(u8"循环器透明度", "LoopPromptA_", "loopavename", 0.5f),
		anjian01_("F1_", u8"F1"), anjian02_("F2_", u8"F2"), anjian03_("F3_", u8"F3"), anjian04_("F4_", u8"F4"), anjian05_("F5_", u8"F5"),
		anjian06_("wuqi1_", u8"武器1"), anjian07_("wuqi2_", u8"武器2"), anjian08_("wuqi3_", u8"武器3"), anjian09_("wuqi4_", u8"武器4"), anjian10_("wuqi5_", u8"武器5"),
		anjian11_("ziliao_", u8"治疗"), anjian12_("ca1_", u8"插槽1"), anjian13_("ca2_", u8"插槽2"), anjian14_("ca3_", u8"插槽3"), anjian15_("jy_", u8"精英")
	{
		inputChangeCallback_ = [this](bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys) { return OnInputChange(changed, keys, changedKeys); };
		Input::i()->AddInputChangeCallback(&inputChangeCallback_);
		loadloopdate();
	}

	LoopPrompt::~LoopPrompt()
	{
		if (auto i = Input::iNoInit(); i)
		{
			i->RemoveInputChangeCallback(&inputChangeCallback_);
		}
	}
	//获取按钮排序保存名
	std::string savebtloops()
	{
		std::string tmp;
		tmp += "|" + std::to_string(TMPbuttonitiems) + ",";
		for (int i = 0; i < TMPbuttonitiems; i++)
		{
			tmp += "|" + BTofLOOP[i] + ",";
		}
		return tmp;
	}
	//获取按键值对应的按键名称
	std::string LoopPrompt::getksystring(std::string tmp)
	{
		if ((int)tmp.find(u8"F1", 0) > 0)tmp = anjian01_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"F2", 0) > 0 ) tmp = anjian02_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"F3", 0) > 0 ) tmp = anjian03_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"F4", 0) > 0 ) tmp = anjian04_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"F5", 0) > 0 ) tmp = anjian05_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"武器1", 0) > 0 ) tmp = anjian06_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"武器2", 0) > 0 ) tmp = anjian07_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"武器3", 0) > 0 ) tmp = anjian08_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"武器4", 0) > 0 ) tmp = anjian09_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"武器5", 0) > 0 ) tmp = anjian10_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"治疗", 0) > 0 ) tmp = anjian11_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"插槽1", 0) > 0 ) tmp = anjian12_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"插槽2", 0) > 0 ) tmp = anjian13_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"插槽3", 0) > 0 ) tmp = anjian14_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"精英", 0) > 0 ) tmp = anjian15_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"切换", 0) > 0 ) tmp = tabekeybind_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"翻滚", 0) > 0 ) tmp = fangunkeybind_.keysDisplayStringArray().data();
		return tmp;
	}
	///保存按钮顺序名称和按钮顺序
	void LoopPrompt::saveloopdate(char* tmpbuf1)
	{
		std::string tmp1 = tmpbuf1;
		if (tmp1 == "")
		{
			Erros = u8"保存失败-当前循环排序存档读未命名!";
			return;
		}
		if (TMPbuttonitiems == 0)
		{
			Erros = u8"保存失败-当前循环排序存档没有按钮排序!";
			return;
		}
		std::string gre = "|"+ tmp1 +",";
		auto cfg = ConfigurationFile::i();
		if (loopnames_ == 0)
		{
			loopnames_++;
			BTofTABE = new std::string[loopnames_];
			BTofTABE[0] = tmp1;
			cfg->ini().SetValue("loopavename", "names", gre.c_str());
			cfg->ini().SetLongValue("loopavename", "namesitems", loopnames_);
			cfg->ini().SetValue("loopdate", tmpbuf1, savebtloops().c_str());
			cfg->Save();
			Erros = u8"保存完成!";
		}
		else
		{
			std::string tmp = cfg->ini().GetValue("loopavename", "names");
			if (tmp.find(tmp1.data(),0) == tmp.npos)
			{
				std::string * tmp2 = new std::string[loopnames_+1];
				tmp2[0] = tmp1;
				for (int i = 0; i < loopnames_; i++)
				{
					tmp2[i+1] = BTofTABE[i].c_str();
				}
				loopnames_++;
				BTofTABE = new std::string[loopnames_];
				gre.clear();
				for (int i = 0; i < loopnames_; i++)
				{
					 BTofTABE[i] = tmp2[i].c_str();
					 gre += "|" + BTofTABE[i] + ",";
				}
				cfg->ini().SetValue("loopavename", "names", gre.c_str());//保存名字
				cfg->ini().SetLongValue("loopavename", "namesitems", loopnames_);//保存名字数量
				cfg->ini().SetValue("loopdate", tmpbuf1, savebtloops().c_str());//保存按钮顺序 
				cfg->Save();
				Erros = u8"保存完成!";
			}
			else
			{
				Erros = u8"发现同名排序,更新按钮排序";
				cfg->ini().SetValue("loopdate", tmpbuf1, savebtloops().c_str());
				cfg->Save();
			}
		}
	}
	//读取存档个数和存档名称 完成
	void LoopPrompt::loadloopdate()
	{
		auto cfg = ConfigurationFile::i();
		loopnames_ = cfg->ini().GetLongValue("loopavename", "namesitems");//项目个数
		if (loopnames_ > 0)
		{
			//读取分配左边已保存按钮顺序文字
			BTofTABE = new std::string[loopnames_];
			std::string tmp = cfg->ini().GetValue("loopavename", "names");//项目名称
			std::string beginFlag = "|";
			std::string endFlag = ",";
			int startPos = 0;
			int endPos = 0;
			int beginPos = 0;
			int endingpos = 0;
			for (int i = 0; i < loopnames_; i++)
			{
				startPos = (int)tmp.find(beginFlag, startPos);
				endPos = (int)tmp.find(endFlag, startPos);
				beginPos = startPos + (int)beginFlag.length();
				endingpos = endPos - startPos - (int)beginFlag.length();
				BTofTABE[i] = tmp.substr(beginPos, endingpos);
				startPos++;
				endPos++;
			}
			
			if (loopnames_ > 0)
			{
				Erros = u8"循环排序存档读取完成,发现"+ std::to_string(loopnames_)+ u8"个存档";
			}
			else
			{
				Erros = u8"循环排序存档读取完成,未发现存档";
			}
		}
	}
	//读取某个存档按钮顺序 完成 
	void LoopPrompt::loadloopbuttondate(std::string tmpname)
	{
		auto cfg = ConfigurationFile::i();
		std::string tmp = cfg->ini().GetValue("loopdate", tmpname.c_str());//根据名称读取存档
		std::string beginFlag = "|";
		std::string endFlag = ",";
		int startPos = 0;
		int endPos = 0;
		int beginPos = 0;
		int endingpos = 0;
		startPos = (int)tmp.find(beginFlag, startPos);
		endPos = (int)tmp.find(endFlag, startPos);
		beginPos = startPos + (int)beginFlag.length();
		endingpos = endPos - startPos - (int)beginFlag.length();
		TMPbuttonitiems = std::stoi(tmp.substr(beginPos, endingpos)) ;//得到数量赋值给TMPbuttonitiems
		startPos++;
		endPos++;
		//重建BTofLOOP数据
		BTofLOOP.clear();
		for (int i = 0; i < TMPbuttonitiems; i++)
		{
			startPos = (int)tmp.find(beginFlag, startPos);
			endPos = (int)tmp.find(endFlag, startPos);
			beginPos = startPos + (int)beginFlag.length();
			endingpos = endPos - startPos - (int)beginFlag.length();
			BTofLOOP.push_back(tmp.substr(beginPos, endingpos).c_str());
			startPos++;
			endPos++;
		}
	}
	//删除按钮顺序存档
	void LoopPrompt::Deleteloopdate(char* tmpbuf1)
	{
		if (loopnames_ >0)
		{
			std::string  gre = tmpbuf1;
			std::string  gre2;
			if (gre.length() > 1)
			{
				for (int i = 0; i < loopnames_; i++)
				{
					if (BTofTABE[i].c_str() != gre)
					{
						gre2 += "|" + BTofTABE[i] + ",";
					}
				}
				loopnames_--;
				auto cfg = ConfigurationFile::i();
				cfg->ini().SetValue("loopavename", "names", gre2.c_str());
				cfg->ini().SetLongValue("loopavename", "namesitems", loopnames_);
				cfg->ini().Delete("loopdate", tmpbuf1);
				TMPbuttonitiems = 0;
				BTofLOOP.clear();
				cfg->Save();
				loadloopdate();
				Erros = u8"当前循环排序名称已删除!";
			}
			else
			{
				Erros = u8"没有给当前循环排序设置名称!";
			}
		}
	}
	//所有按钮设置和添加
	void LoopPrompt::setkeys(Keybind& setting)
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
		ImGui::SameLine();
		if (setting.nickname() !=  "show_LoopPromptUI")
		{
			if (ImGui::Button((u8"添加" + suffix).c_str())&& !setting.keys().empty())
			{
				BTofLOOP.push_back((std::to_string(TMPbuttonitiems) + "{" + setting.displayName() + "}").c_str());
				TMPbuttonitiems++;
			}
			else
			{
				if (setting.keys().empty())
				{
					Erros = u8"没有给当前按钮设置按键!";
				}
			}
		}

	}
	//根据bool参数检测更改按键
	void LoopPrompt::setkeysok(std::set<uint>& keys)
	{
		shezianjian = false;
		if (showkeybind_.isBeingModified())
		{
			showkeybind_.keys(keys);
			showkeybind_.isBeingModified(false);
		}
		if (tabekeybind_.isBeingModified())
		{
			tabekeybind_.keys(keys);
			tabekeybind_.isBeingModified(false);
		}
		if (fangunkeybind_.isBeingModified())
		{
			fangunkeybind_.keys(keys);
			fangunkeybind_.isBeingModified(false);
		}
		if (anjian01_.isBeingModified())
		{
			anjian01_.keys(keys);
			anjian01_.isBeingModified(false);
		}
		if (anjian02_.isBeingModified())
		{
			anjian02_.keys(keys);
			anjian02_.isBeingModified(false);
		}
		if (anjian03_.isBeingModified())
		{
			anjian03_.keys(keys);
			anjian03_.isBeingModified(false);
		}
		if (anjian04_.isBeingModified())
		{
			anjian04_.keys(keys);
			anjian04_.isBeingModified(false);
		}
		if (anjian05_.isBeingModified())
		{
			anjian05_.keys(keys);
			anjian05_.isBeingModified(false);
		}
		if (anjian06_.isBeingModified())
		{
			anjian06_.keys(keys);
			anjian06_.isBeingModified(false);
		}
		if (anjian07_.isBeingModified())
		{
			anjian07_.keys(keys);
			anjian07_.isBeingModified(false);
		}
		if (anjian08_.isBeingModified())
		{
			anjian08_.keys(keys);
			anjian08_.isBeingModified(false);
		}
		if (anjian09_.isBeingModified())
		{
			anjian09_.keys(keys);
			anjian09_.isBeingModified(false);
		}
		if (anjian10_.isBeingModified())
		{
			anjian10_.keys(keys);
			anjian10_.isBeingModified(false);
		}
		if (anjian11_.isBeingModified())
		{
			anjian11_.keys(keys);
			anjian11_.isBeingModified(false);
		}
		if (anjian12_.isBeingModified())
		{
			anjian12_.keys(keys);
			anjian12_.isBeingModified(false);
		}
		if (anjian13_.isBeingModified())
		{
			anjian13_.keys(keys);
			anjian13_.isBeingModified(false);
		}
		if (anjian14_.isBeingModified())
		{
			anjian14_.keys(keys);
			anjian14_.isBeingModified(false);
		}
		if (anjian15_.isBeingModified())
		{
			anjian15_.keys(keys);
			anjian15_.isBeingModified(false);
		}
	}
	//删除某个按钮并且更新按钮排序
	void deletsone(std::string tmp) 
	{
		if (!schans)
		{
			schans = true;
			std::vector<std::string>::iterator it;
			for (it = BTofLOOP.begin(); it != BTofLOOP.end();)
			{
				if (*it == tmp)
				{
					it = BTofLOOP.erase(it);
				}
				else
				{
					it++;
				}
			}
			TMPbuttonitiems--;
			std::string tmp;
			for (int i = 0; i < TMPbuttonitiems; i++)
			{
				tmp += BTofLOOP[i];
			}

			std::string beginFlag = "{";
			std::string endFlag = "}";
			int startPos = 0;
			int endPos = 0;
			int beginPos = 0;
			int endingpos = 0;
			BTofLOOP.clear();
			for (int i = 0; i < TMPbuttonitiems; i++)
			{
				startPos = (int)tmp.find(beginFlag, startPos);
				endPos = (int)tmp.find(endFlag, startPos);
				beginPos = startPos + (int)beginFlag.length();
				endingpos = endPos - startPos - (int)beginFlag.length();
				BTofLOOP.push_back((std::to_string(i) + "{" + tmp.substr(beginPos, endingpos) + "}" ).c_str());
				startPos++;
				endPos++;
			}


		}
		schans = false;
	}
	//判断按钮
	void LoopPrompt::anjianjiance(std::set<uint>& keys)
	{
		if (!anjzq && (int)danqiangbt.find(u8"F1", 0) > 0 && keys == anjian01_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"F2",0) > 0 && keys == anjian02_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"F3", 0) > 0 && keys == anjian03_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"F4", 0) > 0 && keys == anjian04_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"F5", 0) > 0 && keys == anjian05_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"武器1", 0) > 0 && keys == anjian06_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"武器2", 0) > 0 && keys == anjian07_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"武器3", 0) > 0 && keys == anjian08_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"武器4", 0) > 0 && keys == anjian09_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"武器5", 0) > 0 && keys == anjian10_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"治疗", 0) > 0 && keys == anjian11_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"插槽1", 0) > 0 && keys == anjian12_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"插槽2", 0) > 0 && keys == anjian13_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"插槽3", 0) > 0 && keys == anjian14_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"精英", 0) > 0 && keys == anjian15_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"切换", 0) > 0 && keys == tabekeybind_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"翻滚", 0) > 0 && keys == fangunkeybind_.keys())
		{
			anjzq = true;
			return;
		}
	}
	//制作分享文字
	void LoopPrompt::makeFXWZ()
	{
		std::string tmp = buf1;
		if (tmp != "" && TMPbuttonitiems >0)
		{
			std::string tmp = "|";
			tmp += buf1;
			tmp += u8"-享,|"+std::to_string(TMPbuttonitiems) +",|";
			for (int i = 0; i < TMPbuttonitiems; i++)
			{
				for (int t = 0; t < 17; t++)
				{
					if (BTofLOOP[i].find(EncodeMap[t],0) != BTofLOOP[i].npos)
					{
						tmp += "&"+ DecodeMap[t] + ",";
					}
				}
			}
			ImGui::SetClipboardText(tmp.c_str());
			Erros = u8"创建共享文本成功!";
		}
		else
		{
			if (tmp == "")
			{
				Erros = u8"创建共享文本失败-没有给当前循环排序命名!";
			}
			else
			{
				if (TMPbuttonitiems == 0)
				{
					Erros = u8"创建共享文本失败-没有给当前循环排序按钮!";
				}
			}

		}
	}
	//解析分享文字
	void LoopPrompt::parsFXWZ()
	{
		//|方吞逻逤戎1{享},|&A,&F,&K,&B,&G,&L,&M,&N,&C,&H,&L,&M,&N,&D,&I,&L,&M,&N,&E,&J,&O,&P,&Q,
		std::string tmp = buf2;
		try
		{
			if (tmp != "")
			{
				std::string beginFlag = "|";
				std::string endFlag = ",";
				int startPos = 0;
				int endPos = 0;
				int beginPos = 0;
				int endingpos = 0;
				if (tmp.find(beginFlag, startPos) == tmp.npos)
				{
					Erros = u8"输入的文本有误!";
					return;
				}
				startPos = (int)tmp.find(beginFlag, startPos);
				endPos = (int)tmp.find(endFlag, startPos);
				beginPos = startPos + (int)beginFlag.length();
				endingpos = endPos - startPos - (int)beginFlag.length();
				std::string tmp2 = tmp.substr(beginPos, endingpos);
				tmp2.copy(buf1, tmp2.length(), 0);
				*(buf1 + tmp2.length()) = '\0';
				startPos++;
				endPos++;
				startPos = (int)tmp.find(beginFlag, startPos);
				endPos = (int)tmp.find(endFlag, startPos);
				beginPos = startPos + (int)beginFlag.length();
				endingpos = endPos - startPos - (int)beginFlag.length();
				TMPbuttonitiems = std::stoi(tmp.substr(beginPos, endingpos));//得到数量赋值给TMPbuttonitiems
				if (TMPbuttonitiems > 0)
				{
				}
				else
				{
					Erros = u8"解析文本失败!请确认文本格式是否正确";
				}
				startPos++;
				endPos++;
				beginFlag = "&";
				BTofLOOP.clear(); //|河湾{享},|19,|&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,
				for (int i = 0; i < TMPbuttonitiems; i++)
				{
					startPos = (int)tmp.find(beginFlag, startPos);
					endPos = (int)tmp.find(endFlag, startPos);
					beginPos = startPos + (int)beginFlag.length();
					endingpos = endPos - startPos - (int)beginFlag.length();
					std::string tmp3 = tmp.substr(beginPos, endingpos).c_str();
					for (int t = 0; t < 17; t++)
					{
						if (tmp3.find(DecodeMap[t], 0) != tmp3.npos)
						{
							BTofLOOP.push_back((std::to_string(i) + "{" + EncodeMap[t] + "}").c_str());
						}
					}
					startPos++;
					endPos++;
				}
				Erros = u8"解析文本完成!";
				saveloopdate(buf1);
			}
			else
			{
				Erros = u8"没有输入!";
			}
		}
		catch (const std::exception&)
		{
			Erros = u8"解析文本失败!请确认文本格式是否正确";
		}
		
	}

	void LoopPrompt::Draw()
	{
		if (isVisibleLoopPrompt_)
		{
			ImGui::SetNextWindowSize({ 750, 605 }, ImGuiCond_::ImGuiCond_FirstUseEver);
			ImGui::Begin(u8"输出循环提示器设置", &isVisibleLoopPrompt_, ImGuiWindowFlags_NoResize);
			ImGui::Columns(2, false);
			ImGui::Separator();
			//ImGui::Text(u8"保存当前按键排序(名称不能为空!不要输入\"|\"和\",\"!)");
			ImGui::PushItemWidth(200.0f);
			ImGui::InputText(u8"名称", buf1, 128); ImGui::SameLine();
			if (ImGui::IsItemHovered())
			{
				ImGui::BeginTooltip();
				ImGui::TextUnformatted(u8"保存当前按键排序(名称不能为空!不要输入\"|\"和\",\"!)");
				ImGui::EndTooltip();
			}
			if (ImGui::Button(u8"保存")) saveloopdate(buf1); ImGui::SameLine();
			if (ImGui::Button(u8"删除")) Deleteloopdate(buf1); ImGui::SameLine();
			if (ImGui::Button(u8"创建共享")) makeFXWZ();
			ImGui::PushItemWidth(200.0f);
			ImGui::InputText(u8"##载入", buf2, 10240); ImGui::SameLine();
			if (ImGui::Button(u8"载入共享")) parsFXWZ();
			ImGui::NextColumn();
			ImGuiConfigurationWrapper(&ImGui::Checkbox, pingbiwasd_);
			ImGuiConfigurationWrapper(&ImGui::Checkbox, pingbiRK_);
			ImGui::Columns(1);
#pragma region 按键设置-按键设置完成!清除未完成
			ImGui::Columns(3, false);
			ImGui::Separator();
			setkeys(showkeybind_);
			ImGui::NextColumn();
			ImGui::PushItemWidth(150.0f);
			ImGuiConfigurationWrapper(&ImGui::SliderFloat, LoopPromptA_, 0.01f, 1.0f, "%.2f", 1.0f);
			ImGui::NextColumn();
			if (ImGui::Button(u8"清除所有按钮"))
			{
				TMPbuttonitiems = 0;
				BTofLOOP.clear();
			}
			ImGui::Columns(1);

			ImGui::Columns(3, false);
			ImGui::Separator();
			ImGui::Text(u8"按键需要跟游戏设置一样(鼠标左右键已排除)");
			ImGui::NextColumn();
			setkeys(tabekeybind_);
			ImGui::NextColumn();
			setkeys(fangunkeybind_);
			ImGui::Columns(1);
			
			ImGui::Columns(5, NULL);
			ImGui::Separator();
			setkeys(anjian01_); ImGui::NextColumn();
			setkeys(anjian02_); ImGui::NextColumn();
			setkeys(anjian03_); ImGui::NextColumn();
			setkeys(anjian04_); ImGui::NextColumn();
			setkeys(anjian05_); ImGui::NextColumn();

			setkeys(anjian06_); ImGui::NextColumn();
			setkeys(anjian07_); ImGui::NextColumn();
			setkeys(anjian08_); ImGui::NextColumn();
			setkeys(anjian09_); ImGui::NextColumn();
			setkeys(anjian10_); ImGui::NextColumn();

			setkeys(anjian11_); ImGui::NextColumn();
			setkeys(anjian12_); ImGui::NextColumn();
			setkeys(anjian13_); ImGui::NextColumn();
			setkeys(anjian14_); ImGui::NextColumn();
			setkeys(anjian15_); ImGui::NextColumn();

			ImGui::Columns(1);
			ImGui::Separator();
#pragma endregion

#pragma region 所有存档
			ImGui::BeginChild("Child1", ImVec2(ImGui::GetWindowContentRegionWidth() * 0.25f, 350), true);
			if (loopnames_ != 0 && !CGdate)
			{
				for (int i = 0; i < loopnames_; i++)
				{
					if (ImGui::Button(BTofTABE[i].c_str(), ImVec2(-1.0f, 0.0f)))
					{
						loadloopbuttondate(BTofTABE[i]);
						BTofTABE[i].copy(buf1, BTofTABE[i].length(),0);
						*(buf1 + BTofTABE[i].length()) = '\0';
					}
					if (ImGui::IsItemHovered())
					{
						ImGui::BeginTooltip();
						ImGui::TextUnformatted(BTofTABE[i].c_str());
						ImGui::EndTooltip();
					}
				}
			}
			ImGui::EndChild();
			ImGui::SameLine();
#pragma endregion

#pragma region 按钮排序
			ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 5.0f);
			ImGui::BeginChild("Child2", ImVec2(0, 350), true);
			ImGui::Columns(8);
			for (int i = 0; i < TMPbuttonitiems; i++)
			{
				if (!schans)
				{
					if (i % 8 == 0)
					{
						ImGui::Separator();
					}
					if (ImGui::Button(BTofLOOP[i].c_str(), ImVec2(-1.0f, 0.0f)))
					{
						deletsone(BTofLOOP[i]);
					}
					if (ImGui::IsItemHovered())
					{
						ImGui::BeginTooltip();
						ImGui::TextUnformatted(BTofLOOP[i].c_str());
						ImGui::EndTooltip();
					}
					ImGui::NextColumn();
				}
			}
			ImGui::Columns(1);
			ImGui::Separator();
			ImGui::EndChild();
			
			ImGui::PopStyleVar();
#pragma endregion
			if (Erros != "")
			{
				ImGui::Text(Erros.c_str());
			}
			ImGui::End();
		}

		if (isVisibleLoopPromptui_)
		{
			ImGui::SetNextWindowBgAlpha(LoopPromptA_.value());//透明度
			ImGui::Begin(u8"输出循环", &isVisibleLoopPromptui_, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);

			for (int i = anjiansunxu; i < TMPbuttonitiems; i++)
			{
				std::string tmp =  getksystring(BTofLOOP[i].c_str());
				if (i< anjiansunxu +5)
				{
					if (i == anjiansunxu)
					{
						//font_
						ImGui::PushFont(Core::i()->font());
						float tmpposx = 50.0f;
						if (ImGui::CalcTextSize(tmp.c_str()).x + 10.0f > tmpposx)
						{
							tmpposx = ImGui::CalcTextSize(tmp.c_str()).x + 10.0f;
						}

						ImGui::Button(tmp.c_str(), ImVec2(tmpposx, 50.0f));
						ImGui::PopFont();
						danqiangbt = BTofLOOP[i].c_str();
						ImGui::SameLine();
					}
					else if ( i == anjiansunxu +1)
					{
						ImGui::Button(tmp.c_str(), ImVec2(40.0f, 35.0f));
					}
					else
					{
						ImGui::Button(tmp.c_str(),ImVec2(40.0f, 25.0f));
					}
					ImGui::SameLine();
				}
				else
				{
					ImGui::SameLine();
					continue;
				}
			}
			if (anjzq && anjiansunxu  < TMPbuttonitiems)
			{

				anjiansunxu++;
				anjzq = false;
			}
			else
			{
				if (anjiansunxu == TMPbuttonitiems )
				{
					anjiansunxu = 0;
					anjzq = false;
				}
			}

			ImGui::BeginGroup();
			if (ImGui::Button("X"))
			{
				isVisibleLoopPromptui_ = false;
			}
			if (ImGui::Button("R"))
			{
				anjiansunxu = 0;
			}
			ImGui::EndGroup();

			ImGui::End();
		}
	}

	InputResponse GW2Radial::LoopPrompt::OnInputChange(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys)
	{
		//设置界面
		const bool isMenuKeybindLoopPrompt = keys == showKeybindLoopPrompt_.keys();
		if (isMenuKeybindLoopPrompt)
		{
			isVisibleLoopPrompt_ = true;
		}
		//循环器界面
		const bool isMenuKeybindshowkeybind_ = keys == showkeybind_.keys();
		if (isMenuKeybindshowkeybind_)
		{
			isVisibleLoopPromptui_ = true;
		}
		//检测按钮
		if (isVisibleLoopPromptui_)
		{
			//anjianjiance(keys);
			auto fullKeybind = keys;
			fullKeybind.erase(VK_LBUTTON);
			fullKeybind.erase(VK_RBUTTON);
			if (pingbiwasd_.value())
			{
				fullKeybind.erase(0x41);
				fullKeybind.erase(0x53);
				fullKeybind.erase(0x57);
				fullKeybind.erase(0x44);
			}
			for (const auto& ek : changedKeys)
			{
				if (ek.vk == VK_LBUTTON)
					continue;
				if (ek.vk == VK_RBUTTON && pingbiRK_.value())
					continue;
				if (pingbiwasd_.value())
				{
					if (ek.vk == 0x41)
						continue;
					if (ek.vk == 0x53)
						continue;
					if (ek.vk == 0x57)
						continue;
					if (ek.vk == 0x44)
						continue;
				}
				if (!ek.down)
				{
					fullKeybind.insert(ek.vk);
					anjianjiance(fullKeybind);
				}
			}
			
		}


		//检测设置按键
		if (shezianjian)
		{
		    auto fullKeybind = keys;
			fullKeybind.erase(VK_LBUTTON);
			fullKeybind.erase(VK_RBUTTON);
			if (pingbiwasd_.value())
			{
				fullKeybind.erase(0x41);
				fullKeybind.erase(0x53);
				fullKeybind.erase(0x57);
				fullKeybind.erase(0x44);
			}
			for (const auto& ek : changedKeys)
			{
				if (ek.vk == VK_LBUTTON)
					continue;
				if (ek.vk == VK_RBUTTON && pingbiRK_.value())
					continue;
				if (pingbiwasd_.value())
				{
					if (ek.vk == 0x41)
						continue;
					if (ek.vk == 0x53)
						continue;
					if (ek.vk == 0x57)
						continue;
					if (ek.vk == 0x44)
						continue;
				}
				if (!ek.down)
				{
					fullKeybind.insert(ek.vk);
					setkeysok(fullKeybind);
				}
			}
		}
		return isMenuKeybindLoopPrompt ? InputResponse::PREVENT_ALL : InputResponse::PASS_TO_GAME;
	}

}

