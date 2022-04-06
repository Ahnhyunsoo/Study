#pragma once
#include "Dungeon.h"
#include "Shop.h"



class Field
{
private:
	Dungeon* m_dp;
	Shop* m_sp;
	int place;
	
public:
	bool Update();
	void Menu();
	void DungeonFront();
	void Shoping();
	void Mypage();
	Field();
	~Field();
};

