#include "SkllsONE.h"
#include <Wheel.h>

namespace GW2Radial
{

	std::map<SkllsONEType, std::tuple<std::string, std::string, std::array<float, 4>>> data
	{
		{ SkllsONEType::SKLL1,   { "SKLL1",      u8"技能1",        { 186 / 255.f, 237 / 255.f, 126 / 255.f, 1 } } },
		{ SkllsONEType::SKLL2,   { "SKLL2",      u8"技能2",        { 107 / 255.f,  24 / 255.f, 181 / 255.f, 1 } } },
		{ SkllsONEType::SKLL3,   { "SKLL3",      u8"技能3",        { 222 / 255.f,  40 / 255.f,  41 / 255.f, 1 } } },
		{ SkllsONEType::SKLL4,   { "SKLL4",      u8"技能4",        {  57 / 255.f, 134 / 255.f, 231 / 255.f, 1 } } },
		{ SkllsONEType::SKLL5,	 { "SKLL5",      u8"技能5",        {  27 / 255.f, 181 / 255.f,  68 / 255.f, 1 } } },
		{ SkllsONEType::SKLL6,	 { "SKLL6",      u8"技能10",       { 140 / 255.f, 239 / 255.f, 236 / 255.f, 1 } } },
		{ SkllsONEType::SKLL7,	 { "SKLL7",      u8"技能J",        { 239 / 255.f, 121 / 255.f, 214 / 255.f, 1 } } },
		{ SkllsONEType::SKLL8,   { "SKLL8",      u8"技能Q",        { 222 / 255.f, 182 / 255.f,  33 / 255.f, 1 } } },
		{ SkllsONEType::SKLL9,   { "SKLL9",		 u8"技能K",        { 218 / 255.f, 128 / 255.f, 128 / 255.f, 1 } } },
		{ SkllsONEType::SKLL0,   { "SKLL0",      u8"技能A",        { 135 / 255.f, 237 / 255.f, 126 / 255.f, 1 } } },
	};


	SkllsONE::SkllsONE(SkllsONEType m, IDirect3DDevice9* dev)
		: WheelElement(uint(m), "SkllsONE_" + std::get<0>(data.at(m)), "SkllsONE", std::get<1>(data.at(m)), dev)
	{ }

	template<>
	void Wheel::Setup<SkllsONE>(IDirect3DDevice9* dev)
	{
		SetAlphaBlended(true);
		SetResetCursorPositionBeforeKeyPress(true);
		for (const auto& type : data)
			AddElement(std::make_unique<SkllsONE>(type.first, dev));
	}

	std::array<float, 4> SkllsONE::color()
	{
		return std::get<2>(data.at(static_cast<SkllsONEType>(elementId_)));
	}


	//SkllsONE::SkllsONE(SkllsONEType m, IDirect3DDevice9* dev)
	//	: WheelElement(uint(m), std::string("SkllsONE_") + GetSkllsONENicknameFromType(m), "Mounts", GetSkllsONENameFromType(m), dev)
	//{ }

	//template<>
	//void Wheel::Setup<SkllsONE>(IDirect3DDevice9* dev)
	//{
	//	SetAlphaBlended(true);
	//	SetResetCursorPositionBeforeKeyPress(true);
	//	for (const auto& type : SkllsONEType)
	//		AddElement(std::make_unique<SkllsONE>(type.first, dev));
	//	//for (auto i = SkllsONEType::FIRST; i <= SkllsONEType::LAST; i = SkllsONEType(uint(i) + 1))
	//	//	AddElement(std::make_unique<SkllsONE>(i, dev));
	//}

	//std::array<float, 4> SkllsONE::color()
	//{
	//	auto mt = SkllsONEType(elementId_);
	//	switch (mt)
	//	{
	//	case SkllsONEType::SKLL1:
	//		return { 213 / 255.f, 100 / 255.f, 89 / 255.f, 1 };
	//	case SkllsONEType::SKLL2:
	//		return { 212 / 255.f, 198 / 255.f, 94 / 255.f, 1 };
	//	case SkllsONEType::SKLL3:
	//		return { 108 / 255.f, 128 / 255.f, 213 / 255.f, 1 };
	//	case SkllsONEType::SKLL4:
	//		return { 120 / 255.f, 183 / 255.f, 197 / 255.f, 1 };
	//	case SkllsONEType::SKLL5:
	//		return { 199 / 255.f, 131 / 255.f, 68 / 255.f, 1 };
	//	case SkllsONEType::SKLL6:
	//		return { 213 / 255.f, 100 / 255.f, 89 / 255.f, 1 };
	//	case SkllsONEType::SKLL7:
	//		return { 212 / 255.f, 198 / 255.f, 94 / 255.f, 1 };
	//	case SkllsONEType::SKLL8:
	//		return { 108 / 255.f, 128 / 255.f, 213 / 255.f, 1 };
	//	case SkllsONEType::SKLL9:
	//		return { 120 / 255.f, 183 / 255.f, 197 / 255.f, 1 };
	//	case SkllsONEType::SKLL0:
	//		return { 199 / 255.f, 131 / 255.f, 68 / 255.f, 1 };
	//	default:
	//		return { 1, 1, 1, 1 };
	//	}
	//}

}
