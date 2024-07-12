#ifndef _OBJECT_MANAGER_H_
#define _OBJECT_MANAGER_H_

#include "manager.h"
#include "object_pool.h"
#include "stack_allocator.h"
#include "object_factory.h"

#include <vector>

class ObjectManager : public Manager<ObjectManager>
{
	friend class Manager<ObjectManager>;

public:
	GameObject* CreateObject(const std::string& objectType)
	{
		return ObjectFactory::instance()->CreateObject(objectType);
	}

	GameObject* GetFromPool(const std::string& objectType)
	{
		auto it = pools.find(objectType);
		if (it == pools.end()) return nullptr;
		return it->second->borrowObject();
	}

	GameObject* GetObject(const std::string& objectType)
	{
		auto it = GetFromPool(objectType);
		if (it == nullptr)
			return CreateObject(objectType);
		return it;
	}

protected:
	ObjectManager()
	{
		std::vector<std::string> types = { "Bullet" };
		for (const auto& type : types)
			pools[type] = std::make_unique<ObjectPool<GameObject, StackAllocator<GameObject>>>();
	}

private:
	std::unordered_map <std::string, std::unique_ptr<ObjectPool<GameObject, StackAllocator<GameObject>>>> pools;
};


#endif // !_OBJECT_MANAGER_H_
