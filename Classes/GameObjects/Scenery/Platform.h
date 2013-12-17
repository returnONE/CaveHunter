#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include "cocos2d.h"
#include "DTech/FiniteStateMachine/GameObjects/CollisionObject.h"

using namespace MOC::GameObjects;

USING_NS_CC;

class Platform : public CollisionObject
{
private:
	float xVelocity;
	float yVelocity;

public:

	Platform();
	~Platform();

	void DefaultInit(b2World* _world);
	//static Platform* Create(const char *pszFileName);
	//static Platform* Create(const char *pszFileName, State* initialState);
	//static Platform* Create(const char *pszFileName, State* initialState, State* globalState);
	float GetXVelocity() const { return xVelocity; }
	void SetXVelocity(float _xVelocity) { xVelocity = _xVelocity; }
	float GetYVelocity() const { return yVelocity; }
	void SetYVelocity(float _yVelocity) { yVelocity = _yVelocity; }
	
};

#endif