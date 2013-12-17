#include "StateMachine.h"
#include "../Entity/BaseGameEntity.h"

using namespace MOC::Entity;

namespace MOC
{
namespace FiniteStateMachine
{

StateMachine::StateMachine(BaseGameEntity* owner):mOwner(owner),
	mCurrentState(NULL),
	mPreviousState(NULL),
	mGlobalState(NULL) {}

StateMachine::~StateMachine()
{
	delete mCurrentState;
	delete mPreviousState;
	delete mGlobalState;

	mCurrentState = NULL;
	mPreviousState = NULL;
	mGlobalState = NULL;
}

//call this to update the FSM
void  StateMachine::Update()const
{
	//if a global state exists, call its execute method, else do nothing
	if(mGlobalState)
		mGlobalState->Execute(mOwner);
	//same for the current state
	if (mCurrentState)
		mCurrentState->Execute(mOwner);
}

bool StateMachine::HandleMessage(const Message& msg)const
{
	//first see if the current state is valid and that it can handle
	//the message
	if (mCurrentState && mCurrentState->OnMessage(mOwner, msg))
	{
		return true;
	}
	//if not, and if a global state has been implemented, send 
	//the message to the global state
	if (mGlobalState && mGlobalState->OnMessage(mOwner, msg))
	{
		return true;
	}

	return false;
}

//change to a new state
void StateMachine::ChangeState(State* pNewState)
{
	//CCAssert(pNewState && "<StateMachine::ChangeState>:trying to assign null state to current");

	//keep a record of the previous state
	mPreviousState = mCurrentState;
	
	//call the exit method of the existing state
	mCurrentState->Exit(mOwner);

	//change state to the new state
	mCurrentState = pNewState;

	//call the entry method of the new state
	mCurrentState->Enter(mOwner);
}

//change state back to the previous state
void StateMachine::RevertToPreviousState()
{
	ChangeState(mPreviousState);
}
	
//returns true if the current state's type is equal to the type of the
//class passed as a parameter. 
bool StateMachine::isInState(const State& st)const
{
	if (typeid(*mCurrentState) == typeid(st)) return true;
	return false;
}

//only ever used during debugging to grab the name of the current state
std::string StateMachine::GetNameOfCurrentState()const
{
	std::string s(typeid(*mCurrentState).name());
		
	//remove the 'class ' part from the front of the string
	if (s.size() > 5)
	{
		s.erase(0, 6);
	}
		
	return s;
	}
}
}