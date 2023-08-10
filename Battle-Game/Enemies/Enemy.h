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
	bool Frosted;	//Whenever an enemy gets frosted its property �IsFrosted� is turned into Ture
	ENMY_STATUS status;	    //status of the enemy (inactive, inactive, frosted, killed)
	ENMY_TYPE type;	    //type of the enemy (fighter, healer, freezer)
	int Distance;	//Horizontal distance between enemy & the tower of its region
						//Always positive (ranges from 2 to 60)


	double InitialHealth, Power, ReloadSpeed, Speed, LT;		// LT; life Time

	int t_frozen;		// the time needed for the frozen to melt and back active again
	int t_killed;		// the time when the enemy got killed
	int t_firstShot;	// the first shot time of each enemy
	double Health;
	bool reload;
	double DCE;   //Damage to an enemy by a castle bullet (not applicable for ice throws)
	const double Health; //Constant as we need its value stored 
	bool reload;
	double DCE;   //Damage to an enemy by a castle bullet (not applicable for ice throws)
	double Changed_Health; //The original health after Changing it by castle attack
	// we needed to separate the original health of the changed one to be able to compare them.

public:
	Enemy(int id, int typ, int arr, double h, double p, double rel, double spd);
	virtual ~Enemy();

		// getters
	int GetID() const;
	ENMY_STATUS GetStatus() const;
	int GetDistance() const;
	int GettFrozen() const;		// returns the time needed for the ice to melt
	int GetArrvTime() const;
	int GettKilled() const;		// returns the time that enemy got killed at
	int GettFS() const;			// returns the time of the first shot time
	double GetInitialHealth() const;
	double GetHealth() const;
	ENMY_TYPE GetType() const;
	bool GetFrosted() const;
	int getPariority();
	double GetDCE();

		// setters
	void SetStatus(ENMY_STATUS s);
	void SetType(ENMY_TYPE t);
	void SetID(double id);
	void SetAT(double arrival);
	void SetH(double health);
	void SetInitialHealth(double H);
	void SetPOW(double power);
	void SetRLD(double reload);
	void SetSPD(double speed);
	void SettFrozen(int t);
	void SetDistance(int d);
	void SettKilled(int t);
	void SettFS(int t);
	void SetFrosted(bool F);
	void SETt_Frosted(int t);
	void SetDCE(double dce);
	void SetChanged_Health(double CH_H);
	void DecrementDist();	// decremant the distance of each enemy

	void effect_onSpeed();
	void during_reloadperoid();
	void ifFreezing();
	void  Freeze();
	void  Fire();

	int freezingTime(int CastlePower, int CastleHealth);	// calculates the time needed for the ice to melt

	// Virtual Functions: ----------------
	virtual void Move() = 0;	//All enemies can move
	virtual void Act() = 0;	    //Acting means fighting or healing

};
