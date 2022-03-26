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
				m_iplace = 3;
				return 0;
			}
			else if (Input == 3)
			{
				cout << "�̱���" << endl;
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
				m_iplace = 2;
				return 0;
			}
			continue;
			
		case 3:
			cout << "������ġ : �����Ա�" << endl;
			Maingame::m_pp->PrintInfo();
			cout << "1.�ʱ�, 2.�߱�, 3.���, 4.���� : ";
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
