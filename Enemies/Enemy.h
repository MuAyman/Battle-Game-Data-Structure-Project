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
	bool Frosted; //Whenever an enemy gets frosted its property �IsFrosted� is turned into Ture
	ENMY_STATUS status;	    //status of the enemy (inactive, inactive, frosted, killed)
	//int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)

	double Health, Power, ReloadSpeed, Speed;

	int t_frozen;		// the time needed for the frozen to melt and back active again
	int t_killed;		// the time when the enemy got killed
	int t_firstShot;	// the first shot time of each enemy
public:
	Enemy(int id, int typ, int arr, double h, double p, double rel, double spd);
	virtual ~Enemy();

		// getters
	int GetID() const;
	ENMY_STATUS GetStatus() const;
	int GetDistance() const;
	int GettFrozen() const;
	int GetArrvTime() const;
	int GettKilled() const;
	int GettFD() const;

		// setters
	void SetStatus(ENMY_STATUS s);
	void SetID(double id);
	void SetAT(double arrival);
	void SetH(double health);
	void SetPOW(double power);
	void SetRLD(double reload);
	void SetSPD(double speed);
	void SettFrozen(int t);
	void SetDistance(int d);
	void SettKilled(int t);
	void SettFD(int t);


	void DecrementDist();	// decremant the distance of each enemy




	// Virtual Functions: ----------------

	virtual void Move() = 0;	//All enemies can move
	//virtual void Act() = 0;	//Acting means fighting or healing

	//
	// TODO: Add More Member Functions As Needed
	//

};
