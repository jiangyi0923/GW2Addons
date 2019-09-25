#include <Marker.h>
#include <Wheel.h>

namespace GW2Radial
{

std::map<MarkerType, std::tuple<std::string, std::string, std::array<float, 4>>> data
{
	{ MarkerType::ARROW,    { "arrow",      u8"箭头",			{ 186 / 255.f, 237 / 255.f, 126 / 255.f, 1 } } },
	{ MarkerType::CIRCLE,   { "circle",     u8"圆圈",			{ 107 / 255.f,  24 / 255.f, 181 / 255.f, 1 } } },
	{ MarkerType::HEART,    { "heart",      u8"爱心",			{ 222 / 255.f,  40 / 255.f,  41 / 255.f, 1 } } },
	{ MarkerType::SQUARE,   { "square",     u8"方形",			{  57 / 255.f, 134 / 255.f, 231 / 255.f, 1 } } },
	{ MarkerType::STAR,     { "star",       u8"星形",			{  27 / 255.f, 181 / 255.f,  68 / 255.f, 1 } } },
	{ MarkerType::SPIRAL,   { "spiral",     u8"螺旋",			{ 140 / 255.f, 239 / 255.f, 236 / 255.f, 1 } } },
	{ MarkerType::TRIANGLE, { "triangle",   u8"三角",			{ 239 / 255.f, 121 / 255.f, 214 / 255.f, 1 } } },
	{ MarkerType::X,        { "x",          u8"X形",            { 222 / 255.f, 182 / 255.f,  33 / 255.f, 1 } } },
	{ MarkerType::CLEAR,    { "clear_all",  u8"清除全部",		{ 128 / 255.f, 128 / 255.f, 128 / 255.f, 1 } } },
};

Marker::Marker(MarkerType m, IDirect3DDevice9* dev)
	: WheelElement(uint(m), "marker_" + std::get<0>(data.at(m)), "Markers", std::get<1>(data.at(m)), dev)
{ }

template<>
void Wheel::Setup<Marker>(IDirect3DDevice9* dev)
{
	SetAlphaBlended(true);
	SetResetCursorPositionBeforeKeyPress(true);
	for (const auto& type : data)
		AddElement(std::make_unique<Marker>(type.first, dev));
}

std::array<float, 4> Marker::color()
{
	return std::get<2>(data.at(static_cast<MarkerType>(elementId_)));
}

ObjectMarker::ObjectMarker(MarkerType m, IDirect3DDevice9* dev)
	: WheelElement(uint(m), "object_marker_" + std::get<0>(data.at(m)), "ObjectMarkers", std::get<1>(data.at(m)), dev)
{ }

template<>
void Wheel::Setup<ObjectMarker>(IDirect3DDevice9* dev)
{
	SetAlphaBlended(true);
	for (const auto& type : data)
		AddElement(std::make_unique<ObjectMarker>(type.first, dev));
}

std::array<float, 4> ObjectMarker::color()
{
	return std::get<2>(data.at(static_cast<MarkerType>(elementId_)));
}

}