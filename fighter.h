#pragma once
#include "active.h"
#include"Enemies/Enemy.h"
class fighter : public active
{
protected:
	int Dfs; //Damage a fighter causes to Castle
public:
	int calculateDFS(int power, int Distance);
};

