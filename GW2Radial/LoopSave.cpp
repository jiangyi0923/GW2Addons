#include "LoopSave.h"
#include <Shlobj.h>
#include <Utility.h>
#include <tchar.h>
#include <sstream>

namespace GW2Radial
{
	DEFINE_SINGLETON(LoopSave);

	const wchar_t* g_configName = TEXT("LoopSave.ini");

	LoopSave::LoopSave()
	{
		Reload();
	}
	void SplitFilename(const tstring& str, tstring* folder, tstring* file)
	{
		const auto found = str.find_last_of(TEXT("/\\"));
		if (folder) *folder = str.substr(0, found);
		if (file) *file = str.substr(found + 1);
	}
	void LoopSave::Reload()
	{
		// Create folders
		wchar_t exeFullPath[MAX_PATH];
		GetModuleFileNameW(nullptr, exeFullPath, MAX_PATH);
		tstring exeFolder;
		SplitFilename(exeFullPath, &exeFolder, nullptr);

		wchar_t* myDocuments;
		if (FAILED(SHGetKnownFolderPath(FOLDERID_Documents, KF_FLAG_CREATE, nullptr, &myDocuments)))
			myDocuments = nullptr;

		const auto programFilesLocation = exeFolder + L"\\addons\\gw2addons\\";
		const auto myDocumentsLocation = std::wstring(myDocuments) + L"\\GUILD WARS 2\\addons\\gw2addons\\";

		auto [pfExists, pfWritable] = CheckFolder(programFilesLocation);
		auto [mdExists, mdWritable] = CheckFolder(myDocumentsLocation);

		ini_.SetUnicode();
		if (pfExists)
		{
			ini_.LoadFile((programFilesLocation + g_configName).c_str());
		}
		else if (mdExists)
		{
			ini_.LoadFile((myDocumentsLocation + g_configName).c_str());
		}
		if (pfWritable)
			folder_ = programFilesLocation;
		else
			folder_ = myDocumentsLocation;

		location_ = folder_ + g_configName;
	}

	void LoopSave::Save()
	{

	}

	std::tuple<bool /*exists*/, bool /*writable*/> LoopSave::CheckFolder(const std::wstring& folder)
	{
		const auto filepath = folder + g_configName;

		bool exists = true, writable = true;

		if (SHCreateDirectoryExW(nullptr, folder.c_str(), nullptr) == ERROR_ACCESS_DENIED)
			writable = false;

		if (!FileExists(filepath.c_str()))
			exists = false;

		if (writable)
		{
			FILE* fp = nullptr;
			if (_wfopen_s(&fp, filepath.c_str(), L"ab") != 0)
				writable = false;
			else
				fclose(fp);
		}

		return { exists, writable };
	}
}