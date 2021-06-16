#pragma once
#include "..\Defs.h"
#include "../Enemies/Enemy.h"
class Castle
{
	double Health, power, N;
	double initialHealth;	//Needed for the total damage calculation

//	int Num_f_attacks;
	int Ice; // Number of ice fires Castle fires
	int Fire; // Number of fires Castle fires
	bool Frosted; //If Castle frosted or not
//	double Total_damage; //Damage caused by all enemies
//	double Caste_Power;


public:

	void SetHealth(double h);
	void SetPower(double p);
	void SetN(double n);
	double GetPower() const;
	double GetN() const;
	double GetHealth() const;
//	void SetNum_f_attacks(int n);
//	int GetNum_f_attacks() const;
	void SetFrosted(bool F);
	bool GetFrosted() const;
	void SetInitialHealth(double H);
	double GetInitialHealth() const;
//	void SetCaste_Power(double pow);
//	double GetCaste_Power() const;
	void SetIce(int n_Ice);
	int GetIce() const;
	void SetFire(int n_Fire);
	int GetFire() const;


};
