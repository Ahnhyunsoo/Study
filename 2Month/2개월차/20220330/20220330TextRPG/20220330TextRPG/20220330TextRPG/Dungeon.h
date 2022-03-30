#pragma once
#include "Monster.h"
class CDungeon
{
private:
	CMonster* m_mp;
public:
	int CreateMonster();
	void Battle();
	void Easy();
	void Nomal();
	void Hard();
	CDungeon();
	~CDungeon();
};

