#pragma once
#include "main.h"
#include "simpleini\SimpleIni.h"
#include <set>

class Config
{
public:
    Config();
    ~Config();

    void Load();

    const auto& MountOverlayKeybind() { return _MountOverlayKeybind; }
    void MountOverlayKeybind(const std::set<uint>& val);

    const auto& MountOverlayLockedKeybind() { return _MountOverlayLockedKeybind; }
    void MountOverlayLockedKeybind(const std::set<uint>& val);

    const auto& MountKeybind(uint i) { return _MountKeybinds[i]; }
    void MountKeybind(uint i, const std::set<uint>& val);

    const auto& SettingsKeybind() { return _SettingsKeybind; }

    const auto& MouseKeybind() { return _MouseKeybind; }//鼠标按键

    const auto& jishiqiKeybind() { return _jishiqiKeybind; }//鼠标按键

    auto& ResetCursorOnLockedKeybind() { return _ResetCursorOnLockedKeybind; }
    void ResetCursorOnLockedKeybindSave();

    auto& LockCameraWhenOverlayed() { return _LockCameraWhenOverlayed; }
    void LockCameraWhenOverlayedSave();

    auto& OverlayDelayMilliseconds() { return _OverlayDelayMilliseconds; }
    void OverlayDelayMillisecondsSave();

    auto& OverlayScale() { return _OverlayScale; }
    void OverlayScaleSave();

    auto& OverlayDeadZoneScale() { return _OverlayDeadZoneScale; }
    void OverlayDeadZoneScaleSave();

    auto& OverlayDeadZoneBehavior() { return _OverlayDeadZoneBehavior; }
    void OverlayDeadZoneBehaviorSave();

    auto& FavoriteMount() { return _FavoriteMount; }
    void FavoriteMountSave();

    const auto& ImGuiConfigLocation() { return _ImGuiConfigLocation; }

    auto& shubiaoPOSX() { return _shubiaoPOSX; }
    auto& shubiaoPOSY() { return _shubiaoPOSY; }
    auto& shubiaoRED() { return _shubiaoRED; }
    auto& shubiaoGRE() { return _shubiaoGRE; }
    auto& shubiaoBLU() { return _shubiaoBLU; }
    auto& shubiaoALH() { return _shubiaoALH; }
    void shubiaoPOSSave(float _shubiaoPOSX, float _shubiaoPOSY);
    void shubiaoRGBASave(float _shubiaoRED, float _shubiaoGRE, float _shubiaoBLU, float _shubiaoALH);

    const std::string& LastSaveError() const { return _LastSaveError; }
    bool LastSaveErrorChanged() { bool b = _LastSaveErrorChanged; _LastSaveErrorChanged = false; return b; }

protected:
    void Save();

    const TCHAR* ConfigName = TEXT("config.ini");
    const TCHAR* ImGuiConfigName = TEXT("imgui_config.ini");

    // Config file settings
    CSimpleIniA _INI;
    tstring _ConfigFolder;
    TCHAR _ConfigLocation[MAX_PATH];
    char _ImGuiConfigLocation[MAX_PATH];

    // Config data
    std::set<uint> _MountOverlayKeybind;
    std::set<uint> _MountOverlayLockedKeybind;
    std::set<uint> _MountKeybinds[MountTypeCount];
    std::set<uint> _SettingsKeybind;
    std::set<uint> _MouseKeybind;//鼠标跟随模块按键
    std::set<uint> _jishiqiKeybind;
    float _shubiaoPOSX = 30.f;
    float _shubiaoPOSY = 30.f;
    float _shubiaoRED = 1.F;
    float _shubiaoGRE = 1.F;
    float _shubiaoBLU = 1.F;
    float _shubiaoALH = 1.F;

    bool _ResetCursorOnLockedKeybind = true;
    bool _LockCameraWhenOverlayed = true;
    int _OverlayDelayMilliseconds = 0;
    float _OverlayScale = 1.f;
    float _OverlayDeadZoneScale = 0.2f;
    int _OverlayDeadZoneBehavior = 0;
    MountType _FavoriteMount = MountType::RAPTOR;
    std::string _LastSaveError;
    bool _LastSaveErrorChanged = false;
};