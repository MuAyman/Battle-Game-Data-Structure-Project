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
	int EnemyCount, CurrentTimeStep=0;	//the total number of enemies in the game
	int InactiveCount=0, ActiveFighterCount=0, ActiveHealerCount=0,
		ActiveFreezerCount=0, FrostedCount=0, KilledCount=0;	//no. of enemies (Active, Frosted, killed so far)

///////////////////////////////////////////////	Riham ?????????????????
Castle* cas;
fighter BfEnemy;
double DCE;                            //Damage to an enemy by a castle bullet (not applicable for ice throws)

///////////////////////////////////////////


	Queue<Enemy*> Inactive;						//Queue of inactive enemies
	Priority_Queue<Enemy*> ActiveFighter;		//Priority Queue of active fighters
	Priority_Queue<Enemy*> ActiveHlealer;		//Priority Stack of active Healer
	Priority_Queue<Enemy*> ActiveFreezer;		//Priority Queue of freezer enemies
	Queue<Enemy*> Killed;						//Queue of Killed enemies
	Priority_Queue<Enemy*> Frosted;				//Priority Queue of frosted enemies

public:

	Battle();
	void AddAllListsToDrawingList();	//DONE	//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
	Castle * GetCastle();
	void RunSimulation();
	void ActivateEnemies();		//check the inactive list and activate all enemies that has arrived

	void castleAttack();
	void enemiesAttack();
	void updateEnemies();		// updates enemies status and distance
	GAME_STATUS BattleStatus();			// returns how the battle ended (win, loss, or withdraw)
	bool LoadingFunction();		// loads all enemies info from the input file
	void outputing();


	void InteractiveMode();
	void StepByStepMode();
	void SilentMode();

	void SimpleSimulator();

};
