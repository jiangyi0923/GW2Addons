#include "DBINGtool.h"
#include <WinInet.h>
#include <Core.h>
#include <boost/thread.hpp>
#include <tchar.h>



namespace GW2Radial 
{
	DEFINE_SINGLETON(DBINGtool);
	const char* zhiye[9] = { u8"元素",u8"幻术",u8"死灵",u8"游侠",u8"刺客",u8"工程",u8"战士",u8"守护",u8"魂武" };
	const char* ditu[5] = { u8"大型地下城",u8"碎层",u8"竞技场",u8"战场",u8"野外", };
	IDirect3DTexture9* map;//ͼƬ
	IDirect3DTexture9* map2;
	LPDIRECT3DDEVICE9 dive_;
	std::string resultIDS;
	std::string yuansu[5][9];//元素
	std::string huansu[5][9];//幻术
	std::string siling[5][9];//死灵
	std::string youxia[5][9];//游侠
	std::string cike[5][9];//刺客
	std::string gongcheng[5][9];//工程
	std::string zhanshi[5][9];//战士
	std::string shouhu[5][9];//守护
	std::string hunwu[5][9];//魂武
	std::string imgyuansu[5][9];
	std::string imghuansu[5][9];
	std::string imgsiling[5][9];
	std::string imgyouxia[5][9];
	std::string imgcike[5][9];
	std::string imggongcheng[5][9];
	std::string imgzhanshi[5][9];
	std::string imgshouhu[5][9];
	std::string imghunwu[5][9];
	std::string shuchupaihang = "";
	std::string shuchupaihangimg = "";
	std::string imgtmp;
	int zhiyejihuo = 0;
	int ditujihuo = 0;
	std::string tmp1[5][9];
	std::string tmp2[5][9];

	int diyioc = 0;
	bool GetDBDataok = false;
	bool asfdfvfed = true;
	bool duquwancheng = false;

	DBINGtool::DBINGtool():showKeyDBINGtool_("show_DBINGtool", "Show DBINGtool", { VK_F7 }, false)
	{
		dive_ = Core::i()->dive_;
		//D3DXCreateTextureFromFile(dive_, NULL, &map);
		//D3DXCreateTextureFromFile(dive_, L"D:\\15252\\QQ.png", &map);//创建图片缓存 图片位置
		D3DXCreateTextureFromResource(dive_, Core::i()->dllModule(), MAKEINTRESOURCE(IDR_DBTOOLBG), &map);
		D3DXCreateTextureFromResource(dive_, Core::i()->dllModule(), MAKEINTRESOURCE(IDR_DBTOOLLOD), &map2);
		inputChangeCallbackDBINGtool_ = [this](bool changed, const std::set<uint> & keys, const std::list<EventKey> & changedKeys) { return OnInputChangeDBINGtool(changed, keys, changedKeys); };
		Input::i()->AddInputChangeCallback(&inputChangeCallbackDBINGtool_);
	}

	DBINGtool::~DBINGtool()
	{
		if (auto i = Input::iNoInit(); i)
		{
			i->RemoveInputChangeCallback(&inputChangeCallbackDBINGtool_);
		}
		COM_RELEASE(map);
		COM_RELEASE(map2);
	}

	void CharToTchar(const char* _char , TCHAR* tchar)
	{
		int iLength;
		iLength = MultiByteToWideChar(CP_ACP, 0, _char, (int)strlen(_char) + 1, NULL, 0);
		MultiByteToWideChar(CP_ACP, 0, _char, (int)strlen(_char) + 1, tchar, iLength);
	}

	void GetDBData(int aa)
	{
		std::string retVal;
		const auto handle = InternetOpen(L"GetDBData", INTERNET_OPEN_TYPE_PRECONFIG, nullptr, nullptr, 0);
		if (handle == NULL)
		{
			InternetCloseHandle(handle);
		}
		TCHAR* _a = L"https://gw2sy.top/wp-content/uploads/dbtool/dbtool.ini";
		const auto request = InternetOpenUrl(handle, _a, nullptr, 0, INTERNET_FLAG_RELOAD | INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_NO_CACHE_WRITE, 0);
		if (request == NULL)
		{
			InternetCloseHandle(request);
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
		if (response_length > 200)
		{
			std::string beginFlag = "id";
			std::string endFlag = ",";
			std::string namebeginFlag = "name";
			std::string imgbeginFlag = "img";
			std::string typebeginFlag = "type";//count
			std::string countbeginFlag = "count";
			std::string end = "}";
			int startPos = 0;
			int endPos = 0;
			int beginPos = 0;
			int endingpos = 0;

			startPos = (int)retVal.find(beginFlag, startPos);
			endPos = (int)retVal.find(endFlag, startPos);
			beginPos = startPos + (int)beginFlag.length() + 3;
			endingpos = endPos - beginPos - (int)endFlag.length();
			//printf("startPos is %d endPos is %d \r\n", startPos, endPos);
			//printf("beginPos is %d endingpos is %d \r\n", beginPos, endingpos);
			//printf((retVal.substr(beginPos ,endingpos )+" -99 \r\n").c_str());
			int n = atoi((retVal.substr(beginPos, endingpos)).c_str());
			if (n == 99)
			{
				startPos = (int)retVal.find(namebeginFlag, startPos);
				endPos = (int)retVal.find(endFlag, startPos);
				beginPos = startPos + (int)namebeginFlag.length() + 3;
				endingpos = endPos - beginPos - (int)endFlag.length();
				shuchupaihang = retVal.substr(beginPos, endingpos);
				//printf((retVal.substr(beginPos, endingpos) + " -shuchupaihang \r\n").c_str());
				startPos = (int)retVal.find(imgbeginFlag, startPos);
				endPos = (int)retVal.find(endFlag, startPos);
				beginPos = startPos + (int)imgbeginFlag.length() + 3;
				endingpos = endPos - beginPos - (int)endFlag.length();
				shuchupaihangimg = retVal.substr(beginPos, endingpos);
				//printf((retVal.substr(beginPos, endingpos) + " -shuchupaihangimg \r\n").c_str());
			}
			for (int i = 0; i < 9; i++)
			{
				startPos = (int)retVal.find(beginFlag, startPos);
				endPos = (int)retVal.find(endFlag, startPos);
				beginPos = startPos + (int)beginFlag.length() + 3;
				endingpos = endPos - beginPos - (int)endFlag.length();
				int zhiyeID = atoi((retVal.substr(beginPos, endingpos)).c_str());
				//printf((retVal.substr(beginPos, endingpos)+" -zhiyeID \r\n").c_str());
				if (zhiyeID == i)
				{
					for (int j = 0; j < 5; j++)
					{
						startPos = (int)retVal.find(typebeginFlag, startPos);
						endPos = (int)retVal.find(endFlag, startPos);
						beginPos = startPos + (int)typebeginFlag.length() + 3;
						endingpos = endPos - beginPos - (int)endFlag.length();
						int dituleixinID = atoi((retVal.substr(beginPos, endingpos)).c_str());
						//printf((retVal.substr(beginPos, endingpos) + " -dituleixinID \r\n").c_str());
						if (dituleixinID == j)
						{
							startPos = (int)retVal.find(countbeginFlag, startPos);
							endPos = (int)retVal.find(endFlag, startPos);
							beginPos = startPos + (int)countbeginFlag.length() + 3;
							endingpos = endPos - beginPos - (int)endFlag.length();
							int n = atoi((retVal.substr(beginPos, endingpos)).c_str());
							//printf((retVal.substr(beginPos, endingpos) + " -n \r\n").c_str());
							for (int t = 0; t < n; t++)
							{
								std::string namebegintmp1;
								std::string namebegintmp2;
								startPos = (int)retVal.find(namebeginFlag, startPos);
								endPos = (int)retVal.find(endFlag, startPos);
								beginPos = startPos + (int)namebeginFlag.length() + 3;
								endingpos = endPos - beginPos - (int)endFlag.length();
								//printf((retVal.substr(beginPos, endingpos) + " -namebeginFlag \r\n").c_str());
								namebegintmp1 = retVal.substr(beginPos, endingpos);
								startPos = (int)retVal.find(imgbeginFlag, startPos);
								endPos = (int)retVal.find(endFlag, startPos);
								beginPos = startPos + (int)imgbeginFlag.length() + 3;
								endingpos = endPos - beginPos - (int)endFlag.length();
								//printf((retVal.substr(beginPos, endingpos) + " -namebeginFlag \r\n").c_str());
								namebegintmp2 = retVal.substr(beginPos, endingpos);
								if (i ==0)
								{
									yuansu[j][t] = namebegintmp1;
									imgyuansu[j][t] = namebegintmp2;
									
								}
								if (i ==1)
								{
									huansu[j][t] = namebegintmp1;
									imghuansu[j][t] = namebegintmp2;
								}
								if (i ==2)
								{
									siling[j][t] = namebegintmp1;
									imgsiling[j][t] = namebegintmp2;
								}
								if (i == 3)
								{
									youxia[j][t] = namebegintmp1;
									imgyouxia[j][t] = namebegintmp2;
								}
								if (i == 4)
								{
									cike[j][t] = namebegintmp1;
									imgcike[j][t] = namebegintmp2;
								}
								if (i == 5)
								{
									gongcheng[j][t] = namebegintmp1;
									imggongcheng[j][t] = namebegintmp2;
								}
								if (i == 6)
								{
									zhanshi[j][t] = namebegintmp1;
									imgzhanshi[j][t] = namebegintmp2;
								}
								if (i == 7)
								{
									shouhu[j][t] = namebegintmp1;
									imgshouhu[j][t] = namebegintmp2;
								}
								if (i == 8)
								{
									hunwu[j][t] = namebegintmp1;
									imghunwu[j][t] = namebegintmp2;
								}

								GetDBDataok = true;
							}

						}
					}
				}
			}
		}
	}

	std::string GetExePath()
	{
		char szFilePath[MAX_PATH] = { 0 };
		GetModuleFileNameA(NULL, szFilePath, MAX_PATH);
		(strrchr(szFilePath, '\\'))[0] = 0; // 删除文件名，只获得路径字串  
		std::string path = szFilePath;
		// printf(path.c_str());
		return path;
	}
	//与网页的交互,从网页下载 （参数1为文件的URL，参数2为下载的文件的绝对路径，包括文件名及文件类型）
	LPCWSTR stringToLPCWSTR_(std::string orig)
	{
		//std::string tmpss1 = orig;
		size_t origsize = orig.length() + 1;
		const size_t newsize = 100;
		size_t convertedChars = 0;
		wchar_t* wcstring = (wchar_t*)malloc(sizeof(wchar_t) * (orig.length() - 1));
		mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
		return wcstring;
	}

	void WebMutal(int aa)
	{
		asfdfvfed = false;
		std::string Urltmp = "https://gw2sy.top/wp-content/uploads/dbtool/";
		std::string Filetmp = GetExePath() + "\\addons\\gw2addons\\" + imgtmp;
		Urltmp = Urltmp + imgtmp;

		LPCWSTR Url = stringToLPCWSTR_(Urltmp);
		LPCWSTR FileName = stringToLPCWSTR_(Filetmp);
		HINTERNET hInternetOpen = NULL;
		HINTERNET hHttpConnect = NULL;
		HINTERNET hHttpRequest = NULL;
		BYTE* pMessageBody = NULL;    // 保存文件的指针    
		try
		{
			// 先判断是否联网
			//if (!::InternetCheckConnection(lpDwownURL, FLAG_ICC_FORCE_CONNECTION, 0))
			//{
			//	throw 0;
			//}
			// 解析URL以及他的组成部分
			TCHAR szHostName[128] = { 0 };
			TCHAR szUrlPath[512] = { 0 };

			URL_COMPONENTS stUrlAnalysis;
			ZeroMemory(&stUrlAnalysis, sizeof(URL_COMPONENTS));
			stUrlAnalysis.dwStructSize = sizeof(URL_COMPONENTS);
			stUrlAnalysis.dwHostNameLength = sizeof(char) * 128;
			stUrlAnalysis.dwUrlPathLength = sizeof(char) * 512;
			stUrlAnalysis.lpszHostName = szHostName;
			stUrlAnalysis.lpszUrlPath = szUrlPath;

			// 解析域名
			if (!::InternetCrackUrl(Url, 0, ICU_ESCAPE, &stUrlAnalysis))
			{
				throw 0;
			}

			//初始化WinInet,获取跟句柄
			hInternetOpen = ::InternetOpenA(NULL, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);  //INTERNET_OPEN_TYPE_PRECONFIG
			if (NULL == hInternetOpen)
			{
				throw 0;
			}

			//打开一个HTTP的文件协议
			hHttpConnect = ::InternetConnect(hInternetOpen, szHostName, INTERNET_DEFAULT_HTTP_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, INTERNET_FLAG_PASSIVE, 0);
			if (NULL == hHttpConnect)
			{
				throw 0;
			}

			//打开HTTP请求句柄

			hHttpRequest = ::HttpOpenRequest(hHttpConnect, L"GET", szUrlPath, HTTP_VERSION, NULL, NULL, INTERNET_FLAG_NO_UI | INTERNET_FLAG_DONT_CACHE, 1);
			if (NULL == hHttpRequest)
			{
				throw 0;
			}


			if (!::HttpSendRequestA(hHttpRequest, NULL, 0, NULL, NULL))                     //向服务器发送这个请求
			{
				throw 0;
			}

			//  检查HTTP响应消息的头
			DWORD dwInfoBufferLength = 0;
			BYTE* pInfoBuffer = NULL;
			while (!::HttpQueryInfo(hHttpRequest, HTTP_QUERY_CONTENT_LENGTH, pInfoBuffer, &dwInfoBufferLength, NULL))        //接收服务器返回的信息  (此处我们接收文件的大小)    
			{
				DWORD dwError = GetLastError();
				if (dwError == ERROR_INSUFFICIENT_BUFFER)   // 传递给参数的缓冲区太小
				{
					pInfoBuffer = new BYTE[dwInfoBufferLength + 1];
				}
				else
				{
					throw 0;
				}
			}
			memcpy(&pInfoBuffer[dwInfoBufferLength], "\0", 1);

			//得到的文件大小转换为int型 
			unsigned long dwFileSile = _wtoi((WCHAR*)pInfoBuffer);
			delete[] pInfoBuffer;
			DWORD dwBytesRead = 0;
			pMessageBody = new BYTE[dwFileSile + 1];
			if (NULL != pMessageBody)
			{
				if (!InternetReadFile(hHttpRequest, pMessageBody, dwFileSile, &dwBytesRead))
				{
					throw 0;
				}
			}
			else
			{
				throw 0;
			}

			// 保存文件
			HANDLE hFile;
			hFile = ::CreateFile(FileName, GENERIC_WRITE | GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);   // 打开一个文件，获取文件句柄  设置属性为可读可写
			if (NULL == hFile)
			{
				throw 0;
			}
			unsigned long Bytes;
			if (NULL == WriteFile(hFile, pMessageBody, dwFileSile, &Bytes, NULL))   //向文件写入数据
			{
				CloseHandle(hFile);
				throw 0;
			}
			CloseHandle(hFile);
			delete[] pMessageBody;
			delete[] Url;

			//if (NULL != hInternetOpen)
			//{
			//	::InternetCloseHandle(hInternetOpen);
			//}
			//if (NULL != hHttpConnect)
			//{
			//	::InternetCloseHandle(hHttpConnect);
			//}
			//if (NULL != hHttpRequest)
			//{
			//	::InternetCloseHandle(hHttpRequest);
			//}
		}
		catch (...)
		{
			if (NULL != hInternetOpen)
			{
				::InternetCloseHandle(hInternetOpen);
			}
			if (NULL != hHttpConnect)
			{
				::InternetCloseHandle(hHttpConnect);
			}
			if (NULL != hHttpRequest)
			{
				::InternetCloseHandle(hHttpRequest);
			}
			if (NULL != pMessageBody)
			{
				delete[] pMessageBody;
				delete[] Url;
			}
			
			asfdfvfed = false;
		}
		
		if (true)
		{
			COM_RELEASE(map);
			D3DXCreateTextureFromFile(dive_, FileName, &map);//创建图片缓存 图片位置
			asfdfvfed = true;
			delete[] FileName;
		}
	}

	void DBINGtool::Draw()
	{


		

		//if (!isVisibleweb_ && jishiqi)
		//{
		//	if ( kput == 0)
		//	{
		//		isVisibleweb_ = true;
		//		jishiqi = false;
		//	}
		//}
		if (isVisibleDBINGtool_)
		{
			kputDBINGtool = 1;
			if (!_DoUI1(isVisibleDBINGtool_))
			{
				isVisibleDBINGtool_ = false;
				jishiqiDBINGtool = true;
			}
		}

	}

	bool DBINGtool::_DoUI1(bool& ison)
	{
		
		if (diyioc ==0 )
		{
			diyioc = 1;
			boost::thread(&GetDBData, 0);
		}
		if (!ImGui::Begin(u8"配装指南 来源:探险家协会", &ison, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ImGui::End();
			return ison;
		}
		//职业类别
		if (shuchupaihang != "")
		{
			//free(GetDBData);




			if (ImGui::Button(shuchupaihang.c_str()))
			{
				if (asfdfvfed && diyioc == 1)
				{
					asfdfvfed = false;
					imgtmp.clear();
					imgtmp = shuchupaihangimg;
					::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)WebMutal, NULL, NULL, NULL);
					//boost::thread(&WebMutal, 0);
				}

			}

			ImGui::SameLine();
		}


		for (int i = 0; i < 9; i++)
		{
			
			ImGui::PushID(i);
			ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(i / 7.0f, 0.6f, 0.6f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(i / 7.0f, 0.7f, 0.7f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(i / 7.0f, 0.8f, 0.8f));
			//ImGui::Button("Click");
			if (ImGui::Button(zhiye[i]))
			{
				zhiyejihuo = i;
				//getitim();
			}
			ImGui::PopStyleColor(3);
			ImGui::PopID();
		    ImGui::SameLine();
		}


		//for (int i = 0; i < 9; i++)
		//{

		//	ImGui::SameLine();
		//}
		
		
		ImGui::NewLine();
		//各地图
		for (int i = 0; i < 5; i++)
		{
			if (ImGui::Button(ditu[i]))
			{
				ditujihuo = i;
			}
			ImGui::SameLine();
		}
		//各职业各地图的各个图片
		ImGui::NewLine();

		if (GetDBDataok && !duquwancheng)
		{
			
			if (zhiyejihuo == 0)
			{
				for (int t = 0; t < 5; t++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (yuansu[t][j].size() > 1)
						{

							tmp1[t][j] = yuansu[t][j];
							tmp2[t][j] = imgyuansu[t][j];
							//ImGui::Button(tmp1[t][j].c_str());
						}
					}
				}
			}
			if (zhiyejihuo == 1)
			{
				for (int t = 0; t < 5; t++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (huansu[t][j].size() > 1)
						{
							tmp1[t][j] = huansu[t][j];
							tmp2[t][j] = imghuansu[t][j];
							//ImGui::Button(tmp1[t][j].c_str());
						}
					}
				}
			}
			if (zhiyejihuo == 2)
			{
				for (int t = 0; t < 5; t++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (siling[t][j].size() > 2)
						{
							
							tmp1[t][j] = siling[t][j];
							tmp2[t][j] = imgsiling[t][j];
							//ImGui::Button(tmp1[t][j].c_str());
						}
					}
				}
			}
			if (zhiyejihuo == 3)
			{
				for (int t = 0; t < 5; t++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (youxia[t][j].size() > 2)
						{

							tmp1[t][j] = youxia[t][j];
							tmp2[t][j] = imgyouxia[t][j];
							//ImGui::Button(tmp1[t][j].c_str());
						}
					}
				}
			}
			if (zhiyejihuo == 4)
			{
				for (int t = 0; t < 5; t++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (cike[t][j].size() > 2)
						{

							tmp1[t][j] = cike[t][j];
							tmp2[t][j] = imgcike[t][j];
							//ImGui::Button(tmp1[t][j].c_str());
						}
					}
				}
			}
			if (zhiyejihuo == 5)
			{
				for (int t = 0; t < 5; t++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (gongcheng[t][j].size() > 2)
						{

							tmp1[t][j] = gongcheng[t][j];
							tmp2[t][j] = imggongcheng[t][j];
							//ImGui::Button(tmp1[t][j].c_str());
						}
					}
				}
			}
			if (zhiyejihuo == 6)
			{
				for (int t = 0; t < 5; t++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (zhanshi[t][j].size() > 2)
						{

							tmp1[t][j] = zhanshi[t][j];
							tmp2[t][j] = imgzhanshi[t][j];
							//ImGui::Button(tmp1[t][j].c_str());
						}
					}
				}
			}
			if (zhiyejihuo == 7)
			{
				for (int t = 0; t < 5; t++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (shouhu[t][j].size() > 2)
						{

							tmp1[t][j] = shouhu[t][j];
							tmp2[t][j] = imgshouhu[t][j];
							//ImGui::Button(tmp1[t][j].c_str());
						}
					}
				}
			}
			if (zhiyejihuo == 8)
			{
				for (int t = 0; t < 5; t++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (hunwu[t][j].size() > 2)
						{

							tmp1[t][j] = hunwu[t][j];
							tmp2[t][j] = imghunwu[t][j];
							//ImGui::Button(tmp1[t][j].c_str());
						}
					}
				}
			}
			//duquwancheng = true;
		}
		
		for (int i = 0; i < 9; i++)
		{
			if (tmp1[ditujihuo][i].size() > 2 )
			{
				if (ImGui::Button(tmp1[ditujihuo][i].c_str()))
				{
					if (asfdfvfed && diyioc == 1)
					{
						asfdfvfed = false;
						imgtmp.clear();
						imgtmp = tmp2[ditujihuo][i];
						boost::thread(&WebMutal, 0);
						
					}
					//printf("ditujihuo is %d zhiyejihuo is %d i is %d\r\n", ditujihuo, zhiyejihuo, i);

				}
			}

			ImGui::SameLine();
		}

		ImGui::NewLine();
		if (ison)
		{
			if (asfdfvfed)
			{
				//free(getitim);
				ImGui::Image(map, ImVec2(900, 600));
			}
			else
			{
				
				
				
				ImGui::Image(map2, ImVec2(900, 600));
			}
			
		}
		ImGui::End();
		return ison;
	}

	InputResponse DBINGtool::OnInputChangeDBINGtool(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys)
	{
		const bool isMenuKeybindDBINGtool = keys == showKeyDBINGtool_.keys();
		if (isMenuKeybindDBINGtool)
		{
			kputDBINGtool = 1;
			if (jishiqiDBINGtool)
			{
				isVisibleDBINGtool_ = true;
				jishiqiDBINGtool = false;
			}
			else
			{
				isVisibleDBINGtool_ = false;
				jishiqiDBINGtool = true;
			}
		}
		return isMenuKeybindDBINGtool ? InputResponse::PREVENT_ALL : InputResponse::PASS_TO_GAME;
	}
}

