#pragma once
#include "Player.h"
#include "Field.h"
class CGame
{
private:
	CField* m_fp;
public:
	static CPlayer* m_pp;
public:
	void exe();
	CGame();
	~CGame();
};

