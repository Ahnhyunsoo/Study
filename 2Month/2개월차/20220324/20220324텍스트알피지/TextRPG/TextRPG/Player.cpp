#include "stdafx.h"
#include "Player.h"


void Player::Input()
{
	if(m_pp == NULL)
	{
		m_pp = new PInfo;
	}
	else
	{
		SAVE_DELETE(m_pp);
		m_pp = new PInfo;
	}
	
	int Input = 0;

	while (true)
	{
		cout << "1. ����, 2. ������, 3. ����, 4. �ҷ�����, 5. ���� : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			m_pp->name = "����";
			m_pp->m_MaxHp = 200;
			m_pp->m_NowHp = m_pp->m_MaxHp;
			m_pp->m_Level = 1;
			m_pp->m_Damage = 10;
			m_pp->m_MaxExp = 100;
			m_pp->m_NowExp = 0;
			Output();
		return;

		case 2: 
			m_pp->name = "������";
			m_pp->m_MaxHp = 100;
			m_pp->m_NowHp = m_pp->m_MaxHp;
			m_pp->m_Level = 1;
			m_pp->m_Damage = 50;
			m_pp->m_MaxExp = 100;
			m_pp->m_NowExp = 0;
			Output();
		return;

		case 3:
			m_pp->name = "����";
			m_pp->m_MaxHp = 150;
			m_pp->m_NowHp = m_pp->m_MaxHp;
			m_pp->m_Level = 1;
			m_pp->m_Damage = 20;
			m_pp->m_MaxExp = 100;
			m_pp->m_NowExp = 0;
		return;

		case 4:
			cout << "�̱���" << endl;
			system("pause");
			continue;
		case 5:
			cout << "������ �����մϴ�" << endl;
			return;

		default :
			continue;
		}
	}
}


void Player::Output()
{
	cout << m_pp->name << endl;
	cout << m_pp->m_Damage << endl;
	cout << m_pp->m_NowHp << endl;
}

Player::Player()
{
}


Player::~Player()
{
}
