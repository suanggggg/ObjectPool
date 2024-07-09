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
	Allocator m_allocator;
};

#endif // !_OBJECT_POOL_H_
