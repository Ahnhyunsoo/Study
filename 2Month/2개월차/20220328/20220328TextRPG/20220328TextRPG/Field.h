#pragma once
#include "Dungeon.h"
#include "Shop.h"
class CField
{
private:
	CDungeon* m_dp;
	CShop* m_sp;
	int iPlace = 1;

public:
	int Game();
	int Start();
	void Dungeon();
	void Shop();
	
	CField();
	~CField();
};

