#pragma once
#include <Main.h>
#include <WheelElement.h>

namespace GW2Radial
{

enum class MountType : uint
{
	NONE = 0xFFFFFFFF,
	RAPTOR = IDR_MOUNT1,
	SPRINGER = IDR_MOUNT2,
	SKIMMER = IDR_MOUNT3,
	JACKAL = IDR_MOUNT4,
	BEETLE = IDR_MOUNT5,
	GRIFFON = IDR_MOUNT6,
	WARCLAW = IDR_MOUNT7,
    SKYSCALE = IDR_MOUNT8,

	FIRST = RAPTOR,
	LAST = SKYSCALE
};
const unsigned int MountTypeCount = 7;

class Mount : public WheelElement
{
public:
	Mount(MountType m, IDirect3DDevice9* dev);

	bool isActive() const override;

protected:
	static const char* GetMountNameFromType(MountType m)
	{
		switch (m)
		{
		case MountType::RAPTOR:
			return u8"ÄñÁú";
		case MountType::SPRINGER:
			return u8"ÍÃ×Ó";
		case MountType::SKIMMER:
			return u8"·ÉÓã";
		case MountType::JACKAL:
			return u8"É³ÀÇ";
		case MountType::BEETLE:
			return u8"¼×³æ";
		case MountType::GRIFFON:
			return u8"Ê¨ðÕ";
		case MountType::WARCLAW:
			return u8"Õ½×¦";
		case MountType::SKYSCALE:
			return u8"ÁÛÁú";
		default:
			return "[Unknown]";
		}
	}
	static const char* GetMountNicknameFromType(MountType m)
	{
		switch (m)
		{
		case MountType::RAPTOR:
			return "raptor";
		case MountType::SPRINGER:
			return "springer";
		case MountType::SKIMMER:
			return "skimmer";
		case MountType::JACKAL:
			return "jackal";
		case MountType::BEETLE:
			return "beetle";
		case MountType::GRIFFON:
			return "griffon";
		case MountType::WARCLAW:
			return "warclaw";
        case MountType::SKYSCALE:
            return "skyscale";
		default:
			return "unknown";
		}
	}

	std::array<float, 4> color() override;
};

}