#include "BaseGameEntity.h"

#include "EntityManager.h"

namespace MOC
{
namespace Entity
{
int BaseGameEntity::sNextValidId = 0;

BaseGameEntity::BaseGameEntity(CCNode* parent) : mParent(parent)
{
	mId = sNextValidId++;
	mFSM =  new FiniteStateMachine::StateMachine(this);
	EntityManager::Instance()->Register(this);
}

BaseGameEntity::~BaseGameEntity()
{
	delete mFSM;
	mFSM = NULL;
}

void BaseGameEntity::Update()
{
	mFSM->Update();
}

bool BaseGameEntity::HandleMessage(const Message& msg)
{
	return mFSM->HandleMessage(msg);
}

}
}
