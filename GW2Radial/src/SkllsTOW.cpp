#include "SkllsTOW.h"
#include <Wheel.h>

namespace GW2Radial
{

	SkllsTOW::SkllsTOW(SkllsTOWType m, IDirect3DDevice9* dev)
		: WheelElement(uint(m), std::string("SkllsTOW_") + GetSkllsTOWNicknameFromType(m), "Mounts", GetSkllsTOWNameFromType(m), dev)
	{ }

	template<>
	void Wheel::Setup<SkllsTOW>(IDirect3DDevice9* dev)
	{
		for (auto i = SkllsTOWType::FIRST; i <= SkllsTOWType::LAST; i = SkllsTOWType(uint(i) + 1))
			AddElement(std::make_unique<SkllsTOW>(i, dev));
	}

	std::array<float, 4> SkllsTOW::color()
	{
		auto mt = SkllsTOWType(elementId_);
		switch (mt)
		{
		case SkllsTOWType::SKLL6:
			return { 213 / 255.f, 100 / 255.f, 89 / 255.f, 1 };
		case SkllsTOWType::SKLL7:
			return { 212 / 255.f, 198 / 255.f, 94 / 255.f, 1 };
		case SkllsTOWType::SKLL8:
			return { 108 / 255.f, 128 / 255.f, 213 / 255.f, 1 };
		case SkllsTOWType::SKLL9:
			return { 120 / 255.f, 183 / 255.f, 197 / 255.f, 1 };
		case SkllsTOWType::SKLL0:
			return { 199 / 255.f, 131 / 255.f, 68 / 255.f, 1 };
		default:
			return { 1, 1, 1, 1 };
		}
	}

}