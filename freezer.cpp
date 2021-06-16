#include "Freezer.h"



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