#include "stdafx.h"
#include "Maingame.h"
#include "Monster.h"

void Monster::CreateMonster(string _dg)
{
	if (m_pmp == NULL)
	{
		m_pmp = new MInfo;
		if (_dg == "머크우드")
		{
			Tau();
			return;
		}
		else if (_dg == "그락카락")
		{
			Tauking();
			return;
		}
		else if (_dg == "어둠의선더랜드")
		{
			Zombie();
			return;
		}

		else if (_dg == "신전외각")
		{
			Sindo();
			return;
		}
		else if (_dg == "백야")
		{
			Tentacle();
			return;
		}
		else if (_dg == "제2척추")
		{
			Lotus();
			return;
		}

		else if (_dg == "거미소굴")
		{
			Spider();
			return;
		}
		else if (_dg == "용암굴")
		{
			Ghost();
			return;
		}
		else
		{
			Knight();
			return;
		}
	}
		
	
	
}

int Monster::Hp(int _Damage)
{
	if (m_pmp->m_iNowHp <= _Damage)
	{
		m_pmp->m_iNowHp = 0;
		return 1;
	}
	else
	{
		cout << "몬스터 : Hp -" << _Damage << endl;
		m_pmp->m_iNowHp -= _Damage;
		return 0;
	}
}



void Monster::PrintMonster()
{
	cout << "이름 : " << m_pmp->m_sName << endl;
	cout << "레벨 : " << m_pmp->m_iLevel << endl;
	cout << "공격력 : " << m_pmp->m_iDamage << endl;
	cout << "체력 : " << m_pmp->m_iNowHp << " / " << m_pmp->m_iMaxHp << endl;
	cout << "마나 : " << m_pmp->m_iNowMp << " / " << m_pmp->m_iMaxMp << endl;
	cout << "경험치 : " << m_pmp->m_Exp << endl;
	cout << "골드 : " << m_pmp->m_iGold << endl;
	cout << "=================================" << endl;
}

void Monster::Tau()
{
	m_pmp->m_sName = "타우";
	m_pmp->m_iLevel = 1;
	m_pmp->m_iDamage = 5; 
	m_pmp->m_iMaxHp = 20;
	m_pmp->m_iNowHp = m_pmp->m_iMaxHp;
	m_pmp->m_iMaxMp = 10;
	m_pmp->m_iNowMp = m_pmp->m_iMaxMp;
	m_pmp->m_Exp = 5;
	m_pmp->m_iGold = Maingame::GetRandom(1, 10);
}

void Monster::Tauking()
{
	m_pmp->m_sName = "타우킹";
	m_pmp->m_iLevel = 3;
	m_pmp->m_iDamage = 10;
	m_pmp->m_iMaxHp = 40;
	m_pmp->m_iNowHp = m_pmp->m_iMaxHp;
	m_pmp->m_iMaxMp = 20;
	m_pmp->m_iNowMp = m_pmp->m_iMaxMp;
	m_pmp->m_Exp = 10;
	m_pmp->m_iGold = Maingame::GetRandom(5, 10);
}

void Monster::Zombie()
{
	m_pmp->m_sName = "좀비";
	m_pmp->m_iLevel = 5;
	m_pmp->m_iDamage = 15;
	m_pmp->m_iMaxHp = 60;
	m_pmp->m_iNowHp = m_pmp->m_iMaxHp;
	m_pmp->m_iMaxMp = 30;
	m_pmp->m_iNowMp = m_pmp->m_iMaxMp;
	m_pmp->m_Exp = 15;
	m_pmp->m_iGold = Maingame::GetRandom(10, 20);
}

void Monster::Sindo()
{
	m_pmp->m_sName = "GBL신도";
	m_pmp->m_iLevel = 7;
	m_pmp->m_iDamage = 20;
	m_pmp->m_iMaxHp = 80;
	m_pmp->m_iNowHp = m_pmp->m_iMaxHp;
	m_pmp->m_iMaxMp = 40;
	m_pmp->m_iNowMp = m_pmp->m_iMaxMp;
	m_pmp->m_Exp = 20;
	m_pmp->m_iGold = Maingame::GetRandom(15, 25);
}

void Monster::Tentacle()
{
	m_pmp->m_sName = "텐타클";
	m_pmp->m_iLevel = 10;
	m_pmp->m_iDamage = 25;
	m_pmp->m_iMaxHp = 100;
	m_pmp->m_iNowHp = m_pmp->m_iMaxHp;
	m_pmp->m_iMaxMp = 50;
	m_pmp->m_iNowMp = m_pmp->m_iMaxMp;
	m_pmp->m_Exp = 25;
	m_pmp->m_iGold = Maingame::GetRandom(20, 30);
}

void Monster::Lotus()
{
	m_pmp->m_sName = "로터스";
	m_pmp->m_iLevel = 15;
	m_pmp->m_iDamage = 30;
	m_pmp->m_iMaxHp = 120;
	m_pmp->m_iNowHp = m_pmp->m_iMaxHp;
	m_pmp->m_iMaxMp = 60;
	m_pmp->m_iNowMp = m_pmp->m_iMaxMp;
	m_pmp->m_Exp = 30;
	m_pmp->m_iGold = Maingame::GetRandom(30, 50);
}

void Monster::Spider()
{
	m_pmp->m_sName = "거미";
	m_pmp->m_iLevel = 15;
	m_pmp->m_iDamage = 35;
	m_pmp->m_iMaxHp = 120;
	m_pmp->m_iNowHp = m_pmp->m_iMaxHp;
	m_pmp->m_iMaxMp = 60;
	m_pmp->m_iNowMp = m_pmp->m_iMaxMp;
	m_pmp->m_Exp = 40;
	m_pmp->m_iGold = Maingame::GetRandom(40, 50);
}

void Monster::Ghost()
{
	m_pmp->m_sName = "유령";
	m_pmp->m_iLevel = 17;
	m_pmp->m_iDamage = 40;
	m_pmp->m_iMaxHp = 140;
	m_pmp->m_iNowHp = m_pmp->m_iMaxHp;
	m_pmp->m_iMaxMp = 70;
	m_pmp->m_iNowMp = m_pmp->m_iMaxMp;
	m_pmp->m_Exp = 40;
	m_pmp->m_iGold = Maingame::GetRandom(50, 60);
}

void Monster::Knight()
{
	m_pmp->m_sName = "유령기사";
	m_pmp->m_iLevel = 20;
	m_pmp->m_iDamage = 60;
	m_pmp->m_iMaxHp = 200;
	m_pmp->m_iNowHp = m_pmp->m_iMaxHp;
	m_pmp->m_iMaxMp = 100;
	m_pmp->m_iNowMp = m_pmp->m_iMaxMp;
	m_pmp->m_Exp = 60;
	m_pmp->m_iGold = Maingame::GetRandom(100, 200);
}


void Monster::DeleteMonster()
{
	SAVE_DELETE(m_pmp);
}

Monster::Monster()
{
}


Monster::~Monster()
{
}
