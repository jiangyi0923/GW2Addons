#pragma once
#include <Main.h>
#include <Singleton.h>

namespace GW2Radial
{

class MumbleLink : public Singleton<MumbleLink>
{
public:
	MumbleLink();
	~MumbleLink();

	bool isWvW() const;
	//unsigned int id() const;
	//float* fp() const;
	//float* fpF() const;
	//float* fpT() const;
	//float* ap() const;
	//float* apF() const;
	//float* apT() const;



protected:
	const struct MumbleContext* context() const;
	
	HANDLE fileMapping_ = nullptr;
	struct LinkedMem* linkedMemory_ = nullptr;
};

}