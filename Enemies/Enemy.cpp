#include "Enemy.h"


Enemy::Enemy(int id, int typ, int arr, double h, double p, double rel, double spd)
{
	Distance = MaxDistance;
	SetID(id);
	SetStatus((ENMY_STATUS)typ);
	SetAT(arr);
	SetH(h);
	SetPOW(p);
	SetRLD(rel);
	SetSPD(spd);
	SettFrozen(0);	// intinalling the time for frozen enmies to back active again by zero
					// since no frozen enemies in the beginning
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

void Enemy::SettFrozen(int t)
{
	t_frozen = t;
}

int Enemy::GettFrozen() const
{
	return t_frozen;
}

ENMY_STATUS Enemy::GetStatus() const
{
	return status;
}

int Enemy::GettKilled() const
{
	return t_killed;
}

void Enemy::SettKilled(int t)
{
	t_killed = t;
}

int Enemy::GettFD() const
{
	return t_firstShot;
}
void Enemy::SettFD(int t)
{
	t_firstShot = t;
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
