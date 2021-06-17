#pragma once
#include "Enemies/Enemy.h"
#include "Castle\Castle.h"
class Healer :
    public Enemy
{
	Castle Bcastle;

public:
    Healer(int id, int arr, double h, double p, double rel, double spd);

    void Move();
    void Act();

	void ifHealing();
	//void Heal();
};
