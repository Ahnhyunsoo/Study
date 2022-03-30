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
	cout << "경험치 : " << m_iNowExp << " / " << m_iMaxExp << endl;
	cout << "소지금 : " << m_iGold << endl;
	cout << "=======================================" << endl;
}



void CPlayer::Die(int _Exp)
{
	cout << "사망했습니다" << endl;
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
	cout << "몬스터를 처치했습니다" << endl;
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
	cout << "레벨업 !!!!" << endl;
	m_iNowHp = m_iMaxHp;
	system("pause");
	while (point > 0)
	{
		int Input = 0;
		system("cls");
		Print();
		cout << "1. 공격력UP, 2. 체력UP, 3. 소지금UP : ";
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
