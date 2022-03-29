#pragma once
#include "Obj.h"
#include "Player.h"
#include "Monster.h"
class CGame
{
private:
	CObj* m_pp;
	CObj* m_mp;
public:
	void exe();
	CGame();
	~CGame();
};

