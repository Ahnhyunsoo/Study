#pragma once
#include "stdafx.h"
#include "Player.h"
#include "Monster.h"
#include "Dungeon.h"
#include "Define.h"


class Main
{
Player m_CP;
Monster m_CM;
Dungeon m_CD;



public:
	void exe();
	Main();
	~Main();
};

