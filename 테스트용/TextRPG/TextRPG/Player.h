#pragma once
#include "stdafx.h"
#include "Define.h"

class Dungeon;

class Player
{
	PA m_PA;
	Dungeon* g;

public:
	void Knight();
	void Fighter();
	void Gunner();
	void Mage();
	void in();
	string Name();
	void Create();
	void PrintInfo();
	PA GetP();
	Player();
	~Player();
};

