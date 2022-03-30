#pragma once
#include "Obj.h"
class CPlayer final:
	public CObj
{
private:
	int m_iNowExp;
public:
	void Create(string _Name, int Level, int Damage, int Hp, int Exp, int Gold);
	void Print();
	void RecoverHp() { m_iNowHp = m_iMaxHp; }
	void Die(int _Exp);
	void Kill(int _Exp, int _Gold);
	void LevelUp();
	CPlayer();
	~CPlayer();
};

