#include "stdafx.h"
#include "Player.h"
string Player::Name()
{
	string name;
	system("cls");
	cout << "ĳ������ �̸��� �Է��ϼ��� : ";
	cin >> name;
	return name;
}

void Player::Knight()
{
	m_PA->m_ClassName = "�Ͱ˻�";
	m_PA->m_Name = Name();
	m_PA->m_Level = 1;
	m_PA->m_Damage = 10;
	m_PA->m_MaxHp = 200;
	m_PA->m_NowHp = m_PA->m_MaxHp;
	m_PA->m_MaxMp = 50;
	m_PA->m_NowMp = m_PA->m_MaxMp;
	m_PA->m_MaxExp =100;
	m_PA->m_NowExp = m_PA->m_MaxExp;
	m_PA->m_Gold = 0;
	m_PA->m_Skill[0] = { ""};
}

void Player::Fighter()
{
	m_PA->m_ClassName = "������";
	m_PA->m_Name = Name();
	m_PA->m_Level = 1;
	m_PA->m_Damage = 10;
	m_PA->m_MaxHp = 200;
	m_PA->m_NowHp = m_PA->m_MaxHp;
	m_PA->m_MaxMp = 100;
	m_PA->m_NowMp = m_PA->m_MaxMp;
	m_PA->m_MaxExp = 100;
	m_PA->m_NowExp = m_PA->m_MaxExp;
	m_PA->m_Gold = 0;
	m_PA->m_Skill[2] = { "","" };

}

void Player::Gunner()
{
	m_PA->m_ClassName = "�ų�";
	m_PA->m_Name = Name();
	m_PA->m_Level = 1;
	m_PA->m_Damage = 15;
	m_PA->m_MaxHp = 150;
	m_PA->m_NowHp = m_PA->m_MaxHp;
	m_PA->m_MaxMp = 100;
	m_PA->m_NowMp = m_PA->m_MaxMp;
	m_PA->m_MaxExp = 100;
	m_PA->m_NowExp = m_PA->m_MaxExp;
	m_PA->m_Gold = 0;
	m_PA->m_Skill[2] = { "","" };
}

void Player::Mage()
{
	m_PA->m_ClassName = "������";
	m_PA->m_Name = Name();
	m_PA->m_Level = 1;
	m_PA->m_Damage = 5;
	m_PA->m_MaxHp = 100;
	m_PA->m_NowHp = m_PA->m_MaxHp;
	m_PA->m_MaxMp = 300;
	m_PA->m_NowMp = m_PA->m_MaxMp;
	m_PA->m_MaxExp = 100;
	m_PA->m_NowExp = m_PA->m_MaxExp;
	m_PA->m_Gold = 0;
	m_PA->m_Skill[2] = { "","" };
}

void Player::Create()
{
	m_PA = new PInfo;
	int Input = 0;
	cout << "������ �������ּ���" << endl;
	cout << "1. �Ͱ˻�, 2. ������, 3. �ų�, 4. ������ : ";
	cin >> Input;
	while (true)
	{
		switch (Input)
		{
		case 1:
			Knight();
			PrintInfo();
			system("pause");
		case 2:
			Fighter();

		case 3:
			Gunner();

		case 4:
			Mage();

		case 5:
			cout << "������ �����մϴ�" << endl;
			SAVE_DELETE(m_PA);
			exit(0);
		}
	}
}

void Player::PrintInfo()
{
	cout << "��������������������������������������������������������������" << endl;
	cout << "��" << "���� : " << m_PA->m_ClassName << "��" << endl;
}

PA Player::GetP()
{
	return m_PA;
}


Player::Player()
{
}


Player::~Player()
{
}
