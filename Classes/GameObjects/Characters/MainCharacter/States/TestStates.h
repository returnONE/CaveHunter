#ifndef __TEST_STATES_H__
#define __TEST_STATES_H__

#include "DTech/FiniteStateMachine/FSM/State.h"
#include "DTech/FiniteStateMachine/Entity/BaseGameEntity.h"

using namespace MOC::Entity;
using namespace MOC::FiniteStateMachine;

class TestStateA : public State
{
	virtual void Enter(BaseGameEntity* entity);
	virtual void Execute(BaseGameEntity* entity);
	virtual void Exit(BaseGameEntity* entity);
	virtual bool OnMessage(BaseGameEntity* entity, const Message& msg);
};

class TestStateB : public State
{
	virtual void Enter(BaseGameEntity* entity);
	virtual void Execute(BaseGameEntity* entity);
	virtual void Exit(BaseGameEntity* entity);
	virtual bool OnMessage(BaseGameEntity* entity, const Message& msg);
};

#endif //__TEST_STATES_H__