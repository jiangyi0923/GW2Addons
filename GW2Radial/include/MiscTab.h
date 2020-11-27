#pragma once
#include <SettingsMenu.h>
#include <Singleton.h>

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
	void jiemiandaxiao(float value) { return jiemiandaxiao_.value(value); }//

	float zitidaxiao() const { return zitidaxiao_.value(); }
	void zitidaxiao(float value) { return zitidaxiao_.value(value); }

	float zhengtitoumingdu() const { return zhengtitoumingdu_.value(); }
	void zhengtitoumingdu(float value) { return zhengtitoumingdu_.value(value); }

	bool jianyimoshi() const { return jianyimoshi_.value(); }
	void jianyimoshi(bool value) { return jianyimoshi_.value(value); }
	bool jianyimoshi2() const { return jianyimoshi2_.value(); }
	void jianyimoshi2(bool value) { return jianyimoshi2_.value(value); }

	bool UseLooptool() const { return uselooptool_.value(); }
	void UseLooptool(bool value) { return uselooptool_.value(value); }

	bool lodmap() const { return lodmap_.value(); }
	bool dej() const { return dej_.value(); }
	bool hof() const { return hof_.value(); }
	bool bcj() const { return bcj_.value(); }

	bool newmod() const { return newmod_.value(); }
	bool day_to_do() const { return daytodo_.value(); }
	bool day_to_do_heid() const { return daytodo_heid_.value(); }
	
	float tixinmodsiz() const { return tixinmodsiz_.value(); }
	void tixinmodsiz(float value) { return tixinmodsiz_.value(value); }

	bool tixinmod() const { return tixinmod_.value(); }
	void tixinmod(bool value) { return tixinmod_.value(value); }

	bool tixinmodmianrao() const { return tixinmod_mianrao.value(); }
	void tixinmodmianrao(bool value) { return tixinmod_mianrao.value(value); }


	const Keybind& SHOWBOSSTIMER_CK() const { return SHOWBOSSTIMER_CK_; }
	const Keybind& SHOWMOUSELOOP_CK() const { return SHOWMOUSELOOP_CK_; }
	const Keybind& SHOWLOOPTIMER_CK() const { return SHOWLOOPTIMER_CK_; }

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
	ConfigurationOption<float> zitidaxiao_;
	ConfigurationOption<float> zhengtitoumingdu_;
	ConfigurationOption<bool> jianyimoshi_;
	ConfigurationOption<bool> jianyimoshi2_;
	ConfigurationOption<bool> uselooptool_;

	ConfigurationOption<bool> lodmap_;
	ConfigurationOption<bool> dej_;
	ConfigurationOption<bool> hof_;
	ConfigurationOption<bool> bcj_;

	ConfigurationOption<bool> newmod_;
	ConfigurationOption<bool> daytodo_;
	ConfigurationOption<bool> daytodo_heid_;

	ConfigurationOption<bool> tixinmod_;
	ConfigurationOption<float> tixinmodsiz_;
	ConfigurationOption<bool> tixinmod_mianrao;
	int bossleixinjisu = 0;

	//设置按键
	//boss计时器
	Keybind SHOWBOSSTIMER_CK_;
	//鼠标跟随
	Keybind SHOWMOUSELOOP_CK_;
	//输出循环
	Keybind SHOWLOOPTIMER_CK_;

	void setkeys(Keybind& setting);
	void setkeysok(std::set<uint>& keys);
	bool shezianjian = false;
	InputResponse OnInputChange(bool changed, const std::set<uint>& keys, const std::list<EventKey>& changedKeys);
	Input::InputChangeCallback inputChangeCallback_;
	//===================================================
};

}