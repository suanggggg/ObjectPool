#ifndef _OBJECT_FACTORY_H_
#define _OBJECT_FACTORY_H_

#include "factory.h"
#include "bullet_default.h"

class ObjectFactory : public Factory<ObjectFactory, GameObject>
{
	friend class Factory<ObjectFactory, GameObject>;

public:
	GameObject* CreateObject(const std::string& objectType) override
	{
		auto it = creators.find(objectType);
		if (it == creators.end())
			throw std::runtime_error("Unknown object type when create.");
		return it->second();
	}

protected:
	ObjectFactory()
	{
		creators["BulletDefault"] = []() ->GameObject* { return new BulletDefault(); };
	}

private:
	std::unordered_map<std::string, ObjectCreator> creators;
};

#endif // !_OBJECT_FACTORY_H_
