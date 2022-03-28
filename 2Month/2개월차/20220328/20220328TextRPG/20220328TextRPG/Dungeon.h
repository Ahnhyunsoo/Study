#pragma once
#include "Monster.h"
class CDungeon
{
private:
	CMonster* m_mp;
public:
	void CreateMonster(int _Type);
	void PrintMInfo() { m_mp->PrintMInfo(); }
	void Battle();
	void Inven();
	void Use();
	CDungeon();
	~CDungeon();
};

