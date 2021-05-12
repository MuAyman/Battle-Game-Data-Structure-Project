#include "Battle.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>

#include"GUI/GUI.h"

using namespace std;

Battle::Battle()
{
	EnemyCount = 0;
	KilledCount = 0;
	InactiveCount = 0;
	ActiveFighterCount = 0;
	ActiveHealerCount = 0;
	ActiveFreezerCount = 0;
	FrostedCount = 0;
	CurrentTimeStep = 0;
	pGUI = NULL;
}


Castle * Battle::GetCastle()
{
	return &BCastle;
}


void Battle::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();

	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		break;
	case MODE_STEP:
		break;
	case MODE_SLNT:
		break;

	}

	delete pGUI;

}

bool Battle::LoadingFunction()
{
	string name;
	pGUI->PrintMessage("Enter the loading file path: ");
	name = pGUI->GetString();

	ifstream File;
	File.open(name, ios::in);

	if (File.fail())
		return false;
	else
	{
		double h, n , p, c;
		File >> h >> n >> p >> c;
		BCastle.SetHealth(h);				//Setting castle health
		BCastle.SetN(n);					//Setting castle N enemeies to attack at each time 
		BCastle.SetPower(p);				//Setting castle power
		EnemyCount = c;						//Setting enemy count
	
		for (int i = 1; i < EnemyCount; i++)
		{
			File >> h;
			AllEnemies[i].SetID(h);				//Setting enemy id
			
			File >> h;
			AllEnemies[i].SetStatus((ENMY_STATUS)h);	//Setting enemy type

			File >> h;
			AllEnemies[i].SetAT(h);						//Setting enemy arrival time

			File >> h;
			AllEnemies[i].SetH(h);						//Setting enemy health

			File >> h;
			AllEnemies[i].SetPOW(h);					//Setting enemy power

			File >> h;
			AllEnemies[i].SetRLD(h);					//Setting enemy reload time

			File >> h;
			AllEnemies[i].SetSPD(h);					//Setting enemy speed
		}
	}
}

void Battle::SimpleSimulator()
{
	LoadingFunction();
	AddAllListsToDrawingList();
	pGUI->UpdateInterface(CurrentTimeStep);
	ActivateEnemies();
	//move enemies
	void Move();
	///////freeze two active of each type
	//for active healer
	for(int i=0;i=1;i++)
	{
		Enemy* x;
		//Q_Activehealer.dequeue(x);
		Q_Frosted.enqueue(x);
		x->SetStatus(FRST);
		FrostedCount++;
		ActiveCount--;
	}
	//for active freezer
	for (int i = 0; i = 1; i++)
	{
		Enemy* x;
		//Q_Activefreezer.dequeue(x);
		Q_Frosted.enqueue(x);
		x->SetStatus(FRST);
		FrostedCount++;
		ActiveCount--;
	}
	//for active fighter
	for (int i = 0; i = 1; i++)
	{
		Enemy* x;
		//Q_Activefighter.dequeue(x);
		Q_Frosted.enqueue(x);
		x->SetStatus(FRST);
		FrostedCount++;
		ActiveCount--;
	}
	//////2frtosted to active
	for (int i = 0; i = 1; i++)
	{
		Enemy* p;
		Q_Frosted.dequeue(p);
		Q_Active.enqueue(p);
		p->SetStatus(ACTV);
	}
	ActiveCount + 2;
	FrostedCount - 2;

	//////kill one active one frosted
	Enemy* s;
	Q_Active.dequeue(s);
	Q_Killed.enqueue(s);
	s->SetStatus(KILD);
	Enemy* d;
	Q_Frosted.dequeue(d);
	Q_Killed.enqueue(d);
	d->SetStatus(KILD);
	KilledCount + 2;
	FrostedCount - 1;
	ActiveCount - 1;
	////draw
	AddAllListsToDrawingList();
	//print
	string x = to_string(CurrentTimeStep);
	//GUI::PrintMessage();
	pGUI->PrintMessage(x);
}
bool Battle::LoadingFunction()
{
	string name;
	pGUI->PrintMessage("Enter the loading file path: ");
	name = pGUI->GetString();


void Battle::castleAttack()
{

}


void Battle::enemiesAttack()
{

}
//This is just a demo function for project introductory phase
//It should be removed in phases 1&2
void Battle::Just_A_Demo()
{	
	
	pGUI->PrintMessage("Just a Demo. Enter Enemies Count(next phases should read I/P filename):");
	EnemyCount = atoi(pGUI->GetString().c_str());	//get user input as a string then convert to integer

	ifstream File;
	File.open(name, ios::in);

	if (File.fail())
		return false;
	else
	{
		double h, n , p, c;
		File >> h >> n >> p >> c;
		BCastle.SetHealth(h);				//Setting castle health
		BCastle.SetN(n);					//Setting castle N enemeies to attack at each time
		BCastle.SetPower(p);				//Setting castle power
		EnemyCount = c;						//Setting enemy count

		for (int i = 1; i < EnemyCount; i++)
		{
			File >> h;
			AllEnemies[i].SetID(h);				//Setting enemy id

			File >> h;
			AllEnemies[i].SetStatus((ENMY_STATUS)h);	//Setting enemy type

			File >> h;
			AllEnemies[i].SetAT(h);						//Setting enemy arrival time

			File >> h;
			AllEnemies[i].SetH(h);						//Setting enemy health

			File >> h;
			AllEnemies[i].SetPOW(h);					//Setting enemy power

			File >> h;
			AllEnemies[i].SetRLD(h);					//Setting enemy reload time

			File >> h;
			AllEnemies[i].SetSPD(h);					//Setting enemy speed
		}
	}
}

void Battle::SimpleSimulator()
{
	LoadingFunction();
	AddAllListsToDrawingList();
	pGUI->UpdateInterface(CurrentTimeStep);
	ActivateEnemies();
	///////freeze two active
	FrostedCount + 2;
	ActiveFighterCount - 2;

	//////2frtosted to active
	ActiveFighterCount, FrostedCount, KilledCount;
	ActiveFighterCount + 2;
	FrostedCount - 2;

	//////kill one active one frosted
	KilledCount + 2;
	FrostedCount - 1;
	ActiveFighterCount - 1;
	////draw
}


void Battle::castleAttack()
{

}


void Battle::enemiesAttack()

			File >> h;
			AllEnemies[i].SetH(h);						//Setting enemy health

			File >> h;
			AllEnemies[i].SetPOW(h);					//Setting enemy power

			File >> h;
			AllEnemies[i].SetRLD(h);					//Setting enemy reload time

			File >> h;
			AllEnemies[i].SetSPD(h);					//Setting enemy speed
		}
	}
}

void Battle::castleAttack()
{

}


void Battle::enemiesAttack()
{

}

//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
void Battle::AddAllListsToDrawingList()
{
	//Add inactive queue to drawing list

	Enemy* const * InactiveList = Inactive.toArray(InactiveCount);
	for (int i = 0; i < InactiveCount; i++)
		pGUI->AddToDrawingList(InactiveList[i]);

	Enemy* const* ActiveFighterList = ActiveFighter.toArray(ActiveFighterCount);
	for (int i = 0; i < ActiveFighterCount; i++)
		pGUI->AddToDrawingList(ActiveFighterList[i]);

	Enemy* const* ActiveHealerList = ActiveHlealer.GetArray();
	for (int i = 0; i < ActiveHlealer.GetCount(); i++)
		pGUI->AddToDrawingList(ActiveHealerList[i]);

	Enemy* const* ActiveFreezerList = ActiveFreezer.toArray(ActiveFreezerCount);
	for (int i = 0; i < ActiveFreezerCount; i++)
		pGUI->AddToDrawingList(ActiveFreezerList[i]);
	Enemy* const* KilledList = Killed.toArray(KilledCount);
	for (int i = 0; i < KilledCount; i++)
		pGUI->AddToDrawingList(KilledList[i]);
}

//check the inactive list and activate all enemies that has arrived
void Battle::ActivateEnemies()
{
	Enemy *pE;
	while( Inactive.peekFront(pE) )	//as long as there are more inactive enemies
	{
		if(pE->GetArrvTime() > CurrentTimeStep )	//no more arrivals at current time
			return;

		Inactive.dequeue(pE);	//remove enemy from the queue
		pE->SetStatus(ACTV);	//make status active
	}
}
