#pragma once
#include <Main.h>
#include <simpleini/SimpleIni.h>
#include <Singleton.h>

namespace GW2Radial 
{
	class LoopSave : public Singleton<LoopSave>
	{
	public:
		LoopSave();
		void Reload();
		void Save();
		CSimpleIniA& ini() { return ini_; }
	protected:
		static std::tuple<bool /*exists*/, bool /*writable*/> CheckFolder(const std::wstring& folder);
		CSimpleIniA ini_;
		std::wstring folder_;
		std::wstring location_;
	};

}



