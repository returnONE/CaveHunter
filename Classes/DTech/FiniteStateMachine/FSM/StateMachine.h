#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include "../Entity/BaseGameEntity.h"
#include "State.h"
#include "../Messaging/Message.h"

//using namespace MOC::Entity;

namespace MOC
{

namespace Entity
{
	class BaseGameEntity;
}

namespace FiniteStateMachine
{

class State;

class StateMachine
{
private:
	//a pointer to the agent that owns this instance
	Entity::BaseGameEntity*          mOwner;

	State*   mCurrentState;

	//a record of the last state the agent was in
	State*   mPreviousState;

	//this is called every time the FSM is updated
	State*   mGlobalState;


public:

	StateMachine(Entity::BaseGameEntity* owner);
	virtual ~StateMachine();

	//use these methods to initialize the FSM
	void SetCurrentState(State* s){mCurrentState = s;}
	void SetGlobalState(State* s) {mGlobalState = s;}
	void SetPreviousState(State* s){mPreviousState = s;}

	//call this to update the FSM
	void  Update()const;

	bool  HandleMessage(const Messaging::Message& msg)const;

	//change to a new state
	void  ChangeState(State* pNewState);

	//change state back to the previous state
	void  RevertToPreviousState();

	//returns true if the current state's type is equal to the type of the
	//class passed as a parameter. 
	bool  isInState(const State& st)const;

	State*  CurrentState()  const{return mCurrentState;}
	State*  GlobalState()   const{return mGlobalState;}
	State*  PreviousState() const{return mPreviousState;}

	//only ever used during debugging to grab the name of the current state
	std::string         GetNameOfCurrentState()const;
};
}
}

#endif //__STATE_MACHINE_H__