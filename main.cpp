#include <iostream>

#include "object_pool.h"
#include "queue_allocator.h"
#include "stack_allocator.h"

using namespace std;

class A
{
public:

	int x;


	void show()
	{
		cout << x << endl;
	}
};

int main()
{
	ObjectPool<A, StackAllocator<A>> A_pool;
	A* a = A_pool.borrowObject();
	a->x = 100;
	a->show();
	cout << A_pool.getNumberIdle() << endl;
	A_pool.returnObject(a);
	cout << A_pool.getNumberIdle() << endl;
	return 0;
}