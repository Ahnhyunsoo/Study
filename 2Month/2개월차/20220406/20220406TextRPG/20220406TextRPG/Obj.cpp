#include "stdafx.h"
#include "Obj.h"


void Obj::Print()
{
	cout << "이름 : " << m_sName << endl;
	cout << "레벨 : " << m_iLevel << endl;
	cout << "공격력 : " << m_iDamage << endl;
	cout << "체력 : " << m_iNowHp << " / " << m_iMaxHp << endl;	
}

void Obj::Create(string name, int level, int damage, int hp, int exp, int gold)
{
	m_sName = name;
	m_iLevel = level;
	m_iDamage = damage;
	m_iMaxHp = hp;
	m_iNowHp = m_iMaxHp;
	m_iExp = exp;
	m_iGold = gold;
}

Obj::Obj()
{
}


Obj::~Obj()
{
}
