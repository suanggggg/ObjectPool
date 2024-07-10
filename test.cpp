#include <iostream>

#include "object_pool.h"
#include "queue_allocator.h"
#include "stack_allocator.h"

using namespace std;

class TestQueueAllocator
{
	typedef ObjectPool<TestQueueAllocator, QueueAllocator<TestQueueAllocator>> ObjectPool;

public:
	TestQueueAllocator()
	{
		cout << "TestQueueAllocator()" << endl << endl;
	}

	~TestQueueAllocator()
	{
		cout << "~TestQueueAllocator()" << endl << endl;
	}

	void* operator new(size_t size)
	{
		cout << "new TestQueueAllocator" << endl << endl;
		return pool.allocate(size);
	}

	void operator delete(void* p)
	{
		cout << "delete TestQueueAllocator" << endl << endl;
		pool.deallocate(p);
	}

private:
	static ObjectPool pool;
};

class TestStackAllocator
{
	typedef ObjectPool<TestStackAllocator, StackAllocator<TestStackAllocator>> ObjectPool;

public:
	TestStackAllocator()
	{
		cout << "TestStackAllocator()" << endl << endl;
	}

	~TestStackAllocator()
	{
		cout << "~TestStackAllocator()" << endl << endl;
	}

	void* operator new(size_t size)
	{
		cout << "new TestStackAllocator" << endl << endl;
		return pool.allocate(size);
	}

	void operator delete(void* p)
	{
		cout << "delete TestStackAllocator" << endl << endl;
		pool.deallocate(p);
	}

private:
	static ObjectPool pool;
};

TestQueueAllocator::ObjectPool TestQueueAllocator::pool;
TestStackAllocator::ObjectPool TestStackAllocator::pool;

int main()
{
	TestQueueAllocator* a = new TestQueueAllocator();
	delete a;
	TestStackAllocator* b = new TestStackAllocator();
	delete b;
	return 0;
}
