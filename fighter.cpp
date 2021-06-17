#include "Fighter.h"


Fighter::Fighter(int id, int arr, double h, double p, double rel, double spd): Enemy(id, 0, arr, h, p, rel, spd)
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
	Enemy*e;
	Battle *Ba;
	if (!e->Getreload_period() && e->GetType() == FIGHTER)
	{

		double k;
		double DFC = (k / ((e->GetDistance()) * (e->Getpower())));
		if (e->GetHealth() < (0.5 * (e->GetInitialHealth())))
		{
			k = 0.5;
		}
		else

		{
			k = 1;
		}
		Bcastle.SetTotal_damage( Bcastle.GetTotal_damage()+ DFC);
		e->SettFS(Ba->getcurrenttimestep());

	}
}

//void Fighter::Act()
//{
//	
//}
