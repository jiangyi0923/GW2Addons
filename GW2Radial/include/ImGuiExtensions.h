#pragma once
#include <Main.h>
#include <imgui.h>
#include <Keybind.h>
#include <ConfigurationOption.h>

ImVec2 operator*(const ImVec2& a, const ImVec2& b);
ImVec2 operator*(const ImVec2& a, float b);
ImVec2 operator-(const ImVec2& a, const ImVec2& b);
ImVec2 operator*=(ImVec2& a, const ImVec2& b);

ImVec4 operator/(const ImVec4& v, float f);
void ImGuiKeybindInput(GW2Radial::Keybind& setting);

template<typename F, typename T, typename... Args>
void ImGuiConfigurationWrapper(F fct, const char* name, GW2Radial::ConfigurationOption<T>& value, Args&&... args)
{
	if(fct(name, &value.value(), std::forward<Args>(args)...))
		value.ForceSave();
}
//===================================================
template<typename F, typename T>
void ImGuiConfigurationWrapper(F fct, GW2Radial::ConfigurationOption<T>& value, float args, float args2)
{
	if (fct(value.displayName().c_str(), &value.value(), args, args2, "", 1.0f))
		value.ForceSave();
}

template<typename F, typename T, typename... Args>
void ImGuiConfigurationWrapper(F fct, const char* name, GW2Radial::ConfigurationOption<T>& value1, GW2Radial::ConfigurationOption<T>& value2, Args&& ... args)
{
	float vec4f[2];
	vec4f[0] = value1.value();
	vec4f[1] = value2.value();
	if (fct(name, vec4f, std::forward<Args>(args)...))
		value1.value() = vec4f[0], value1.ForceSave(),
		value2.value() = vec4f[1], value2.ForceSave();
}

template<typename F, typename T, typename... Args>
void ImGuiConfigurationWrapper(F fct, const char* name,
	GW2Radial::ConfigurationOption<T>& value0,
	GW2Radial::ConfigurationOption<T>& value1,
	GW2Radial::ConfigurationOption<T>& value2,
	GW2Radial::ConfigurationOption<T>& value3,
	Args&& ... args)
{
	float vec4f[4];
	vec4f[0] = value0.value();
	vec4f[1] = value1.value();
	vec4f[2] = value2.value();
	vec4f[3] = value3.value();
	if (fct(name, vec4f, std::forward<Args>(args)...))
		value0.value() = vec4f[0], value0.ForceSave(),
		value1.value() = vec4f[1], value1.ForceSave(),
		value2.value() = vec4f[2], value2.ForceSave(),
		value3.value() = vec4f[3], value3.ForceSave();
}
//========================================================
template<typename F, typename T, typename... Args>
void ImGuiConfigurationWrapper(F fct, GW2Radial::ConfigurationOption<T>& value, Args&&... args)
{
	if(fct(value.displayName().c_str(), &value.value(), std::forward<Args>(args)...))
		value.ForceSave();
}

inline void ImGuiIndent()
{
	ImGui::Indent(ImGui::GetStyle().FramePadding.x * 2 + ImGui::GetFontSize());
}

inline void ImGuiUnindent()
{
	ImGui::Unindent(ImGui::GetStyle().FramePadding.x * 2 + ImGui::GetFontSize());
}

inline void ImGuiSpacing()
{
	ImGui::Dummy(ImVec2(1, 5));
}

void ImGuiTitle(const char* text);