#include "stdafx.h"
#include "Monster.h"

void CMonster::Monster(int Monster)
{
	if (Monster == ���)
	{
		m_sName = "���";
		m_iLevel = 1;
		m_iDamage = 10;
		m_iMaxHp = 50;
		m_iNowHp = m_iMaxHp;
		m_iExp = 10;
	}
	else if (Monster == �簡��)
	{
		m_sName = "�簡��";
		m_iLevel = 5;
		m_iDamage = 20;
		m_iMaxHp = 100;
		m_iNowHp = m_iMaxHp;
		m_iExp = 30;
	}
	else if (Monster == ����)
	{
		m_sName = "����";
		m_iLevel = 99;
		m_iDamage = 200;
		m_iMaxHp = 1500;
		m_iNowHp = m_iMaxHp;
		m_iExp = 1000;
	}


}


void CMonster::PrintMonster()
{
	cout << "���� : " << m_sName << endl;
	cout << "���� : " << m_iLevel << endl;
	cout << "���ݷ� : " << m_iDamage << endl;
	cout << "ü�� : " << m_iNowHp << " / " << m_iMaxHp << endl;
	cout << "����ġ : " << m_iExp << endl;
	cout << "===============================" << endl;
}

int CMonster::GetDamage()
{
	return m_iDamage;
}

int CMonster::GetExp()
{
	return m_iExp;
}

int CMonster::State(int Damage , int Hp)
{
	if (m_iNowHp > Damage)
	{
		m_iNowHp -= Damage;
		return 0;
	}
	else if (m_iNowHp <= Damage && Hp > m_iDamage)
	{
		cout << "���͸� óġ�߽��ϴ�" << endl;
		system("pause");
		m_iNowHp = m_iMaxHp;
		return 1;
	}
	else if (m_iNowHp <= Damage)
	{
		m_iNowHp = m_iMaxHp;
		return 0;
	}

}

