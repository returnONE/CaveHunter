#ifndef __BASE_GAME_ENTITY_H__
#define __BASE_GAME_ENTITY_H__

#include "../Messaging/Message.h"
#include "../FSM/StateMachine.h"
#include "cocos2d.h"

using namespace MOC::Messaging;
USING_NS_CC;

namespace MOC
{

namespace FiniteStateMachine
{
	class StateMachine;
}

namespace Entity
{
class BaseGameEntity
{
protected:
	int mId;
	//every entity has a type associated with it (health, troll, ammo etc)
	int mType;
	//this is a generic flag. 
	bool mTag;
	FiniteStateMachine::StateMachine* mFSM;
	CCNode* mParent;
	static int sNextValidId;

public:
	BaseGameEntity(CCNode* parent);
	~BaseGameEntity();

public:
	virtual bool HandleMessage(const Message& msg);
	virtual void Update();

	int GetId() const { return mId; }
	void SetId(int val) { mId = val; }
	int GetType() const { return mType; }
	void SetType(int val) { mType = val; }
	bool IsTagged() const { return mTag; }
	void Tag(bool val) { mTag = val; }
	FiniteStateMachine::StateMachine* GetFSM() const { return mFSM; }
	CCNode* GetParent() const { return mParent; }

};
}
}

#endif //__BASE_GAME_ENTITY_H__