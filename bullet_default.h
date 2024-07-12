#ifndef _BULLET_DEFAULT_H_
#define _BULLET_DEFAULT_H_

#include "bullet.h"

class BulletDefault : public Bullet
{
public:
	void show()
	{
		std::cout << "BulletDefault" << std::endl;
	}
};

#endif // !_BULLET_DEFAULT_H_
