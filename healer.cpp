
#include "Healer.h"
#include "Generic_DS\Queue.h"
#include "Priority_Queue.h"
#include "ArrayStack.h"
#include "Battle.h"


Healer::Healer(int id, int arr, double h, double p, double rel, double spd)
    : Enemy(id, 0, arr, h, p, rel, spd)
{
};



void Healer::Move()
{
	
	for (int i = 0; i = Speed - 1; i++)
	{
			DecrementDist();
			incrementDist();
	}

}

void Healer::Act(Enemy* h, Enemy* d)
{
	
	if (!h->GetFrosted() && !d->GetFrosted() && (d->GetType() == FIGHTER || d->GetType() == FREEZER))
	{
		int distancebetweenenemies = (h->GetDistance()) - (d->GetDistance());
		if (distancebetweenenemies <= 2)
		{
			d->SetH(d->GetHealth() + (20 / (100 * distancebetweenenemies)) * (h->GetHealth()));
		}
	}
}








void Healer::Act()
{
}


/*void Healer::Heal()
{
	//Enemy* e;
	//Queue <Enemy*> tempQ;
	//int countTempQ = 0, tempcounter = 0;

	//tempcounter = ActiveHealerCount;
	//for (int i = 0; i < tempcounter; i++)
	//{
	//	ActiveHlealer.dequeue(e);
	//	ActiveHealerCount--;

	//	Healer* ptrH = dynamic_cast<Healer*>(e);

	//	ptrH->Act();	// dectremting the distance

	//	tempQ.enqueue(ptrH);
	//	countTempQ++;
	//}
	//// re inserting the enemies again in the ActiveHlealer queue after
	//// updating the the distance
	//for (int i = 0; i < countTempQ; i++)
	//{
	//	tempQ.dequeue(e);
	//	ActiveHlealer.insert_Stack(e, e->GetID());	// switch the id by the real priority [for the team]
	//	ActiveHealerCount++;
	//}
	}*/


void Healer::ifHealing()
{
	//  if ((!(Frosted || Killed))&& Distance <=2) { Heal(); }
}
