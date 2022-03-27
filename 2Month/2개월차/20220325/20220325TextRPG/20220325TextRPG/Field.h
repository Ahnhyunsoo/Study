#pragma once
#include "Dungeon.h"
#include "Shop.h"

class Field
{
private:
	int m_iplace = 1;
	Dungeon* m_dp;
	Shop* m_sp;
public:

	int Menu();
	Field();
	~Field();
};

