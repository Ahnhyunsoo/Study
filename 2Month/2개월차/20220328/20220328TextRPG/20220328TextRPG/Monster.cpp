#include "stdafx.h"
#include "Monster.h"

void CMonster::CreateMonster(int _Type)
{
	if (_Type == 1)
	{
		Easy();
	}
	else if (_Type == 2)
	{
		Nomal();
	}
	else
	{
		Hard();
	}
}

void CMonster::Easy()
{
	m_sName = "���ѳ�";
	m_iDamage = 5;
	m_iMaxHp = 40;
	m_iNowHp = m_iMaxHp;
	m_iLevel = 1;
	m_iGold = 10;
	m_iExp = 10;
}

void CMonster::Nomal()
{
	m_sName = "�߰���";
	m_iDamage = 10;
	m_iMaxHp = 60;
	m_iNowHp = m_iMaxHp;
	m_iLevel = 3;
	m_iGold = 30;
	m_iExp = 20;
}

void CMonster::Hard()
{
	m_sName = "���ѳ�";
	m_iDamage = 50;
	m_iMaxHp = 100;
	m_iNowHp = m_iMaxHp;
	m_iLevel = 5;
	m_iGold = 50;
	m_iExp = 50;
}

void CMonster::PrintMInfo()
{
	cout << "�̸� : " << m_sName << endl;
	cout << "���� : " << m_iLevel << endl;
	cout << "���ݷ� : " << m_iDamage << endl;
	cout << "ü�� : " << m_iNowHp << " / " << m_iMaxHp << endl;
	cout << "����ġ : " << m_iExp << endl;
	cout << "��� : " << m_iGold << endl;
	cout << "=====================================" << endl;
}

int CMonster::SetMHp(int _Damage)
{
	if (m_iNowHp <= _Damage)
	{
		return 1;
	}
	else
	{
		m_iNowHp -= _Damage;
	}
}

CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}
