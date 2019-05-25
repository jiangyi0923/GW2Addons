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

		bool _DoUI(bool& ison);

	protected:
		int ass[96] = {};
		int bosstimepaixu0[96] = { 0,1,2,3,4,5,6,7,8,1,9,3,0,5,2,7,4,1,6,3,8,5,9,7,0,1,2,3,4,5,6,7,8,1,9,3,0,5,2,7,4,1,6,3,8,5,9,7,0,1,2,3,4,5,6,7,8,1,9,3,0,5,2,7,4,1,6,3,8,5,9,7,0,1,2,3,4,5,6,7,8,1,9,3,0,5,2,7,4,1,6,3,8,5,9, 7, };
		int bosstimepaixu1[96] = { 10, 11, 12, 23, 13, 23, 14, 15, 23, 16, 17, 23, 18, 23, 19, 15, 10, 20, 21, 23, 13, 23, 22, 15, 23, 11, 12, 23, 18, 23, 14, 15, 10, 16, 17, 23, 13, 23, 19, 15, 18, 20, 21, 23, 10, 23, 22, 15, 13, 11, 12, 23, 23, 23, 14, 15, 18, 16, 17, 23, 10, 23, 19, 15, 13, 20, 21, 23, 23, 23, 22, 15, 23, 11, 18, 12, 23, 23, 10, 14, 15, 16, 13, 17, 23, 23, 19, 15, 23, 20, 21, 23, 18, 23, 22, 15, };
		int bosstimepaixu2[96] = { 24,25,26,23,27,28,29,23,24,25,26,28,27,23,29,28,24,25,26,23,27,23,29,28,24,25,26,23,27,28,29,23,24,25,26,28,27,23,29,28,24,25,26,23,27,23,29,28,24,25,26,23,27,28,29,23,24,25,26,28,27,23,29,28,24,25,26,23,27,23,29,28,24,25,26,23,27,28,29,23,24,25,26,28,27,23,29,28,24,25,26,23,27,23,29,28, };

		int kput = 0;
		float scroll_x = 0;
		bool isVisibleweb_ = false;
		Keybind showKeybindweb_;


		int days = 0;
		bool ghen = false;

		bool jishiqi = true;
		Input::InputChangeCallback inputChangeCallbackweb_;
		InputResponse OnInputChangeweb(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys);



	};
}






