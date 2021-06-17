#pragma once
#include "Enemies/Enemy.h"
#include "Castle\Castle.h"
#include "Battle.h"
class Fighter :  public Enemy
{
protected:

	Castle Bcastle;
//    Battle B;

public:
    Fighter(int id, int arr, double h, double p, double rel, double spd);
    void Move();
    void Act();

};
