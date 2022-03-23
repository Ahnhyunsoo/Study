#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
	memset(&m_tInfo, 0, sizeof(INFO));
}

CPlayer::~CPlayer()
{
}

void CPlayer::SelectJob(void)
{
	int	iInput = 0;

	cout << "직업을 선택하세요(1. 전사 2. 마법사 3. 도적) : ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		m_tInfo.strName = "전사";
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;

	case 2:
		m_tInfo.strName = "마법사";
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;

	case 3:
		m_tInfo.strName = "도적";
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;

	default:
		break;
	}

}

void CPlayer::Render(void)
{
	cout << "===================================" << endl;
	cout << "이름 : " << m_tInfo.strName << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
}
