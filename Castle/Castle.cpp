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
double Castle::Getamountofice() const
{
	return amountofice;
}
void  Castle::setamountofice(double ice)
{
	amountofice = ice;
}

double Castle::GetHealth() const
{
	return Health;
}
void Castle::SetNum_f_attacks(int n)
{
	Num_f_attacks = n;
}
int Castle::GetNum_f_attacks() const
{
	return Num_f_attacks;
}
void Castle::SetFrosted(bool F)
{
	//if(amountofice=50)
	Frosted = F;
}
bool  Castle::GetFrosted() const
{
	return Frosted;
}
void  Castle::SetTotal_damage(double dama)
{
	Total_damage = dama;
}
double  Castle::GetTotal_damage() const
{
	return Total_damage;
}
void Castle::SetCaste_Power(double pow)
{
	Caste_Power = pow;
}
double Castle::GetCaste_Power() const
{
	return Caste_Power;
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