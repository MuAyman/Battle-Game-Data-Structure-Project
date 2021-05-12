#pragma once

#include "Enemies\Enemy.h"
#include "Castle\Castle.h"
#include "Generic_DS\Queue.h"
#include "Priority_Queue.h"
#include "ArrayStack.h"
#include "GUI\GUI.h"

// it is the controller of the project
class Battle
{
private:
	GUI* pGUI;
	Castle BCastle;

	int EnemyCount, CurrentTimeStep;	//the actual number of enemies in the game
	int InactiveCount, ActiveFighterCount, ActiveHealerCount,
		ActiveFreezerCount, FrostedCount, KilledCount;	//no. of enemies (Active, Frosted, killed so far)

	Enemy AllEnemies[MaxEnemyCount];		// This Array of All Enemies (objects)
								  			
	Queue<Enemy*> Inactive;					//Queue of inactive enemies
	Priority_Queue<Enemy*> ActiveFighter;	//Priority Queue of active fighters
	ArrayStack<Enemy*> ActiveHlealer;		//Stack of active Healer
	Queue<Enemy*> ActiveFreezer;			//Queue of freezer enemies

	int EnemyCount;	//the actual number of enemies in the game
	int ActiveCount, FrostedCount, KilledCount;	//no. of enemies (Active, Frosted, killed so far)
	int CurrentTimeStep;
	//Enemy * BEnemiesForDraw[MaxEnemyCount]; // This Array of Pointers is used for drawing elements in the GUI
								  			// No matter what list type you are using to hold enemies, 
											// you must pass the enemies to the GUI function as an array of enemy pointers. 
											// At every time step, you should update those pointers 
											// to point to the current active enemies 
											// then pass the pointers list to the GUI function


	Queue<Enemy*> Q_Inactive;		//Queue of inactive enemies


	int InactiveCount, ActiveCount,Activehealers, Activefighters, Activefreezers, FrostedCount, KilledCount;
	Queue<Enemy*> Q_Active;			//Queue of active enemies
	Queue<Enemy*> Q_Inactive;		//Queue of inactive enemies
	Queue<Enemy*> Q_Frosted;		//Queue of frosted enemies
	Queue<Enemy*> Q_Killed;			//Queue of killed enemies
	Queue<Enemy*>Q_Activehealer;
	Queue<Enemy*>Q_Activefighter;
	Queue<Enemy*>Q_Activefreezer;


	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	//Queue for all enemies in the battle
	int DemoListCount;
	Enemy* DemoList[MaxEnemyCount];	//Important: This is just for demo
	/// ==>


	//
	// TODO: Add More Data Members As Needed
	//


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

