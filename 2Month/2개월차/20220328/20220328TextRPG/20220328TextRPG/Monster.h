#pragma once
#include "Obj.h"
class CMonster : public CObj
{
public:
	void CreateMonster(int _Type);
	void PrintMInfo();
	int SetMHp(int _Damage);
	int GetDamage() { return m_iDamage; }
	int GetExp() { return m_iExp; }
	int GetGold() { return m_iGold; }
	void Easy();
	void Nomal();
	void Hard();
	CMonster();
	~CMonster();
};

