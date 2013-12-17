#include "TimeCounter.h"

namespace MOC
{
namespace Utils
{

TimeCounter::TimeCounter()
{
	mTotalFrames = 0;
	mTotalTime = 0;
}


TimeCounter* TimeCounter::Instance()
{
	static TimeCounter instance; 
	return &instance;
}

void TimeCounter::Update(float dt)
{
	mTotalFrames++;
	mTotalTime+=dt;
}

}
}