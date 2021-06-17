#pragma once
#include "Enemies/Enemy.h"
#include "Castle\Castle.h"
class Freezer :
    public Enemy
{
	Castle Bcastle;
public:
    Freezer(int id, int arr, double h, double p, double rel, double spd);

    void Move();
    void Act();
};

