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
	if (!e->Getreload_period())
	{
		if (e->GetTYPE() == FIGHTER)
		{
			int k;
			double DFC = (k / ((e->GetDistance()) * (e->Getpower())));
			if (e->GetChanged_Health < (0.5 * (e->GetHealth())))
			{
				k = 0.5;
			}
			else

			{
				k = 1;
			}
			BCastle.SetTotal_damage(BCastle.GetTotal_damage += DFC);
			e->setfirstshot(CurrentTimeStep);
		}
	}