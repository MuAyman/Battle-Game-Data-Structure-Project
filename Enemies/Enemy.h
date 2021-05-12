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
	int Distance;
	bool Frosted; //Whenever an enemy gets frosted its property “IsFrosted” is turned into Ture
	ENMY_STATUS status;	    //status of the enemy (inactive, inactive, frosted, killed)
	//int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)

	double Health, Power, ReloadSpeed, Speed, LT;


public:
	Enemy(int id=0, int arrTime=0, int d = MaxDistance);
	virtual ~Enemy();

	int Enemy::GetID() const;
	ENMY_STATUS GetStatus() const;
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

	void SetDistance(int );
	int GetDistance() const;

	int GetArrvTime() const;




	// Virtual Functions: ----------------

	virtual void Move() = 0;	//All enemies can move
	//virtual void Act() = 0;	    //Acting means fighting or healing

	//
	// TODO: Add More Member Functions As Needed
	//

};
