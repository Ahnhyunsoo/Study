#pragma once
#include "stdafx.h"
#include "Define.h"
#include "Player.h"
#include "Field.h"
#include "Monster.h"


class Maingame
{
private:
	Player p;
	Monster m;
	Field* fp;
public:
	void exe();
	bool Contury();
	void DungeonEntry();
	void Dungeon();
	Maingame();
	~Maingame();
};

