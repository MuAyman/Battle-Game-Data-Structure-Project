#pragma once
#include "Enemies/Enemy.h"
class Fighter :
    public Enemy
{

public:
    Fighter(int id, int arr, double h, double p, double rel, double spd);
	void Move();
	
};

