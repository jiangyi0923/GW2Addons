#include "Config.h"
#include <Shlobj.h>
#include "Utility.h"
#include <tchar.h>
#include <sstream>

Config::Config()
{
    _SettingsKeybind.insert(VK_SHIFT);
    _SettingsKeybind.insert(VK_MENU);
    _SettingsKeybind.insert('M');
    _MouseKeybind.insert(VK_F9);//������ģ�鰴��
    _jishiqiKeybind.insert(VK_F8);
}


Config::~Config()
{
}

void LoadKeybindString(const char* keys, std::set<uint>& out)
{
    if (strnlen_s(keys, 256) > 0)
    {
        std::stringstream ss(keys);
        std::vector<std::string> result;

        while (ss.good())
        {
            std::string substr;
            std::getline(ss, substr, ',');
            int val = std::stoi(substr);
            out.insert((uint)val);
        }
    }
}

void Config::Load()
{
    // Create folders
    TCHAR exeFullPath[MAX_PATH];
    GetModuleFileName(0, exeFullPath, MAX_PATH);
    tstring exeFolder;
    SplitFilename(exeFullPath, &exeFolder, nullptr);
    _ConfigFolder = exeFolder + TEXT("\\addons\\mounts\\");
    _tcscpy_s(_ConfigLocation, (_ConfigFolder + ConfigName).c_str());
#if _UNICODE
    strcpy_s(_ImGuiConfigLocation, ws2s(_ConfigFolder + ImGuiConfigName).c_str());
#else
    strcpy_s(_ImGuiConfigLocation, (_ConfigFolder + ImGuiConfigName).c_str());
#endif
    SHCreateDirectoryEx(nullptr, _ConfigFolder.c_str(), nullptr);

    // Load INI settings
    _INI.SetUnicode();
    _INI.LoadFile(_ConfigLocation);
    _ResetCursorOnLockedKeybind = _INI.GetBoolValue("General", "reset_cursor_on_locked_keybind", _ResetCursorOnLockedKeybind);
    _LockCameraWhenOverlayed = _INI.GetBoolValue("General", "lock_camera_when_overlayed", _LockCameraWhenOverlayed);
    _OverlayDelayMilliseconds = _INI.GetLongValue("General", "overlay_delay_ms", _OverlayDelayMilliseconds);
    _OverlayScale = (float)_INI.GetDoubleValue("General", "overlay_scale", _OverlayScale);
    _shubiaoPOSX = (float)_INI.GetDoubleValue("shubiao", "shubiaoPOSX", _shubiaoPOSX);
    _shubiaoPOSY = (float)_INI.GetDoubleValue("shubiao", "shubiaoPOSY", _shubiaoPOSY);
    _shubiaoRED = (float)_INI.GetDoubleValue("shubiao", "shubiaoRED", _shubiaoRED);
    _shubiaoGRE = (float)_INI.GetDoubleValue("shubiao", "shubiaoGRE", _shubiaoGRE);
    _shubiaoBLU = (float)_INI.GetDoubleValue("shubiao", "shubiaoBLU", _shubiaoBLU);
    _shubiaoALH = (float)_INI.GetDoubleValue("shubiao", "shubiaoALH", _shubiaoALH);
    _OverlayDeadZoneScale = (float)_INI.GetDoubleValue("General", "overlay_dead_zone_scale", _OverlayDeadZoneScale);
    _OverlayDeadZoneBehavior = _INI.GetLongValue("General", "overlay_dead_zone_behavior", _OverlayDeadZoneBehavior);
    _FavoriteMount = (MountType)_INI.GetLongValue("General", "favorite_mount", (int)_FavoriteMount);

    const char* keys = _INI.GetValue("Keybinds", "mount_wheel", nullptr);
    LoadKeybindString(keys, _MountOverlayKeybind);
    const char* keys_locked = _INI.GetValue("Keybinds", "mount_wheel_locked", nullptr);
    LoadKeybindString(keys_locked, _MountOverlayLockedKeybind);

    for (uint i = 0; i < MountTypeCount; i++)
    {
        const char* keys_mount = _INI.GetValue("Keybinds", ("mount_" + std::to_string(i)).c_str(), nullptr);
        LoadKeybindString(keys_mount, _MountKeybinds[i]);
    }
}

void Config::shubiaoPOSSave(float _shubiaoPOSX, float _shubiaoPOSY)
{
    _INI.SetDoubleValue("shubiao", "shubiaoPOSX", _shubiaoPOSX);
    Save();
    _INI.SetDoubleValue("shubiao", "shubiaoPOSY", _shubiaoPOSY);
    Save();
}
void Config::shubiaoRGBASave(float _shubiaoRED, float _shubiaoGRE, float _shubiaoBLU, float _shubiaoALH)
{
    _INI.SetDoubleValue("shubiao", "shubiaoRED", _shubiaoRED);
    Save();
    _INI.SetDoubleValue("shubiao", "shubiaoGRE", _shubiaoGRE);
    Save();
    _INI.SetDoubleValue("shubiao", "shubiaoBLU", _shubiaoBLU);
    Save();
    _INI.SetDoubleValue("shubiao", "shubiaoALH", _shubiaoALH);
    Save();
}



void Config::MountOverlayKeybind(const std::set<uint>& val)
{
    _MountOverlayKeybind = val;
    std::string setting_value = "";
    for (const auto& k : _MountOverlayKeybind)
        setting_value += std::to_string(k) + ", ";

    _INI.SetValue("Keybinds", "mount_wheel", (setting_value.size() > 0 ? setting_value.substr(0, setting_value.size() - 2) : setting_value).c_str());
    Save();
}

void Config::MountOverlayLockedKeybind(const std::set<uint>& val)
{
    _MountOverlayLockedKeybind = val;
    std::string setting_value = "";
    for (const auto& k : _MountOverlayLockedKeybind)
        setting_value += std::to_string(k) + ", ";

    _INI.SetValue("Keybinds", "mount_wheel_locked", (setting_value.size() > 0 ? setting_value.substr(0, setting_value.size() - 2) : setting_value).c_str());
    Save();
}

void Config::MountKeybind(uint i, const std::set<uint>& val)
{
    _MountKeybinds[i] = val;
    std::string setting_value = "";
    for (const auto& k : _MountKeybinds[i])
        setting_value += std::to_string(k) + ", ";

    _INI.SetValue("Keybinds", ("mount_" + std::to_string(i)).c_str(), (setting_value.size() > 0 ? setting_value.substr(0, setting_value.size() - 2) : setting_value).c_str());
    Save();
}

void Config::ResetCursorOnLockedKeybindSave()
{
    _INI.SetBoolValue("General", "reset_cursor_on_locked_keybind", _ResetCursorOnLockedKeybind);
    Save();
}

void Config::LockCameraWhenOverlayedSave()
{
    _INI.SetBoolValue("General", "lock_camera_when_overlayed", _LockCameraWhenOverlayed);
    Save();
}

void Config::OverlayDelayMillisecondsSave()
{
    _INI.SetLongValue("General", "overlay_delay_ms", _OverlayDelayMilliseconds);
    Save();
}

void Config::OverlayScaleSave()
{
    _INI.SetDoubleValue("General", "overlay_scale", _OverlayScale);
    Save();
}

void Config::OverlayDeadZoneScaleSave()
{
    _INI.SetDoubleValue("General", "overlay_dead_zone_scale", _OverlayDeadZoneScale);
    Save();
}

void Config::OverlayDeadZoneBehaviorSave()
{
    _INI.SetLongValue("General", "overlay_dead_zone_behavior", _OverlayDeadZoneBehavior);
    Save();
}

void Config::FavoriteMountSave()
{
    _INI.SetLongValue("General", "favorite_mount", (int)_FavoriteMount);
    Save();
}

void Config::Save()
{
    auto r = _INI.SaveFile(_ConfigLocation);

    if (r < 0)
    {
        switch (r)
        {
        case SI_FAIL:
            _LastSaveError = "Unknown error";
            break;
        case SI_NOMEM:
            _LastSaveError = "Out of memory";
            break;
        case SI_FILE:
            char buf[1024];
            if (strerror_s(buf, errno) == 0)
                _LastSaveError = buf;
            else
                _LastSaveError = "Unknown error";
        }
    }
    else
        _LastSaveError.clear();

    _LastSaveErrorChanged = true;
}