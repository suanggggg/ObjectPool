#ifndef _BULLET_H_
#define _BULLET_H_

#include <iostream>

#include "game_object.h"

class Bullet : public GameObject
{
public:
	virtual void show() = 0;
};

#endif // !_BULLET_H_
