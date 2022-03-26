#pragma once
#include "Player.h"
#include "Field.h"


class Maingame
{

private:
	Field* m_fp;

public:
	static Player* m_pp;

public:
	void exe();	
	static int GetRandom(int m_mini, int m_max);
	Maingame();
	~Maingame();
};

