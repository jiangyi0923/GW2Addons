#pragma once

#include <Main.h>
#include <Singleton.h>
#include <list>
#include <Keybind.h>
#include <Input.h>
#include <ConfigurationOption.h>

namespace GW2Radial
{

class SettingsMenu : public Singleton<SettingsMenu>
{
public:
	class Implementer
	{
	public:
		virtual void DrawMenu() = 0;
	};

	SettingsMenu();

	void Draw();

	const Keybind& showKeybind() const { return showKeybind_; }
	
	//===================================================
	//boos
	bool showboostime() const { return showboostime_.value(); }
	void showboostime(bool value) { return showboostime_.value(value); }
	//bool getmingtian() const { return getmingtian_.value(); }
	//void getmingtian(bool value) { return getmingtian_.value(value); }
	bool getweb() const { return getweb_.value(); }
	void getweb(bool value) { return getweb_.value(value); }
	//xy
	float shubiaoPOSX() const { return shubiaoPOSX_.value(); }
	void shubiaoPOSX(float value) { return shubiaoPOSX_.value(value); }
	float shubiaoPOSY() const { return shubiaoPOSY_.value(); }
	void shubiaoPOSY(float value) { return shubiaoPOSY_.value(value); }
	//Rgba
	float shubiaoRED() const { return shubiaoRED_.value(); }
	void shubiaoRED(float value) { return shubiaoRED_.value(value); }
	float shubiaoGRE() const { return shubiaoGRE_.value(); }
	void shubiaoGRE(float value) { return shubiaoGRE_.value(value); }
	float shubiaoBLU() const { return shubiaoBLU_.value(); }
	void shubiaoBLU(float value) { return shubiaoBLU_.value(value); }
	float shubiaoALH() const { return shubiaoALH_.value(); }
	void shubiaoALH(float value) { return shubiaoALH_.value(value); }
	//===================================================

	void AddImplementer(Implementer* impl) { implementers_.push_back(impl); }
	void RemoveImplementer(Implementer* impl) { implementers_.remove(impl); }

protected:
	InputResponse OnInputChange(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys);

	std::list<Implementer*> implementers_;

	//===================================================
//boos
	ConfigurationOption<bool> showboostime_;
	//ConfigurationOption<bool> getmingtian_;
	ConfigurationOption<bool> getweb_;
	//xy
	ConfigurationOption<float> shubiaoPOSX_;
	ConfigurationOption<float> shubiaoPOSY_;
	//gba
	ConfigurationOption<float> shubiaoRED_;
	ConfigurationOption<float> shubiaoGRE_;
	ConfigurationOption<float> shubiaoBLU_;
	ConfigurationOption<float> shubiaoALH_;
	//===================================================

	bool isVisible_ = false;
	Keybind showKeybind_;
	
	Input::InputChangeCallback inputChangeCallback_;
};

}