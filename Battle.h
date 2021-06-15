#pragma once

#include "Enemies\Enemy.h"
#include "Castle\Castle.h"
#include "Generic_DS\Queue.h"
#include "Priority_Queue.h"
#include "ArrayStack.h"
#include "GUI\GUI.h"
#include "fighter.h"

// it is the controller of the project
class Battle
{
private:
	GUI* pGUI;
	Castle BCastle;
	int EnemyCount, CurrentTimeStep;	//the actual number of enemies in the game
	int InactiveCount, ActiveFighterCount, ActiveHealerCount,
		ActiveFreezerCount, FrostedCount, KilledCount;	//no. of enemies (Active, Frosted, killed so far)
	Castle* cas;
	//Enemy AllEnemies[MaxEnemyCount];		// This Array of All Enemies (objects)
	fighter BfEnemy;
	Queue<Enemy*> Inactive;					//Queue of inactive enemies
	Priority_Queue<Enemy*> ActiveFighter;	//Priority Queue of active fighters
	ArrayStack<Enemy*> ActiveHlealer;		//Stack of active Healer
	Queue<Enemy*> ActiveFreezer;			//Queue of freezer enemies
	double DCE;                            //Damage to an enemy by a castle bullet (not applicable for ice throws)
public:
	
	Battle();
	void AddAllListsToDrawingList();	//DONE	//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
	Castle * GetCastle();
	void RunSimulation();
	void ActivateEnemies();		//check the inactive list and activate all enemies that has arrived

	void castleAttack();
	void enemiesAttack();

	bool LoadingFunction();
	void SimpleSimulator();
	
};

