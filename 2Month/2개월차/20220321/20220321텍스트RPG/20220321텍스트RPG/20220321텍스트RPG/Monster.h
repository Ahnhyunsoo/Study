#pragma once
#include "stdafx.h"

class CMonster
{
	string m_sName;
	int m_iLevel;
	int m_iMaxHp;
	int m_iNowHp;
	int m_iDamage;
	int m_iExp;

public:
	void Monster(int Monster);
	int State(int Damage, int Hp);
	void PrintMonster();
	int GetDamage();
	int GetExp();
};