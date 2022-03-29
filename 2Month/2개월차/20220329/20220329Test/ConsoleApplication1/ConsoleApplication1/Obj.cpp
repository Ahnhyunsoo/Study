#include "stdafx.h"
#include "Obj.h"

void CObj::Create(string _Name, int _Damage, int _Hp)
{
	m_sName = _Name;
	m_iDamage = _Damage;
	m_iMaxHp = _Hp;
	m_iNowHp = m_iMaxHp;
	m_iLevel = 1;
}

void CObj::Print()
{
	cout << m_sName << endl;
	cout << m_iDamage << endl;
	cout << m_iLevel << endl;
	cout << m_iMaxHp << endl;
	cout << m_iNowHp << endl;
	
}

void CObj::Test()
{
	cout << "ºÎ¸ð" << endl;
}

CObj::CObj()
{
}


CObj::~CObj()
{
}
