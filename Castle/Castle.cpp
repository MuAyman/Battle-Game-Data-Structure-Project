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

void Castle::SetFrosted(bool F)
{
	Frosted = F;
}

bool  Castle::GetFrosted() const
{
	return Frosted;
}


void Castle::SetInitialHealth(double H)
{
	initialHealth = H;
}
double Castle::GetInitialHealth() const
{
	return initialHealth;
}


void Castle::SetIce(int n_Ice)
{
	Ice = n_Ice;
}
int Castle::GetIce() const
{
	return Ice;
}

void Castle::SetFire(int n_Fire)
{
	Fire = n_Fire;
}

int Castle::GetFire() const
{
	return Fire;
}

void Castle::Attack()
{

}

void Castle::ifAttack()
{
	if (!Frosted) { Attack(); }     
}