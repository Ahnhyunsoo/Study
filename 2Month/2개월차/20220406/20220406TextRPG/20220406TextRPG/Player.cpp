#include "stdafx.h"
#include "Player.h"


void Player::Print()
{
	Obj::Print();
	cout << "����ġ : " << m_iNowExp << " / " << m_iExp << endl;
	cout << "������ : " << m_iGold << endl;
	cout << "���� : " << m_sWP << endl; 
	cout << "�� : " << m_sAM << endl;
	cout << "========================================" << endl;



}

void Player::Kill(int Exp, int Gold)
{
	cout << "���� óġ�߽��ϴ�" << endl;
	m_iKill += 1;
	system("pause");
	m_iGold += Gold;
	if (m_iNowExp + Exp >= m_iExp)
	{
		m_iNowExp = (m_iNowExp + Exp) - m_iExp;
		LevelUp();
		m_iKill += 1;
	}
	else
		m_iNowExp += Exp;

}

void Player::LevelUp()
{
	system("cls");
	cout << "������!!!" << endl;
	system("pause");
	m_iDamage += 20;
	m_iMaxHp += 50;
	m_iNowHp = m_iMaxHp;
	m_iExp += 50;
	m_iGold += 100;
	m_iLevel += 1;

}

bool Player::Create()
{
	while (true)
	{
		int Input;
		cout << "1. ������, 2. ������, 3. ���� : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			Fighter();
			Print();
			return 0;

		case 2:
			Wizard();
			Print();
			return 0;

		case 3:
			cout << "������ �����մϴ�" << endl;
			return 1;

		default:
			continue;
		}
	}
}

void Player::Fighter()
{
	string name = "������";
	int level = 1;
	int damage = 20;
	int hp = 200;
	int exp = 100;
	int gold = 100;

	Obj::Create(name, level, damage, hp, exp, gold);
}

void Player::Wizard()
{
	string name = "������";
	int level = 1;
	int damage = 50;
	int hp = 100;
	int exp = 100;
	int gold = 100;

	Obj::Create(name, level, damage, hp, exp, gold);
}





Player::Player()
	:m_iAttack(0),m_igetdamage(0),m_iDie(0),m_iKill(0),m_iNowExp(0),m_sWP("����"),m_sAM("����")
{
	m_ip = new Inventory;	
}




Player::~Player()
{
}
