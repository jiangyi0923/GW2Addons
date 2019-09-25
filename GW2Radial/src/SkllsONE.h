#pragma once
#include <Main.h>
#include <WheelElement.h>

namespace GW2Radial
{

	enum class SkllsONEType : uint
	{
		//NONE = 0xFFFFFFFF,
		SKLL1 = IDR_SKLL1,
		SKLL2 = IDR_SKLL2,
		SKLL3 = IDR_SKLL3,
		SKLL4 = IDR_SKLL4,
		SKLL5 = IDR_SKLL5,
		SKLL6 = IDR_SKLL6,
		SKLL7 = IDR_SKLL7,
		SKLL8 = IDR_SKLL8,
		SKLL9 = IDR_SKLL9,
		SKLL0 = IDR_SKLL0,

		//FIRST = SKLL1,
		//LAST = SKLL0
	};

	class SkllsONE : public WheelElement
	{
	public:
		SkllsONE(SkllsONEType m, IDirect3DDevice9* dev);

		std::array<float, 4> color() override;
	};


	//const unsigned int SkllsONETypeCount = 10;

	//class SkllsONE : public WheelElement
	//{
	//public:
	//	SkllsONE(SkllsONEType m, IDirect3DDevice9* dev);

	//	//static void AddAllNovelties(class Wheel* w, IDirect3DDevice9* dev);

	//protected:
	//	static const char* GetSkllsONENameFromType(SkllsONEType m)
	//	{
	//		switch (m)
	//		{
	//		case SkllsONEType::SKLL1:
	//			return u8"技能1";
	//		case SkllsONEType::SKLL2:
	//			return u8"技能2";
	//		case SkllsONEType::SKLL3:
	//			return u8"技能3";
	//		case SkllsONEType::SKLL4:
	//			return u8"技能4";
	//		case SkllsONEType::SKLL5:
	//			return u8"技能5";
	//		case SkllsONEType::SKLL6:
	//			return u8"技能10";
	//		case SkllsONEType::SKLL7:
	//			return u8"技能J";
	//		case SkllsONEType::SKLL8:
	//			return u8"技能Q";
	//		case SkllsONEType::SKLL9:
	//			return u8"技能K";
	//		case SkllsONEType::SKLL0:
	//			return u8"技能A";
	//		default:
	//			return "[Unknown]";
	//		}
	//	}
	//	static const char* GetSkllsONENicknameFromType(SkllsONEType m)
	//	{
	//		switch (m)
	//		{
	//		case SkllsONEType::SKLL1:
	//			return "SKLL1";
	//		case SkllsONEType::SKLL2:
	//			return "SKLL2";
	//		case SkllsONEType::SKLL3:
	//			return "SKLL3";
	//		case SkllsONEType::SKLL4:
	//			return "SKLL4";
	//		case SkllsONEType::SKLL5:
	//			return "SKLL5";
	//		case SkllsONEType::SKLL6:
	//			return "SKLL10";
	//		case SkllsONEType::SKLL7:
	//			return "SKLLJ";
	//		case SkllsONEType::SKLL8:
	//			return "SKLLQ";
	//		case SkllsONEType::SKLL9:
	//			return "SKLLK";
	//		case SkllsONEType::SKLL0:
	//			return "SKLLA";
	//		default:
	//			return "unknown";
	//		}
	//	}

	//	std::array<float, 4> color() override;
	//};

}