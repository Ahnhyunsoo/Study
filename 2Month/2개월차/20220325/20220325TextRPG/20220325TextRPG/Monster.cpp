#include "stdafx.h"
#include "Maingame.h"
#include "Monster.h"

void Monster::CreateMonster(string _dg)
{
	if (m_pmp == NULL)
	{
		m_pmp = new MInfo;
		if (_dg == "��ũ���")
		{
			Tau();
			return;
		}
		else if (_dg == "�׶�ī��")
		{
			Tauking();
			return;
		}
		else if (_dg == "����Ǽ�������")
		{
			Zombie();
			return;
		}

		else if (_dg == "�����ܰ�")
		{
			Sindo();
			return;
		}
		else if (_dg == "���")
		{
			Tentacle();
			return;
		}
		else if (_dg == "��2ô��")
		{
			Lotus();
			return;
		}

		else if (_dg == "�Ź̼ұ�")
		{
			Spider();
			return;
		}
		else if (_dg == "��ϱ�")
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
		cout << "���� : Hp -" << _Damage << endl;
		m_pmp->m_iNowHp -= _Damage;
		return 0;
	}
}



void Monster::PrintMonster()
{
	cout << "�̸� : " << m_pmp->m_sName << endl;
	cout << "���� : " << m_pmp->m_iLevel << endl;
	cout << "���ݷ� : " << m_pmp->m_iDamage << endl;
	cout << "ü�� : " << m_pmp->m_iNowHp << " / " << m_pmp->m_iMaxHp << endl;
	cout << "���� : " << m_pmp->m_iNowMp << " / " << m_pmp->m_iMaxMp << endl;
	cout << "����ġ : " << m_pmp->m_Exp << endl;
	cout << "��� : " << m_pmp->m_iGold << endl;
	cout << "=================================" << endl;
}

void Monster::Tau()
{
	m_pmp->m_sName = "Ÿ��";
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
	m_pmp->m_sName = "Ÿ��ŷ";
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
	m_pmp->m_sName = "����";
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
	m_pmp->m_sName = "GBL�ŵ�";
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
	m_pmp->m_sName = "��ŸŬ";
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
	m_pmp->m_sName = "���ͽ�";
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
	m_pmp->m_sName = "�Ź�";
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
	m_pmp->m_sName = "����";
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
	m_pmp->m_sName = "���ɱ��";
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
