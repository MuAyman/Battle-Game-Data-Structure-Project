#include "Fighter.h"


Fighter::Fighter(int id, int arr, double h, double p, double rel, double spd)
    : Enemy(id, 0, arr, h, p, rel, spd)
{
};


void Fighter::Move()
{
	for (int i = 0; i = Speed - 1; i++)
	{
		DecrementDist();
	}
}

void Fighter::Act()
{

}