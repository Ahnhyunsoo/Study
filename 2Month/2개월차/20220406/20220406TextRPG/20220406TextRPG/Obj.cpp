#include "stdafx.h"
#include "Obj.h"


void Obj::Print()
{
	cout << "�̸� : " << m_sName << endl;
	cout << "���� : " << m_iLevel << endl;
	cout << "���ݷ� : " << m_iDamage << endl;
	cout << "ü�� : " << m_iNowHp << " / " << m_iMaxHp << endl;	
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
