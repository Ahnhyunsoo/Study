#pragma once
#include "Obj.h"
class CMonster :
	public CObj
{
public:
	void Create(string _Name, int Level, int Damage, int Hp, int Exp, int Gold);
	void Print();
	int GetExp() { return m_iMaxExp; }	
	CMonster();
	~CMonster();
};

