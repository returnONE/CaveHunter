#ifndef __COLLISION_OBJECT_H__
#define __COLLISION_OBJECT_H__

#define PTM_RATIO 32

#include "GameObject.h"
#include "Box2D\Box2D.h"

namespace MOC
{
namespace GameObjects
{
class CollisionObject : public GameObject
{
protected:
	b2BodyDef*    mBodyDef;
	b2Body*       mBody;
	b2FixtureDef* mFixtureDef;
	b2Fixture*    mFixture;

	b2World*      mWorld;

protected:
	void initPhysics(b2World* world);
public:
	//virtual bool init();

	void initWithGeometryDescription(const char *textureFileName, const char *geometryDescriptionFile, b2World* world, State* initialState, State* globalState);
	void initWithGlobalState(const char *pszFileName, b2World* world, State* initialState, State* globalState);
	void initWithInitialState(const char *pszFileName, b2World* world, State* initialState);

	void addBodyToSprite();
	void bodyUpdate(float dt);

	//The following methods will be used in case of
	virtual void OnCollisionEnter(b2Contact* contact){}
	virtual void OnCollisionStay(b2Contact* contact){}
	virtual void OnCollisionExit(b2Contact* contact){}

	virtual void update(float dt);

	virtual void release();

	static CollisionObject* create(const char *textureFileName, const char *geometryDescriptionFile, b2World* world, State* initialState, State* globalState);
	static CollisionObject* create(const char *pszFileName, b2World* world, State* initialState, State* globalState);
	static CollisionObject* create(const char *pszFileName, b2World* world, State* initialState);
	static CollisionObject* create(const char *pszFileName, b2World* world);
};
}
}

#endif //__COLLISION_OBJECT_H__