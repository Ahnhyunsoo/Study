#include "stdafx.h"
#include "Obj.h"


void CObj::CreateObj(string _Name, int _Damage, int _MaxHp, int _Exp)
{
	m_sName = _Name;
	m_iLevel = 1;
	m_iDamage = _Damage;
	m_iMaxHp = _MaxHp;
	m_iNowHp = _MaxHp;
	m_iExp = _Exp;
	m_iGold = 0;
}

void CObj::PrintObj()
{
	cout << m_sName << endl;
	cout << m_iLevel << endl;
	cout << m_iDamage << endl;
	cout << m_iMaxHp << endl;
}


CObj::CObj()
{
}


CObj::~CObj()
{
}
