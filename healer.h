#pragma once
#include "Enemies/Enemy.h"
class Healer :
    public Enemy
{


public:
    Healer(int id, int arr, double h, double p, double rel, double spd);

    void Move();
    void Act();

	void ifHealing();
	void Heal();
};
