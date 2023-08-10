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




Freezer::Freezer(int id, int arr, double h, double p, double rel, double spd)
	: Enemy(id, 2, arr, h, p, rel, spd)
{

};


void Freezer::Move()
{
	for (int i = 0; i = Speed - 1; i++)
	{
		DecrementDist();
	}
}

void Freezer::Act()
{
	Enemy* e;
	if (!e->Getreload_period())
	{
		if (e->GetTYPE() == FREEZER)
		{
			//double amountofice;
			BCastle.setamountofice(BCastle.Getamountofice() + (e->Getpower()));
			if (BCastle.Getamountofice() == 20)
				BCastle.SetFrosted(1);
		}
	}
}




}