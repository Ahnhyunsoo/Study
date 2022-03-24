#pragma once
#include "stdafx.h"
#include "Player.h"
#include "Monster.h"
#include "define.h"
#include "Field.h"

class Maingame
{
	Player* m_cp;
	Field* m_pf;
	Monster* m_pm;
	
public:
	void exe();
	Maingame();
	~Maingame();
};

