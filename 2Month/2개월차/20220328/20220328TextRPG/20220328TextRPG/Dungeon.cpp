#include "stdafx.h"
#include "Dungeon.h"
#include "Game.h"

void CDungeon::CreateMonster(int _Type)
{
	if (m_mp == NULL)
	{
		m_mp = new CMonster;
	}
	m_mp->CreateMonster(_Type);
}

void CDungeon::Battle()
{
	while (true)
	{
		int Input = 0;
		system("cls");
		CGame::m_pp->PlayerInfo();
		m_mp->PrintMInfo();
		cout << "1. ����, 2. �κ��丮, 3. ���� : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			
			if (CGame::m_pp->SetPHp(m_mp->GetDamage()) == 1)
			{				
				CGame::m_pp->Die(m_mp->GetExp());
				SAVE_DELETE(m_mp);
				return;
			}
			if (m_mp->SetMHp(CGame::m_pp->GetDamage()) == 1)
			{
				CGame::m_pp->Kill(m_mp->GetExp(), m_mp->GetGold());
				SAVE_DELETE(m_mp);
				return;
			}
			else
				continue;

		case 2:
			Inven();
			continue;

		case 3:
			SAVE_DELETE(m_mp);
			return;
		}
	}
}

void CDungeon::Inven()
{
	while (true)
	{
		int Input = 0;
		system("cls");
		CGame::m_pp->InvenInfo();
		cout << endl << "1. ���, 2. �ڷΰ���: ";
		cin >> Input;
		if (Input == 1)
		{
			Use();
		}
		else if (Input == 2)
		{
			return;
		}
		else
			continue;
	}
}

void CDungeon::Use()
{
	while (true)
	{
		int Input = 0;
		system("cls");
		CGame::m_pp->InvenInfo();
		cout << "�ڷΰ��� : 0" << endl;
		cout << "�����ۻ�� : �����۹�ȣ �Է� : ";
		cin >> Input;
		if (Input == 0)
		{
			return;
		}
		else
		{
			CGame::m_pp->SetInven(Input);
			continue;
		}

	}
}

CDungeon::CDungeon()
{
}


CDungeon::~CDungeon()
{
}
