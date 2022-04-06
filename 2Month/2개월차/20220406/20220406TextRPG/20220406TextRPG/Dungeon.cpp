#include "stdafx.h"
#include "Dungeon.h"
#include "Game.h"

bool Dungeon::Update()
{
	int Input;
	while (true)
	{		
		system("cls");
		Game::m_pp->Print();
		cout << "1. 초급, 2. 중급, 3. 고급, 4. 마을 : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			m_mp->Create("초급",1,5,50,10,10);
			Battle();
			Release();
			return 0;

		case 2:
			m_mp->Create("중급", 10, 20, 100, 50, 50);
			Battle();
			Release();
			return 0;

		case 3:
			m_mp->Create("고급", 5, 50, 200, 100, 100);
			Battle();
			Release();
			return 0;

		case 4:
			if (m_mp != NULL)
			{
				Release();
			}
			return 1;
		}
	}
}

void Dungeon::Battle()
{
	int Input;
	while (true)
	{
		system("cls");
		Game::m_pp->Print();
		m_mp->Print();
		cout << "=======================================" << endl;
		cout << "1. 공격, 2. 인벤토리, 3. 도망 : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			if (p->SetHp(m_mp->GetDamage()) == 1)   // p= Game::m_pp
			{
				p->HitDamage();
				p->Die();
				return;
			}
			p->HitDamage();

			if (m_mp->SetHp(p->GetDamage()) == 1)
			{
				p->Attack();
				p->Kill(m_mp->GetExp(), m_mp->GetGold());
				return;
				Game::m_pp->Getip()->GetInven()[1];
			}
			p->Attack();
			break;

		case 2:
			Inven();
			
			continue;

		case 3:
			return;
		}
		
	}
}

void Dungeon::Inven()
{
	p->Getip()->Print();
	system("pause");
}

Dungeon::Dungeon()
{
	m_mp = new Monster;
}


Dungeon::~Dungeon()
{
}
