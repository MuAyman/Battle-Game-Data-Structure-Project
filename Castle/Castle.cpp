#include "Castle.h"




void Castle::SetHealth(double h)
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed
}

void Castle::SetPower(double p)
{
	power = p;
}


void Castle::SetN(double n)
{
	N = n;
}

double Castle::GetPower() const
{
	return power;
}

double Castle::GetN() const
{
	return N;
}

double Castle::GetHealth() const
{
	return Health;
}