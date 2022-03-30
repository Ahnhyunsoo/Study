#pragma once
#include "Obj.h"
#include "Player.h"
#include "Field.h"

class Maingame
{
	CField* m_fp;
public:
	static CObj* m_pp;
	void exe();
	Maingame();
	~Maingame();
};

