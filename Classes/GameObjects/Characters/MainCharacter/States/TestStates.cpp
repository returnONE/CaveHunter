#include "TestStates.h"
#include "cocos2d.h"

USING_NS_CC;

void TestStateA::Enter(BaseGameEntity* entity)
{
	CCLog("Entered TestStateA");
	CCSprite* sprite = (CCSprite*)entity->GetParent();
	sprite->runAction(CCMoveBy::create(0.5f, ccp(-10, -10)));
}

void TestStateA::Execute(BaseGameEntity* entity)
{
	CCLog("Executed TestStateA");
}

void TestStateA::Exit(BaseGameEntity* entity)
{
	CCLog("Exited TestStateA");
	delete this;
}

bool TestStateA::OnMessage(BaseGameEntity* entity, const Message& msg)
{
	switch(msg.GetMessage())
	{
	case 0:
		entity->GetFSM()->ChangeState(new TestStateB());
		return true;
	}
	return false;
}






void TestStateB::Enter(BaseGameEntity* entity)
{
	CCLog("Entered TestStateA");
	CCSprite* sprite = (CCSprite*)entity->GetParent();
	sprite->runAction(CCSequence::create(CCMoveBy::create(0.5f, ccp(10, 10)), NULL));

}

void TestStateB::Execute(BaseGameEntity* entity)
{
	CCLog("Executed TestStateA");

}

void TestStateB::Exit(BaseGameEntity* entity)
{
	CCLog("Exited TestStateA");
	delete this;
}

bool TestStateB::OnMessage(BaseGameEntity* entity, const Message& msg)
{
	switch(msg.GetMessage())
	{
	case 0:
		entity->GetFSM()->ChangeState(new TestStateA());
		return true;
	}
	return false;
}
