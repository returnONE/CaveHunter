#include "MessageDispatcher.h"
#include "../Entity/EntityManager.h"
#include "../Utils/TimeCounter.h"
//uncomment below to send message info to the debug window

using namespace MOC::Entity;

namespace MOC
{
namespace Messaging
{

MessageDispatcher* MessageDispatcher::Instance()
{
	static MessageDispatcher instance; 

	return &instance;
}

void MessageDispatcher::Discharge(BaseGameEntity* pReceiver, const Message& message)
{
	if (!pReceiver->HandleMessage(message))
	{
		//message could not be handled
	}
}

void MessageDispatcher::DispatchMsg(double       delay,
	int          sender,
	int          receiver,
	int          msg,
	void*        AdditionalInfo = NULL)
{

	//get a pointer to the receiver
	BaseGameEntity* pReceiver = Entity::EntityManager::Instance()->GetEntity(receiver);

	//make sure the receiver is valid
	if (pReceiver == NULL)
	{
		return;
	}

	//create the message
	Message message(0, sender, receiver, msg, AdditionalInfo);

	//if there is no delay, route message immediately                       
	if (delay <= 0.0)                                                        
	{
		//send the message to the recipient
		Discharge(pReceiver, message);
	}

	//else calculate the time when the message should be dispatched
	else
	{
		double CurrentTime = Utils::TimeCounter::Instance()->TotalFrames(); 

		message.SetDispatchTime(CurrentTime + delay);

		//and put it in the queue
		mPriorityQ.insert(message);   
	}
}

//---------------------- DispatchDelayedMessages -------------------------
//
//  This function dispatches any messages with a timestamp that has
//  expired. Any dispatched messages are removed from the queue
//------------------------------------------------------------------------
void MessageDispatcher::DispatchDelayedMessages()
{ 
	//first get current time
	double CurrentTime = Utils::TimeCounter::Instance()->TotalFrames(); 

	//now peek at the queue to see if any messages need dispatching.
	//remove all messages from the front of the queue that have gone
	//past their sell by date
	while( !mPriorityQ.empty() &&
		(mPriorityQ.begin()->GetDispatchTime() < CurrentTime) && 
		(mPriorityQ.begin()->GetDispatchTime() > 0) )
	{
		//read the message from the front of the queue
		const Message& message = *mPriorityQ.begin();

		//find the recipient
		BaseGameEntity* pReceiver = EntityManager::Instance()->GetEntity(message.GetReceiver());

		//send the message to the recipient
		Discharge(pReceiver, message);

		//remove it from the queue
		mPriorityQ.erase(mPriorityQ.begin());
	}
}

} //namespace Messaging
} //namespace MOC