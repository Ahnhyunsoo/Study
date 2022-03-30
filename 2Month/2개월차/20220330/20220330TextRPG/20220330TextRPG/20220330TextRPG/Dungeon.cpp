#include "stdafx.h"
#include "Dungeon.h"
#include "Maingame.h"

int CDungeon::CreateMonster()
{
	
	while (true)
	{
		int Input = 0;
		system("cls");
		Maingame::m_pp->Print();
		cout << "1. �ʱ�, 2. �߱�, 3. ���, 4. ���ܰ� : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			Easy();
			break;

		case 2:
			Nomal();
			break;

		case 3:
			Hard();
			break;

		case 4:
			return 1;
		}
	}
}

void CDungeon::Battle()
{
	while (true)
	{
		int Input = 0;
		system("cls");
		PrintP();
		m_mp->Print();
		cout << "1. ����, 2. �κ��丮, 3. ���� : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			//HP�� ����
			//CObj::SetHp(static_cast<CPlayer*>(Maingame::m_pp)->GetDamage());
			if (Maingame::m_pp->SetHp(m_mp->GetDamage()) == 1)
			{
				C()->Die(m_mp->GetExp());
				return;
			}

			//HP() = static_cast<CPlayer*>(Maingame::m_pp)->GetDamage()
				//static_cast<CPlayer*>(Maingame::m_pp)->GetDamage()
				

			if (m_mp->SetHp(HP()) == 1)
			{
				C()->Kill(m_mp->GetExp(), m_mp->GetGold());
				return;
			}
			break;
			
		case 2:
			continue;

		case 3:
			return;
		}
	}
}

void CDungeon::Easy()
{
	if (m_mp == NULL)
	{
		m_mp = new CMonster;
		m_mp->Create("�ʱ�", 1, 5, 40, 10, 20);
	}
	Battle();
	SAVE_DELETE(m_mp);
	return;
}

void CDungeon::Nomal()
{
	if (m_mp == NULL)
	{
		m_mp = new CMonster;
		m_mp->Create("�߱�", 3, 10, 100, 30, 100);
	}
	Battle();
	SAVE_DELETE(m_mp);
	return;
}

void CDungeon::Hard()
{
	if (m_mp == NULL)
	{
		m_mp = new CMonster;
		m_mp->Create("���", 5, 40, 200, 100, 2000);
	}
	Battle();
	SAVE_DELETE(m_mp);
	return;
}

CDungeon::CDungeon()
{
}


CDungeon::~CDungeon()
{
}
