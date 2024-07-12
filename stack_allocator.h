#ifndef _STACK_ALLOCATOR_H_
#define _STACK_ALLOCATOR_H_

#include "allocator.h"

#include <stack>

template <typename T>
class StackAllocator : public Allocator<T>
{
public:
	StackAllocator() = default;

	~StackAllocator() = default;

	virtual T* allocate()
	{
		if (m_stack.empty()) return nullptr;

		T* p = m_stack.top();
		m_stack.pop();
		return p;
	}

	virtual void deallocate(T* p)
	{
		if (p == nullptr) return;
		m_stack.push(p);
	}

	virtual size_t getNumberIdle() { return m_stack.size(); }

private:
	std::stack<T*> m_stack;
};

#endif // !_STACK_ALLOCATOR_H_
