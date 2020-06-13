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
#include <Utility.h>
#include <Core.h>


namespace GW2Radial
{

	DEFINE_SINGLETON(BossTime);
#pragma region 计时器数据
	const char* BossTime::BossName(int xuhao)
	{
		const char* tmp = "";
		switch (xuhao)
		{
			//老地图
		case  1:tmp = u8"碎裂巨兽";	break;
		case  2:tmp = u8"冰萨满";		break;
		case  3:tmp = u8"人马王莫迪尔";		break;
		case  4:tmp = u8"火元素";		break;
		case  5:tmp = u8"马克魔像";	break;
		case  6:tmp = u8"巨型林地虫"; break;
		case  7:tmp = u8"卓玛之爪";	break;
		case  8:tmp = u8"暗影巨兽";	break;
		case  9:tmp = u8"海盗科文顿"; break;
		case 10:tmp = u8"超能毁灭者"; break;
		case 11:tmp = u8"僵尸龙";		break;
		case 12:tmp = u8"三重麻烦";	break;
		case 13:tmp = u8"喀壳虫女王"; break;
		case 14:tmp = u8"甘达拉跑男"; break;//20
		case 15:tmp = u8"林线瀑布跑男"; break;//20
		case 16:tmp = u8"钢铁平原跑男"; break;//20
			//荆棘
		case 17:tmp = u8"苍翠龙母"; break;//10
		case 18:tmp = u8"缠藤虫王"; break;
		case 19:tmp = u8"赤金四门"; break;
		case 20:tmp = u8"巨龙阵地"; break;
		case 21:tmp = u8"沙尘暴"; break;//40
		case 22:tmp = u8"诺兰山庄"; break;
		case 23:tmp = u8"塞德拉避难所"; break;
		case 24:tmp = u8"新沃土之森"; break;
			//烈焰
		case 25:tmp = u8"赌场闪电战"; break;//05
		case 26:tmp = u8"巨努多崛起"; break;
		case 27:tmp = u8"雷云焦油"; break;
		case 28:tmp = u8"埋藏宝藏"; break;
		case 29:tmp = u8"护送灭龙车"; break;//00
		case 30:tmp = u8"晋升之路"; break;
		case 31:tmp = u8"雷云使者"; break;
		case 32:tmp = u8"烈焰塑形"; break;
		case 33:tmp = u8"巨蛇之怒"; break;
		case 34:tmp = u8"磨难血口"; break;
		case 35:tmp = u8"死亡碎裂巨兽"; break;
		case 36:tmp = u8"帕拉瓦攻城"; break;
			//冰巢
		case 37:tmp = u8"神圣烈焰仪式"; break;//10
		case 38:tmp = u8"厄运传说圣坛"; break;//38
		case 39:tmp = u8"软泥怪坑"; break;//05
		case 40:tmp = u8"金属音乐会"; break;//39
		case 41:tmp = u8"德拉克"; break;//05
		case 42:tmp = u8"冬季风暴"; break;
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
		case  17:tmp = u8"[&BAgIAAA=]上方[&BMIHAAA=]"; break;
		case  18:tmp = u8"[&BPUHAAA=]"; break;
		case  19:tmp = u8"[&BGwIAAA=]"; break;
		case  20:tmp = u8"[&BBAIAAA=]"; break;
		case  21:tmp = u8"[&BHoHAAA=]"; break;
		case  22:tmp = u8"[&BK8JAAA=]"; break;
		case  23:tmp = u8"[&BK0JAAA=]2点方向"; break;
		case  24:tmp = u8"[&BLQJAAA=]7点方向[&BK4JAAA=]"; break;
		case  25:tmp = u8"[&BLsKAAA=]"; break;
		case  26:tmp = u8"[&BMEKAAA=]8点方向[&BHAKAAA=]"; break;
		case  27:tmp = u8"[&BKYLAAA=]"; break;
		case  28:tmp = u8"[&BGsKAAA=]"; break;
		case  29:tmp = u8"[&BIMLAAA=]"; break;
		case  30:tmp = u8"[&BFMKAAA=]"; break;
		case  31:tmp = u8"[&BLsLAAA=]"; break;
		case  32:tmp = u8"[&BEoKAAA=]10点方向[&BG0KAAA=]"; break;
		case  33:tmp = u8"[&BHQKAAA=]"; break;
		case  34:tmp = u8"[&BKMKAAA=]"; break;
		case  35:tmp = u8"[&BJQLAAA=]1点方向[&BHwLAAA=]"; break;
		case  36:tmp = u8"[&BAkLAAA=]7点方向攻城[&BPcKAAA=]到[&BAELAAA=]"; break;
		case  37:tmp = u8"[&BBsMAAA=]在[&BAcMAAA=]到[&BB0MAAA=]"; break;
		case  38:tmp = u8"[&BBsMAAA=]在[&BAUMAAA=]到[&BAEMAAA=]"; break;
		case  39:tmp = u8"[&BPgLAAA=]"; break;
		case  40:tmp = u8"[&BPgLAAA=]3点方向[&BBkMAAA=]"; break;
		case  41:tmp = u8"[&BDkMAAA=]到[&BEEMAAA=]"; break;
		case  42:tmp = u8"[&BCcMAAA=]"; break;
		default:break;
		}
		return tmp;
	}
#pragma endregion
	BossTime::BossTime()://showKeybindweb_("show_BossTime", "Show BossTime", { VK_F8 }, false),
		gudingwinpos_(u8"锁定窗口位置", "gudingwinpos_", "shubiao", false),
		gudingwinpos_x(u8"窗口位置x", "gudingwinpos_x", "shubiao", 500.0f),
		gudingwinpos_y(u8"窗口位置y", "gudingwinpos_y", "shubiao", 5.0f)
	{
		Texture_1 = CreateTextureFromResource(Core::i()->getdevice(), Core::i()->dllModule(), IDR_NEXT);
		Texture_2 = CreateTextureFromResource(Core::i()->getdevice(), Core::i()->dllModule(), IDR_NOW);
		Texture_3 = CreateTextureFromResource(Core::i()->getdevice(), Core::i()->dllModule(), IDR_LAST);

		Texture_add		 = CreateTextureFromResource(Core::i()->getdevice(), Core::i()->dllModule(), IDR_ADD);
		Texture_cancel	 = CreateTextureFromResource(Core::i()->getdevice(), Core::i()->dllModule(), IDR_CANCEL);
		Texture_close	 = CreateTextureFromResource(Core::i()->getdevice(), Core::i()->dllModule(), IDR_CLOSE);
		Texture_edit	 = CreateTextureFromResource(Core::i()->getdevice(), Core::i()->dllModule(), IDR_EDIT);
		Texture_recovery = CreateTextureFromResource(Core::i()->getdevice(), Core::i()->dllModule(), IDR_RECOVERY);
		Texture_remove	 = CreateTextureFromResource(Core::i()->getdevice(), Core::i()->dllModule(), IDR_REMOVE);
		Texture_delete	 = CreateTextureFromResource(Core::i()->getdevice(), Core::i()->dllModule(), IDR_DELETE);

		inputChangeCallbackweb_ = [this](bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys) { return OnInputChangeweb(changed, keys, changedKeys); };
		Input::i()->AddInputChangeCallback(&inputChangeCallbackweb_);
	}
	BossTime::~BossTime()
	{
		COM_RELEASE(Texture_1);
		COM_RELEASE(Texture_2);
		COM_RELEASE(Texture_3);

		COM_RELEASE(Texture_add);
		COM_RELEASE(Texture_cancel);
		COM_RELEASE(Texture_close);
		COM_RELEASE(Texture_edit);
		COM_RELEASE(Texture_recovery);
		COM_RELEASE(Texture_remove);
		COM_RELEASE(Texture_delete);

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
#pragma region 网页获取
	bool geting = true;
	bool wancheng = false;
	const char* W_arrc = nullptr;//剪切板
	const char * W_time1 = nullptr;//时间
	const char * W_time2 = nullptr;//时间
	std::string* FetchReleaseData(const char * days);//声明获取方法函数
	std::string * W_renwu1 = new std::string[5];//恩物显示
	std::string * W_renwu2 = new std::string[5];//恩物保存显示
	std::string* result = new std::string[6];//恩物储存
	std::string* tmpIDname = new std::string[32];//恩物储存
	LPCWSTR stringToLPCWSTR(std::string orig);//标致转换
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
		strTime.copy(out2, strTime.length(), 0);//这里5，代表复制几个字符，0代表复制的位置  
		*(out2 + strTime.length()) = '\0';//要手动加上结束符
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
				char response_data[8000];//缓冲区
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

		//printf("%d",response_length);


		std::string beginFlagtmp = u8"head";
		int startPostmp = 0;
		startPostmp = (int)retVal.find(beginFlagtmp, startPostmp);
		if (startPostmp > 0)
		{
			result[0] = "0";
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
#pragma region 新UI

	bool isbts = false;
	bool isbtn = false;
	int  NEWBOSSJISU = 0;
	std::string Clipboardtmp = "";
	int tesss = 0;
	ImVec2 toolwindospost = {};
	float toolwindospost_y = 0;
	float windospost_y = 0;
	float toolwindossize_y = 0;


	///

	bool showdaydo = true;
	int dossizes = 0;
	bool* alldobl;
	std::vector<std::string> alldost;
	std::string alldotmp;
	bool iswantadd = false;
	std::array<char, 256> intmp;
	///

	std::string BossTime::SHOWNEWUI_BUTTONS_TYPE(int bosspaixuid, int show_TYPE, int h, int s)
	{
		std::string tmp_out = "";
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
		std::string arrc1 = label;
		std::string arrc2 = BossPost(bosspaixuid);
		std::string arrc3 = u8" 来自\"gw2sy.top\"神油boss提示器";
		if (show_TYPE == 0)
		{
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.127f, 0.842f, 0.660f, touming_));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.127f, 0.842f, 0.760f, touming_));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.127f, 0.842f, 0.860f, touming_));
		}
		if (show_TYPE == 1)
		{
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.327f, 0.842f, 0.660f, touming_));//3
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.327f, 0.842f, 0.760f, touming_));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.327f, 0.842f, 0.860f, touming_));
		}
		if (show_TYPE == 2)
		{
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.927f, 0.842f, 0.660f, touming_));//9
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.927f, 0.842f, 0.760f, touming_));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.927f, 0.842f, 0.860f, touming_));
		}
		if (show_TYPE == 3)
		{
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.527f, 0.842f, 0.660f, touming_));//5
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.527f, 0.842f, 0.760f, touming_));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.527f, 0.842f, 0.860f, touming_));
		}


		if (ImGui::Button(label, ImVec2(-1, 22.0f * daxiao_ * daxiao2_)))
		{
			if (bosspaixuid != 0)
			{
				ImGui::SetClipboardText((arrc1 + arrc2 + arrc3).c_str());
			}
			ImGui::CloseCurrentPopup();
		}
		ImGui::PopStyleColor(3);
		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::TextUnformatted(u8"点击即可复制到剪切板");
			ImGui::EndTooltip();
		}
		return arrc1 + arrc2 + "-";
	}

	void BossTime::TOOLSVIM(bool& showtoolwind)
	{
		if (tesss == 0)
		{
			if (!isbtn && !isbts)
			{
				
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
				//NEWBOSSJISU = (ttsh * 60 + ttss) / 15;//时间测试代码
				NEWBOSSJISU = (now_time.tm_hour * 60 + now_time.tm_min) / 15;
			}
			return;
		}
		ImGuiIO IIO = ImGui::GetIO();
		if (ImGui::GetWindowPos().y > IIO.DisplaySize.y / 2)  //位置 = 主界面高度 - 本窗口高度      
		{
			toolwindospost.y = ( windospost_y - toolwindossize_y);
		}
		ImGui::SetNextWindowPos(toolwindospost);
		ImGui::SetNextWindowBgAlpha(touming_);
		ImGui::Begin("uid", &showtoolwind, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoTitleBar);
		{
			isbtn = ImGui::IsMouseHoveringWindow();
			ImGui::SetWindowFontScale(daxiao_);
			toolwindossize_y = ImGui::GetWindowSize().y;
			
			if (tesss == 2)
			{
				ImGui::Text(u8" 当前选中的所有BOSS");
				ImGui::Separator();
			}
			else
			{
				if (tesss == 1)
				{
					ImGui::Text(u8" 前15分钟内所有BOSS");
				}
				if (tesss == 3)
				{
					ImGui::Text(u8" 后15分钟内所有BOSS");
				}
				ImGui::Separator();
			}
			SHOWNEWUI_BUTTONS();
			ImGui::Separator();
			ImGui::Text(u8"移开鼠标复原");
			ImGui::SameLine(ImGui::CalcTextSize(u8"移开鼠标复原").x+40);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.1f, 0.1f, 0.660f, touming_));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.1f, 0.1f, 0.760f, touming_));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.1f, 0.1f, 0.860f, touming_));
			if (ImGui::SmallButton(u8"关闭##toolui"))
			{
				showtoolwind = false;
			}
			if (MiscTab::i()->day_to_do() && !showdaydo)
			{
				ImGui::SameLine(ImGui::CalcTextSize(u8"移开鼠标复原").x +10+ ImGui::CalcTextSize(u8"打开每天必做").x);
				if (ImGui::SmallButton(u8"打开每天必做##dayui"))
				{
					showdaydo = true;
				}
			}
			if (MiscTab::i()->getweb())
			{

				ImGui::Text(u8"网页日常 : (%s)", W_time1);
				//bool node_open = ImGui::TreeNode(u8"网页日常", u8"网页日常 : (%s)", W_time1);
				ImGui::SameLine();
				//if (ImGui::SmallButton(u8"昨天"))
				//{
				//	if (wancheng)
				//	{
				//		if (days == 0)
				//		{
				//			for (int i = 0; i < 5; i++)
				//			{
				//				W_renwu2[i] = W_renwu1[i];
				//			}
				//			W_time2 = W_time1;
				//		}

				//		days--;
				//		const char* addday = GetTime(days);
				//		W_time1 = addday;
				//		boost::thread thServer(getsting, addday);
				//	}

				//}
				//ImGui::SameLine();

				if (ImGui::SmallButton(u8"明天"))
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
				ImGui::SameLine();
				if (ImGui::SmallButton(u8"复制"))
				{
					std::string arrc1 = u8" 的网页任务: ";
					std::string arrc12 = W_time1;
					std::string arrc2 = u8"来自\"gw2sy.top\"神油boss提示器";
					std::string arrc3 = u8"--";
					std::string r1 = u8"任务一:";
					std::string r2 = u8"任务二:";
					std::string r3 = u8"任务三:";
					std::string r4 = u8"任务四:";
					std::string r5 = u8"任务五:";
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
				//if (node_open)
				{
					if (wancheng)
					{
						if (W_renwu1[0] != "0")
						{
							for (int i = 0; i < 5; i++)
							{
								ImGui::Text((" " + W_renwu1[i]).c_str());
							}
							//ImGui::TreePop();
						}
						else
						{
							ImGui::Text(u8"未获取到信息请等待官网更新活动");
							//ImGui::TreePop();
						}
					}
					else
					{
						ImGui::Text(u8"正在获取中请耐心等候");
						//ImGui::TreePop();
					}
				}

			}
			ImGui::PopStyleColor(3);

			ImGui::End();
		}
		if (!isbtn && !isbts)
		{
			tesss = 0;
			if (MiscTab::i()->getweb())
			{
				time_t time_seconds = time(0);
				tm now_time;
				localtime_s(&now_time, &time_seconds);

				//if (MiscTab::i()->getweb())
				//{
				//	if (geting)
				//	{
				//		W_time1 = GetTime(0);
				//		boost::thread thServer(getsting, W_time1);
				//	}
				//}
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
					if (!ghen && now_time.tm_hour == 0 && now_time.tm_min == 0)
					{
						ghen = true;
						const char* adddayend = GetTime(0);
						if (W_time1 != adddayend)
						{
							W_time1 = adddayend;
							boost::thread thServer(getsting, adddayend);
						}
					}
				}
			}
		}
	}

	void BossTime::SHOWNEWUI_BUTTONS()
	{
		Clipboardtmp = "";

		if (BSPX1[NEWBOSSJISU] != 0 )
		{
			int h = 0, s = 0;
			for (int i = 0; i < 96; i++)
			{
				if (i == NEWBOSSJISU)
				{
					Clipboardtmp += SHOWNEWUI_BUTTONS_TYPE(BSPX1[NEWBOSSJISU], 0, h, s);
					break;
				}
				if (s < 60) s = s + 15;
				if (s == 60) h++, s = 0;
				if (h == 24)	  h = 0;
			}
		}
		
		if (BSPX2[NEWBOSSJISU] != 0)
		{
			int h = 0, s = 0;
			for (int i = 0; i < 96; i++)
			{
				if (BSPX2[i] == 14 || BSPX2[i] == 15 || BSPX2[i] == 16)
				{
					s = 20;
				}
				if (i == NEWBOSSJISU)
				{
					Clipboardtmp += SHOWNEWUI_BUTTONS_TYPE(BSPX2[NEWBOSSJISU], 0, h, s);
				}
				if (s == 20) s = s - 5;
				if (s < 60)  s = s + 15;
				if (s == 60) h++, s = 0;
				if (h == 24)	  h = 0;
			}
		}
		if (BSPX3[NEWBOSSJISU] != 0)
		{
			int h = 0, s = 0;
			for (int i = 0; i < 96; i++)
			{
				if (BSPX3[i] == 17)
				{
					s = 10;
				}
				if (BSPX3[i] == 21)
				{
					s = 40;
				}
				if (i == NEWBOSSJISU)
				{
					Clipboardtmp += SHOWNEWUI_BUTTONS_TYPE(BSPX3[NEWBOSSJISU], 1, h, s);
				}
				if (s == 10) s = s - 10;
				if (s == 40) s = s + 5;
				if (s < 60) s = s + 15;
				if (s == 60) h++, s = 0;
				if (h == 24)	  h = 0;
			}
			
		}
		if (BSPX4[NEWBOSSJISU] != 0)
		{
			int h = 0, s = 0;
			for (int i = 0; i < 96; i++)
			{
				if (i == NEWBOSSJISU)
				{
					Clipboardtmp += SHOWNEWUI_BUTTONS_TYPE(BSPX4[NEWBOSSJISU], 1, h, s);
				}
				if (s < 60)  s = s + 15;
				if (s == 60) h++, s = 0;
				if (h == 24)	  h = 0;
			}
			
		}
		if (BSPX5x[NEWBOSSJISU] != 0)
		{
			int h = 0, s = 0;
			for (int i = 0; i < 96; i++)
			{
				if (BSPX5[i] == 25)
				{
					s = 5;
				}
				//if (BSPX5[i] == 29)
				//{
				//	s = 0;
				//}
				if (i == NEWBOSSJISU)
				{
					Clipboardtmp += SHOWNEWUI_BUTTONS_TYPE(BSPX5x[NEWBOSSJISU], 2, h, s);
				}
				if (s == 5)  s = s - 5;
				/*if (BSPX5[i] == 29)s = s + 15;*/
				if (s < 60)  s = s + 15;
				if (s == 60) h++, s = 0;
				if (h == 24)	  h = 0;
			}
			
		}
		if (BSPX51[NEWBOSSJISU] != 0)
		{
			int h = 0, s = 0;
			for (int i = 0; i < 96; i++) 
			{
				if (i == NEWBOSSJISU)
				{
					Clipboardtmp += SHOWNEWUI_BUTTONS_TYPE(BSPX51[NEWBOSSJISU], 2, h, s);
				}
				if (s < 60)  s = s + 15;
				if (s == 60) h++, s = 0;
				if (h == 24)	  h = 0;
			}

		}

		if (BSPX6[NEWBOSSJISU] != 0)
		{
			int h = 0, s = 0;
			for (int i = 0; i < 96; i++)
			{
				if (i == NEWBOSSJISU)
				{
					Clipboardtmp += SHOWNEWUI_BUTTONS_TYPE(BSPX6[NEWBOSSJISU], 2, h, s);
				}
				if (s < 60)  s = s + 15;
				if (s == 60) h++, s = 0;
				if (h == 24)	  h = 0;
			}
			
		}
		if (BSPX7[NEWBOSSJISU] != 0)
		{
			int h = 0, s = 0;
			for (int i = 0; i < 96; i++)
			{
				if (BSPX7[i] == 37)s = 10;//10
				if (BSPX7[i] == 38)s = 38;//38
				if (BSPX7[i] == 39)s = 5;//05
				if (BSPX7[i] == 40)s = 39;//39
				if (i == NEWBOSSJISU)
				{
					Clipboardtmp += SHOWNEWUI_BUTTONS_TYPE(BSPX7[NEWBOSSJISU], 3, h, s);
				}
				if (s == 10)s = s - 10;
				if (s == 38)s = s - 8;
				if (s == 5)s = s - 5;
				if (s == 39)s = s - 9;
				if (s < 60)  s = s + 15;
				if (s == 60) h++, s = 0;
				if (h == 24)	  h = 0;
			}
			
		}
		if (BSPX8[NEWBOSSJISU] != 0)
		{
			int h = 0, s = 0;
			for (int i = 0; i < 96; i++)
			{
				if (BSPX8[i] == 41)
				{
					s = 5;
				}
				if (i == NEWBOSSJISU)
				{
					Clipboardtmp += SHOWNEWUI_BUTTONS_TYPE(BSPX8[NEWBOSSJISU], 3, h, s);
				}
				if (s == 5) s = s - 5;
				if (s < 60)  s = s + 15;
				if (s == 60) h++, s = 0;
				if (h == 24)	  h = 0;
			}
			
		}
	}

	void BossTime::SHOWNEWUI(bool& showit) 
	{
		if (showit)
		{
			ImGui::SetNextWindowBgAlpha(touming_);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize,0);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(4, 4));
			ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(2, 1));
			if (gwps())
			{
				ImGui::SetNextWindowPos(ImVec2(sPOSX(), sPOSY()));
			}
			ImGui::Begin(u8"新ui", &showit,ImGuiWindowFlags_AlwaysAutoResize|ImGuiWindowFlags_NoTitleBar);
			float bosx = ImGui::GetWindowPos().x;
			float bosy = ImGui::GetWindowPos().y;
			ImGui::SetWindowFontScale(daxiao_);
			isbts = ImGui::IsMouseHoveringWindow();
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.0f, 0.0f, 0.0f, 0.0f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.0f, 0.0f, 0.0f, 0.2f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.0f, 0.0f, 0.0f, 0.4f));


			if (ImGui::ImageButton(Texture_3, { 32 * daxiao_,32 * daxiao_ }))
			{
				ImGui::CloseCurrentPopup();
				if (NEWBOSSJISU > 0)
				{
					NEWBOSSJISU--;
				}
				else
				{
					if (NEWBOSSJISU == 0)
					{
						NEWBOSSJISU = 95;
					}
				}
			}
			if (ImGui::IsItemDeactivated())
			{
				tesss = 1;
			}
			ImGui::SameLine(0.0f);

			if (ImGui::ImageButton(Texture_2, { 32 * daxiao_,32 * daxiao_ }))
			{
				std::string arrc3 = u8" 来自\"gw2sy.top\"神油boss提示器";
				ImGui::SetClipboardText((Clipboardtmp + arrc3).c_str());
			}
			if (ImGui::IsItemHovered())
			{
				tesss = 2;
				ImGui::BeginTooltip();
				ImGui::TextUnformatted(u8"右键本按钮可以锁定窗口位置\r\n点击可复制当前所有boss");
				ImGui::EndTooltip();
			}
			if (ImGui::BeginPopupContextItem())
			{
				ImGuiConfigurationWrapper(&ImGui::Checkbox, gudingwinpos_);
				if (gudingwinpos_.value())
				{
					sPOSX(bosx);
					sPOSY(bosy);
				}
				ImGui::EndPopup();
			}
			ImGui::SameLine(0.0f);

			if (ImGui::ImageButton(Texture_1, { 32 * daxiao_,32 * daxiao_ }))
			{
				ImGui::CloseCurrentPopup();
				if (NEWBOSSJISU < 95)
				{
					NEWBOSSJISU++;
				}
				else
				{
					if (NEWBOSSJISU == 95)
					{
						NEWBOSSJISU = 0;
					}
				}
			}

			if (ImGui::IsItemDeactivated())
			{
				tesss = 3;
			}
			ImGui::PopStyleColor(3);
			ImGui::PopStyleVar(3);
			windospost_y = ImGui::GetWindowPos().y;
			toolwindospost = { ImGui::GetWindowPos().x , ImGui::GetWindowPos().y + ImGui::GetWindowSize().y };
			TOOLSVIM(showit);
			ImGui::End();
		}
	}
#pragma endregion 新UI

#pragma region 每日必做



	void BossTime::readalldo_W()
	{
		auto cfg = ConfigurationFile::i();
		alldotmp = cfg->ini().GetValue("shubiao", "alltodo_");
		std::string beginFlag = u8"|";
		int startPos = 0;
		int endPos = 1;
		int beginPos = 0;
		int endingpos = 0;
		startPos = (int)alldotmp.find(beginFlag, startPos);
		endPos = (int)alldotmp.find(beginFlag, endPos);
		beginPos = startPos + (int)beginFlag.length();
		endingpos = endPos - startPos - (int)beginFlag.length();
		dossizes = std::stoi(alldotmp.substr(beginPos, endingpos));
		alldobl = new bool[dossizes];
		startPos++;
		endPos++;
		alldost.clear();
		for (int i = 0; i < dossizes; i++)
		{
			startPos = (int)alldotmp.find(beginFlag, startPos);
			endPos = (int)alldotmp.find(beginFlag, endPos);
			beginPos = startPos + (int)beginFlag.length();
			endingpos = endPos - startPos - (int)beginFlag.length();
			alldost.push_back(alldotmp.substr(beginPos, endingpos).c_str());
			startPos++;
			endPos++;
		}
		startPos = 0;
		endPos = 1;
		beginPos = 0;
		endingpos = 0;
		alldotmp.clear();
		alldotmp = cfg->ini().GetValue("shubiao", "alltodo_BL");
		for (int i = 0; i < dossizes; i++)
		{
			startPos = (int)alldotmp.find(beginFlag, startPos);
			endPos = (int)alldotmp.find(beginFlag, endPos);
			beginPos = startPos + (int)beginFlag.length();
			endingpos = endPos - startPos - (int)beginFlag.length();
			if (alldotmp.substr(beginPos, endingpos).find("B"))
			{
				alldobl[i] = false;
			}
			else
			{
				alldobl[i] = true;
			}
			startPos++;
			endPos++;
		}
	}

	void BossTime::readalldo()
	{
		auto cfg = ConfigurationFile::i();
		if (dossizes == 0)
		{
			alldotmp = cfg->ini().GetValue("shubiao", "alltodo_", u8"|13|网页日常|日常碎层|家园采集|公会采集|日常制作|龙母|跑男|四门|虫王|分身|双狗|赌场|地虫|");
		}
		if (cfg->ini().GetBoolValue("shubiao", "alltodo_oot", true) && (int)alldotmp.find(u8"|13|网页日常|日常碎层|家园采集|公会采集|日常制作|龙母|跑男|四门|虫王|分身|双狗|赌场|地虫|", 0) == 0 && dossizes == 0)
		{
			cfg->ini().SetValue("shubiao", "alltodo_", alldotmp.c_str());
			std::string alldotmp_2 = "|";
			for (int i = 0; i < 13; i++)
			{
				alldotmp_2 += "A|";
			}
			cfg->ini().SetValue("shubiao", "alltodo_BL", alldotmp_2.c_str());
			cfg->ini().SetBoolValue("shubiao", "alltodo_oot", false);
			cfg->Save();
			readalldo_W();
		}
		else
		{
			if (dossizes == 0)
			{
				readalldo_W();
			}
		}
	}

	void BossTime::savealldo()
	{
		auto cfg = ConfigurationFile::i();
		std::string alldotmp_2 = "|";
		for (int i = 0; i < dossizes; i++)
		{

			if (alldobl[i])
			{
				alldotmp_2 += "B|";
			}
			else
			{
				alldotmp_2 += "A|";
			}
		}
		cfg->ini().SetValue("shubiao", "alltodo_BL", alldotmp_2.c_str());
		cfg->Save();

	}

	void BossTime::DELsonedo(int intmp_)
	{
		auto cfg = ConfigurationFile::i();
		std::string tmp = "|" + std::to_string(dossizes - 1) + "|";
		for (int i = 0; i < dossizes; i++)
		{
			if (i != intmp_)
			{
				tmp += (alldost[i] + "|").c_str();
			}
		}
		cfg->ini().SetValue("shubiao", "alltodo_", tmp.c_str());
		cfg->Save();
		dossizes = 0;
	}
	void BossTime::ADDsonedo(std::string intmp_)
	{
		if (intmp_ == "")
		{
			return;
		}
		if (intmp_.find("|",0) != intmp_.npos)
		{
			return;
		}
		auto cfg = ConfigurationFile::i();
		std::string tmp = cfg->ini().GetValue("shubiao", "alltodo_");
		if ((int)tmp.find(intmp_.c_str(), 0) > 0)
		{
			return;
		}
		tmp.clear();
		tmp += "|";
		tmp += std::to_string(dossizes + 1);
		tmp += "|";
		for (int i = 0; i < dossizes; i++)
		{
			tmp += (alldost[i] + "|").c_str();
		}
		tmp += (intmp_ + "|").c_str();
		cfg->ini().SetValue("shubiao", "alltodo_", tmp.c_str());
		cfg->Save();
		dossizes = 0;
		//readalldo();
	}
	bool editmod = false;
	void BossTime::DayToDo()
	{
		if (MiscTab::i()->day_to_do()&&showdaydo)
		{
			readalldo();

			ImGui::SetNextWindowBgAlpha(touming_);

			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(4, 4));
			ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(2, 1));

			ImGui::PushStyleColor(ImGuiCol_TitleBgActive, (ImVec4)ImColor::HSV(0.0f, 0.0f, 0.0f, touming_));
			ImGui::PushStyleColor(ImGuiCol_TitleBg, (ImVec4)ImColor::HSV(0.0f, 0.0f, 0.0f, touming_));
			ImGui::PushStyleColor(ImGuiCol_TitleBgCollapsed, (ImVec4)ImColor::HSV(0.0f, 0.0f, 0.0f, touming_));

			//ImGui::Begin("daytodos", &showdaydo, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
			ImGui::Begin(u8"每日必做", NULL,  ImGuiWindowFlags_AlwaysAutoResize);
			ImGui::SetWindowFontScale(daxiao_);

			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(0.0f, 0.0f, 0.0f, 0.0f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(0.0f, 0.0f, 0.0f, 0.2f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(0.0f, 0.0f, 0.0f, 0.4f));

			ImGui::PushStyleColor(ImGuiCol_FrameBg, (ImVec4)ImColor::HSV(1.0f, 1.0f, 0.0f, 0.3f));
			ImGui::PushStyleColor(ImGuiCol_FrameBgActive, (ImVec4)ImColor::HSV(1.0f, 0.0f, 1.0f, 0.5f));
			ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, (ImVec4)ImColor::HSV(1.0f, 0.0f, 1.0f, 0.7f));

			ImGui::PushStyleColor(ImGuiCol_CheckMark, (ImVec4)ImColor::HSV(1.0f, 0.0f, 1.0f, 6.0f));
			
			for (int i = 0; i < dossizes; i++)
			{
				if ( MiscTab::i()->day_to_do_heid()&&!alldobl[i])
				{
					if (editmod)
					{
						ImGui::ImageButton(Texture_delete, { 12 * daxiao_,12 * daxiao_ });
						if (ImGui::IsItemClicked())
						{
							DELsonedo(i);
						}
						if (ImGui::IsItemHovered())
						{
							ImGui::BeginTooltip();
							ImGui::TextUnformatted(u8"删除此项");
							ImGui::EndTooltip();
						}
						ImGui::SameLine();
					}
					if (ImGui::Checkbox(alldost[i].c_str(), &alldobl[i]))
					{
						savealldo();
					}
				}
				else
				{
					if (!MiscTab::i()->day_to_do_heid())
					{
						if (editmod)
						{
							ImGui::ImageButton(Texture_delete, { 12 * daxiao_,12 * daxiao_ });
							if (ImGui::IsItemClicked())
							{
								DELsonedo(i);
							}
							if (ImGui::IsItemHovered())
							{
								ImGui::BeginTooltip();
								ImGui::TextUnformatted(u8"删除此项");
								ImGui::EndTooltip();
							}
							ImGui::SameLine();
						}
						if (ImGui::Checkbox(alldost[i].c_str(), &alldobl[i]))
						{
							savealldo();
						}
					}

				}
			}
			
			if (editmod)
			{
				if (!iswantadd) {
					if (ImGui::ImageButton(Texture_add, { 12 * daxiao_,12 * daxiao_ }))
					//if (ImGui::SmallButton("+##DayToDoADD")) 
					{
						intmp.fill(NULL);
						iswantadd = true;
					}
					if (ImGui::IsItemHovered())
					{
						ImGui::BeginTooltip();
						ImGui::TextUnformatted(u8"添加项目");
						ImGui::EndTooltip();
					}
				}

				if (iswantadd) {
					ImGui::InputText("##addtodo", intmp.data(), intmp.size()); ImGui::SameLine();

					if (ImGui::ImageButton(Texture_add, { 12 * daxiao_,12 * daxiao_ }))
					//if (ImGui::SmallButton("+##toadd"))
					{
						ADDsonedo(intmp.data());
						iswantadd = false;
					}
					if (ImGui::IsItemHovered())
					{
						ImGui::BeginTooltip();
						ImGui::TextUnformatted(u8"添加");
						ImGui::EndTooltip();
					}
					ImGui::SameLine();
					if (ImGui::ImageButton(Texture_cancel, { 12 * daxiao_,12 * daxiao_ }))
					//if (ImGui::SmallButton("x##notoadd")) 
					{
						iswantadd = false;
					}
					if (ImGui::IsItemHovered())
					{
						ImGui::BeginTooltip();
						ImGui::TextUnformatted(u8"取消");
						ImGui::EndTooltip();
					}
					ImGui::Text(u8"请注意!不要输入\"|\"! ");
				}
				if (!iswantadd)
				{
					ImGui::SameLine();
					if (ImGui::ImageButton(Texture_remove, { 12 * daxiao_,12 * daxiao_ }))
					//if (ImGui::SmallButton("C##reld"))
					{
						for (int i = 0; i < dossizes; i++)
						{
							alldobl[i] = false;
						}
						savealldo();
					}
					if (ImGui::IsItemHovered())
					{
						ImGui::BeginTooltip();
						ImGui::TextUnformatted(u8"清除所有项目勾选");
						ImGui::EndTooltip();
					}
					ImGui::SameLine();
					if (ImGui::ImageButton(Texture_recovery, { 12 * daxiao_,12 * daxiao_ }))
					//if (ImGui::SmallButton("R##reld"))
					{
						auto cfg = ConfigurationFile::i();
						cfg->ini().SetValue("shubiao", "alltodo_", u8"|13|网页日常|日常碎层|家园采集|公会采集|日常制作|龙母|跑男|四门|虫王|分身|双狗|赌场|地虫|");
						std::string alldotmp_2 = "|";
						for (int i = 0; i < 13; i++)
						{
							alldotmp_2 += "A|";
						}
						cfg->ini().SetValue("shubiao", "alltodo_BL", alldotmp_2.c_str());
						cfg->Save();
						readalldo_W();
					}
					if (ImGui::IsItemHovered())
					{
						ImGui::BeginTooltip();
						ImGui::TextUnformatted(u8"初始到原始项目");
						ImGui::EndTooltip();
					}

				}
			}
			else
			{
				if (ImGui::ImageButton(Texture_edit, { 12 * daxiao_,12 * daxiao_ }))
				//if (ImGui::SmallButton(u8"编辑##editmod"))
				{
					editmod = true;
				}
				if (ImGui::IsItemHovered())
				{
					ImGui::BeginTooltip();
					ImGui::TextUnformatted(u8"编辑");
					ImGui::EndTooltip();
				}
			}

			if (!iswantadd)
			{
				if (editmod)
				{
					ImGui::SameLine();
					if (ImGui::ImageButton(Texture_cancel, { 12 * daxiao_,12 * daxiao_ }))
					//if (ImGui::SmallButton(u8"取消##editmod"))
					{
						editmod = false;
					}
					if (ImGui::IsItemHovered())
					{
						ImGui::BeginTooltip();
						ImGui::TextUnformatted(u8"取消");
						ImGui::EndTooltip();
					}
				}

				ImGui::SameLine();
				if (ImGui::ImageButton(Texture_close, { 12 * daxiao_,12 * daxiao_ }))
				//if (ImGui::SmallButton(u8"关##cldaydo"))
				{
					showdaydo = false;
				}
				if (ImGui::IsItemHovered())
				{
					ImGui::BeginTooltip();
					ImGui::TextUnformatted(u8"关闭");
					ImGui::EndTooltip();
				}
			}

			ImGui::PopStyleColor(10);
			ImGui::PopStyleVar(3);
			ImGui::End();
		}
		
		
	}


#pragma endregion 每日必做

	void BossTime::Button_showit(int bosspaixuid, int showsidh, int showsidL, int h, int s)
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
				std::string arrc3 = u8" 来自\"gw2sy.top\"神油boss提示器";
				ImGui::SetClipboardText((arrc1 + arrc2 + arrc3).c_str());
			}
		}
		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::TextUnformatted(u8"点击即可复制到剪切板");
			ImGui::EndTooltip();
		}
	}

	bool BossTime::_DoUI(bool &ison)
	{
		daxiao_ = MiscTab::i()->jiemiandaxiao();
		daxiao2_ = MiscTab::i()->zitidaxiao() / 15.0f;
		touming_ = MiscTab::i()->zhengtitoumingdu();
		if (ison && MiscTab::i()->newmod())
		{
			SHOWNEWUI(ison);
		}

		if (MiscTab::i()->day_to_do())
		{
			DayToDo();
		}

		if (ison && !MiscTab::i()->newmod())
		{

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
			if (MiscTab::i()->jianyimoshi())//自定义显示
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

#pragma region BOSS排序显示

			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(scroll_x / 120.0f / daxiao_ * daxiao2_ * 0.01031f, 0.6f, 0.6f, touming_));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(scroll_x / 120.0f / daxiao_ * daxiao2_ * 0.01031f, 0.6f, 0.8f, touming_));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(scroll_x / 120.0f / daxiao_ * daxiao2_ * 0.01031f, 0.6f, 1.0f, touming_));

			//boss排序主循环
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

			if (ImGui::GetIO().WantCaptureMouse == 1)
			{
				if (ImGui::SmallButton("<<<--------- "))scroll_x_delta = -360.0f * daxiao_ * daxiao2_; ImGui::SameLine();
				if (ImGui::SmallButton("<------------ "))scroll_x_delta = -120.0f * daxiao_ * daxiao2_; ImGui::SameLine();
				if (ImGui::SmallButton(u8"关 闭")) ison = false; 
				if (ImGui::IsItemHovered())
				{
					ImGui::BeginTooltip();
					ImGui::TextUnformatted(u8"\r\n==========右键本按钮可以锁定窗口位置==========\r\n\n");
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
					bool node_open = ImGui::TreeNode(u8"网页日常", u8"网页日常 : (%s)", W_time1);
					ImGui::SameLine(303.0f * daxiao_ * daxiao2_, spacing);
					if (ImGui::SmallButton(u8"明天"))
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
					if (ImGui::SmallButton(u8"复制"))
					{
						std::string arrc1 = u8" 的网页任务: ";
						std::string arrc12 = W_time1;
						std::string arrc2 = u8"来自\"gw2sy.top\"神油boss提示器";
						std::string arrc3 = u8"--";
						std::string r1 = u8"任务一:";
						std::string r2 = u8"任务二:";
						std::string r3 = u8"任务三:";
						std::string r4 = u8"任务四:";
						std::string r5 = u8"任务五:";
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
								ImGui::Text(u8"-----未获取到信息请等待官网更新活动-----");
								ImGui::TreePop();
							}
						}
						else
						{
							ImGui::Text(u8"-----正在获取中请耐心等候-----");
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
