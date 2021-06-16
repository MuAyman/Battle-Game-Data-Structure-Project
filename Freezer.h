#pragma once
#include "Enemies/Enemy.h"
class Freezer :
    public Enemy
{

public:
    Freezer(int id, int arr, double h, double p, double rel, double spd);

    void Move();
    void Act();
};

