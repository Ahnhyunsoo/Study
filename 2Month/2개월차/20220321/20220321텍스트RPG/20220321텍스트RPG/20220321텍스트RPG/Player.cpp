#include "stdafx.h"
#include "Player.h"

void CPlayer::Character(int Character)
{
	if (Character == ����)
	{
		m_sName = "����";
		m_iLevel = 1;
		m_iDamage = 10;
		m_iMaxHp = 200;
		m_iNowHp = m_iMaxHp;
		m_iMaxExp = 100;
		m_iNowExp = 0;
	}
	else if (Character == ������)
	{
		m_sName = "������";
		m_iLevel = 1;
		m_iDamage = 100;
		m_iMaxHp = 100;
		m_iNowHp = m_iMaxHp;
		m_iMaxExp = 100;
		m_iNowExp = 0;
	}
	else if (Character == ����)
	{
		m_sName = "����";
		m_iLevel = 1;
		m_iDamage = 20;
		m_iMaxHp = 150;
		m_iNowHp = m_iMaxHp;
		m_iMaxExp = 100;
		m_iNowExp = 0;
	}


}

void CPlayer::PrintPlayer()
{
	cout << "���� : " << m_sName << endl;
	cout << "���� : " << m_iLevel << endl;
	cout << "���ݷ� : " << m_iDamage << endl;
	cout << "ü�� : " << m_iNowHp << " / " << m_iMaxHp << endl;
	cout << "����ġ : " << m_iNowExp << " / " << m_iMaxExp << endl;
	cout << "===============================" << endl;
}

void CPlayer::LevelUp()
{
	cout << "������ !!!" << endl;
	system("pause");
	m_iLevel += 1;
	m_iDamage += 10;
	m_iMaxHp += 20;
	m_iMaxExp += 50;
	m_iNowHp = m_iMaxHp;
	m_iNowExp = 0;
}

void CPlayer::State(int Damage, int Exp, int kill)
{
	if (m_iNowHp-Damage > 0)
	{
		m_iNowHp -= Damage;
		if (kill == 1 && m_iNowExp + Exp < m_iMaxExp && m_iNowHp > 1)
		{
			m_iNowExp += Exp;
		}
		else if (kill == 1 && m_iNowExp + Exp >= m_iMaxExp && m_iNowHp > 1)
		{
			LevelUp();
		}
		return;
	}
	else if (m_iNowHp-Damage <= 0)
	{
		cout << "����߽��ϴ�" << endl;
		system("pause");
		m_iNowHp = m_iMaxHp;
		if (kill == 0 && m_iNowExp <= Exp)
		{
			m_iNowExp = 0;
		}
		else if (kill == 0 && m_iNowExp > Exp)
		{
			m_iNowExp -= Exp;
		}
	}
	
}

int CPlayer::GetDamage()
{
	return m_iDamage;
}

int CPlayer::GetHp()
{
	return m_iNowHp;
}



