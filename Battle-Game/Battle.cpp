#include "Battle.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include "Enemies/Enemy.h"
#include "Fighter.h"
#include "Freezer.h"
#include "Healer.h"
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
		InteractiveMode();
		break;
	case MODE_STEP:
		StepByStepMode();
		break;
	case MODE_SLNT:
		SilentMode();
		break;

	}

	delete pGUI;

}

void Battle::updateEnemies()
{
				/////////////////   Updating the frosted queue firslty    /////////////////
	Enemy* e;
	Queue<Enemy*> tempQ;
	int countTempQ=0, tempcounter=0;

	for (int i = 0; i < FrostedCount; i++)
	{
		Frosted.dequeue(e);
		FrostedCount--;
		e->SettFrozen((e->GettFrozen() - 1));	// updating the freezing time needed for the ice to melt

		if (e->GettFrozen() == 0)	// the ice melted already and the enemy is back active again
		{
			Fighter* ptrF = dynamic_cast<Fighter*>(e);
			Healer* ptrH = dynamic_cast<Healer*>(e);
			Freezer* ptrFr = dynamic_cast<Freezer*>(e);

			if (ptrF)
			{
				ActiveFighter.insert(ptrF, ptrF->GetID());	// switch the id by the real priority [for the team]
				ActiveFighterCount++;
			}
			else if (ptrH)
			{
				ActiveHlealer.insert_Stack(ptrH, ptrH->GetID());	// switch the id by the real priority [for the team]
				ActiveHealerCount++;
			}
			else if (ptrFr)
			{
				ActiveFreezer.insert(ptrH, ptrH->GetID());	// switch the id by the real priority [for the team]
				ActiveFreezerCount++;
			}
		}
		else	// the ice didnt melt yet and enemy is still frozen
		{
			tempQ.enqueue(e);
			countTempQ++;
		}
	}

	// re inserting the enemies again in the frosted queue after
	// updating the the freezing time
	for (int i = 0; i < countTempQ; i++)
	{
		tempQ.dequeue(e);
		Frosted.insert(e, e->GettFrozen());		// that's the real priority [for the team]
		FrostedCount++;
	}


					/////////////////   Updating the distances secondly    /////////////////

		// updating the distances of the active fighter
	tempcounter = ActiveFighterCount;
	for (int i = 0; i < tempcounter; i++)
	{
		ActiveFighter.dequeue(e);
		ActiveFighterCount--;

		Fighter* ptrF = dynamic_cast<Fighter*>(e);

		ptrF->DecrementDist();	// dectremting the distance

		tempQ.enqueue(ptrF);
		countTempQ++;
	}
	// re inserting the enemies again in the ActiveFighter queue after
	// updating the the distance
	for (int i = 0; i < countTempQ; i++)
	{
		tempQ.dequeue(e);
		ActiveFighter.insert(e, e->GetID());	// switch the id by the real priority [for the team]
		ActiveFighterCount++;
	}

		// updating the distances of the active healers
	tempcounter = ActiveHealerCount;
	for (int i = 0; i < tempcounter; i++)
	{
		ActiveHlealer.dequeue(e);
		ActiveHealerCount--;

		Healer* ptrH = dynamic_cast<Healer*>(e);

		ptrH->DecrementDist();	// dectremting the distance

		tempQ.enqueue(ptrH);
		countTempQ++;
	}
	// re inserting the enemies again in the ActiveHlealer queue after
	// updating the the distance
	for (int i = 0; i < countTempQ; i++)
	{
		tempQ.dequeue(e);
		ActiveHlealer.insert_Stack(e, e->GetID());	// switch the id by the real priority [for the team]
		ActiveHealerCount++;
	}

		// updating the distances of the active freezers
	tempcounter = ActiveFreezerCount;
	for (int i = 0; i < tempcounter; i++)
	{
		ActiveFreezer.dequeue(e);
		ActiveFreezerCount--;

		Freezer* ptrFr = dynamic_cast<Freezer*>(e);

		ptrFr->DecrementDist();	// dectremting the distance

		tempQ.enqueue(ptrFr);
		countTempQ++;
	}
	// re inserting the enemies again in the ActiveFreezer stack after
	// updating the the distance
	for (int i = 0; i < countTempQ; i++)
	{
		tempQ.dequeue(e);
		ActiveFreezer.insert_Stack(e, e->GetID());	// switch the id by the real priority [for the team]
		ActiveFreezerCount++;
	}


	// freeing the memory taken by the temp variables
	for (int i = 0; i < tempcounter; i++)
	{
		tempQ.dequeue(e);
		delete e;
	}
}


GAME_STATUS Battle::BattleStatus()
{
	if (BCastle.GetHealth() <= 0)	// the castle has fallen and it can be either loss or drawn
		if (KilledCount == EnemyCount)	// all enemies fall too, so it's drawn
			return DRAWN;
		else	// there still some enemies, then its loss
			return LOSS;
	else		// the castle is still standing, so it's win
		return WIN;

}

bool Battle::LoadingFunction()
{
	string name;
	pGUI->PrintMessage("Enter the loading file path: ");
	//name = pGUI->GetString();

	ifstream File;
	File.open("input.txt", ios::in);

	if (File.fail())
		return false;
	else
	{
		double h, n, CP, c, id, typ, arr, EP, rel, spd;
		File >> h >> n >> CP >> c;
		BCastle.SetHealth(h);				//Setting castle health
		BCastle.SetInitialHealth(h);
		BCastle.SetN(n);					//Setting castle N enemeies to attack at each time
		BCastle.SetPower(CP);				//Setting castle power
		EnemyCount = c;						//Setting enemy count
		Enemy* a;
		cout << "EnemyCount" << EnemyCount << endl;

		for (int i = 1; i < EnemyCount; i++)
		{
			File >> id >> typ >> arr >> h >> EP >> rel >> spd;

			if (typ == 0)
				a = new Fighter(id, arr, h, EP, rel, spd);
			else if (typ == 1)
				a = new Healer(id, arr, h, EP, rel, spd);
			else if (typ == 2)
				a = new Freezer(id, arr, h, EP, rel, spd);
			else
				return false;			//type error

			Inactive.enqueue(a);
			InactiveCount++;
		}
	}
	cout << "InactiveCount" << InactiveCount << endl;
	return true;
}


void Battle::InteractiveMode()
{
	CurrentTimeStep = 0;
	LoadingFunction();
	AddAllListsToDrawingList();
	pGUI->UpdateInterface(CurrentTimeStep);

	while ((KilledCount <= EnemyCount) && !(BCastle.GetHealth() <= 0))
	{
		CurrentTimeStep++;
		ActivateEnemies();
		castleAttack();
		enemiesAttack();
		updateEnemies();

		pGUI->ResetDrawingList();
		AddAllListsToDrawingList();
		pGUI->UpdateInterface(CurrentTimeStep);

		pGUI->waitForClick();		// Action of proceeding
	}

	outputing();	// output processing
}

void Battle::outputing()
{
	ofstream outputfile;
	Enemy* e;
	int FD=0, KD=0, LT=0, FirstShotDelays=0, KillDaleys=0;

	outputfile.open("Output.txt");

	// game status
	if (BattleStatus() == 0)
		outputfile << "Game is WIN.\n";
	else if (BattleStatus() == 1)
		outputfile << "Game is LOSS.\n";
	else if (BattleStatus() == 2)
		outputfile << "Game is DRAWN.\n";

	// enemies data
	outputfile << "KTS ID     FD KD LT\n";

	while (KilledCount != 0)
	{
		Killed.dequeue(e);
		KilledCount--;
		FD = e->GettFS() + e->GetArrvTime();
		KD = e->GettKilled() + e->GettFS();
		LT = FD + KD;
		outputfile << e->GettKilled() << " " << e->GetID() << "     "
			<< FD << " " << KD << " " << LT << "\n";

		FirstShotDelays += FD;		// getting the sum of FD's
		KillDaleys += KD;			// getting the sum of KD's
	}

	if (KilledCount < EnemyCount)	// in case the game was loss and there still some active or frossted enemies
	{
		while (ActiveFighterCount != 0)
		{
			ActiveFighter.dequeue(e);
			ActiveFighterCount--;
			FD = e->GettFS() + e->GetArrvTime();
			KD = 0;		// since he's not dead asln
			LT = CurrentTimeStep - e->GetArrvTime();	// since he's still alive
			outputfile << 0 << " " << e->GetID() << "     "		// KTS is zero since he's still alive
				<< FD << " " << KD << " " << LT << "\n";

			FirstShotDelays += FD;		// getting the sum of FD's
			KillDaleys += KD;			// getting the sum of KD's
		}

		while (ActiveFreezerCount != 0)
		{
			ActiveFreezer.dequeue(e);
			ActiveFreezerCount--;
			FD = e->GettFS() + e->GetArrvTime();
			KD = 0;		// since he's not dead asln
			LT = CurrentTimeStep - e->GetArrvTime();	// since he's still alive
			outputfile << 0 << " " << e->GetID() << "     "		// KTS is zero since he's still alive
				<< FD << " " << KD << " " << LT << "\n";

			FirstShotDelays += FD;		// getting the sum of FD's
			KillDaleys += KD;			// getting the sum of KD's
		}



void Battle::InteractiveMode()
{
	CurrentTimeStep = 0;
	LoadingFunction();
	AddAllListsToDrawingList();
	pGUI->UpdateInterface(CurrentTimeStep);

	while ((KilledCount <= EnemyCount) && !(BCastle.GetHealth() <= 0))
	{
		CurrentTimeStep++;
		ActivateEnemies();
		castleAttack();
		enemiesAttack();
		updateEnemies();

		pGUI->ResetDrawingList();
		AddAllListsToDrawingList();
		pGUI->UpdateInterface(CurrentTimeStep);

		pGUI->waitForClick();		// Action of proceeding
	}

	outputing();	// output processing
}

void Battle::outputing()
{
	ofstream outputfile;
	Enemy* e;
	int FD=0, KD=0, LT=0, FirstShotDelays=0, KillDaleys=0;

	outputfile.open("Output.txt");

	// game status
	if (BattleStatus() == 0)
		outputfile << "Game is WIN.\n";
	else if (BattleStatus() == 1)
		outputfile << "Game is LOSS.\n";
	else if (BattleStatus() == 2)
		outputfile << "Game is DRAWN.\n";

	// enemies data
	outputfile << "KTS ID     FD KD LT\n";

	while (KilledCount != 0)
	{
		Killed.dequeue(e);
		KilledCount--;
		FD = e->GettFS() + e->GetArrvTime();
		KD = e->GettKilled() + e->GettFS();
		LT = FD + KD;
		outputfile << e->GettKilled() << " " << e->GetID() << "     "
			<< FD << " " << KD << " " << LT << "\n";

		FirstShotDelays += FD;		// getting the sum of FD's
		KillDaleys += KD;			// getting the sum of KD's
	}

	if (KilledCount < EnemyCount)	// in case the game was loss and there still some active or frossted enemies
	{
		while (ActiveFighterCount != 0)
		{
			ActiveFighter.dequeue(e);
			ActiveFighterCount--;
			FD = e->GettFS() + e->GetArrvTime();
			KD = 0;		// since he's not dead asln
			LT = CurrentTimeStep - e->GetArrvTime();	// since he's still alive
			outputfile << 0 << " " << e->GetID() << "     "		// KTS is zero since he's still alive
				<< FD << " " << KD << " " << LT << "\n";

			FirstShotDelays += FD;		// getting the sum of FD's
			KillDaleys += KD;			// getting the sum of KD's
		}

		while (ActiveFreezerCount != 0)
		{
			ActiveFreezer.dequeue(e);
			ActiveFreezerCount--;
			FD = e->GettFS() + e->GetArrvTime();
			KD = 0;		// since he's not dead asln
			LT = CurrentTimeStep - e->GetArrvTime();	// since he's still alive
			outputfile << 0 << " " << e->GetID() << "     "		// KTS is zero since he's still alive
				<< FD << " " << KD << " " << LT << "\n";

			FirstShotDelays += FD;		// getting the sum of FD's
			KillDaleys += KD;			// getting the sum of KD's
		}

		while (ActiveHealerCount != 0)
		{
			ActiveHlealer.dequeue(e);
			ActiveHealerCount--;
			FD = e->GettFS() + e->GetArrvTime();
			KD = 0;		// since he's not dead asln
			LT = CurrentTimeStep - e->GetArrvTime();	// since he's still alive
			outputfile << 0 << " " << e->GetID() << "     "		// KTS is zero since he's still alive
				<< FD << " " << KD << " " << LT << "\n";

			FirstShotDelays += FD;		// getting the sum of FD's
			KillDaleys += KD;			// getting the sum of KD's
		}

		while (FrostedCount != 0)
		{
			Frosted.dequeue(e);
			FrostedCount--;
			FD = e->GettFS() + e->GetArrvTime();
			KD = 0;		// since he's not dead asln
			LT = CurrentTimeStep - e->GetArrvTime();	// since he's still alive
			outputfile << 0 << " " << e->GetID() << "     "		// KTS is zero since he's still alive
				<< FD << " " << KD << " " << LT << "\n";

			FirstShotDelays += FD;		// getting the sum of FD's
			KillDaleys += KD;			// getting the sum of KD's
		}
	}

	outputfile << "Castle Total Damage: " << BCastle.GetInitialHealth() - BCastle.GetHealth() << "\n";

	outputfile << "Total Enemies" << EnemyCount << "\n";
	outputfile.close();

	outputfile << "Average First-Shot Delay" << FirstShotDelays / EnemyCount << "\n";

	outputfile << "Average Kill Delay" << KillDaleys / EnemyCount << "\n";

	outputfile.close();

	delete e;
}

void Battle::StepByStepMode()
{
	CurrentTimeStep = 0;
	LoadingFunction();
	AddAllListsToDrawingList();
	pGUI->UpdateInterface(CurrentTimeStep);

	while (KilledCount < EnemyCount)
	{
		CurrentTimeStep++;
		ActivateEnemies();
		castleAttack();
		enemiesAttack();
		updateEnemies();

		pGUI->ResetDrawingList();
		AddAllListsToDrawingList();
		pGUI->UpdateInterface(CurrentTimeStep);

		Sleep(1000);		// Action of proceeding
	}
	outputing();	//output processing
}

void Battle::SilentMode()
{
	CurrentTimeStep = 0;
	LoadingFunction();
	AddAllListsToDrawingList();

	while (KilledCount < EnemyCount)
	{
		CurrentTimeStep++;
		ActivateEnemies();
		castleAttack();
		enemiesAttack();
		updateEnemies();
	}
	outputing();	// output processing
}


void Battle::castleAttack()
{
	if(!BCastle.GetFrosted())
	{

		Enemy* e;
		while (ActiveFighter.dequeue(e)&& BCastle.GetN() !=0)
		{
			ActiveFighterCount--;
			BCastle.SetN(BCastle.GetN() - 1);
			e->effect_onSpeed();
			if ((e->GetType() == 0)|| (e->GetType() == 2))
			{
				e->SetDCE(BCastle.GetPower() / (e->GetDistance()));
		Queue<Enemy*> all_Actives;
		while (ActiveFighter.dequeue(e) || ActiveHealer.dequeue(e) || ActiveFreezer.dequeue(e))
		{
			all_Actives.enqueue(e);
		}
		while (all_Actives.dequeue(e)&& BCastle.GetN() !=0)
		{
			ActiveFighter.dequeue(e);
			BCastle.SetN(BCastle.GetN() - 1);
			if (e->GetType() == 0)
			{
				e->SetDCE(BCastle.GetPower() / (e->GetDistance()));
				ActiveFighterCount--;
			}
			else if (e->GetType() == 2)
			{
				e->SetDCE(BCastle.GetPower() / (e->GetDistance()));
				ActiveFreezerCount--;
			}
			else if (e->GetType() == 1)
			{
				e->SetDCE(0.5*BCastle.GetPower() / (e->GetDistance()));

				ActiveHealerCount--;
			}
			e->SetChanged_Health((e->GetHealth()) - (e->GetDCE()));
			e->effect_onSpeed();
			switch (Ballence_ofCastle)
			{
			
				case 1 :
				{
					BCastle.Attack_Bullets();
				}
				case 2:
				{
					BCastle.Attack_Ice();
					e->SetFrosted(1);
				}
				case 3:
				{
					BCastle.Attack_Bullets();
				}
				case 4:
				{
					BCastle.Attack_Bullets();
				}
				case 5:
				{
					BCastle.Attack_Bullets();
				}

			}
		}
	}
}


void Battle::enemiesAttack()
{

		Enemy *e;
		if (!e->Getreload_period())
		{
			if (e->GetTYPE() == FIGHTER)
			{
				int k;
				double DFC = (k / ((e->GetDistance())*(e->Getpower())));
				if (e->GetChanged_Health < (0.5*(e->GetHealth())))
				{
					k = 0.5;
				}
				else

				{
					k = 1;
				}
				BCastle.SetTotal_damage(BCastle.GetTotal_damage += DFC);
				e->setfirstshot(CurrentTimeStep);
			}
			else if (e->GetTYPE() == FREEZER)
			{
				//double amountofice;
				BCastle.setamountofice(BCastle.Getamountofice() + (e->Getpower() ));
				if (BCastle.Getamountofice() == 20)
					BCastle.SetFrosted(1);
			}
		}*/
		Enemy* e;
		Queue<Enemy*> tempQ;
		int countTempQ = 0, tempcounter = 0;
		tempcounter = ActiveFighterCount;

		//for activefighter
		for (int i = 0; i < tempcounter; i++)
		{
			ActiveFighter.dequeue(e);
			ActiveFighterCount--;

			Fighter* ptrF = dynamic_cast<Fighter*>(e);

			ptrF->Act();	// dectremting the distance

			tempQ.enqueue(ptrF);
			countTempQ++;
		}

		for (int i = 0; i < countTempQ; i++)
		{
			tempQ.dequeue(e);
			ActiveFighter.insert(e, e->GetID());

			ActiveFighterCount++;
		}
		//for activefreezer
		tempcounter = ActiveFreezerCount;
		for (int i = 0; i < tempcounter; i++)
		{
			ActiveFreezer.dequeue(e);
			ActiveFreezerCount--;

			Freezer* ptrFr = dynamic_cast<Freezer*>(e);

			ptrFr->Act();	// dectremting the distance

			tempQ.enqueue(ptrFr);
			countTempQ++;
		}
		// re inserting the enemies again in the ActiveFreezer stack after
		// updating the the distance
		for (int i = 0; i < countTempQ; i++)
		{
			tempQ.dequeue(e);
			ActiveFreezer.insert_Stack(e, e->GetID());	// switch the id by the real priority [for the team]
			ActiveFreezerCount++;
		}
		// freeing the memory taken by the temp variables
		for (int i = 0; i < tempcounter; i++)
		{
			tempQ.dequeue(e);
			delete e;
		}
	}

void Battle::heal()
{
	Enemy* e;
	Enemy* d;
	if (e->GetType() == HEALER && !e->GetFrosted() && !d->GetFrosted() && (e->GetType() == FIGHTER || e->GetType() == FREEZER))
	{
		int distancebetweenenemies = (e->GetDistance()) - (d->GetDistance());
		if (distancebetweenenemies <= 2)
		{
			d->SetH(d->GetHealth() + (20 / (100 * distancebetweenenemies)) * (e->GetHealth()));
		}
	}
}


//Add enemy lists (inactive, active,.....) to drawing list to be displayed on user interface
void Battle::AddAllListsToDrawingList()
{
	//Add inactive queue to drawing list
	cout << "InactiveCount" << InactiveCount << endl;
	Enemy* const * InactiveList = Inactive.toArray(InactiveCount);
	for (int i = 0; i < InactiveCount; i++)
		pGUI->AddToDrawingList(InactiveList[i]);

	Enemy* const* ActiveFighterList = ActiveFighter.toArray(ActiveFighterCount);
	for (int i = 0; i < ActiveFighterCount; i++)
		pGUI->AddToDrawingList(ActiveFighterList[i]);

	Enemy* const* ActiveHealerList = ActiveHlealer.toArray(ActiveHealerCount);
	for (int i = 0; i < ActiveHealerCount; i++)
		pGUI->AddToDrawingList(ActiveHealerList[i]);

	Enemy* const* ActiveFreezerList = ActiveFreezer.toArray(ActiveFreezerCount);
	for (int i = 0; i < ActiveFreezerCount; i++)
		pGUI->AddToDrawingList(ActiveFreezerList[i]);
	//Enemy* const* KilledList = Killed.toArray(KilledCount);
	//for (int i = 0; i < KilledCount; i++)
		//pGUI->AddToDrawingList(KilledList[i]);
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
		InactiveCount--;
		Fighter* ptrF = dynamic_cast<Fighter*>(pE);
		Healer* ptrH = dynamic_cast<Healer*>(pE);
		Freezer* ptrFr = dynamic_cast<Freezer*>(pE);

		if (ptrF)
		{
			ActiveFighter.insert(ptrF, ptrF->GetID());
				ActiveFighterCount++;
		}
		else if (ptrH)
		{
			ActiveHlealer.insert_Stack(ptrH, ptrH->GetID());
			ActiveHealerCount++;
		}
		else if (ptrFr)
		{
			ActiveFreezer.insert(ptrH, ptrH->GetID());
			ActiveFreezerCount++;
		}
	}
}
