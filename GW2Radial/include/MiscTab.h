#pragma once
#include <SettingsMenu.h>
#include <Singleton.h>
#include <ConfigurationOption.h>
namespace GW2Radial
{

class MiscTab : public SettingsMenu::Implementer, public Singleton<MiscTab>
{
public:
	MiscTab();
	~MiscTab();

	const char * GetTabName() const override { return u8"神油工具"; }
	void DrawMenu() override;
	//===================================================
//boos
	bool showboostime() const { return showboostime_.value(); }
	void showboostime(bool value) { return showboostime_.value(value); }
	//bool getmingtian() const { return getmingtian_.value(); }
	//void getmingtian(bool value) { return getmingtian_.value(value); }
	bool getweb() const { return getweb_.value(); }
	void getweb(bool value) { return getweb_.value(value); }
	bool showfankuai() const { return showfankuai_.value(); }
	void showfankuai(bool value) { return showfankuai_.value(value); }

	int shubiaofankuaiyangshi() const { return shubiaofankuaiyangshi_.value(); }
	void shubiaofankuaiyangshi(int value) { return shubiaofankuaiyangshi_.value(value); }

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
	
	float jiemiandaxiao() const { return jiemiandaxiao_.value(); }
	void jiemiandaxiao(float value) { return jiemiandaxiao_.value(value); }

	//===================================================
	uint vk_ = 0;
protected:
	//===================================================
//boos
	ConfigurationOption<bool> showboostime_;
	//ConfigurationOption<bool> getmingtian_;
	ConfigurationOption<bool> getweb_;
	ConfigurationOption<bool> showfankuai_;
	//方块样式
	ConfigurationOption<int> shubiaofankuaiyangshi_;
	//xy
	ConfigurationOption<float> shubiaoPOSX_;
	ConfigurationOption<float> shubiaoPOSY_;
	//gba
	ConfigurationOption<float> shubiaoRED_;
	ConfigurationOption<float> shubiaoGRE_;
	ConfigurationOption<float> shubiaoBLU_;
	ConfigurationOption<float> shubiaoALH_;

	ConfigurationOption<float> jiemiandaxiao_;

	//===================================================
};

}