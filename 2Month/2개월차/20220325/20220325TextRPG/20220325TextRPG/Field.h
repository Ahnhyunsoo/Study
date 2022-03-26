#pragma once
#include "Dungeon.h"

class Field
{
private:
	int m_iplace;
	Dungeon* m_dp;
public:

	void SetPlace(int _place);
	int Menu();
	Field();
	~Field();
};

