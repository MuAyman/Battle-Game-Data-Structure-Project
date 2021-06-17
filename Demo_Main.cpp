#include "Battle.h"
#include "GUI\GUI.h"
#include "Priority_Queue.h"

int main()
{
	Battle* pGameBattle = new Battle;
	pGameBattle->RunSimulation();
	
	delete pGameBattle;
	
	return 0;
}
