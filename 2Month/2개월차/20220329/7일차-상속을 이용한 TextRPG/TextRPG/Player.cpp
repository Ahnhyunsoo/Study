#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
	: CObj()
{
}


CPlayer::CPlayer(char* _pName, int _iAttack, int _iMaxHp, int _iLevel /*= 1*/)
	: CObj(_pName, _iAttack, _iMaxHp, _iLevel)
{

}

CPlayer::~CPlayer()
{
}

void CPlayer::SelectJob(void)
{
	int		iInput = 0;

	cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 해호 4. 종료) : ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "전사");
		m_tInfo.iMaxHp = 100;
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxExp = 100;
		m_tInfo.iLevel = 1;
		m_tInfo.iMoney = 100000;

		break;
	
	case 2:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "마법사");
		m_tInfo.iMaxHp = 100;
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxExp = 100;
		m_tInfo.iLevel = 1;
		m_tInfo.iMoney = 100000;
		break;

	case 3:
		strcpy_s(m_tInfo.szName, sizeof(m_tInfo.szName), "해호");
		m_tInfo.iMaxHp = 100;
		m_tInfo.iAttack = 2;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iExp = 0;
		m_tInfo.iMaxExp = 10000000;
		m_tInfo.iLevel = 1;
		m_tInfo.iMoney = 0;
		break;

	case 4:
		return;

	default:
		break;
	}
}

void CPlayer::Combat_Win(int _iExp, int _iMoney)
{
	m_tInfo.iExp += _iExp;
	m_tInfo.iMoney += _iMoney;

	if (m_tInfo.iExp >= m_tInfo.iMaxExp)
	{
		m_tInfo.iLevel++;

		m_tInfo.iExp -= m_tInfo.iMaxExp;
		m_tInfo.iMaxExp += 100;
		m_tInfo.iAttack += 5;
		m_tInfo.iMaxHp += 50;
		m_tInfo.iHp = m_tInfo.iMaxHp;
	}

}

void CPlayer::Combat_Lose(void)
{
	m_tInfo.iExp >>= 1;
	m_tInfo.iMoney >>= 1;
	m_tInfo.iHp = m_tInfo.iMaxHp;
}

void CPlayer::Combat_Run(void)
{
	m_tInfo.iExp = 0;
	m_tInfo.iMoney = 0;
}
