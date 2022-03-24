#include "stdafx.h"
#include "Player.h"


int Player::Input()
{
	if(m_pp == NULL)
	{
		m_pp = new PInfo;
	}
	else
	{
		SAVE_DELETE(m_pp);
		return 1;
	}
	
	int Input = 0;

	while (true)
	{
		cout << "1. 전사, 2. 마법사, 3. 도적, 4. 불러오기, 5. 종료 : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			m_pp->name = "전사";
			m_pp->m_MaxHp = 200;
			m_pp->m_NowHp = m_pp->m_MaxHp;
			m_pp->m_Level = 1;
			m_pp->m_Damage = 10;
			m_pp->m_MaxExp = 100;
			m_pp->m_NowExp = 0;
		return 0;

		case 2: 
			m_pp->name = "마법사";
			m_pp->m_MaxHp = 100;
			m_pp->m_NowHp = m_pp->m_MaxHp;
			m_pp->m_Level = 1;
			m_pp->m_Damage = 50;
			m_pp->m_MaxExp = 100;
			m_pp->m_NowExp = 0;
		return 0;

		case 3:
			m_pp->name = "도적";
			m_pp->m_MaxHp = 150;
			m_pp->m_NowHp = m_pp->m_MaxHp;
			m_pp->m_Level = 1;
			m_pp->m_Damage = 20;
			m_pp->m_MaxExp = 100;
			m_pp->m_NowExp = 0;
		return 0;

		case 4:
			cout << "미구현" << endl;
			system("pause");
			continue;
		case 5:
			cout << "게임을 종료합니다" << endl;
			if (m_pp != NULL)
			{
				SAVE_DELETE(m_pp);
			}
			return 1;

		default :
			continue;
		}
	}
}


void Player::Output()
{
	cout << "직업 : " << m_pp->name << endl;
	cout << "레벨 : " << m_pp->m_Level << endl;
	cout << "공격력 : " << m_pp->m_Damage << endl;
	cout << "체력 : " << m_pp->m_NowHp << " / " << m_pp->m_MaxHp << endl;
	cout << "경험치 : " << m_pp->m_NowExp << " / " << m_pp->m_MaxExp << endl;
	cout << "========================" << endl;
}

int Player::Hp(int Damage)
{
	if (m_pp->m_NowHp > Damage)
	{
		m_pp->m_NowHp -= Damage;
		return 0;
	}
	else
	{
		return 1;
	}
}

void Player::Die(int Exp)
{
	if (m_pp->m_NowExp <= Exp)
	{
		m_pp->m_NowExp = 0;
	}
	else if (m_pp->m_NowExp > Exp)
	{
		m_pp->m_NowExp -= Exp;
	}
	cout << "캐릭터가 사망했습니다 마을로 돌아갑니다" << endl;
	m_pp->m_NowHp = m_pp->m_MaxHp;
	system("pause");
}

Player::Player()
{
}


Player::~Player()
{
}
