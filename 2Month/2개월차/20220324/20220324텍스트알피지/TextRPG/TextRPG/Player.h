#pragma once
#include "stdafx.h"
#include "define.h"
class Player
{
public:
	void Input();
	void Output();
	PPInfo GetM_PP();
	Player();
	~Player();







private:
	PPInfo m_pp;
};

