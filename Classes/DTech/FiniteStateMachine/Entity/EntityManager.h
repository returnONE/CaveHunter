#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#include "BaseGameEntity.h"
#include "cocos2d.h"

using namespace std;

namespace MOC
{
namespace Entity
{
class EntityManager
{
private:
	map<int, BaseGameEntity*>* mEntities;

	static EntityManager* sInstance;

private:
	EntityManager();
	~EntityManager();

public:
	static EntityManager* Instance();
	static void Release();

	BaseGameEntity* GetEntity(int id);

	void Register(BaseGameEntity* entity);
	void Unregister(BaseGameEntity* entity);
};
}
}

#endif //__ENTITY_MANAGER_H__