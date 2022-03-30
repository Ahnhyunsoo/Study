#include "stdafx.h"
#include "Player.h"


void CPlayer::Create(string _Name, int Level, int Damage, int Hp, int Exp, int Gold)
{	
		CObj::Create(_Name, Level, Damage, Hp, Exp, Gold);
		m_iNowExp = 0;

		
}

void CPlayer::Print()
{
	CObj::Print();
	cout << "����ġ : " << m_iNowExp << " / " << m_iMaxExp << endl;
	cout << "������ : " << m_iGold << endl;
	cout << "=======================================" << endl;
}



void CPlayer::Die(int _Exp)
{
	cout << "����߽��ϴ�" << endl;
	system("pause");
	m_iNowHp = m_iMaxHp;
	if (m_iNowExp > _Exp)
	{
		m_iNowExp -= _Exp;
	}
	else
		m_iNowExp = 0;
	
	
}

void CPlayer::Kill(int _Exp, int _Gold)
{
	cout << "���͸� óġ�߽��ϴ�" << endl;
	system("pause");
	m_iGold += _Gold;

	if (m_iNowExp + _Exp >= m_iMaxExp)
	{
		m_iNowExp = (m_iNowExp+_Exp) - m_iMaxExp;
		m_iMaxExp += 50;
		LevelUp();
	}
	else
	{
		m_iNowExp += _Exp;
	}
}

void CPlayer::LevelUp()
{
	int point = 3;
	cout << "������ !!!!" << endl;
	m_iNowHp = m_iMaxHp;
	system("pause");
	while (point > 0)
	{
		int Input = 0;
		system("cls");
		Print();
		cout << "1. ���ݷ�UP, 2. ü��UP, 3. ������UP : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			m_iDamage += 10;
			point -= 1;
			break;

		case 2:
			m_iMaxHp += 20;
			m_iNowHp = m_iMaxHp;
			point -= 1;
			break;

		case 3:
			m_iGold += 500;
			point -= 1;
			break;

		default :
			continue;
		}
	}
		
}

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}
