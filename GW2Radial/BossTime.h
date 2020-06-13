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
		//const Keybind& showKeybindweb() const { return showKeybindweb_; }
		bool gwps() const { return gudingwinpos_.value(); }
		void gwps(bool value) { return gudingwinpos_.value(value); }
		float sPOSX() const { return gudingwinpos_x.value(); }
		void sPOSX(float value) { return gudingwinpos_x.value(value); }
		float sPOSY() const { return gudingwinpos_y.value(); }
		void sPOSY(float value) { return gudingwinpos_y.value(value); }
		std::string SHOWNEWUI_BUTTONS_TYPE(int bosspaixuid, int show_TYPE, int h, int s);
		void TOOLSVIM(bool& showtoolwind);
		void SHOWNEWUI_BUTTONS();
		void SHOWNEWUI(bool& showit);
		void readalldo_W();
		void readalldo();
		bool _DoUI(bool& ison);

	protected:

		int BSPX1[97] = { 1,2,3,4,5,6,7,8,9,2,10,4,1,6,3,8,5,2,7,4,9,6,10,8,1,2,3,4,5,6,7,8,9,2,10,4,1,6,3,8,5,2,7,4,9,6,10,8,1,2,3,4,5,6,7,8,9,2,10,4,1,6,3,8,5,2,7,4,9,6,10,8,1,2,3,4,5,6,7,8,9,2,10,4,1,6,3,8,5,2,7,4,9,6,10,8,1};
		int BSPX2[97] = { 11,14,0,0,12,0,0,0,0,15,0,0,13,0,0,0,11,16,0,0,12,0,0,0,0,14,0,0,13,0,0,0,11,15,0,0,12,0,0,0,13,16,0,0,11,0,0,0,12,14,0,0,0,0,0,0,13,15,0,0,11,0,0,0,12,16,0,0,0,0,0,0,0,14,13,0,0,0,11,0,0,15,12,0,0,0,0,0,0,16,0,0,13,0,0,0,11};
		int BSPX3[97] = { 17,0,18,21,19,0,20,21,17,0,18,21,19,0,20,21,17,0,18,21,19,0,20,21,17,0,18,21,19,0,20,21,17,0,18,21,19,0,20,21,17,0,18,21,19,0,20,21,17,0,18,21,19,0,20,21,17,0,18,21,19,0,20,21,17,0,18,21,19,0,20,21,17,0,18,21,19,0,20,21,17,0,18,21,19,0,20,21,17,0,18,21,19,0,20,21,17};
		int BSPX4[97] = { 0,0,22,0,23,0,0,24,0,0,22,0,23,0,0,24,0,0,22,0,23,0,0,24,0,0,22,0,23,0,0,24,0,0,22,0,23,0,0,24,0,0,22,0,23,0,0,24,0,0,22,0,23,0,0,24,0,0,22,0,23,0,0,24,0,0,22,0,23,0,0,24,0,0,22,0,23,0,0,24,0,0,22,0,23,0,0,24,0,0,22,0,23,0,0,24,0};
		int BSPX5[97] = { 25,0,26,27,28,29,26,31,25,0,26,27,28,29,26,31,25,0,26,27,28,29,26,31,25,0,26,27,28,29,26,31,25,0,26,27,28,29,26,31,25,0,26,27,28,29,26,31,25,0,26,27,28,29,26,31,25,0,26,27,28,29,26,31,25,0,26,27,28,29,26,31,25,0,26,27,28,29,26,31,25,0,26,27,28,29,26,31,25,0,26,27,28,29,26,31,25};
		int BSPX6[97] = { 32,0,33,0,34,35,30,36,32,0,33,0,34,35,30,36,32,0,33,0,34,35,30,36,32,0,33,0,34,35,30,36,32,0,33,0,34,35,30,36,32,0,33,0,34,35,30,36,32,0,33,0,34,35,30,36,32,0,33,0,34,35,30,36,32,0,33,0,34,35,30,36,32,0,33,0,34,35,30,36,32,0,33,0,34,35,30,36,32,0,33,0,34,35,30,36,32};
		int BSPX7[97] = { 37,0,38,0,39,0,40,0,37,0,38,0,39,0,40,0,37,0,38,0,39,0,40,0,37,0,38,0,39,0,40,0,37,0,38,0,39,0,40,0,37,0,38,0,39,0,40,0,37,0,38,0,39,0,40,0,37,0,38,0,39,0,40,0,37,0,38,0,39,0,40,0,37,0,38,0,39,0,40,0,37,0,38,0,39,0,40,0,37,0,38,0,39,0,40,0,37};
		int BSPX8[97] = { 0,0,0,0,41,0,0,42,0,0,0,0,41,0,0,42,0,0,0,0,41,0,0,42,0,0,0,0,41,0,0,42,0,0,0,0,41,0,0,42,0,0,0,0,41,0,0,42,0,0,0,0,41,0,0,42,0,0,0,0,41,0,0,42,0,0,0,0,41,0,0,42,0,0,0,0,41,0,0,42,0,0,0,0,41,0,0,42,0,0,0,0,41,0,0,42,0 };
		int BSPX51[97] = { 0,0,0,0,29,0,0,0,0,0,0,0,29,0,0,0,0,0,0,0,29,0,0,0,0,0,0,0,29,0,0,0,0,0,0,0,29,0,0,0,0,0,0,0,29,0,0,0,0,0,0,0,29,0,0,0,0,0,0,0,29,0,0,0,0,0,0,0,29,0,0,0,0,0,0,0,29,0,0,0,0,0,0,0,29,0,0,0,0,0,0,0,29,0,0,0,0 };
		int BSPX5x[97] = { 25,0,26,27,28,0,26,31,25,0,26,27,28,0,26,31,25,0,26,27,28,0,26,31,25,0,26,27,28,0,26,31,25,0,26,27,28,0,26,31,25,0,26,27,28,0,26,31,25,0,26,27,28,0,26,31,25,0,26,27,28,0,26,31,25,0,26,27,28,0,26,31,25,0,26,27,28,0,26,31,25,0,26,27,28,0,26,31,25,0,26,27,28,0,26,31,25 };
		
		const char* BossName(int xuhao);
		const char* BossPost(int xuhao);

		void savealldo();

		void DELsonedo(int intmp_);

		void ADDsonedo(std::string intmp_);

		void DayToDo();

		void Button_showit(int bosspaixuid, int showsidh, int showsidL, int h, int s);


		float daxiao_ =1.0f;
		float daxiao2_ = 1.0f;
		float touming_ =0.44f;
		int kput = 0;
		float scroll_x = 0;
		bool isVisibleweb_ = false;
		//Keybind showKeybindweb_;

		IDirect3DTexture9* Texture_1 = nullptr;
		IDirect3DTexture9* Texture_2 = nullptr;
		IDirect3DTexture9* Texture_3 = nullptr;

		IDirect3DTexture9* Texture_add = nullptr;
		IDirect3DTexture9* Texture_cancel = nullptr;
		IDirect3DTexture9* Texture_close = nullptr;
		IDirect3DTexture9* Texture_edit = nullptr;
		IDirect3DTexture9* Texture_recovery = nullptr;
		IDirect3DTexture9* Texture_remove = nullptr;
		IDirect3DTexture9* Texture_delete = nullptr;


		ConfigurationOption<bool> gudingwinpos_;
		ConfigurationOption<float> gudingwinpos_x;
		ConfigurationOption<float> gudingwinpos_y;
		//ConfigurationOption<const char*> isnewday_;
		int days = 0;
		bool ghen = false;

		bool jishiqi = true;
		Input::InputChangeCallback inputChangeCallbackweb_;
		InputResponse OnInputChangeweb(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys);



	};
}






