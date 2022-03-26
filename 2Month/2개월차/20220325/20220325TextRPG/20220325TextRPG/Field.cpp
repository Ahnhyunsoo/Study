#include "stdafx.h"
#include "Maingame.h"
#include "Field.h"




	

int Field::Menu()
{
	while (true)
	{
		int Input = 0;
		switch (m_iplace)
		{
			system("cls");
			
		case 1:
			cout << "현재위치 : 세리아방" << endl;
			Maingame::m_pp->PrintInfo();
			cout << "1. 마을, 2. 상점, 3. 저장, 4. 종료 : ";
			cin >> Input;
			if (Input == 1)
			{
				m_iplace = 2;
				return 0;
			}
			else if (Input == 2)
			{
				m_iplace = 3;
				return 0;
			}
			else if (Input == 3)
			{
				cout << "미구현" << endl;
				continue;
			}
			else if (Input == 4)
			{
				if (m_dp != NULL)
				{
					SAVE_DELETE(m_dp);
				}
				return 1;
			}
			else
			continue;
		case 2:

			if (m_dp == NULL)
			{
				m_dp = new Dungeon;
			}
			
			cout << "현재위치 : 마을" << endl;
			Maingame::m_pp->PrintInfo();
			cout << "1.그란플로리스, 2.베히모스, 3.언더풋, 4.세리아방 : ";
			cin >> Input;
			if (Input >= 1 && Input <= 3)
			{
				m_dp->CreateDungeon(Input);
				m_iplace = 3;
				return 0;
			}
			else if (Input == 4)
			{
				m_iplace = 2;
				return 0;
			}
			continue;
			
		case 3:
			cout << "현재위치 : 던전입구" << endl;
			Maingame::m_pp->PrintInfo();
			cout << "1.초급, 2.중급, 3.상급, 4.마을 : ";
			cin >> Input;
			if (Input >= 1 && Input <= 4)
			{
				m_iplace = 3;
				return Input;
			}
			continue;
		
	
		}
	}
}


void Field::SetPlace(int _Place)
{
	m_iplace = _Place;
}

Field::Field()
{
	
}


Field::~Field()
{
}
