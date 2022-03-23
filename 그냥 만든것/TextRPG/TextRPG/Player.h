#pragma once
#include "stdafx.h"
#include "Define.h"

class Player
{
	PA m_PA;
public:
	void Knight();
	void Fighter();
	void Gunner();
	void Mage();
	string Name();
	void Create();
	void PrintInfo();
	PA GetP();
	Player();
	~Player();
};

