#pragma once
#include "stdafx.h"

class CPlayer
{
	string m_sName;
	int m_iLevel;
	int m_iMaxHp;
	int m_iNowHp;
	int m_iDamage;
	int m_iMaxExp;
	int m_iNowExp;

public:
	void Character(int Character);
	void State(int Damage, int Exp, int kill);
	void PrintPlayer();
	void LevelUp();
	int GetDamage();
	int GetHp();
	
};
