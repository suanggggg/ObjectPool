#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <string>
#include <memory>
#include <functional>
#include <unordered_map>

template <typename Subclass, typename T>
class Factory
{
protected:
	typedef std::function<T* ()> ObjectCreator;

public:
	static Subclass* instance()
	{
		if (!factory)
			factory = new Subclass();
		return factory;
	}

	virtual T* CreateObject(const std::string& objectType) { return nullptr; }

protected:
	Factory() = default;
	~Factory() = default;
	Factory(const Factory&) = delete;
	Factory& operator = (const Factory&) = delete;

private:
	static Subclass* factory;
};

template <typename Subclass, typename T>
Subclass* Factory<Subclass, T>::factory = nullptr;

#endif // !_FACTORY_H_
