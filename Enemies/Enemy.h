#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "D:\ZC\Spring 21\Data Structures\Project\CIE205Project_Code_S2021\Castle\Castle.h"

class GUI;
// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases
class Enemy
{

protected:
	int ID;         //Each enemy has a unique ID (sequence number)
	int ArrvTime;	//arrival time (time it starts to join battle)
	int Distance = 60;
	bool Frosted; //Whenever an enemy gets frosted its property “IsFrosted” is turned into Ture
	ENMY_STATUS status;	    //status of the enemy (inactive, inactive, frosted, killed)
	ENMY_TYPE type;	    //type of the enemy (fighter, healer, freezer)
	//int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	int min_distance = 2;
	Castle eCastle;
	double Health, Power, ReloadSpeed, Speed, LT;
	double Changed_Health;
	bool reload;
	bool Killed;
	int t_Frosted = (eCastle.GetCaste_Power()* eCastle.GetHealth()) / (Health * Power * Distance);
	double DCE;                            //Damage to an enemy by a castle bullet (not applicable for ice throws)
public:
	Enemy(int id=0, int arrTime=0, int d = MaxDistance);
	virtual ~Enemy();

	int Enemy::GetID() const;
	ENMY_STATUS GetStatus() const;
	void SetStatus(ENMY_STATUS s);
	ENMY_TYPE GetType() const;
	void SetType(ENMY_TYPE t);
	void SetID(double id);
	void SetAT(double arrival);
	void SetH(double health);
	void SetPOW(double power);
	void SetRLD(double reload);
	void SetSPD(double speed);
	bool IsFrosted();
	void DecrementDist();

	void SetDistance(int );
	int GetDistance() const;

	int GetArrvTime() const;
	double GetChanged_Health() const;

	void effect_onSpeed();
	void during_reloadperoid();
	void ifFreezing();
	void  Freeze();
	void  Fire();
	void SetFrosted(bool F);
	bool GetFrosted() const;
	void SETt_Frosted(int t);
	int GETt_Frosted();
	int getPariority();
	void SetDCE(double dce);
	double GetDCE();
	// Virtual Functions: ----------------

	virtual void Move() = 0;	//All enemies can move
	virtual void Act() = 0;	    //Acting means fighting or healing

	//
	// TODO: Add More Member Functions As Needed
	//

};
