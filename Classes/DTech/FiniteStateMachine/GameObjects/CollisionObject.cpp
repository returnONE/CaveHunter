#include "CollisionObject.h"

namespace MOC
{
namespace GameObjects
{

//bool CollisionObject::init(){};

void CollisionObject::initWithGeometryDescription(const char *textureFileName, const char *geometryDescriptionFile, b2World* world, State* initialState, State* globalState)
{

}

void CollisionObject::initWithGlobalState(const char *pszFileName, b2World* world, State* initialState, State* globalState)
{

}

void CollisionObject::initWithInitialState(const char *pszFileName, b2World* world, State* initialState, int bodyType)
{
	mWorld = world;
	GameObject::initWithInitialState(pszFileName, initialState);
	this->addBodyToSprite(bodyType);
	this->schedule( schedule_selector(CollisionObject::update));
}

void CollisionObject::addBodyToSprite(int bodyType)
{
	mBodyDef = new b2BodyDef();
	mBodyDef->type = (b2BodyType)bodyType;
	mBodyDef->position.Set(this->getPositionX()/PTM_RATIO, this->getPositionY()/PTM_RATIO);
	mBodyDef->userData = this;

	mBody = mWorld->CreateBody(mBodyDef);

	b2PolygonShape spriteShape;
    spriteShape.SetAsBox(this->getContentSize().width/PTM_RATIO/2, this->getContentSize().height/PTM_RATIO/2);

	mFixtureDef = new b2FixtureDef();
	mFixtureDef->shape = &spriteShape;
	mFixtureDef->density = 10.0;
	mFixtureDef->isSensor = false;

	mFixture = mBody->CreateFixture(mFixtureDef);
}

void CollisionObject::setCollisionObjectPosition(const Point& pos)
{
	this->setPosition(pos);

	//first time positioning
	b2Vec2 b2Position = b2Vec2(this->getPositionX()/PTM_RATIO, this->getPositionY()/PTM_RATIO);
	float32 b2Angle = -1 * CC_DEGREES_TO_RADIANS(this->getRotation());
	mBody->SetTransform(b2Position, b2Angle);
}

void CollisionObject::update(float dt)
{
	bodyUpdate(dt);
	//setPosition(ccp());
}

void CollisionObject::bodyUpdate(float dt)
{
	mWorld->Step(dt, 10, 10);

	//b2Vec2 b2Position = b2Vec2(this->getPositionX()/PTM_RATIO, this->getPositionY()/PTM_RATIO);
	//float32 b2Angle = -1 * CC_DEGREES_TO_RADIANS(this->getRotation());

	//mBody->SetTransform(b2Position, b2Angle);

	this->setPosition(Point(mBody->GetPosition().x * PTM_RATIO, mBody->GetPosition().y * PTM_RATIO));
}

void CollisionObject::release()
{
	mWorld->DestroyBody(this->mBody);
    //for(b2Body *b = mWorld->GetBodyList(); b; b=b->GetNext()) {
    //    if (b->GetUserData() != NULL) {
    //        CCSprite *curSprite = (CCSprite *)b->GetUserData();
    //        if (this == curSprite) {
    //            mWorld->DestroyBody(b);
    //            break;
    //        }
    //    }
    //}
 
	//remove spritesheet child
    //[_spriteSheet removeChild:sprite cleanup:YES];
}


//CollisionObject* CollisionObject::create(const char *textureFileName, const char *geometryDescriptionFile, b2World* world, State* initialState, State* globalState)
//{
//
//}
//
//CollisionObject* CollisionObject::create(const char *pszFileName, b2World* world, State* initialState, State* globalState)
//{
//
//}
//
//CollisionObject* CollisionObject::create(const char *pszFileName, b2World* world, State* initialState)
//{
//
//}
//
//CollisionObject* CollisionObject::create(const char *pszFileName, b2World* world)
//{
//
//}
//
}
}
