#pragma once
#include "stdafx.h"
#include "Define.h"

class Monster
{
	MMInfo m_pm;
public:
	int GetDamage() { return m_pm->m_Damage; }
	int GetExp() { return m_pm->m_Exp; }
	int Input();
	void Output();
	void Release();
	Monster();
	~Monster();
};

