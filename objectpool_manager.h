#ifndef _OBJECTPOOL_MANAGER_H_
#define _OBJECTPOOL_MANAGER_H_

#include "manager.h"
#include "object_pool.h"
#include "stack_allocator.h"

class ObjectpoolManager : public Manager<ObjectpoolManager>
{
	friend class Manager<ObjectpoolManager>;

};

#endif // !_OBJECTPOOL_MANAGER_H_
