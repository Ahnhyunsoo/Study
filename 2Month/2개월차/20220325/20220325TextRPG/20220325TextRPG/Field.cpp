#include "stdafx.h"
#include "Maingame.h"
#include "Field.h"




	

int Field::Menu()
{
	while (true)
	{
		system("cls");
		int Input = 0;
		switch (m_iplace)
		{			
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
				m_iplace = 5;
				return 0;
			}
			else if (Input == 3)
			{
				cout << "미구현" << endl;
				continue;
			}
			else if (Input == 4)
			{
				cout << "게임을 종료합니다" << endl;

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
				m_iplace = 1;
				return 0;
			}
			continue;
			
		case 3:
			cout << "현재위치 : 던전입구" << endl;
			Maingame::m_pp->PrintInfo();
			m_dp->PrintDungeon();
			cin >> Input;
			if (Input >= 1 && Input <= 3)
			{
				m_dp->Place(Input);
				m_iplace = 4;
				return 0;
			}
			else if (Input == 4)
			{
				SAVE_DELETE(m_dp);
				m_iplace = 2;
				return 0;
			}
			continue;
		
		case 4:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << "현재던전 : " << m_dp->GetPlace() << endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << "========================"  << endl;
			m_dp->CreateM(m_dp->GetPlace());
			m_dp->PrintInfo();
			if (m_dp->Battle() == 1)
			{
				m_iplace = 3;
				return 0;
			}
			break;

		case 5:
			cout << "현재위치 : 상점" << endl;
			if (m_sp == NULL)
			{
				m_sp = new Shop;
			}
			if (m_sp->CreateShop() == 1)
			{
				SAVE_DELETE(m_sp);
				m_iplace = 1;
				return 0;
			}

			m_sp->PrintShop();
			system("pause");
			continue;		
		}
	}
}




Field::Field()
{
	
}


Field::~Field()
{
}
