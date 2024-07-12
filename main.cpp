#include <iostream>

#include "object_manager.h"

using namespace std;

int main()
{
	auto a = ObjectManager::instance()->CreateObject("BulletDefault");
	a->show();
}