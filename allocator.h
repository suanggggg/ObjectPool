#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

#include <stdexcept>

template <typename T>
class Allocator
{
public:
	virtual T* allocate() = 0;
	virtual void deallocate(T* p) = 0;

	virtual size_t getNumberIdle() = 0;
};

#endif // !_ALLOCATOR_H_
