#include "Enemy.h"


Enemy::Enemy(int id, int arrTime, int d):ID(id),ArrvTime(arrTime)
{
	SetDistance(d);
}

Enemy::~Enemy()
{
}

int Enemy::GetID() const
{
	return ID;
}


void Enemy::SetStatus(ENMY_STATUS s)
{
	status = s;
}

void Enemy::SetID(double id)
{
	ID = id;
}

void Enemy::SetAT(double arrival)
{
	ArrvTime = arrival;
}

void Enemy::SetH(double health)
{
	Health = health;
}

void Enemy::SetPOW(double power)
{
	Power = power;
}

void Enemy::SetRLD(double reload)
{
	ReloadSpeed = reload;
}

void Enemy::SetSPD(double speed)
{
	Speed = speed;
}

ENMY_STATUS Enemy::GetStatus() const
{
	return status;
}
ENMY_TYPE Enemy::GetType() const
{
	return type;
}
void Enemy::SetType(ENMY_TYPE t)
{
	type = t;
}

void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}



int Enemy::GetArrvTime() const
{
	return ArrvTime;
}

bool Enemy::IsFrosted()
{
	return Frosted;
}
void Enemy::SetFrosted(bool F)
{
	Frosted = F;
}

bool  Enemy::GetFrosted() const
{
	return Frosted;
}
double  Enemy::GetChanged_Health() const
{
	return Changed_Health;
}
void Enemy::effect_onSpeed()  // call on move!!
{
	if (Changed_Health < 0.5 * Health) { Speed = 0.5 * Speed; };
}
void  Enemy::during_reloadperoid()
{
	if (reload) { Move(); }
	else { Move(); Act(); };
}
void  Enemy::Freeze()
{

}
void  Enemy::Fire()
{

}
void  Enemy::ifFreezing()
{
	if (! Frosted) { Freeze(); Fire(); }
	else { Fire(); }
	
}
void Enemy::SETt_Frosted(int t)
{
	t_Frosted = t;
}
int Enemy::GETt_Frosted()
{
	return t_Frosted;
}
int Enemy::getPariority()
{
	return 1 / (Health * Power * Distance * LT);
}

void Enemy::SetDCE(double dce)
{
	DCE = dce;
}
double Enemy::GetDCE()
{
	return DCE;
}
