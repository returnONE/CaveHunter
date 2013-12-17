#include "GameObject.h"

namespace MOC
{
namespace GameObjects
{
bool GameObject::init()
{
	if(CCSprite::init())
	{
		mEntity = new BaseGameEntity(this);
		return true;
	}
	return false;
}

void GameObject::initWithInitialState(const char *pszFileName, State* initialState)
{
	init();
	Sprite::initWithSpriteFrameName(pszFileName);
	//initWithFile(pszFileName);
	mEntity->GetFSM()->SetCurrentState(initialState);
}

void GameObject::initWithGlobalState(const char *pszFileName, State* initialState, State* globalState)
{
	init();
	initWithFile(pszFileName);
	mEntity->GetFSM()->SetCurrentState(initialState);
	mEntity->GetFSM()->SetGlobalState(globalState);
}

GameObject* GameObject::create(const char *pszFileName)
{
	GameObject* result = new GameObject();
	result->initWithFile(pszFileName);
	return result;
}

GameObject* GameObject::create(const char *pszFileName, State* initialState)
{
	//init();
	GameObject* result = new GameObject();
	result->initWithInitialState(pszFileName, initialState);
	return result;
}

GameObject* GameObject::create(const char *pszFileName, State* initialState, State* globalState)
{
	GameObject* result = new GameObject();
	result->initWithGlobalState(pszFileName, initialState, globalState);
	return result;
}
void GameObject::update(float dt)
{
	CCSprite::update(dt);
	mEntity->Update();
}

void GameObject::release()
{
	delete mEntity;
}

}
}
