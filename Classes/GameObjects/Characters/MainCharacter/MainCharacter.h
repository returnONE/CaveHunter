#ifndef __MAINCHARACTER_H__
#define __MAINCHARACTER_H__

#include "cocos2d.h"
#include "DTech/FiniteStateMachine/GameObjects/CollisionObject.h"

using namespace MOC::GameObjects;

USING_NS_CC;

class MainCharacter : public CollisionObject
{
private:
	float xVelocity;
	float yVelocity;

public:

	MainCharacter();
	~MainCharacter();

	void DefaultInit(b2World* _world);
	//static MainCharacter* Create(const char *pszFileName);
	//static MainCharacter* Create(const char *pszFileName, State* initialState);
	//static MainCharacter* Create(const char *pszFileName, State* initialState, State* globalState);
	float GetXVelocity() const { return xVelocity; }
	void SetXVelocity(float _xVelocity) { xVelocity = _xVelocity; }
	float GetYVelocity() const { return yVelocity; }
	void SetYVelocity(float _yVelocity) { yVelocity = _yVelocity; }
	
};

#endif