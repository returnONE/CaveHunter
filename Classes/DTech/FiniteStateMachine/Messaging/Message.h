#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include "cocos2d.h"

//these telegrams will be stored in a priority queue. Therefore the >
//operator needs to be overloaded so that the PQ can sort the telegrams
//by time priority. Note how the times must be smaller than
//SmallestDelay apart before two Telegrams are considered unique.
#define SMALLEST_DELAY 0.25

namespace MOC
{
namespace Messaging
{
class Message
{
private:
	
	//the entity that sent this message
	int mSender;
	
	//the entity that is to receive this message
	int mReceiver;

	//the message itself. These are all enumerated in the file
	//"MessageTypes.h"
	int mMessage;
	
	//messages can be dispatched immediately or delayed for a specified amount
	//of time. If a delay is necessary this field is stamped with the time 
	//the message should be dispatched.
	double mDispatchTime;
	//any additional information that may accompany the message
	void* mExtraInfo;

public:
	Message(double time,
		int sender,
		int receiver,
		int msg,
		void* info = NULL);

	bool operator==(const Message &other) const;
	bool operator<(const Message &other) const;
	
	int GetSender() const { return mSender; }
	int GetReceiver() const { return mReceiver; }
	int GetMessage() const { return mMessage; }
	double GetDispatchTime() const { return mDispatchTime; }
	void SetDispatchTime(double val) { mDispatchTime = val; }
	void* ExtraInfo() const { return mExtraInfo; }
};
}
}

#endif