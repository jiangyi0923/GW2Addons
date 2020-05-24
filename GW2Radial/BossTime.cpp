#include "BossTime.h"
//#include <SettingsMenu.h>
#include <MiscTab.h>
#include <imgui.h>
#include <time.h>
#include <WinInet.h>
#include <sstream>
#include <iostream>
#include <ImGuiExtensions.h>
#include <boost/date_time/gregorian/gregorian.hpp>
//#include <DBINGtool.h>

namespace GW2Radial
{

	DEFINE_SINGLETON(BossTime);
#pragma region ��ʱ������
	const char* BossTime::BossName(int xuhao)
	{
		const char* tmp = "";
		switch (xuhao)
		{
			//�ϵ�ͼ
		case  1:tmp = u8"���Ѿ���";	break;
		case  2:tmp = u8"������";		break;
		case  3:tmp = u8"������Ī�϶�";		break;
		case  4:tmp = u8"��Ԫ��";		break;
		case  5:tmp = u8"���ħ��";	break;
		case  6:tmp = u8"�����ֵس�"; break;
		case  7:tmp = u8"׿��֮צ";	break;
		case  8:tmp = u8"��Ӱ����";	break;
		case  9:tmp = u8"�������Ķ�"; break;
		case 10:tmp = u8"���ܻ�����"; break;
		case 11:tmp = u8"��ʬ��";		break;
		case 12:tmp = u8"�����鷳";	break;
		case 13:tmp = u8"���ǳ�Ů��"; break;
		case 14:tmp = u8"�ʴ�������"; break;//20
		case 15:tmp = u8"�����ٲ�����"; break;//20
		case 16:tmp = u8"����ƽԭ����"; break;//20
			//����
		case 17:tmp = u8"�Դ���ĸ"; break;//10
		case 18:tmp = u8"���ٳ���"; break;
		case 19:tmp = u8"�������"; break;
		case 20:tmp = u8"�������"; break;
		case 21:tmp = u8"ɳ����"; break;//40
		case 22:tmp = u8"ŵ��ɽׯ"; break;
		case 23:tmp = u8"������������"; break;
		case 24:tmp = u8"������֮ɭ"; break;
			//����
		case 25:tmp = u8"�ĳ�����ս"; break;//05
		case 26:tmp = u8"��Ŭ������"; break;
		case 27:tmp = u8"���ƽ���"; break;
		case 28:tmp = u8"��ر���"; break;
		case 29:tmp = u8"����������"; break;//00
		case 30:tmp = u8"����֮·"; break;
		case 31:tmp = u8"����ʹ��"; break;
		case 32:tmp = u8"��������"; break;
		case 33:tmp = u8"����֮ŭ"; break;
		case 34:tmp = u8"ĥ��Ѫ��"; break;
		case 35:tmp = u8"�������Ѿ���"; break;
		case 36:tmp = u8"�����߹���"; break;
			//����
		case 37:tmp = u8"��ʥ������ʽ"; break;//10
		case 38:tmp = u8"���˴�˵ʥ̳"; break;//38
		case 39:tmp = u8"����ֿ�"; break;//05
		case 40:tmp = u8"�������ֻ�"; break;//39
		case 41:tmp = u8"������"; break;//05
		case 42:tmp = u8"�����籩"; break;
		default:break;
		}
		return tmp;
	}

	const char* BossTime::BossPost(int xuhao)
	{
		const char* tmp = "";
		switch (xuhao)
		{
		case  1:tmp = u8"[&BE4DAAA=]"; break;
		case  2:tmp = u8"[&BMIDAAA=]"; break;
		case  3:tmp = u8"[&BKcAAAA=]"; break;
		case  4:tmp = u8"[&BEcAAAA=]"; break;
		case  5:tmp = u8"[&BNQCAAA=]"; break;
		case  6:tmp = u8"[&BEEFAAA=]"; break;
		case  7:tmp = u8"[&BHoCAAA=]"; break;
		case  8:tmp = u8"[&BPcAAAA=]"; break;
		case  9:tmp = u8"[&BKgBAAA=]"; break;
		case  10:tmp = u8"[&BM0CAAA=]"; break;
		case  11:tmp = u8"[&BNABAAA=]"; break;
		case  12:tmp = u8"[&BKoBAAA=]"; break;
		case  13:tmp = u8"[&BNcGAAA=]"; break;
		case  14:tmp = u8"[&BJEBAAA=]"; break;
		case  15:tmp = u8"[&BEYEAAA=]"; break;
		case  16:tmp = u8"[&BOkBAAA=]"; break;
		case  17:tmp = u8"[&BAgIAAA=]�Ϸ�[&BMIHAAA=]"; break;
		case  18:tmp = u8"[&BPUHAAA=]"; break;
		case  19:tmp = u8"[&BGwIAAA=]"; break;
		case  20:tmp = u8"[&BBAIAAA=]"; break;
		case  21:tmp = u8"[&BHoHAAA=]"; break;
		case  22:tmp = u8"[&BK8JAAA=]"; break;
		case  23:tmp = u8"[&BK0JAAA=]2�㷽��"; break;
		case  24:tmp = u8"[&BLQJAAA=]7�㷽��[&BK4JAAA=]"; break;
		case  25:tmp = u8"[&BLsKAAA=]"; break;
		case  26:tmp = u8"[&BMEKAAA=]8�㷽��[&BHAKAAA=]"; break;
		case  27:tmp = u8"[&BKYLAAA=]"; break;
		case  28:tmp = u8"[&BGsKAAA=]"; break;
		case  29:tmp = u8"[&BIMLAAA=]"; break;
		case  30:tmp = u8"[&BFMKAAA=]"; break;
		case  31:tmp = u8"[&BLsLAAA=]"; break;
		case  32:tmp = u8"[&BEoKAAA=]10�㷽��[&BG0KAAA=]"; break;
		case  33:tmp = u8"[&BHQKAAA=]"; break;
		case  34:tmp = u8"[&BKMKAAA=]"; break;
		case  35:tmp = u8"[&BJQLAAA=]1�㷽��[&BHwLAAA=]"; break;
		case  36:tmp = u8"[&BAkLAAA=]7�㷽�򹥳�[&BPcKAAA=]��[&BAELAAA=]"; break;
		case  37:tmp = u8"[&BBsMAAA=]��[&BAcMAAA=]��[&BB0MAAA=]"; break;
		case  38:tmp = u8"[&BBsMAAA=]��[&BAUMAAA=]��[&BAEMAAA=]"; break;
		case  39:tmp = u8"[&BPgLAAA=]"; break;
		case  40:tmp = u8"[&BPgLAAA=]3�㷽��[&BBkMAAA=]"; break;
		case  41:tmp = u8"[&BDkMAAA=]��[&BEEMAAA=]"; break;
		case  42:tmp = u8"[&BCcMAAA=]"; break;
		default:break;
		}
		return tmp;
	}
#pragma endregion
	BossTime::BossTime()://showKeybindweb_("show_BossTime", "Show BossTime", { VK_F8 }, false),
		gudingwinpos_(u8"��������λ��", "gudingwinpos_", "shubiao", false),
		gudingwinpos_x(u8"����λ��x", "gudingwinpos_x", "shubiao", 500.0f),
		gudingwinpos_y(u8"����λ��y", "gudingwinpos_y", "shubiao", 5.0f)
	{
		inputChangeCallbackweb_ = [this](bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys) { return OnInputChangeweb(changed, keys, changedKeys); };
		Input::i()->AddInputChangeCallback(&inputChangeCallbackweb_);
	}
	BossTime::~BossTime()
	{
		if (auto i = Input::iNoInit(); i)
		{
			i->RemoveInputChangeCallback(&inputChangeCallbackweb_);
		}
	}
	void BossTime::Draw()
	{
		if (!isVisibleweb_ && jishiqi)
		{
			if (MiscTab::i()->showboostime() && kput == 0)
			{
				isVisibleweb_ = true;
				jishiqi = false;
			}
		}
		if (isVisibleweb_)
		{
			kput = 1;
			if (!_DoUI(isVisibleweb_))
			{
				isVisibleweb_ = false;
				jishiqi = true;
			}
		}
	}


#pragma region ��ҳ��ȡ
	bool geting = true;
	bool wancheng = false;
	const char* W_arrc = nullptr;//���а�
	const char * W_time1 = nullptr;//ʱ��
	const char * W_time2 = nullptr;//ʱ��
	std::string* FetchReleaseData(const char * days);//������ȡ��������
	std::string * W_renwu1 = new std::string[5];//������ʾ
	std::string * W_renwu2 = new std::string[5];//���ﱣ����ʾ
	std::string* result = new std::string[6];//���ﴢ��
	std::string* tmpIDname = new std::string[32];//���ﴢ��
	LPCWSTR stringToLPCWSTR(std::string orig);//����ת��
	LPCWSTR stringToLPCWSTR(std::string orig)
	{
		size_t origsize = orig.length() + 1;
		const size_t newsize = 100;
		size_t convertedChars = 0;
		wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length() - 1));
		mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
		return wcstring;
	}
	const char *  GetTime(int day)
	{
		using namespace boost::gregorian;
		boost::gregorian::date nowday = day_clock::local_day();
		boost::gregorian::date d2 = nowday + boost::gregorian::days(day);
		boost::gregorian::day_iterator d_iter(d2);
		std::string strTime = boost::gregorian::to_iso_extended_string(*d_iter);
		//char* out = new char[strTime.length()];
		//for (int i = 0; i <= strTime.length(); ++i)
		//	out[i] = strTime[i];
		char * out2 = new char[strTime.length()];
		strTime.copy(out2, strTime.length(), 0);//����5�������Ƽ����ַ���0�����Ƶ�λ��  
		*(out2 + strTime.length()) = '\0';//Ҫ�ֶ����Ͻ�����
		return out2;
	}
	std::string* FetchReleaseData(const char* days)
	{
		wancheng = false;
		std::string retVal;
		std::string _a = "http://do.gw2.kongzhong.com/task/completes?date=";
		std::string _b = days;
		std::string _tmp = _a + _b;
		DWORD response_length = 0;
		LPCWSTR ul = stringToLPCWSTR(_tmp);
		HINTERNET hSession = InternetOpen(L"RookIE/1.0", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
		if (hSession != NULL)
		{
			HINTERNET handle2 = InternetOpenUrl(hSession, ul, NULL, 0, INTERNET_FLAG_RELOAD | INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_NO_CACHE_WRITE, 0);
			if (handle2 != NULL)
			{
				char response_data[8000];//������
				if (InternetReadFile(handle2, response_data, sizeof(response_data) - 1, &response_length) && response_length > 0)
				{
					response_data[response_length] = '\0';
					response_length++;
				}
				if (response_length>0)
				{
					response_data[response_length] = '\0';
				}
				else
				{
					response_data[0] = '\0';
				}
				retVal = response_data;
				InternetCloseHandle(handle2);
				handle2 = NULL;
			}
			else
			{
				result[0] = "0";
				geting = false;
				wancheng = true;
				return result;
			}
			InternetCloseHandle(hSession);
			hSession = NULL;
		}
		else
		{
			result[0] = "0";
			geting = false;
			wancheng = true;
			return result;
		}
		if (response_length > 350)
		{
			std::string beginFlag = u8"task_name";
			std::string endFlag = u8",";
			std::string end = u8"}";
			int startPos = 0;
			int endPos = 0;
			int beginPos = 0;
			int endingpos = 0;
			for (int i = 0; i < 6; i++)
			{
				startPos = (int)retVal.find(beginFlag, startPos);
				endPos = (int)retVal.find(endFlag, startPos);
				beginPos = startPos + (int)beginFlag.length() + 2;
				endingpos = endPos - startPos - (int)beginFlag.length() - 2;
				result[i] = retVal.substr(beginPos, endingpos);
				if ((int)result[i].find(end) > 0)
				{
					result[i].replace(result[i].size() - 1, result[i].size(), "");
					if ((int)result[i].find(end) > 0)
					{
						result[i].replace(result[i].size() - 1, result[i].size(), "");
					}
				}
				startPos++;
				endPos++;
			}
			wancheng = true;
		}
		else
		{
			result[0] = "0";
			wancheng = true;
		}
		return result;
	}

	void getsting(const char *  days)
	{
		geting = false;
		W_renwu1 = FetchReleaseData(days);
	}
#pragma endregion

	void BossTime::Button_showit(int bosspaixuid,int showsidh,int showsidL,int h,int s)
	{
		char num_buf[32];
		char str3[32];
		const char* label = BossName(bosspaixuid);
		if (bosspaixuid != 0)
		{
			sprintf_s(num_buf, u8"[%02d:%02d]", h, s);
			strcpy_s(str3, num_buf);
			strcat_s(str3, label);
			label = str3;
		}
		if (ImGui::Button(label, ImVec2(120.0f * daxiao_ * daxiao2_, 22.0f * daxiao_ * daxiao2_)))
		{
			if (bosspaixuid != 0)
			{
				std::string arrc1 = label;
				std::string arrc2 = BossPost(bosspaixuid);
				std::string arrc3 = u8" ����\"gw2sy.top\"����boss��ʾ��";
				ImGui::SetClipboardText((arrc1 + arrc2 + arrc3).c_str());
			}
		} 
		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::TextUnformatted(u8"\r\n=======������ɸ��Ƶ����а�=======\r\n\n");
			ImGui::EndTooltip();
		}
	}

	bool BossTime::_DoUI(bool &ison)
	{
		if (ison)
		{
			daxiao_ = MiscTab::i()->jiemiandaxiao();
			daxiao2_ = MiscTab::i()->zitidaxiao()/15.0f;
			touming_ = MiscTab::i()->zhengtitoumingdu();
			ImGui::SetNextWindowBgAlpha(touming_);
			if (gwps())
			{
				ImGui::SetNextWindowPos(ImVec2(sPOSX(), sPOSY()));
			}
			ImGui::Begin("BOSS", &ison, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
			float bosx = ImGui::GetWindowPos().x;
			float bosy = ImGui::GetWindowPos().y;
			const float spacing = ImGui::GetStyle().ItemInnerSpacing.x;
			static int lines = 3;
			ImGui::SetWindowFontScale(daxiao_); 
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
			ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 1));

			float scrollingdaxiao = 45 * daxiao_ * daxiao2_;
			if (MiscTab::i()->jianyimoshi())//�Զ�����ʾ
			{
				if (!MiscTab::i()->jianyimoshi2() || ImGui::GetIO().WantCaptureMouse == 1)
				{
					int mmtL = 0;
					if (MiscTab::i()->dej())mmtL += 2;
					if (MiscTab::i()->hof())mmtL += 2;
					if (MiscTab::i()->bcj())mmtL += 2;
					if (mmtL > 1)scrollingdaxiao = (mmtL*46/2 +45) * daxiao_ * daxiao2_;
				}
			}
			else
			{
				if (!MiscTab::i()->jianyimoshi2() || ImGui::GetIO().WantCaptureMouse == 1)
				{
					scrollingdaxiao = 183 * daxiao_ * daxiao2_;
				}
			}

			ImGui::BeginChild("scrolling", ImVec2(360 * daxiao_ * daxiao2_, scrollingdaxiao), false);
			ImGui::SetWindowFontScale(daxiao_);

#pragma region BOSS������ʾ
			//scroll_x = ImGui::GetScrollX();
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(scroll_x / 120.0f / daxiao_ * daxiao2_ * 0.01031f, 0.6f, 0.6f, touming_));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(scroll_x / 120.0f / daxiao_ * daxiao2_ * 0.01031f, 0.6f, 0.8f, touming_));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(scroll_x / 120.0f / daxiao_ * daxiao2_ * 0.01031f, 0.6f, 1.0f, touming_));

			//if (MiscTab::i()->jianyimoshi())//Ҫ��
			{
				for (int t = 0; t < 8; t++)
				{
					int h = 0, s = 0;

					if (t == 0)
					{
						for (int i = 0; i < 97; i++)
						{
							if (i > 0) ImGui::SameLine(0.0F, 0.0F);
							Button_showit(BSPX1[i], t, i, h, s);
							if (s < 60) s = s + 15;
							if (s == 60) h++, s = 0;
							if (h == 24)	  h = 0;
						}
					}
					if (t == 1)
					{
						for (int i = 0; i < 97; i++)
						{
							if (i > 0) ImGui::SameLine(0.0F, 0.0F);
							if (BSPX2[i] == 14 || BSPX2[i] == 15 || BSPX2[i] == 16)
							{
								s = 20;
							}
							Button_showit(BSPX2[i], t, i, h, s);
							if (s == 20) s = s - 5;
							if (s < 60)  s = s + 15;
							if (s == 60) h++, s = 0;
							if (h == 24)	  h = 0;
						}
					}
					if (!MiscTab::i()->jianyimoshi2() || ImGui::GetIO().WantCaptureMouse == 1)
					{
						if (MiscTab::i()->dej())
						{
							if (t == 2)
							{
								for (int i = 0; i < 97; i++)
								{
									if (i > 0) ImGui::SameLine(0.0F, 0.0F);
									if (BSPX3[i] == 17)
									{
										s = 10;
									}
									if (BSPX3[i] == 21)
									{
										s = 40;
									}
									Button_showit(BSPX3[i], t, i, h, s);
									if (s == 10) s = s - 10;
									if (s == 40) s = s +5;
									if (s < 60) s = s + 15;
									if (s == 60) h++, s = 0;
									if (h == 24)	  h = 0;
								}
							}
							if (t == 3)
							{
								for (int i = 0; i < 97; i++)
								{
									if (i > 0) ImGui::SameLine(0.0F, 0.0F);
									Button_showit(BSPX4[i], t, i, h, s);
									if (s < 60)  s = s + 15;
									if (s == 60) h++, s = 0;
									if (h == 24)	  h = 0;
								}
							}
						}
						else
						{
							if (!MiscTab::i()->jianyimoshi())
							{
								if (t == 2)
								{
									for (int i = 0; i < 97; i++)
									{
										if (i > 0) ImGui::SameLine(0.0F, 0.0F);
										if (BSPX3[i] == 17)
										{
											s = 10;
										}
										if (BSPX3[i] == 21)
										{
											s = 40;
										}
										Button_showit(BSPX3[i], t, i, h, s);
										if (s == 10) s = s - 10;
										if (s == 40) s = s + 5;
										if (s < 60) s = s + 15;
										if (s == 60) h++, s = 0;
										if (h == 24)	  h = 0;
									}
								}
								if (t == 3)
								{
									for (int i = 0; i < 97; i++)
									{
										if (i > 0) ImGui::SameLine(0.0F, 0.0F);
										Button_showit(BSPX4[i], t, i, h, s);
										if (s < 60)  s = s + 15;
										if (s == 60) h++, s = 0;
										if (h == 24)	  h = 0;
									}
								}
							}
						}
						if (MiscTab::i()->hof())
						{
							if (t == 4)
							{
								for (int i = 0; i < 97; i++)
								{
									if (i > 0) ImGui::SameLine(0.0F, 0.0F);
									if (BSPX5[i]==25)
									{
										s = 5;
									}
									if (BSPX5[i] == 29)
									{
										s = 0;
									}
									Button_showit(BSPX5[i], t, i, h, s);
									if (s == 5)  s = s - 5;
									if (BSPX5[i] == 29)s = s + 15;
									if (s < 60)  s = s + 15;
									if (s == 60) h++, s = 0;
									if (h == 24)	  h = 0;
								}
							}
							if (t == 5)
							{
								for (int i = 0; i < 97; i++)
								{
									if (i > 0) ImGui::SameLine(0.0F, 0.0F);
									Button_showit(BSPX6[i], t, i, h, s);
									if (s < 60)  s = s + 15;
									if (s == 60) h++, s = 0;
									if (h == 24)	  h = 0;
								}
							}
						}
						else
						{
							if (!MiscTab::i()->jianyimoshi())
							{
								if (t == 4)
								{
									for (int i = 0; i < 97; i++)
									{
										if (i > 0) ImGui::SameLine(0.0F, 0.0F);
										if (BSPX5[i] == 25)
										{
											s = 5;
										}
										if (BSPX5[i] == 29)
										{
											s = 0;
										}
										Button_showit(BSPX5[i], t, i, h, s);
										if (s == 5)  s = s - 5;
										if (BSPX5[i] == 29)s = s + 15;
										if (s < 60)  s = s + 15;
										if (s == 60) h++, s = 0;
										if (h == 24)	  h = 0;
									}
								}
								if (t == 5)
								{
									for (int i = 0; i < 97; i++)
									{
										if (i > 0) ImGui::SameLine(0.0F, 0.0F);
										Button_showit(BSPX6[i], t, i, h, s);
										if (s < 60)  s = s + 15;
										if (s == 60) h++, s = 0;
										if (h == 24)	  h = 0;
									}
								}
							}
						}
						if (MiscTab::i()->bcj())
						{
							if (t == 6)
							{
								for (int i = 0; i < 97; i++)
								{
									if (i > 0) ImGui::SameLine(0.0F, 0.0F);
									if (BSPX7[i] == 37)s = 10;//10
									if (BSPX7[i] == 38)s = 38;//38
									if (BSPX7[i] == 39)s = 5;//05
									if (BSPX7[i] == 40)s = 39;//39
									Button_showit(BSPX7[i], t, i, h, s);
									if(s== 10)s = s - 10;
									if (s == 38)s = s - 8;
									if (s == 5)s = s  - 5;
									if (s == 39)s = s - 9;
									if (s < 60)  s = s + 15;
									if (s == 60) h++, s = 0;
									if (h == 24)	  h = 0;
								}
							}
							if (t == 7)
							{
								for (int i = 0; i < 97; i++)
								{
									if (i > 0) ImGui::SameLine(0.0F, 0.0F);
									if (BSPX8[i] == 41)
									{
										s = 5;
									}
									Button_showit(BSPX8[i], t, i, h, s);
									if (s == 5) s = s - 5;
									if (s < 60)  s = s + 15;
									if (s == 60) h++, s = 0;
									if (h == 24)	  h = 0;
								}
							}
						}
						else
						{
							if (!MiscTab::i()->jianyimoshi())
							{
								if (t == 6)
								{
									for (int i = 0; i < 97; i++)
									{
										if (i > 0) ImGui::SameLine(0.0F, 0.0F);
										if (BSPX7[i] == 37)s = 10;//10
										if (BSPX7[i] == 38)s = 38;//38
										if (BSPX7[i] == 39)s = 5;//05
										if (BSPX7[i] == 40)s = 39;//39
										Button_showit(BSPX7[i], t, i, h, s);
										if (s == 10)s = s - 10;
										if (s == 38)s = s - 8;
										if (s == 5)s = s - 5;
										if (s == 39)s = s - 9;
										if (s < 60)  s = s + 15;
										if (s == 60) h++, s = 0;
										if (h == 24)	  h = 0;
									}
								}
								if (t == 7)
								{
									for (int i = 0; i < 97; i++)
									{
										if (i > 0) ImGui::SameLine(0.0F, 0.0F);
										if (BSPX8[i] == 41)
										{
											s = 5;
										}
										Button_showit(BSPX8[i], t, i, h, s);
										if (s == 5) s = s - 5;
										if (s < 60)  s = s + 15;
										if (s == 60) h++, s = 0;
										if (h == 24)	  h = 0;
									}
								}
							}
						}
					}
				}
			}
			
#pragma endregion

			scroll_x = ImGui::GetScrollX();
			ImGui::EndChild();
			time_t time_seconds = time(0);
			tm now_time;
			localtime_s(&now_time, &time_seconds);

			if (MiscTab::i()->getweb())
			{
				if (geting)
				{
					W_time1 = GetTime(0);
					boost::thread thServer(getsting, W_time1);
				}
			}
			
			float scroll_x_delta = 0.0f;
			ImGui::IsItemHovered();
			if (ImGui::GetIO().WantCaptureMouse == 1)
			{
				if (ImGui::SmallButton("<<<--------- "))scroll_x_delta = -360.0f * daxiao_ * daxiao2_; ImGui::SameLine();
				if (ImGui::SmallButton("<------------ "))scroll_x_delta = -120.0f * daxiao_ * daxiao2_; ImGui::SameLine();
				if (ImGui::SmallButton(u8"�� ��")) ison = false; 
				if (ImGui::IsItemHovered())
				{
					ImGui::BeginTooltip();
					ImGui::TextUnformatted(u8"\r\n==========�Ҽ�����ť������������λ��==========\r\n\n");
					ImGui::EndTooltip();
				}
				if (ImGui::BeginPopupContextItem())
				{
					ImGuiConfigurationWrapper(&ImGui::Checkbox, gudingwinpos_);
					if (gudingwinpos_.value())
					{
						sPOSX(bosx );
						sPOSY(bosy );
					}
					ImGui::EndPopup();
				}
				ImGui::SameLine();
				if (ImGui::SmallButton(" ------------>"))scroll_x_delta = +120.0f * daxiao_ * daxiao2_; ImGui::SameLine();
				if (ImGui::SmallButton(" --------->>>"))scroll_x_delta = +360.0f * daxiao_ * daxiao2_; ImGui::SameLine();
				if (scroll_x_delta != 0.0f)ImGui::BeginChild("scrolling"), ImGui::SetScrollX(ImGui::GetScrollX() + scroll_x_delta), ImGui::EndChild();
				ImGui::AlignTextToFramePadding();
				ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());
				if (MiscTab::i()->getweb())
				{
					ImGui::Spacing();
					bool node_open = ImGui::TreeNode(u8"��ҳ�ճ�", u8"��ҳ�ճ� : (%s)", W_time1);
					ImGui::SameLine(303.0f * daxiao_ * daxiao2_, spacing);
					if (ImGui::SmallButton(u8"����"))
					{
						if (wancheng)
						{
							if (days == 0)
							{
								for (int i = 0; i < 5; i++)
								{
									W_renwu2[i] = W_renwu1[i];
								}
								W_time2 = W_time1;
							}
							days++;
							const char* addday = GetTime(days);
							W_time1 = addday;
							boost::thread thServer(getsting, addday);
						}

					}
					ImGui::SameLine(335.0f * daxiao_ * daxiao2_, spacing);
					if (ImGui::SmallButton(u8"����"))
					{
						std::string arrc1 = u8" ����ҳ����: ";
						std::string arrc12 = W_time1;
						std::string arrc2 = u8"����\"gw2sy.top\"����boss��ʾ��";
						std::string arrc3 = u8"--";
						std::string r1 = u8"����һ:";
						std::string r2 = u8"�����:";
						std::string r3 = u8"������:";
						std::string r4 = u8"������:";
						std::string r5 = u8"������:";
						std::string r6 = "\r\n";
						if (W_renwu1[0] != "0")
						{
							W_arrc = (arrc12 + arrc1 + r6 + r1 + W_renwu1[0] + r6 + r2 + W_renwu1[1] + r6 + r3 + W_renwu1[2] + r6 + r4 + W_renwu1[3] + r6 + r5 + W_renwu1[4] + r6 + arrc2).c_str();
							ImGui::SetClipboardText(W_arrc);
						}
						else
						{
							ImGui::SetClipboardText("");
						}
					}
					if (node_open)
					{
						if (wancheng)
						{
							if (W_renwu1[0] != "0")
							{
								for (int i = 0; i < 5; i++)
								{
									ImGui::Text((" " + W_renwu1[i]).c_str());
								}
								ImGui::TreePop();
							}
							else
							{
								ImGui::Text(u8"-----δ��ȡ����Ϣ��ȴ��������»-----");
								ImGui::TreePop();
							}
						}
						else
						{
							ImGui::Text(u8"-----���ڻ�ȡ�������ĵȺ�-----");
							ImGui::TreePop();
						}
					}
					
				}
			}
			else
			{
				ImGui::BeginChild("scrolling");
				if (now_time.tm_hour * 60 + now_time.tm_min < 30)
				{
					ImGui::SetScrollX(((now_time.tm_hour * 60 + now_time.tm_min) / 15) * 120.0f* daxiao_ * daxiao2_);
				}
				else
				{
					ImGui::SetScrollX(((now_time.tm_hour * 60 + now_time.tm_min) / 15 - 1) * 120.0f* daxiao_ * daxiao2_);
				}
				ImGui::EndChild();
				if (MiscTab::i()->getweb())
				{
					if (wancheng)
					{
						if (days != 0)
						{
							days = 0;
							W_time1 = W_time2;
							for (int i = 0; i < 5; i++)
							{
								W_renwu1[i] = W_renwu2[i];
							}
						}
						if (!ghen&&now_time.tm_hour == 0 && now_time.tm_min == 0) 
						{
							ghen = true;
							const char *  adddayend = GetTime(0);
							if (W_time1 != adddayend)
							{
								W_time1 = adddayend;
								boost::thread thServer(getsting, adddayend);
							}
						}
					}
				}
			}
			ImGui::PopStyleColor(3);
			ImGui::End();
			
			ImGui::PopStyleVar(4);
		}
		return ison;
	}


	InputResponse BossTime::OnInputChangeweb(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys)
	{
		const bool isMenuKeybindweb = keys == MiscTab::i()->SHOWBOSSTIMER_CK().keys();
		if (isMenuKeybindweb)
		{
			kput = 1;
			if (jishiqi)
			{
				isVisibleweb_ = true;
				jishiqi = false;
			}
			else
			{
				isVisibleweb_ = false;
				jishiqi = true;
			}
		}
		return isMenuKeybindweb ? InputResponse::PREVENT_ALL : InputResponse::PASS_TO_GAME;
	}


}
