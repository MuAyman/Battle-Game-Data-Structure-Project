#pragma once
#include "..\Defs.h"
#include "../Enemies/Enemy.h"
class Castle
{
	double Health, power, N;
	double initialHealth;	//Needed for the total damage calculation

	int Ice; // Number of ice fires Castle fires
	int Fire; // Number of fires Castle fires
	bool Frosted; //If Castle frosted or not
    double Total_damage; //Damage caused by all enemies
	int Ice; // Number of ice fires Castle fires
	int Fire; // Number of fires Castle fires
	bool Frosted; //If Castle frosted or not
    double Total_damage; //Damage caused by all enemies


public:

	void SetHealth(double h);
	void SetPower(double p);
	void SetN(double n);    // Number of attacks per time step
	double GetPower() const;
	double GetN() const;  // Number of attacks per time step
	double GetHealth() const;

	void SetFrosted(bool F);
	bool GetFrosted() const;
	void SetInitialHealth(double H);
	double GetInitialHealth() const;
	void SetIce(int n_Ice);
	int GetIce() const;
	void SetFire(int n_Fire);
	int GetFire() const;
	void Attack_Bullets();  // Attacking with firing bullets
	void Attack_Ice();     // Attacking with throwing ice
	void ifAttack();      // if castle is frozen! doesn't attack

};
