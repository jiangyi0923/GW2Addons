#pragma once
#include <Main.h>
#include <Singleton.h>
#include <Keybind.h>
#include <Input.h>
#include <boost/thread.hpp>


namespace GW2Radial
{
	class BossTime :public Singleton<BossTime>
	{

	public:
		BossTime();
		~BossTime();
		void Draw();
		const Keybind& showKeybindweb() const { return showKeybindweb_; }
		bool gwps() const { return gudingwinpos_.value(); }
		void gwps(bool value) { return gudingwinpos_.value(value); }
		float sPOSX() const { return gudingwinpos_x.value(); }
		void sPOSX(float value) { return gudingwinpos_x.value(value); }
		float sPOSY() const { return gudingwinpos_y.value(); }
		void sPOSY(float value) { return gudingwinpos_y.value(value); }
		bool _DoUI(bool& ison);

	protected:
		int BSPX1[97] = { 1,2,3,4,5,6,7,8,9,2,10,4,1,6,3,8,5,2,7,4,9,6,10,8,1,2,3,4,5,6,7,8,9,2,10,4,1,6,3,8,5,2,7,4,9,6,10,8,1,2,3,4,5,6,7,8,9,2,10,4,1,6,3,8,5,2,7,4,9,6,10,8,1,2,3,4,5,6,7,8,9,2,10,4,1,6,3,8,5,2,7,4,9,6,10,8,1 };
		int BSPX2[97] = { 11,32,0,33,12,34,0,35,0,32,0,33,13,34,0,35,11,32,0,33,12,34,0,35,0,32,0,33,13,34,0,35,11,32,0,33,12,34,0,35,13,32,0,33,11,34,0,35,12,32,0,33,0,34,0,35,13,32,0,33,11,34,0,35,12,32,0,33,0,34,0,35,0,32,13,33,0,34,11,35,0,32,12,33,0,34,0,35,0,32,0,33,13,34,0,35,11 };
		int BSPX3[97] = { 28,14,29,0,30,0,31,0,28,15,29,0,30,0,31,0,28,16,29,0,30,0,31,0,28,14,29,0,30,0,31,0,28,15,29,0,30,0,31,0,28,16,29,0,30,0,31,0,28,14,29,0,30,0,31,0,28,15,29,0,30,0,31,0,28,16,29,0,30,0,31,0,28,14,29,0,30,0,31,0,28,15,29,0,30,0,31,0,28,16,29,0,30,0,31,0,28 };
		int BSPX4[97] = { 17,0,18,19,20,21,22,23,17,0,18,19,20,21,22,23,17,0,18,19,20,21,22,23,17,0,18,19,20,21,22,23,17,0,18,19,20,21,22,23,17,0,18,19,20,21,22,23,17,0,18,19,20,21,22,23,17,0,18,19,20,21,22,23,17,0,18,19,20,21,22,23,17,0,18,19,20,21,22,23,17,0,18,19,20,21,22,23,17,0,18,19,20,21,22,23,17 };
		int BSPX5[97] = { 24,0,25,0,24,26,25,27,24,0,25,0,24,26,25,27,24,0,25,0,24,26,25,27,24,0,25,0,24,26,25,27,24,0,25,0,24,26,25,27,24,0,25,0,24,26,25,27,24,0,25,0,24,26,25,27,24,0,25,0,24,26,25,27,24,0,25,0,24,26,25,27,24,0,25,0,24,26,25,27,24,0,25,0,24,26,25,27,24,0,25,0,24,26,25,27,24 };
		const char* BossName(int xuhao);
		const char* BossPost(int xuhao);


		int kput = 0;
		float scroll_x = 0;
		bool isVisibleweb_ = false;
		Keybind showKeybindweb_;

		ConfigurationOption<bool> gudingwinpos_;
		ConfigurationOption<float> gudingwinpos_x;
		ConfigurationOption<float> gudingwinpos_y;
		int days = 0;
		bool ghen = false;

		bool jishiqi = true;
		Input::InputChangeCallback inputChangeCallbackweb_;
		InputResponse OnInputChangeweb(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys);



	};
}






