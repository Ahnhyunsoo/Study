#include "stdafx.h"
#include "Player.h"
#include "Dungeon.h"

string Player::Name()
{
	string name;
	system("cls");
	cout << "캐릭터의 이름을 입력하세요 : ";
	cin >> name;
	return name;
	
}

void Player::in()
{
	g = new Dungeon;
}
void Player::Knight()
{
	m_PA->m_ClassName = "귀검사";
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
	m_PA->m_ClassName = "격투가";
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
	m_PA->m_ClassName = "거너";
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
	m_PA->m_ClassName = "마법사";
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
	in();
	g->CreatePlace();

}

void Player::PrintInfo()
{
	cout << "───────────────────────────────" << endl;
	cout << "│" << "직업 : " << m_PA->m_ClassName << "│" << endl;
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
