#include <iostream>

#include "object_pool.h"
#include "queue_allocator.h"
#include "stack_allocator.h"

using namespace std;

class TestQueueAllocator
{
	typedef ObjectPool<TestQueueAllocator, StackAllocator<TestQueueAllocator>> ObjectPool;

public:
	TestQueueAllocator()
	{
		cout << "TestQueueAllocator()" << endl;
	}

	~TestQueueAllocator()
	{
		cout << "~TestQueueAllocator()" << endl;
	}

	void* operator new(size_t size)
	{
		cout << "new TestQueueAllocator" << endl;
		return pool.allocate(size);
	}

	void operator delete(void* p)
	{
		cout << "delete TestQueueAllocator" << endl;
		pool.deallocate(p);
	}

private:
	static ObjectPool pool;
};

TestQueueAllocator::ObjectPool TestQueueAllocator::pool;

int main()
{
	TestQueueAllocator* a = new TestQueueAllocator();
	delete a;
	return 0;
}