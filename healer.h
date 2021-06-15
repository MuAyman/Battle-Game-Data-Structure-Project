#pragma once
#include "Enemies/Enemy.h"
class healer:public Enemy
{
public:
	void incrementDist();
	void ifHealing();
	void Heal();
};

