#ifndef __STATE_H__
#define __STATE_H__

#include "../Messaging/Message.h"
#include "../Entity/BaseGameEntity.h"

using namespace MOC::Messaging;

namespace MOC
{

namespace Entity
{
	class BaseGameEntity;
}

namespace FiniteStateMachine
{
class State
{
public:
	virtual ~State(){}
	virtual void Enter(Entity::BaseGameEntity* entity) = 0;
	virtual void Execute(Entity::BaseGameEntity* entity) = 0;
	virtual void Exit(Entity::BaseGameEntity* entity) = 0;
	virtual bool OnMessage(Entity::BaseGameEntity* entity, const Message& msg) = 0;
};
}
}

#endif //__STATE_H__