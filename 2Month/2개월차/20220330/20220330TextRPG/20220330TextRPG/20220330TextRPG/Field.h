#pragma once
#include "Shop.h"
#include "Dungeon.h"
class CField
{
private :
	CDungeon* m_dp;
	CShop* m_sp;
	int iPlace;
public:
	int Update();
	void Start();
	void Dungeon();
	void Shop();
	CField();
	~CField();
};

