#include "stdafx.h"
#include "Player.h"

int CPlayer::CreatePlayer()
{
	while (true)
	{
		system("cls");
		cout << "1. 전사, 2. 마법사, 3. 종료 : ";
		int Input = 0;
		cin >> Input;
		switch (Input)
		{
		case 1:
			m_sName = "전사";
			m_iMaxHp = 200;
			m_iNowHp = m_iMaxHp;
			m_iDamage = 20;
			m_iExp = 100;
			return 0;

		case 2:
			m_sName = "마법사";
			m_iMaxHp = 100;
			m_iNowHp = m_iMaxHp;
			m_iDamage = 50;
			m_iExp = 100;
			return 0;

		case 3:
			cout << "게임을 종료합니다" << endl;
			return 1;
		default :
			continue;
		}
	}
}

void CPlayer::PlayerInfo()
{
	cout << "이름 : " << m_sName << endl;
	cout << "레벨 : " << m_iLevel << endl;
	cout << "공격력 : " << m_iDamage << endl;
	cout << "체력 : " << m_iNowHp << " / " << m_iMaxHp << endl;
	cout << "경험치 : " << m_iNowExp << " / " << m_iExp << endl;
	cout << "소지금 : " << m_iGold << endl;
	cout << "=====================================" << endl;
}

int CPlayer::SetPHp(int _Damage)
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

void CPlayer::Die(int _Exp)
{
	cout << "사망했습니다" << endl;
	system("pause");
	if (m_iNowExp > _Exp)
	{
		m_iNowExp -= _Exp;
	}
	else
	{
		m_iNowExp = 0;
	}
	m_iNowHp = m_iMaxHp;
}

void CPlayer::Kill(int _Exp, int _Gold)
{
	cout << "몬스터를 처치했습니다" << endl;
	system("pause");
	if (m_iNowExp + _Exp >= m_iExp)
	{
		m_iGold += _Gold;
		LevelUp();
	}
	else
	{
		m_iGold += _Gold;
		m_iNowExp += _Exp;
	}
}

void CPlayer::LevelUp()
{
	cout << "레벨업!!!" << endl;
	system("pause");
	m_iMaxHp += 50;
	m_iNowHp = m_iMaxHp;
	m_iDamage += 10;
	m_iExp += 50;
	m_iNowExp = 0;
	m_iLevel += 1;
	m_iGold += 100;
}

void CPlayer::InvenInfo()
{
	for (int i = 0; i < 5; ++i)
	{
		m_ivp[i].PrintInventory();
	}
}

void CPlayer::SetInven(int _Slot)
{
	if (_Slot <= 5)
	{
		if (m_ivp[_Slot - 1].SetInven() == 1)
		{
			if (m_ivp[_Slot-1].GetName() == "포션");
			{
				if (m_iNowHp + 30 >= m_iMaxHp)
				{
					m_iNowHp = m_iMaxHp;
				}
				else
				{
					m_iNowHp += 30;
				}
			}
		}
	}
	else
	{
		cout << "아이템이 없습니다" << endl;
		system("pause");
	}
	
}

CPlayer::CPlayer()
{
	m_iLevel = 1;
	m_iGold = 0;
	m_iNowExp = 0;
	m_ivp = new CInventory[5];
	for (int i = 0; i < 5; ++i)
	{
		m_ivp[i].InitSlot(i);
	}
	
}


CPlayer::~CPlayer()
{
}
