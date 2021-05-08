#pragma once
#include "..\Defs.h"
class Castle
{
	double Health, power, N;


public:

	void SetHealth(double h);
	void SetPower(double p);
	void SetN(double n);
	double GetPower() const;
	double GetN() const;
	double GetHealth() const;


};

