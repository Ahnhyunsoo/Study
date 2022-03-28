#include "stdafx.h"
#include "Player.h"

int CPlayer::CreatePlayer()
{
	while (true)
	{
		system("cls");
		cout << "1. ����, 2. ������, 3. ���� : ";
		int Input = 0;
		cin >> Input;
		switch (Input)
		{
		case 1:
			m_sName = "����";
			m_iMaxHp = 200;
			m_iNowHp = m_iMaxHp;
			m_iDamage = 20;
			m_iExp = 100;
			return 0;

		case 2:
			m_sName = "������";
			m_iMaxHp = 100;
			m_iNowHp = m_iMaxHp;
			m_iDamage = 50;
			m_iExp = 100;
			return 0;

		case 3:
			cout << "������ �����մϴ�" << endl;
			return 1;
		default :
			continue;
		}
	}
}

void CPlayer::PlayerInfo()
{
	cout << "�̸� : " << m_sName << endl;
	cout << "���� : " << m_iLevel << endl;
	cout << "���ݷ� : " << m_iDamage << endl;
	cout << "ü�� : " << m_iNowHp << " / " << m_iMaxHp << endl;
	cout << "����ġ : " << m_iNowExp << " / " << m_iExp << endl;
	cout << "������ : " << m_iGold << endl;
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
	cout << "����߽��ϴ�" << endl;
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
	cout << "���͸� óġ�߽��ϴ�" << endl;
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
	cout << "������!!!" << endl;
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
			if (m_ivp[_Slot-1].GetName() == "����");
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
		cout << "�������� �����ϴ�" << endl;
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
