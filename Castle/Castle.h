#pragma once
#include "..\Defs.h"
#include "D:\ZC\Spring 21\Data Structures\Project\CIE205Project_Code_S2021\Enemies\Enemy.h"
class Castle
{
	double Health, power, N;



	//
	// TODO: Add More Data Members As Needed
	int Num_f_attacks; 
	const int location = 0; // determine the locatin of castle from enemies
	int Ice; // Number of ice fires Castle fires
	int Fire; // Number of fires Castle fires
	bool Frosted; //If Castle frosted or not
	double Total_damage; //Damage caused by all enemies 
	double Caste_Power;

	//


public:

	void SetHealth(double h);
	void SetPower(double p);
	void SetN(double n);
	double GetPower() const;
	double GetN() const;
	double GetHealth() const;
	void SetNum_f_attacks(int n);
	int GetNum_f_attacks() const;
	void SetFrosted(bool F);
	bool GetFrosted() const;
	void SetTotal_damage(double dama);
	double GetTotal_damage() const;
	void SetCaste_Power(double pow);
	double GetCaste_Power() const;
	void SetIce(int n_Ice);
	int GetIce() const;
	void SetFire(int n_Fire);
	int GetFire() const;


};

