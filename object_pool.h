#ifndef _OBJECT_POOL_H_
#define _OBJECT_POOL_H_

#include "allocator.h"

#include <stdexcept>

template <typename T, typename Allocator>
class ObjectPool
{
public:
	ObjectPool() = default;
	~ObjectPool() = default;

	T* borrowObject()
	{
		std::cout << "borrow" << std::endl;
		return reinterpret_cast<T*>(allocate(sizeof(T)));
	}

	void returnObject(T* p)
	{
		std::cout << "return" << std::endl;
		deallocate(static_cast<void*>(p));
	}

	size_t getNumberIdle()
	{
		return m_allocator.getNumberIdle();
	}

	void* allocate(size_t size)
	{
		if (sizeof(T) != size)
			throw std::bad_alloc();
		return m_allocator.allocate();
	}

	void deallocate(void* p)
	{
		m_allocator.deallocate(static_cast<T*>(p));
	}
private:
	

private:
	Allocator m_allocator;
};

#endif // !_OBJECT_POOL_H_
