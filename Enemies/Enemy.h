#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"

class GUI;
// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases
class Enemy
{

protected:
	const int ID;         //Each enemy has a unique ID (sequence number)
	const int ArrvTime;	//arrival time (time it starts to join battle)

	ENMY_STATUS status;	    //status of the enemy (inactive,active, frosted, killed)
	int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	double Health;	//Enemy health
	int power;
	double speed;
	int Reload_period;
	/*int x;
	int y;*/
	double LT; //the total time an enemy stays alive until being killed

	
	//
	// TODO: Add More Data Members As Needed
	//

public:
	Enemy(int id, int arrTime, int d = MaxDistance);
	virtual ~Enemy();

	int Enemy::GetID() const;
	ENMY_STATUS GetStatus() const;
	void SetStatus(ENMY_STATUS);
	
	void DecrementDist();

	void SetDistance(int );
	int GetDistance() const;

	int GetArrvTime() const;
	



	// Virtual Functions: ----------------

	//virtual void Move() = 0;	//All enemies can move
	//virtual void Act() = 0;	    //Acting means fighting or healing

	//
	// TODO: Add More Member Functions As Needed
	//

};

