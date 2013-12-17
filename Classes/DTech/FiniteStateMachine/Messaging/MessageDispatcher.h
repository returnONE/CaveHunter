#ifndef __MESSAGE_DISPATCHER_H__
#define __MESSAGE_DISPATCHER_H__

#include "Message.h"
#include "cocos2d.h"
#include "../Entity/BaseGameEntity.h"

#define SEND_MSG_IMMEDIATELY  0.0
#define NO_ADDITIONAL_INFO    0
#define SENDER_ID_IRRELEVANT -1

USING_NS_CC;
using namespace std;
using namespace MOC::Entity;
//class BaseGameEntity;

namespace MOC
{
namespace Messaging
{
class MessageDispatcher
{
private:
	//a std::set is used as the container for the delayed messages
	//because of the benefit of automatic sorting and avoidance
	//of duplicates. Messages are sorted by their dispatch time.
	set<Message> mPriorityQ;

private:
	//this method is utilized by DispatchMsg or DispatchDelayedMessages.
	//This method calls the message handling member function of the receiving
	//entity, pReceiver, with the newly created telegram
	void Discharge(BaseGameEntity* pReceiver, const Message& msg);

	MessageDispatcher(){}

	//copy ctor and assignment should be private
	MessageDispatcher(const MessageDispatcher&);
	MessageDispatcher& operator=(const MessageDispatcher&);
public:
	static MessageDispatcher* Instance();

	//send a message to another agent. Receiving agent is referenced by ID.
	void DispatchMsg(double      delay,
		int         sender,
		int         receiver,
		int         msg,
		void*       ExtraInfo);

	//send out any delayed messages. This method is called each time through   
	//the main game loop.
	void DispatchDelayedMessages();
};
}
}

#endif __MESSAGE_DISPATCHER_H__