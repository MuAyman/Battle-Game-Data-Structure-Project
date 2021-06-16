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
int Enemy::Getfirstshot() const
{
	return t_firstshot;
}
int Enemy::setfirstshot(int fsh)
{
	t_firstshot = fsh;
}
bool  Enemy::Getreload_period() const
{
	return reload_period;
}
void  Enemy::setreload_period(bool rp)
{
	reload_period = rp;
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
ENMY_TYPE  Enemy::GetTYPE()const
{
	return Type;
}

void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}
void Enemy::incrementDist()
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
double Enemy::Getpower() const
{
	return Power;
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
double  Enemy::GetChanged_Health() const
{
	return Changed_Health;
}
void Enemy::effect_onSpeed()  // call on move!!
{
	if (Changed_Health < 0.5 * Health) { Speed = 0.5 * Speed; };
}
double  Enemy::GetHealth() const
{
	return Health;
}
void