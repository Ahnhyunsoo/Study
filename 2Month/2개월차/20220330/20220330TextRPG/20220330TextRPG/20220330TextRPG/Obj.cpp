#include "stdafx.h"
#include "Obj.h"

void CObj::Create(string _Name, int Level, int Damage, int Hp, int Exp, int Gold)
{
	m_sName = _Name;
	m_iLevel = Level;
	m_iDamage = Damage;
	m_iMaxHp = Hp;
	m_iNowHp = m_iMaxHp;
	m_iMaxExp = Exp;
	m_iGold = Gold;
}

void CObj::Print()
{
	cout << "직업 : " << m_sName << endl;
	cout << "레벨 : " << m_iLevel << endl;
	cout << "공격력 : " << m_iDamage << endl;
	cout << "체력 : " << m_iNowHp << " / " << m_iMaxHp << endl;
}

int CObj::SetHp(int _Damage)
{
	if (m_iNowHp <= _Damage)
	{
		return 1;
	}
	else
	{
		m_iNowHp -= _Damage;
		return 0;
	}
}

CObj::CObj()
{
}


CObj::~CObj()
{
}
