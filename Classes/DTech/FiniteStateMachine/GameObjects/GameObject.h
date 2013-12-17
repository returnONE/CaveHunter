#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include "cocos2d.h"
#include "../Entity/BaseGameEntity.h"
#include "../FSM/State.h"

USING_NS_CC;
using namespace MOC::Entity;
using namespace MOC::FiniteStateMachine;

namespace MOC
{
namespace GameObjects
{
class GameObject : public Sprite
{
protected:
	BaseGameEntity* mEntity;
	
public:
	virtual bool init();
	virtual void initWithInitialState(const char *pszFileName, State* initialState);
	virtual void initWithGlobalState(const char *pszFileName, State* initialState, State* globalState);

	static GameObject* create(const char *pszFileName);
	static GameObject* create(const char *pszFileName, State* initialState);
	static GameObject* create(const char *pszFileName, State* initialState, State* globalState);

	virtual void update(float dt);

	virtual void release();

	BaseGameEntity* GetEntity() const { return mEntity; }
	void SetEntity(BaseGameEntity* val) { mEntity = val; }
};
}
}

#endif //__GAME_OBJECT_H__