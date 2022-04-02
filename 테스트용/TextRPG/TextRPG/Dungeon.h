#pragma once
#include "stdafx.h"
#include "Monster.h"
#include "Player.h"
#include "Define.h"

class Dungeon
{
private:
	PA m_pp;
	MA m_mp;
	Player cp;
	int place = 0;

public:
	void CreatePlace();
	void SelectMenu();
	void DungeonEntry();
	void Dungeons();
	Dungeon();
	~Dungeon();
};

