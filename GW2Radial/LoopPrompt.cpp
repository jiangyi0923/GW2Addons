#include "LoopPrompt.h"
#include <imgui.h>
#include <ImGuiExtensions.h>
#include <Wheel.h>
#include <Utility.h>
#include <Core.h>
namespace GW2Radial
{
	DEFINE_SINGLETON(LoopPrompt);

	int TMPdataitiems = 0;//�浵���ݱ仯����
	int TMPbuttonitiems = 0;//��ť�����仯����
	std::string* BTofTABE = nullptr;
	std::vector<std::string> BTofLOOP;
	bool schans = false;
	int anjiansunxu = 0;
	std::string danqiangbt = "";
	bool anjzq = false;

	LoopPrompt::LoopPrompt() : showKeybindLoopPrompt_("show_LoopPrompt", "Show LoopPrompt", { VK_F10 }, false),
		showkeybind_("show_LoopPromptUI", u8"����ѭ����", { VK_F7 }, true),
		tabekeybind_("tabekey", u8"�л�"), pingbiwasd_(u8"����WASD�����","pingbiwasd","loopavename",true), pingbiRK_(u8"��������Ҽ�", "pingbiRK", "loopavename", true),
		fangunkeybind_("fangunkey", u8"����"), LoopPromptA_(u8"ѭ����͸����", "LoopPromptA_", "loopavename", 0.5f),
		anjian01_("F1_", u8"F1"), anjian02_("F2_", u8"F2"), anjian03_("F3_", u8"F3"), anjian04_("F4_", u8"F4"), anjian05_("F5_", u8"F5"),
		anjian06_("wuqi1_", u8"����1"), anjian07_("wuqi2_", u8"����2"), anjian08_("wuqi3_", u8"����3"), anjian09_("wuqi4_", u8"����4"), anjian10_("wuqi5_", u8"����5"),
		anjian11_("ziliao_", u8"����"), anjian12_("ca1_", u8"���1"), anjian13_("ca2_", u8"���2"), anjian14_("ca3_", u8"���3"), anjian15_("jy_", u8"��Ӣ")
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
	//��ȡ��ť���򱣴���
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
	//��ȡ����ֵ��Ӧ�İ�������
	std::string LoopPrompt::getksystring(std::string tmp)
	{
		if ((int)tmp.find(u8"F1", 0) > 0)tmp = anjian01_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"F2", 0) > 0 ) tmp = anjian02_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"F3", 0) > 0 ) tmp = anjian03_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"F4", 0) > 0 ) tmp = anjian04_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"F5", 0) > 0 ) tmp = anjian05_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"����1", 0) > 0 ) tmp = anjian06_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"����2", 0) > 0 ) tmp = anjian07_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"����3", 0) > 0 ) tmp = anjian08_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"����4", 0) > 0 ) tmp = anjian09_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"����5", 0) > 0 ) tmp = anjian10_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"����", 0) > 0 ) tmp = anjian11_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"���1", 0) > 0 ) tmp = anjian12_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"���2", 0) > 0 ) tmp = anjian13_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"���3", 0) > 0 ) tmp = anjian14_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"��Ӣ", 0) > 0 ) tmp = anjian15_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"�л�", 0) > 0 ) tmp = tabekeybind_.keysDisplayStringArray().data();
		if ((int)tmp.find(u8"����", 0) > 0 ) tmp = fangunkeybind_.keysDisplayStringArray().data();
		return tmp;
	}
	///���水ť˳�����ƺͰ�ť˳��
	void LoopPrompt::saveloopdate(char* tmpbuf1)
	{
		std::string tmp1 = tmpbuf1;
		if (tmp1 == "")
		{
			Erros = u8"����ʧ��-��ǰѭ������浵��δ����!";
			return;
		}
		if (TMPbuttonitiems == 0)
		{
			Erros = u8"����ʧ��-��ǰѭ������浵û�а�ť����!";
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
			Erros = u8"�������!";
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
				cfg->ini().SetValue("loopavename", "names", gre.c_str());//��������
				cfg->ini().SetLongValue("loopavename", "namesitems", loopnames_);//������������
				cfg->ini().SetValue("loopdate", tmpbuf1, savebtloops().c_str());//���水ť˳�� 
				cfg->Save();
				Erros = u8"�������!";
			}
			else
			{
				Erros = u8"����ͬ������,���°�ť����";
				cfg->ini().SetValue("loopdate", tmpbuf1, savebtloops().c_str());
				cfg->Save();
			}
		}
	}
	//��ȡ�浵�����ʹ浵���� ���
	void LoopPrompt::loadloopdate()
	{
		auto cfg = ConfigurationFile::i();
		loopnames_ = cfg->ini().GetLongValue("loopavename", "namesitems");//��Ŀ����
		if (loopnames_ > 0)
		{
			//��ȡ��������ѱ��水ť˳������
			BTofTABE = new std::string[loopnames_];
			std::string tmp = cfg->ini().GetValue("loopavename", "names");//��Ŀ����
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
				Erros = u8"ѭ������浵��ȡ���,����"+ std::to_string(loopnames_)+ u8"���浵";
			}
			else
			{
				Erros = u8"ѭ������浵��ȡ���,δ���ִ浵";
			}
		}
	}
	//��ȡĳ���浵��ť˳�� ��� 
	void LoopPrompt::loadloopbuttondate(std::string tmpname)
	{
		auto cfg = ConfigurationFile::i();
		std::string tmp = cfg->ini().GetValue("loopdate", tmpname.c_str());//�������ƶ�ȡ�浵
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
		TMPbuttonitiems = std::stoi(tmp.substr(beginPos, endingpos)) ;//�õ�������ֵ��TMPbuttonitiems
		startPos++;
		endPos++;
		//�ؽ�BTofLOOP����
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
	//ɾ����ť˳��浵
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
				Erros = u8"��ǰѭ������������ɾ��!";
			}
			else
			{
				Erros = u8"û�и���ǰѭ��������������!";
			}
		}
	}
	//���а�ť���ú����
	void LoopPrompt::setkeys(Keybind& setting)
	{
		std::string suffix = "##" + setting.nickname();
		ImGui::Text(setting.displayName().c_str());
		ImGui::SameLine();
		if (setting.keys().empty())
		{
			ImGui::Text(u8"��");
		}
		else
		{
			ImGui::Text(setting.keysDisplayStringArray().data());
		}

		ImVec2 mix_(ImGui::GetItemRectMin().x - 3.0f, ImGui::GetItemRectMin().y - 1.0f);
		ImVec2 max_(ImGui::GetItemRectMax().x + 4.0f, ImGui::GetItemRectMax().y + 4.0f);
		ImGui::GetWindowDrawList()->AddRect(mix_, max_, IM_COL32(255, 255, 0, 255));
		
		ImGui::SameLine();
		if (!setting.isBeingModified() && ImGui::Button((u8"����" + suffix).c_str()))
		{
			setting.isBeingModified(true);
			setting.keysDisplayStringArray().at(0) = '\0';
			shezianjian = true;
		}
		else if (setting.isBeingModified() && ImGui::Button((u8"���" + suffix).c_str()))
		{
			setting.keys(std::set<uint>());
			shezianjian = false;
			setting.isBeingModified(false);
		}
		ImGui::SameLine();
		if (setting.nickname() !=  "show_LoopPromptUI")
		{
			if (ImGui::Button((u8"���" + suffix).c_str())&& !setting.keys().empty())
			{
				BTofLOOP.push_back((std::to_string(TMPbuttonitiems) + "{" + setting.displayName() + "}").c_str());
				TMPbuttonitiems++;
			}
			else
			{
				if (setting.keys().empty())
				{
					Erros = u8"û�и���ǰ��ť���ð���!";
				}
			}
		}

	}
	//����bool���������İ���
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
	//ɾ��ĳ����ť���Ҹ��°�ť����
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
	//�жϰ�ť
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
		if (!anjzq && (int)danqiangbt.find(u8"����1", 0) > 0 && keys == anjian06_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"����2", 0) > 0 && keys == anjian07_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"����3", 0) > 0 && keys == anjian08_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"����4", 0) > 0 && keys == anjian09_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"����5", 0) > 0 && keys == anjian10_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"����", 0) > 0 && keys == anjian11_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"���1", 0) > 0 && keys == anjian12_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"���2", 0) > 0 && keys == anjian13_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"���3", 0) > 0 && keys == anjian14_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"��Ӣ", 0) > 0 && keys == anjian15_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"�л�", 0) > 0 && keys == tabekeybind_.keys())
		{
			anjzq = true;
			return;
		}
		if (!anjzq && (int)danqiangbt.find(u8"����", 0) > 0 && keys == fangunkeybind_.keys())
		{
			anjzq = true;
			return;
		}
	}
	//������������
	void LoopPrompt::makeFXWZ()
	{
		std::string tmp = buf1;
		if (tmp != "" && TMPbuttonitiems >0)
		{
			std::string tmp = "|";
			tmp += buf1;
			tmp += u8"-��,|"+std::to_string(TMPbuttonitiems) +",|";
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
			Erros = u8"���������ı��ɹ�!";
		}
		else
		{
			if (tmp == "")
			{
				Erros = u8"���������ı�ʧ��-û�и���ǰѭ����������!";
			}
			else
			{
				if (TMPbuttonitiems == 0)
				{
					Erros = u8"���������ı�ʧ��-û�и���ǰѭ������ť!";
				}
			}

		}
	}
	//������������
	void LoopPrompt::parsFXWZ()
	{
		//|�������C��1{��},|&A,&F,&K,&B,&G,&L,&M,&N,&C,&H,&L,&M,&N,&D,&I,&L,&M,&N,&E,&J,&O,&P,&Q,
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
					Erros = u8"������ı�����!";
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
				TMPbuttonitiems = std::stoi(tmp.substr(beginPos, endingpos));//�õ�������ֵ��TMPbuttonitiems
				if (TMPbuttonitiems > 0)
				{
				}
				else
				{
					Erros = u8"�����ı�ʧ��!��ȷ���ı���ʽ�Ƿ���ȷ";
				}
				startPos++;
				endPos++;
				beginFlag = "&";
				BTofLOOP.clear(); //|����{��},|19,|&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,&F,
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
				Erros = u8"�����ı����!";
				saveloopdate(buf1);
			}
			else
			{
				Erros = u8"û������!";
			}
		}
		catch (const std::exception&)
		{
			Erros = u8"�����ı�ʧ��!��ȷ���ı���ʽ�Ƿ���ȷ";
		}
		
	}

	void LoopPrompt::Draw()
	{
		if (isVisibleLoopPrompt_)
		{
			ImGui::SetNextWindowSize({ 750, 605 }, ImGuiCond_::ImGuiCond_FirstUseEver);
			ImGui::Begin(u8"���ѭ����ʾ������", &isVisibleLoopPrompt_, ImGuiWindowFlags_NoResize);
			ImGui::Columns(2, false);
			ImGui::Separator();
			//ImGui::Text(u8"���浱ǰ��������(���Ʋ���Ϊ��!��Ҫ����\"|\"��\",\"!)");
			ImGui::PushItemWidth(200.0f);
			ImGui::InputText(u8"����", buf1, 128); ImGui::SameLine();
			if (ImGui::IsItemHovered())
			{
				ImGui::BeginTooltip();
				ImGui::TextUnformatted(u8"���浱ǰ��������(���Ʋ���Ϊ��!��Ҫ����\"|\"��\",\"!)");
				ImGui::EndTooltip();
			}
			if (ImGui::Button(u8"����")) saveloopdate(buf1); ImGui::SameLine();
			if (ImGui::Button(u8"ɾ��")) Deleteloopdate(buf1); ImGui::SameLine();
			if (ImGui::Button(u8"��������")) makeFXWZ();
			ImGui::PushItemWidth(200.0f);
			ImGui::InputText(u8"##����", buf2, 10240); ImGui::SameLine();
			if (ImGui::Button(u8"���빲��")) parsFXWZ();
			ImGui::NextColumn();
			ImGuiConfigurationWrapper(&ImGui::Checkbox, pingbiwasd_);
			ImGuiConfigurationWrapper(&ImGui::Checkbox, pingbiRK_);
			ImGui::Columns(1);
#pragma region ��������-�����������!���δ���
			ImGui::Columns(3, false);
			ImGui::Separator();
			setkeys(showkeybind_);
			ImGui::NextColumn();
			ImGui::PushItemWidth(150.0f);
			ImGuiConfigurationWrapper(&ImGui::SliderFloat, LoopPromptA_, 0.01f, 1.0f, "%.2f", 1.0f);
			ImGui::NextColumn();
			if (ImGui::Button(u8"������а�ť"))
			{
				TMPbuttonitiems = 0;
				BTofLOOP.clear();
			}
			ImGui::Columns(1);

			ImGui::Columns(3, false);
			ImGui::Separator();
			ImGui::Text(u8"������Ҫ����Ϸ����һ��(������Ҽ����ų�)");
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

#pragma region ���д浵
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

#pragma region ��ť����
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
			ImGui::SetNextWindowBgAlpha(LoopPromptA_.value());//͸����
			ImGui::Begin(u8"���ѭ��", &isVisibleLoopPromptui_, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);

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
		//���ý���
		const bool isMenuKeybindLoopPrompt = keys == showKeybindLoopPrompt_.keys();
		if (isMenuKeybindLoopPrompt)
		{
			isVisibleLoopPrompt_ = true;
		}
		//ѭ��������
		const bool isMenuKeybindshowkeybind_ = keys == showkeybind_.keys();
		if (isMenuKeybindshowkeybind_)
		{
			isVisibleLoopPromptui_ = true;
		}
		//��ⰴť
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


		//������ð���
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

