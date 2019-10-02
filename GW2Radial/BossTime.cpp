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
#pragma region 计时器数据
	const char* BossTime::BossName(int xuhao)
	{
		const char* tmp = "";
		switch (xuhao)
		{
		case  1:tmp = u8"碎裂巨兽";	break;
		case  2:tmp = u8"冰萨满";		break;
		case  3:tmp = u8"人马王";		break;
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
		case 14:tmp = u8"甘达拉跑男"; break;
		case 15:tmp = u8"林线瀑布跑男"; break;
		case 16:tmp = u8"钢铁平原跑男"; break;
		case 17:tmp = u8"赌场闪电战"; break;
		case 18:tmp = u8"巨蛇之怒"; break;
		case 19:tmp = u8"雷云焦油"; break;
		case 20:tmp = u8"埋藏的宝藏"; break;
		case 21:tmp = u8"磨难血口"; break;
		case 22:tmp = u8"晋升之路"; break;
		case 23:tmp = u8"雷云使者"; break;
		case 24:tmp = u8"烈焰塑形"; break;
		case 25:tmp = u8"巨努多崛起"; break;
		case 26:tmp = u8"亚哈巨兽"; break;
		case 27:tmp = u8"伊斯坦攻城"; break;
		case 28:tmp = u8"苍翠龙母"; break;
		case 29:tmp = u8"缠藤虫王"; break;
		case 30:tmp = u8"赤金四门"; break;
		case 31:tmp = u8"巨龙阵地"; break;
		case 32:tmp = u8"戈瑟玛雕像"; break;
		case 33:tmp = u8"厄运传说圣坛"; break;
		case 34:tmp = u8"软泥坑"; break;
		case 35:tmp = u8"金属音乐会"; break;
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
		case  2:tmp = u8"[&BH4BAAA=]"; break;
		case  3:tmp = u8"[&BLEAAAA=]"; break;
		case  4:tmp = u8"[&BEYAAAA=]"; break;
		case  5:tmp = u8"[&BNQCAAA=]"; break;
		case  6:tmp = u8"[&BEEFAAA=]"; break;
		case  7:tmp = u8"[&BHoCAAA=]"; break;
		case  8:tmp = u8"[&BPwAAAA=]"; break;
		case  9:tmp = u8"[&BKgBAAA=]"; break;
		case 10:tmp = u8"[&BM0CAAA=]"; break;
		case 11:tmp = u8"[&BNABAAA=]"; break;
		case 12:tmp = u8"[&BKoBAAA=]"; break;
		case 13:tmp = u8"[&BNcGAAA=]"; break;
		case 14:tmp = u8"[&BOQAAAA=]"; break;
		case 15:tmp = u8"[&BEYEAAA=]"; break;
		case 16:tmp = u8"[&BOkBAAA=]"; break;
		case 17:tmp = u8"[&BLsKAAA=]"; break;
		case 18:tmp = u8"[&BPIKAAA=]"; break;
		case 19:tmp = u8"[&BKYLAAA=]"; break;
		case 20:tmp = u8"[&BGsKAAA=]"; break;
		case 21:tmp = u8"[&BGQKAAA=]"; break;
		case 22:tmp = u8"[&BLgKAAA=]"; break;
		case 23:tmp = u8"[&BLsLAAA=]"; break;
		case 24:tmp = u8"[&BG0KAAA=]"; break;
		case 25:tmp = u8"[&BFgKAAA=]"; break;
		case 26:tmp = u8"[&BHALAAA=]"; break;
		case 27:tmp = u8"[&BPcKAAA=]"; break;
		case 28:tmp = u8"[&BAgIAAA=]"; break;
		case 29:tmp = u8"[&BPUHAAA=]"; break;
		case 30:tmp = u8"[&BGwIAAA=]"; break;
		case 31:tmp = u8"[&BBAIAAA=]"; break;
		case 32:tmp = u8"[&BAcMAAA=]"; break;
		case 33:tmp = u8"[&BAEMAAA=]"; break;
		case 34:tmp = u8"[&BP0LAAA=]"; break;
		case 35:tmp = u8"[&BBkMAAA=]"; break;
		default:break;
		}
		return tmp;
	}
#pragma endregion
	BossTime::BossTime():showKeybindweb_("show_BossTime", "Show BossTime", { VK_F8 }, false),
		gudingwinpos_(u8"锁定窗口位置", "gudingwinpos_", "shubiao", false),
		gudingwinpos_x(u8"窗口位置x", "gudingwinpos_x", "shubiao", 500.0f),
		gudingwinpos_y(u8"窗口位置y", "gudingwinpos_y", "shubiao", 5.0f)
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
#pragma region 日志
	//struct ExampleAppLog
	//{
	//	ImGuiTextBuffer     Buf;
	//	ImGuiTextFilter     Filter;
	//	ImVector<int>       LineOffsets;        // Index to lines offset
	//	bool                ScrollToBottom;

	//	void    Clear() { Buf.clear(); LineOffsets.clear(); }

	//	void    AddLog(const char* fmt, ...) IM_FMTARGS(2)
	//	{
	//		int old_size = Buf.size();
	//		va_list args;
	//		va_start(args, fmt);
	//		Buf.appendfv(fmt, args);
	//		Buf.appendfv("\r\n", args);
	//		va_end(args);
	//		for (int new_size = Buf.size(); old_size < new_size; old_size++)
	//			if (Buf[old_size] == '\n')
	//				LineOffsets.push_back(old_size);
	//		ScrollToBottom = true;
	//	}

	//	void    Draw(const char* title, bool* p_open = NULL)
	//	{
	//		ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_FirstUseEver);
	//		
	//		if (!ImGui::Begin(title, p_open))
	//		{
	//			ImGui::End();
	//			return;
	//		}
	//		if (ImGui::Button(u8"取消")) Clear();
	//		ImGui::SameLine();
	//		bool copy = ImGui::Button(u8"拷贝");
	//		ImGui::SameLine();
	//		Filter.Draw(u8"过滤器", -100.0f);
	//		ImGui::Separator();
	//		ImGui::BeginChild(u8"滚动", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
	//		if (copy) ImGui::LogToClipboard();

	//		if (Filter.IsActive())
	//		{
	//			const char* buf_begin = Buf.begin();
	//			const char* line = buf_begin;
	//			for (int line_no = 0; line != NULL; line_no++)
	//			{
	//				const char* line_end = (line_no < LineOffsets.Size) ? buf_begin + LineOffsets[line_no] : NULL;
	//				if (Filter.PassFilter(line, line_end))
	//					ImGui::TextUnformatted(line, line_end);
	//				line = line_end && line_end[1] ? line_end + 1 : NULL;
	//			}
	//		}
	//		else
	//		{
	//			ImGui::TextUnformatted(Buf.begin());
	//		}

	//		//if (ScrollToBottom)
	//			//ImGui::SetScrollHereY(1.0f);
	//		ScrollToBottom = false;
	//		ImGui::EndChild();
	//		ImGui::End();
	//	}
	//};
	//static ExampleAppLog log;//
	//bool is = true;//
#pragma endregion

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
		char* out = new char[strTime.length()];
		for (int i = 0; i <= strTime.length(); ++i)
			out[i] = strTime[i];
		return out;
	}

	std::string* FetchReleaseData(const char * days)
	{
		wancheng = false;
		std::string retVal;
		const auto handle = InternetOpen(L"getwebname", INTERNET_OPEN_TYPE_PRECONFIG, nullptr, nullptr, 0);
		if (handle == nullptr)
		{
			InternetCloseHandle(handle);
			result[0] = "0";
			geting = false;
			wancheng = true;
		}
		std::string _a = "http://do.gw2.kongzhong.com/task/completes?date=";
		std::string _b = days;
		std::string _tmp = _a + _b;
		LPCWSTR ul = stringToLPCWSTR(_tmp);

		const auto request = InternetOpenUrl(handle, ul, nullptr, 0, INTERNET_FLAG_RELOAD | INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_NO_CACHE_WRITE, 0);
		delete(ul);

		if (request == nullptr)
		{
			InternetCloseHandle(request);
			result[0] = "0";
			geting = false;
			wancheng = true;
		}
		char response_data[8000];//缓冲区
		DWORD response_length = 0;

		if (InternetReadFile(request, response_data, sizeof(response_data) - 1, &response_length) && response_length > 0)
		{
			response_data[response_length] = '\0';
			response_length++;
		}
		InternetCloseHandle(request);
		InternetCloseHandle(handle);
		retVal = response_data;

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
		ImGui::PushID(showsidh * 100 + showsidL);
		float hue = showsidL * 0.01f;
		ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(hue, 0.6f, 0.6f, touming_));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(hue, 0.7f, 0.7f, touming_));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(hue, 0.8f, 0.8f, touming_));
		if (ImGui::Button(label, ImVec2(120.0f * daxiao_, 22.0f * daxiao_)))
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
			ImGui::TextUnformatted(u8"\r\n=======点击即可复制到剪切板=======\r\n\n");
			ImGui::EndTooltip();
		}
		ImGui::PopStyleColor(3);
		ImGui::PopID();
	}

	bool BossTime::_DoUI(bool &ison)
	{
		if (ison)
		{
			daxiao_ = MiscTab::i()->jiemiandaxiao();
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
			float scrollingdaxiao = 45 * daxiao_;
			if (MiscTab::i()->jianyimoshi() == false || ImGui::GetIO().WantCaptureMouse == 1)
			{
				scrollingdaxiao = 115 * daxiao_;
			}
			ImGui::BeginChild("scrolling", ImVec2(360 * daxiao_, scrollingdaxiao), false);
			ImGui::SetWindowFontScale(daxiao_);
			for (int t = 0; t < 5; t++)
			{
				int h = 0, s = 0;

				if (t == 0)
				{
					for (int i = 0; i < 97; i++)
					{
						if (i > 0) ImGui::SameLine(0.0F, 0.0F);
						Button_showit( BSPX1[i], t, i, h, s);
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
						if (BSPX2[i] == 32 || BSPX2[i] == 34)
						{
							s = 10;
						}
						if (BSPX2[i] == 33 || BSPX2[i] == 35)
						{
							s = 40;
						}
						Button_showit( BSPX2[i], t, i, h, s);
						if (s == 10 || s == 40)s = s + 5;
						if (s < 60)  s = s + 15;
						if (s == 60) h++, s = 0;
						if (h == 24)	  h = 0;
					}
				}
				if (MiscTab::i()->jianyimoshi() == false || ImGui::GetIO().WantCaptureMouse == 1)
				{
					if (t == 2)
					{
						for (int i = 0; i < 97; i++)
						{
							if (i > 0) ImGui::SameLine(0.0F, 0.0F);
							if (BSPX3[i] == 28)
							{
								s = 10;
							}
							if (BSPX3[i] == 14 || BSPX3[i] == 15 || BSPX3[i] == 16)
							{
								s = 20;
							}
							Button_showit(BSPX3[i], t, i, h, s);
							if (s == 10) s = s - 10;
							if (s == 20) s = s - 5;
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
							if (BSPX4[i] == 17)
							{
								s = 5;
							}
							if (BSPX4[i] == 21)
							{
								s = 0;
							}
							Button_showit(BSPX4[i], t, i, h, s);
							if (s == 5)s = 0;
							if (BSPX4[i] == 21)s = 15;
							if (s < 60)  s = s + 15;
							if (s == 60) h++, s = 0;
							if (h == 24)	  h = 0;
						}
					}
					if (t == 4)
					{
						for (int i = 0; i < 97; i++)
						{
							if (i > 0) ImGui::SameLine(0.0F, 0.0F);
							Button_showit(BSPX5[i], t, i, h, s);
							if (s < 60)  s = s + 15;
							if (s == 60) h++, s = 0;
							if (h == 24)	  h = 0;
						}
					}
				}

				
			}

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
					boost::thread(&getsting, W_time1);
				}
			}
			float scroll_x_delta = 0.0f;
			ImGui::IsItemHovered();
			if (ImGui::GetIO().WantCaptureMouse == 1)
			{
				ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(scroll_x / 120.0f / daxiao_ * 0.01031f, 0.6f, 0.6f, touming_));
				ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(scroll_x / 120.0f / daxiao_ * 0.01031f, 0.6f, 0.6f, touming_));
				ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(scroll_x / 120.0f / daxiao_ * 0.01031f, 0.6f, 0.6f, touming_));
				if (ImGui::SmallButton("<<<----------"))scroll_x_delta = -360.0f * daxiao_; ImGui::SameLine();
				if (ImGui::SmallButton("<-------------"))scroll_x_delta = -120.0f * daxiao_; ImGui::SameLine();
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
				if (ImGui::SmallButton("------------->"))scroll_x_delta = +120.0f * daxiao_; ImGui::SameLine();
				if (ImGui::SmallButton("---------->>>"))scroll_x_delta = +360.0f * daxiao_; ImGui::SameLine();
				ImGui::PopStyleColor(3);
				if (scroll_x_delta != 0.0f)ImGui::BeginChild("scrolling"), ImGui::SetScrollX(ImGui::GetScrollX() + scroll_x_delta), ImGui::EndChild();
				ImGui::AlignTextToFramePadding();
				ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());
				if (MiscTab::i()->getweb())
				{
					ImGui::Spacing();
					bool node_open = ImGui::TreeNode(u8"网页日常", u8"网页日常 : (%s)", W_time1);
					ImGui::SameLine(303.0f * daxiao_, spacing);
					ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(scroll_x / 120.0f / daxiao_ * 0.01031f, 0.6f, 0.6f, touming_));
					ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(scroll_x / 120.0f / daxiao_ * 0.01031f, 0.6f, 0.6f, touming_));
					ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(scroll_x / 120.0f / daxiao_ * 0.01031f, 0.6f, 0.6f, touming_));
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
							boost::thread(&getsting, addday);
						}

					}
					ImGui::SameLine(335.0f * daxiao_, spacing);
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
					ImGui::PopStyleColor(3);
					
				}
			}
			else
			{
				ImGui::BeginChild("scrolling");
				if (now_time.tm_hour * 60 + now_time.tm_min < 30)
				{
					ImGui::SetScrollX(((now_time.tm_hour * 60 + now_time.tm_min) / 15) * 120.0f* daxiao_);
				}
				else
				{
					ImGui::SetScrollX(((now_time.tm_hour * 60 + now_time.tm_min) / 15 - 1) * 120.0f* daxiao_);
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
								boost::thread(&getsting, adddayend);
							}
						}
					}
				}
			}
			
			ImGui::End();
			ImGui::PopStyleVar(4);
		}
		//log.Draw(u8"Log", &is);//日志显示
		return ison;
	}

	InputResponse BossTime::OnInputChangeweb(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys)
	{
		const bool isMenuKeybindweb = keys == showKeybindweb_.keys();
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
