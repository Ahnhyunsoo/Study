#pragma once
#include "Obj.h"
class Monster :
	public Obj
{
public:
	int GetDamage() { return m_iDamage; }
	int GetExp() { return m_iExp; }
	int GetGold() { return m_iGold; }
	Monster();
	~Monster();
};

