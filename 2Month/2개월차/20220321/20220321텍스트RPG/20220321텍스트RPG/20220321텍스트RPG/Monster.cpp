#include "stdafx.h"
#include "Monster.h"

void CMonster::Monster(int Monster)
{
	if (Monster == 고블린)
	{
		m_sName = "고블린";
		m_iLevel = 1;
		m_iDamage = 10;
		m_iMaxHp = 50;
		m_iNowHp = m_iMaxHp;
		m_iExp = 10;
	}
	else if (Monster == 루가루)
	{
		m_sName = "루가루";
		m_iLevel = 5;
		m_iDamage = 20;
		m_iMaxHp = 100;
		m_iNowHp = m_iMaxHp;
		m_iExp = 30;
	}
	else if (Monster == 안톤)
	{
		m_sName = "안톤";
		m_iLevel = 99;
		m_iDamage = 200;
		m_iMaxHp = 1500;
		m_iNowHp = m_iMaxHp;
		m_iExp = 1000;
	}


}


void CMonster::PrintMonster()
{
	cout << "직업 : " << m_sName << endl;
	cout << "레벨 : " << m_iLevel << endl;
	cout << "공격력 : " << m_iDamage << endl;
	cout << "체력 : " << m_iNowHp << " / " << m_iMaxHp << endl;
	cout << "경험치 : " << m_iExp << endl;
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
		cout << "몬스터를 처치했습니다" << endl;
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

