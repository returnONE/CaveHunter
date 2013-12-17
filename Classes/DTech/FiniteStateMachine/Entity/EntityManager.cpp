#include "EntityManager.h"

USING_NS_CC;

namespace MOC
{
namespace Entity
{
	
EntityManager* EntityManager::sInstance = NULL;

EntityManager::EntityManager()
{
	mEntities = new map<int, BaseGameEntity*>();
}

EntityManager::~EntityManager()
{
	mEntities->clear();
	delete mEntities;
	mEntities = NULL;
}

EntityManager* EntityManager::Instance()
{
	if(!sInstance)
	{
		sInstance = new EntityManager();
	}
	return sInstance;
}

void EntityManager::Release()
{
	delete sInstance;
	sInstance = NULL;
}

BaseGameEntity* EntityManager::GetEntity(int id)
{
	//find the entity
	map<int, BaseGameEntity*>::const_iterator ent = mEntities->find(id);

	//assert that the entity is a member of the map
	//CCAssert( (ent !=  mEntities->end()) && "<EntityManager::GetEntity>: invalid ID");

	return ent->second;
}

void EntityManager::Register(BaseGameEntity* entity)
{
	mEntities->insert(std::make_pair(entity->GetId(), entity));
}

void EntityManager::Unregister(BaseGameEntity* entity)
{
	mEntities->erase(mEntities->find(entity->GetId()));
}

}//namespace EntityManager
}//namespace MOC

