#include "stdafx.h"
#include "Player.h"

void Player::Knight()
{
	string name;
	cout << "ĳ�����̸� : ";
	cin >> name;
	m_pp->m_sCharacter = "�Ͱ˻�";
	m_pp->m_sName = name;
	m_pp->m_iDamage = 20;
	m_pp->m_iMaxHp = 200;
	m_pp->m_iNowHp = m_pp->m_iMaxHp;
	m_pp->m_iMaxMp = 100;
	m_pp->m_iNowMp = m_pp->m_iMaxMp;
	m_pp->m_iMaxExp = 100;
	
}

void Player::Fighter()
{
	string name;
	cout << "ĳ�����̸� : ";
	cin >> name;
	m_pp->m_sCharacter = "������";
	m_pp->m_sName = name;
	m_pp->m_iDamage = 15;
	m_pp->m_iMaxHp = 150;
	m_pp->m_iNowHp = m_pp->m_iMaxHp;
	m_pp->m_iMaxMp = 200;
	m_pp->m_iNowMp = m_pp->m_iMaxMp;
	m_pp->m_iMaxExp = 100;
}

void Player::Mage()
{
	string name;
	cout << "ĳ�����̸� : ";
	cin >> name;
	m_pp->m_sCharacter = "������";
	m_pp->m_sName = name;
	m_pp->m_iDamage = 10;
	m_pp->m_iMaxHp = 100;
	m_pp->m_iNowHp = m_pp->m_iMaxHp;
	m_pp->m_iMaxMp = 400;
	m_pp->m_iNowMp = m_pp->m_iMaxMp;
	m_pp->m_iMaxExp = 100;
}


int Player::CreatePlayer()
{
	
	if (m_pp == NULL)
	{
		m_pp = new PInfo;
	}

	if (m_ip == NULL)
	{
		m_ip = new Inventory[10];
	}

	for (int i = 0; i < 10; ++i)
	{
		m_ip[i].Slot(i+1);
	}



	while (true)
	{
		int Input = 0;
		system("cls");
		cout << "1. �Ͱ˻�, 2. ������, 3. ������, 4. �ҷ�����, 5. ���� : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			Knight();
			return 0;

		case 2:
			Fighter();
			return 0;

		case 3:
			Mage();
			return 0;

		case 4:
			cout << "�̱���" << endl;
			break;

		case 5:
			cout << "������ �����մϴ�" << endl;
			SAVE_DELETE(m_pp);
			return 1;
			
		default:
			continue;
		}
	}
}

void Player::PrintInfo()
{
	cout << "���� : " << m_pp->m_sCharacter << endl;
	cout << "�̸� : " << m_pp->m_sName << endl;
	cout << "���� : " << m_pp->m_iLevel << endl;
	cout << "���ݷ� : " << m_pp->m_iDamage << endl;
	cout << "ü�� : " << m_pp->m_iNowHp << " / " << m_pp->m_iMaxHp << endl;
	cout << "���� : " << m_pp->m_iNowMp << " / " << m_pp->m_iMaxMp << endl;
	cout << "����ġ : " << m_pp->m_iNowExp << " / " << m_pp->m_iMaxExp << endl;
	cout << "������ : " << m_pp->m_iGold << endl;
	cout << "=================================" << endl;
}

int Player::Hp(int _Damage)
{
	if (m_pp->m_iNowHp <= _Damage)
	{
		return 1;
	}
	else
	{
		cout << "�÷��̾� : Hp -" << _Damage << endl;
		m_pp->m_iNowHp -= _Damage;
		return 0;
	}
}

void Player::Die(int _Exp)
{
	cout << "����߽��ϴ�" << endl;
	system("pause");
	m_pp->m_iNowHp = m_pp->m_iMaxHp;
	
	if (m_pp->m_iNowExp <= _Exp)
	{
		m_pp->m_iNowExp = 0;
	}
	else
	{
		m_pp->m_iNowExp -= _Exp;
	}

}

int Player::Kill(int _Exp, int _Gold)
{
	if (m_pp->m_iNowExp + _Exp >= m_pp->m_iMaxExp)
	{
		m_pp->m_iNowExp = 0;
		m_pp->m_iGold += _Gold;
		return 1;
	}
	else
	{
		m_pp->m_iNowExp += _Exp;
		m_pp->m_iGold += _Gold;
		return 0;
	}
}

void Player::LevelUp()
{
	int Point = 3;
	cout << "������ !!!" << endl;
	m_pp->m_iMaxExp += 50;
	m_pp->m_iNowExp = 0;
	m_pp->m_iGold += 100;
	m_pp->m_iNowHp = m_pp->m_iMaxHp;
	m_pp->m_iNowMp = m_pp->m_iMaxMp;

	system("pause");
	while (Point >= 1)
	{
		int Input = 0;
		system("cls");
		PrintInfo();
		cout << "��½�ų �ɷ�ġ�� �������ּ���" << endl;
		cout << "1.���ݷ�, 2.Hp, 3.Mp : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			m_pp->m_iDamage += 10;
			break;

		case 2:
			m_pp->m_iMaxHp += 20;
			m_pp->m_iNowHp = m_pp->m_iMaxHp;
			break;

		case 3:
			m_pp->m_iMaxMp += 30;
			m_pp->m_iNowMp = m_pp->m_iMaxMp;
			break;

		default:
			cout << "�߸� �Է� �ϼ̽��ϴ�" << endl;
			system("pause");
			continue;
		}
		Point -= 1;
	}
}

void Player::PrintInventory()
{
	cout << "���� : " << m_pp->m_sCharacter << endl;
	cout << "�̸� : " << m_pp->m_sName << endl;
	cout << "������ : " << m_pp->m_iGold << endl << endl;

	for (int i = 0; i < 10; ++i)
	{
		m_ip[i].PrintInventory();
	}
}


Player::Player()
{
}


Player::~Player()
{
}
