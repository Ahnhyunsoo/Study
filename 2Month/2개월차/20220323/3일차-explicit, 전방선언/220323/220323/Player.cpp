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

	cout << "������ �����ϼ���(1. ���� 2. ������ 3. ����) : ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		m_tInfo.strName = "����";
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;

	case 2:
		m_tInfo.strName = "������";
		m_tInfo.iAttack = 10;
		m_tInfo.iHp = 100;
		break;

	case 3:
		m_tInfo.strName = "����";
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
	cout << "�̸� : " << m_tInfo.strName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t���ݷ� : " << m_tInfo.iAttack << endl;
}
