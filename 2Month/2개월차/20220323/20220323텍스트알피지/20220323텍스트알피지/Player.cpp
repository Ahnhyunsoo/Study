#include "stdafx.h"
#include "Player.h"


void Player::Warrior(PPInfo pp)
{
	pp->m_sName = "����";
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
	pp->m_sName = "������";
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
	pp->m_sName = "����";
	pp->m_iLevel = 1;
	pp->m_iMaxHp = 150;
	pp->m_iNowHp = pp->m_iMaxHp;
	pp->m_iNowExp = 0;
	pp->m_iMaxExp = 100;
	pp->m_iDamage = 30;
	pp->m_iMaxMp = 100;
	pp->m_iNowMp = pp->m_iMaxMp;
}

void Player::Create(Field* m_fp)//f12 �Լ����̵� (�巡����)
{
	pp = new PInfo;

	while (true)
	{		
		m_fp->SetPlace(ĳ���ͻ���);
		int Place = m_fp->GetPlace();

		switch (m_fp->PrintMenu(Place))
		{
		case ����:
			Player::Warrior(pp);
			m_fp->SetPlace(����);  
			return;

		case ������:
			Player::Wizard(pp);
			m_fp->SetPlace(����);
			return;

		case ����:
			Player::Thief(pp);
			m_fp->SetPlace(����);
			return;

		case �ҷ�����:
			cout << "�̱��� �Դϴ�" << endl;
			system("pause");
			continue;

		case ����:
			cout << "������ �����մϴ�" << endl;
			SAVE_DELETE(pp);
			SAVE_DELETE(m_fp);
			return;
		}
	}

	
}

void Player::Output()
{
	cout << "�̸� : " << pp->m_sName << endl;
	cout << "���� : " << pp->m_iLevel << endl;
	cout << "ü�� : " << pp->m_iNowHp << " / " << pp->m_iMaxHp << endl;
	cout << "���� : " << pp->m_iNowMp << " / " << pp->m_iMaxMp << endl;
	cout << "���ݷ� : " << pp->m_iDamage << endl;
	cout << "����ġ : " << pp->m_iNowExp << " / " << pp->m_iMaxExp << endl;	
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
		cout << "ĳ���Ͱ� ����߽��ϴ�." << endl;
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
