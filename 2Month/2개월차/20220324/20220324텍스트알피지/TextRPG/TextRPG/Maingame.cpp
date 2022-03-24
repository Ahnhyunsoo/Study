#include "stdafx.h"
#include "Maingame.h"




void Maingame::exe()
{

	while (true)
	{
		system("cls");
		int place = m_pf->GetPlace();
		switch (place)
		{
		case 1:
			if (m_cp->Input() == 1)
			{
				SAVE_DELETE(m_cp);
				SAVE_DELETE(m_pf);
				return;
			}
			m_pf->SetPlace(2);
			break;

		case 2:
			if (Town() == 1)
			{
				SAVE_DELETE(m_cp);
				SAVE_DELETE(m_pf);

				return;
			}
			m_pf->SetPlace(3);
			break;

		case 3:
			if (DungeonEntry() == 1)
			{
				SAVE_DELETE(m_cp);
				SAVE_DELETE(m_pf);
				return;
			}
			m_pf->SetPlace(4);
			break;

		case 4:
			Dungeon();
			m_pf->SetPlace(3);
			break;

		case 5:
			break;
		}
		
	}
	return;
	
}


int Maingame::Town()
{
	int Input = 0;
	while (true)
	{
		system("cls");
		m_cp->Output();
		cout << "1. 사냥터, 2. 저장, 3. 종료 : ";
		cin >> Input;

		switch (Input)
		{
		case 1:
			return 0;
			break;

		case 2:
			cout << "미구현" << endl;
			continue;

		case 3:
			cout << "게임을 종료합니다." << endl;
			return 1;

		default:
			continue;
		}
	}
}

int Maingame::DungeonEntry()
{
			m_cp->Output();
			if (m_pm == NULL)
			{
				m_pm = new Monster;
			}

			if (m_pm->Input() == 1)
			{
				if (m_pm != NULL)
				{
					SAVE_DELETE(m_pm);
				}
				return 1;
			}
			else
				return 0;
}

void Maingame::Dungeon()
{
	int Input = 0;

	while (true)
	{
		system("cls");
		m_cp->Output();
		m_pm->Output();
		cout << "1.공격, 2. Hp회복, 3. 도망 : ";
		cin >> Input;
		switch (Input)
		{
		case 1:			
			if (m_cp->Hp(m_pm->GetDamage()) == 1)
			{
				m_cp->Die(m_pm->GetExp());
			}			
				break;

		case 2:
			break;

		case 3:
			return;
		}
	}
}

Maingame::Maingame()
{
	m_cp = new Player;
	m_pf = new Field;
}


Maingame::~Maingame()
{
}
