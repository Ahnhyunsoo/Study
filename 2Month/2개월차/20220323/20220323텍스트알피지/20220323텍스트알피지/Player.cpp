#include "stdafx.h"
#include "Player.h"


void Player::Warrior(PPInfo pp)
{
	pp->m_sName = "전사";
	pp->m_iLevel = 1;
	pp->m_iMaxHp = 200;
	pp->m_iNowHp = pp->m_iMaxHp;
	pp->m_iNowExp = 0;
	pp->m_iMaxExp = 100;
	pp->m_iDamage = 20;
	pp->m_iMaxMp = 50;
	pp->m_iNowMp = pp->m_iMaxMp;	
}

void Player::Wizard(PPInfo pp)
{
	pp->m_sName = "마법사";
	pp->m_iLevel = 1;
	pp->m_iMaxHp = 100;
	pp->m_iNowHp = pp->m_iMaxHp;
	pp->m_iNowExp = 0;
	pp->m_iMaxExp = 100;
	pp->m_iDamage = 10;
	pp->m_iMaxMp = 200;
	pp->m_iNowMp = pp->m_iMaxMp;
}

void Player::Thief(PPInfo pp)
{
	pp->m_sName = "도적";
	pp->m_iLevel = 1;
	pp->m_iMaxHp = 150;
	pp->m_iNowHp = pp->m_iMaxHp;
	pp->m_iNowExp = 0;
	pp->m_iMaxExp = 100;
	pp->m_iDamage = 30;
	pp->m_iMaxMp = 100;
	pp->m_iNowMp = pp->m_iMaxMp;
}

void Player::Create(Field* m_fp)//f12 함수로이동 (드래그한)
{
	pp = new PInfo;

	while (true)
	{		
		m_fp->SetPlace(캐릭터생성);
		int Place = m_fp->GetPlace();

		switch (m_fp->PrintMenu(Place))
		{
		case 전사:
			Player::Warrior(pp);
			m_fp->SetPlace(마을);  
			return;

		case 마법사:
			Player::Wizard(pp);
			m_fp->SetPlace(마을);
			return;

		case 도적:
			Player::Thief(pp);
			m_fp->SetPlace(마을);
			return;

		case 불러오기:
			cout << "미구현 입니다" << endl;
			system("pause");
			continue;

		case 종료:
			cout << "게임을 종료합니다" << endl;
			SAVE_DELETE(pp);
			SAVE_DELETE(m_fp);
			return;
		}
	}

	
}

void Player::Output()
{
	cout << "이름 : " << pp->m_sName << endl;
	cout << "레벨 : " << pp->m_iLevel << endl;
	cout << "체력 : " << pp->m_iNowHp << " / " << pp->m_iMaxHp << endl;
	cout << "마나 : " << pp->m_iNowMp << " / " << pp->m_iMaxMp << endl;
	cout << "공격력 : " << pp->m_iDamage << endl;
	cout << "경험치 : " << pp->m_iNowExp << " / " << pp->m_iMaxExp << endl;	
	cout << "======================" << endl;
}

void Player::PlayerHp(MMInfo _mp)
{
	if (pp->m_iNowHp > _mp->m_iDamage)
	{
		pp->m_iNowHp -= _mp->m_iDamage;
	}
	else if (pp->m_iNowHp <= _mp->m_iDamage)
	{
		cout << "캐릭터가 사망했습니다." << endl;
		system("pause");
		pp->m_iNowHp = pp->m_iMaxHp;
	}
}



PPInfo Player::GetP()
{
	return pp;
}

void Player::Release()
{
	delete pp;
	pp = nullptr;
}

Player::Player()
{
}


Player::~Player()
{
}
