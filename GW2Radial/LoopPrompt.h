#pragma once
#include <Main.h>
#include <Singleton.h>
#include <Keybind.h>
#include <Input.h>
#include <ConfigurationOption.h>
#include <imgui.h>

namespace GW2Radial
{
	class LoopPrompt : public Singleton<LoopPrompt>
	{
	public:
		LoopPrompt();
		~LoopPrompt();
		std::string getksystring(std::string tmp);
		void saveloopdate(char* tmpbuf1);
		void loadloopdate();
		void loadloopbuttondate(std::string tmpname);
		void Deleteloopdate(char* tmpbuf1);
		void setkeys(Keybind& setting);
		void setkeysok(std::set<uint>& keys);
		void anjianjiance(std::set<uint>& keys);
		void makeFXWZ();
		void parsFXWZ();


		void Draw();
		const Keybind& showKeybind() const { return showKeybindLoopPrompt_; }
	protected:
		InputResponse OnInputChange(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys);
		bool isVisibleLoopPrompt_ = false;
		bool isVisibleLoopPromptui_ = false;
		Keybind showKeybindLoopPrompt_, showkeybind_,tabekeybind_ , fangunkeybind_;

		Keybind anjian01_, anjian02_, anjian03_, anjian04_, anjian05_;
		Keybind anjian06_, anjian07_, anjian08_, anjian09_, anjian10_;
		Keybind anjian11_, anjian12_, anjian13_, anjian14_, anjian15_;
		ConfigurationOption<float> LoopPromptA_;
		ConfigurationOption<bool> pingbiwasd_;
		ConfigurationOption<bool> pingbiRK_;
		bool shezianjian = false;
		int loopnames_ = 0;
		char buf1[128] = "";
		char buf2[10240] = "";
		bool CGdate = false;
		std::string Erros = "";
		Input::InputChangeCallback inputChangeCallback_;

		std::string * EncodeMap = new std::string[17]
		{
			u8"F1",u8"F2",u8"F3",u8"F4",u8"F5",
			u8"ÎäÆ÷1",u8"ÎäÆ÷2",u8"ÎäÆ÷3",u8"ÎäÆ÷4",u8"ÎäÆ÷5",
			u8"ÖÎÁÆ",u8"²å²Û1",u8"²å²Û2",u8"²å²Û3",u8"¾«Ó¢",
			u8"ÇÐ»»",u8"·­¹ö"
		};
		std::string * DecodeMap = new std::string[17]
		{
			"A","B","C","D","E",
			"F","G","H","I","J",
			"K","L","M","N","O",
			"P","Q"
		};
	};
};