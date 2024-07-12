#ifndef _QUEUE_ALLOCATOR_H_
#define _QUEUE_ALLOCATOR_H_

#include "allocator.h"

#include <queue>

template <typename T>
class QueueAllocator : public Allocator<T>
{
public:
	QueueAllocator() = default;
	~QueueAllocator() = default;

	virtual T* allocate()
	{
		if (m_queue.empty()) return nullptr;

		T* p = m_queue.front();
		m_queue.pop();
		return p;
	}

	virtual void deallocate(T* p)
	{
		if (p == nullptr) return;
		m_queue.push(p);
	}

	virtual size_t getNumberIdle() { return m_queue.size(); }

private:
	std::queue<T*> m_queue;
};

#endif // !_QUEUE_ALLOCATOR_H_
