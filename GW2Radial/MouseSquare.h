#pragma once
#include <Main.h>
#include <Singleton.h>
#include <Keybind.h>
#include <Input.h>
namespace GW2Radial
{
	class MouseSquare : public Singleton<MouseSquare>
	{
	public:

		MouseSquare();
		~MouseSquare();
		bool Doui(bool Do);
		void Draw();
		const Keybind& showKeybind() const { return showKeybindMouseSquare_; }

	protected:
		InputResponse OnInputChange(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys);
		bool isVisibleMouseSquare_ = false;
		Keybind showKeybindMouseSquare_;
		bool jishiqiMouseSquare = true;
		Input::InputChangeCallback inputChangeCallback_;
		int kput = 0;
	};
};
