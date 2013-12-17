#ifndef __TIME_COUNTER_H__
#define __TIME_COUNTER_H__

namespace MOC
{
namespace Utils
{
	class TimeCounter
	{
	private:
		double mTotalFrames;
		double mTotalTime;
	private:
		TimeCounter();
	public:
		static TimeCounter* Instance();
		void Update(float dt);

		double TotalFrames() const { return mTotalFrames; }
		double TotalTime() const { return mTotalTime; }
	};
}
}

#endif //__TIME_COUNTER_H__