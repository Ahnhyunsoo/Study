#pragma once
#include "stdafx.h"
#include "define.h"
class Player
{

public:
	int Input();
	void Output();
	int Hp(int Damage);
	void Die(int Exp);


	Player();
	~Player();








private:
	PPInfo m_pp;
};

