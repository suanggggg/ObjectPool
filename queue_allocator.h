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
		if (m_queue.empty())
		{
			unsigned char data[sizeof(T)];
			return reinterpret_cast<T*>(&data);
		}

		T* p = m_queue.front();
		m_queue.pop();
		return p;
	}

	virtual void deallocate(T* p)
	{
		if (p == nullptr) return;
		m_queue.push(p);
	}

private:
	std::queue<T*> m_queue;
};

#endif // !_QUEUE_ALLOCATOR_H_
