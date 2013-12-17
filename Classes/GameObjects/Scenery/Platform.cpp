#include "Platform.h"

Platform::Platform()
{
	xVelocity = 0;
	yVelocity = 0;
}

Platform::~Platform()
{

}

void Platform::DefaultInit(b2World* _world)
{
	mBodyDef = new b2BodyDef();
	mBodyDef->type = b2_dynamicBody;
	mBodyDef->position.Set(CCDirector::sharedDirector()->getWinSize().width/2/PTM_RATIO, 50/PTM_RATIO);
	//mBodyDef->userData =

	mBody = _world->CreateBody(mBodyDef);

	mFixtureDef = new b2FixtureDef();
	mFixtureDef->density = 10.0f;
	mFixtureDef->friction = 0.4f;
	mFixtureDef->restitution = 0.1f;

	mFixture = mBody->CreateFixture(mFixtureDef);
}