#pragma once
#include <Main.h>
#include <WheelElement.h>
namespace GW2Radial
{

	enum class SkllsTOWType : uint
	{
		NTOW = 0xFFFFFFFF,
		SKLL6 = IDR_SKLL6,
		SKLL7 = IDR_SKLL7,
		SKLL8 = IDR_SKLL8,
		SKLL9 = IDR_SKLL9,
		SKLL0 = IDR_SKLL0,

		FIRST = SKLL6,
		LAST = SKLL0
	};
	const unsigned int SkllsTOWTypeCount = 6;

	class SkllsTOW : public WheelElement
	{
	public:
		SkllsTOW(SkllsTOWType m, IDirect3DDevice9* dev);

		//static void AddAllNovelties(class Wheel* w, IDirect3DDevice9* dev);

	protected:
		static const char* GetSkllsTOWNameFromType(SkllsTOWType m)
		{
			switch (m)
			{
			case SkllsTOWType::SKLL6:
				return u8"����10";
			case SkllsTOWType::SKLL7:
				return u8"����J";
			case SkllsTOWType::SKLL8:
				return u8"����Q";
			case SkllsTOWType::SKLL9:
				return u8"����K";
			case SkllsTOWType::SKLL0:
				return u8"����A";
			default:
				return "[Unknown]";
			}
		}
		static const char* GetSkllsTOWNicknameFromType(SkllsTOWType m)
		{
			switch (m)
			{
			case SkllsTOWType::SKLL6:
				return "SKLL10";
			case SkllsTOWType::SKLL7:
				return "SKLLJ";
			case SkllsTOWType::SKLL8:
				return "SKLLQ";
			case SkllsTOWType::SKLL9:
				return "SKLLK";
			case SkllsTOWType::SKLL0:
				return "SKLLA";
			default:
				return "unknown";
			}
		}

		std::array<float, 4> color() override;
	};

}