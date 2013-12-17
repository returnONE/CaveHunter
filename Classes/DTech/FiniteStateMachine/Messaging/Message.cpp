#include "Message.h"

namespace MOC
{
namespace Messaging
{

Message::Message(double time,
	int sender,
	int receiver,
	int msg,
	void* info) : mDispatchTime(time),
	mSender(sender), mReceiver(receiver),
	mMessage(msg), mExtraInfo(info)
{
}

bool Message::operator==(const Message &other) const
{
	return ( fabs(mDispatchTime - other.GetDispatchTime()) < SMALLEST_DELAY) &&
		(mSender == other.GetSender()) &&
		(mReceiver == other.GetReceiver()) &&
		(mMessage == other.GetMessage());
}

bool Message::operator<(const Message &other) const
{
	if (*this == other)
	{
		return false;
	}
	else
	{
		return  (mDispatchTime < other.GetDispatchTime());
	}
}

}
}