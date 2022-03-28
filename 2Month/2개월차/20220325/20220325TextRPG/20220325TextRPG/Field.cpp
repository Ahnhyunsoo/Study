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
			cout << "������ġ : �����ƹ�" << endl;
			Maingame::m_pp->PrintInfo();
			cout << "1. ����, 2. ����, 3. ����, 4. ���� : ";
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
				cout << "�̱���" << endl;
				continue;
			}
			else if (Input == 4)
			{
				cout << "������ �����մϴ�" << endl;

				return 1;
			}
			else
			continue;
		case 2:

			if (m_dp == NULL)
			{
				m_dp = new Dungeon;
			}
			
			cout << "������ġ : ����" << endl;
			Maingame::m_pp->PrintInfo();
			cout << "1.�׶��÷θ���, 2.������, 3.���ǲ, 4.�����ƹ� : ";
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
			cout << "������ġ : �����Ա�" << endl;
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
			cout << "������� : " << m_dp->GetPlace() << endl << endl;
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
			cout << "������ġ : ����" << endl;
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
