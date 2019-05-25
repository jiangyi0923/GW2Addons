#pragma once
#include <Main.h>
#include <Singleton.h>
#include <Keybind.h>
#include <Input.h>
namespace GW2Radial 
{
	class DBINGtool : public Singleton<DBINGtool>
	{
	public:
		DBINGtool();
		~DBINGtool();
		void Draw();
		bool _DoUI1(bool& ison);
		const Keybind& showKeyDBINGtool() const { return showKeyDBINGtool_; }
	protected:

		int kputDBINGtool = 0;
		bool isVisibleDBINGtool_ = false;
		Keybind showKeyDBINGtool_;
		int shoucidianji = 0;
		bool jishiqiDBINGtool = true;
		Input::InputChangeCallback inputChangeCallbackDBINGtool_;
		InputResponse OnInputChangeDBINGtool(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys);
	};

}


