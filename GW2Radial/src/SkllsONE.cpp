#include "SkllsONE.h"
#include <Wheel.h>

namespace GW2Radial
{

	SkllsONE::SkllsONE(SkllsONEType m, IDirect3DDevice9* dev)
		: WheelElement(uint(m), std::string("SkllsONE_") + GetSkllsONENicknameFromType(m), "Mounts", GetSkllsONENameFromType(m), dev)
	{ }

	void SkllsONE::AddAllNovelties(Wheel* w, IDirect3DDevice9* dev)
	{
		for (auto i = SkllsONEType::FIRST; i <= SkllsONEType::LAST; i = SkllsONEType(uint(i) + 1))
			w->AddElement(std::make_unique<SkllsONE>(i, dev));
	}

	std::array<float, 4> SkllsONE::color()
	{
		auto mt = SkllsONEType(elementId_);
		switch (mt)
		{
		case SkllsONEType::SKLL1:
			return { 213 / 255.f, 100 / 255.f, 89 / 255.f, 1 };
		case SkllsONEType::SKLL2:
			return { 212 / 255.f, 198 / 255.f, 94 / 255.f, 1 };
		case SkllsONEType::SKLL3:
			return { 108 / 255.f, 128 / 255.f, 213 / 255.f, 1 };
		case SkllsONEType::SKLL4:
			return { 120 / 255.f, 183 / 255.f, 197 / 255.f, 1 };
		case SkllsONEType::SKLL5:
			return { 199 / 255.f, 131 / 255.f, 68 / 255.f, 1 };
		default:
			return { 1, 1, 1, 1 };
		}
	}

}
