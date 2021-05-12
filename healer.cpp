#include "healer.h"
void healer::incrementDist()
{
if (Distance == MinDistance)
Distance++;
	}
void healer::Move()
{
	for (int i=0;i=speed-1;i++)
	{
		DecrementDist();
		incrementDist();
	}
	
}
