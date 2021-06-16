#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

class GUI;
// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases
class Enemy
{

protected:
	int ID;         //Each enemy has a unique ID (sequence number)
	int ArrvTime;	//arrival time (time it starts to join battle)
	int Distance = 60;
	int t_firstshot;
	bool Frosted; //Whenever an enemy gets frosted its property “IsFrosted” is turned into Ture
	ENMY_STATUS status;	    //status of the enemy (inactive, inactive, frosted, killed)
	//int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	ENMY_TYPE Type;
	int min_distance = 2;
	double Health, Power, ReloadSpeed, Speed, LT;
	double Changed_Health;
	bool reload_period;

public:
	Enemy(int id=0, int arrTime=0, int d = MaxDistance);
	virtual ~Enemy();
	bool Getreload_period() const;
	void setreload_period(bool rp);
	int GetID() const;
	int Getfirstshot() const;
	int setfirstshot(int fsh);
	ENMY_STATUS GetStatus() const;
	ENMY_TYPE GetTYPE() const;
	void SetStatus(ENMY_STATUS s);
	void SetID(double id);
	void SetAT(double arrival);
	void SetH(double health);
	void SetPOW(double power);
	void SetRLD(double reload);
	void SetSPD(double speed);
	bool IsFrosted();
	void SetFrosted(bool F);
	void DecrementDist();
	void incrementDist();
	void SetDistance(int );
	int GetDistance() const;
	double Getpower() const;
	int GetArrvTime() const;
	double GetChanged_Health() const;
	double GetHealth() const;
	void effect_onSpeed();


	// Virtual Functions: ----------------

	//virtual void Move() = 0;	//All enemies can move
	//virtual void Act() = 0;	    //Acting means fighting or healing

	//
	// TODO: Add More Member Functions As Needed
	//

};
