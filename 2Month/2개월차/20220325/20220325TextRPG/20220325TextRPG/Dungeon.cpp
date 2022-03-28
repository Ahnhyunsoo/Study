#include "stdafx.h"
#include "Dungeon.h"
#include "Maingame.h"


void Dungeon::CreateDungeon(int _Num)
{
	if (_Num == 1)
	{
		DG1();
	}
	else if (_Num == 2)
	{
		DG2();
	}
	else
		DG3();
}


void Dungeon::Place(int _Place)
{
	if (_Place == 1)
	{
		m_sPlace = m_sDG1;
	}
	else if (_Place == 2)
	{
		m_sPlace = m_sDG2;
	}
	else
	{
		m_sPlace = m_sDG3;
	}
}

int Dungeon::Battle()
{
	while (true)
	{
		int Input = 0;
		cout << "1. 공격, 2. Hp회복, 3. Mp회복 , 4. 던전탈출 : ";
		cin >> Input;
		while (true)
		{
			switch (Input)
			{
			case 1:
				if (Maingame::m_pp->Hp(m_mp->GetDamage()) == 1)
				{
					Maingame::m_pp->Die(m_mp->GetExp());
					return 1;
				}
				
				if (m_mp->Hp(Maingame::m_pp->GetDamage()) == 1)
				{
					cout << "몬스터를 처치했습니다" << endl;
					system("pause");
					if (Maingame::m_pp->Kill(m_mp->GetExp(), m_mp->GetGold()) == 1)
					{
						Maingame::m_pp->LevelUp();
					}
					DeleteMonster();					
					return 1;
				}
				system("pause");
				


			case 2:
				return 0;

			case 3:
				return 0;

			case 4:
				cout << "던전을 탈출합니다" << endl;
				system("pause");
				DeleteMonster();
				return 1;

			default:
				continue;
			}

		}
	}

}


string Dungeon::GetPlace()
{
	return m_sPlace;
}

void Dungeon::CreateM(string DG)
{

	if (m_mp == NULL)
	{
		m_mp = new Monster;
		m_mp->CreateMonster(DG);
	}
	
}

void Dungeon::DeleteMonster()
{
	m_mp->DeleteMonster();
	SAVE_DELETE(m_mp);
}

void Dungeon::PrintInfo()
{
	Maingame::m_pp->PrintInfo();
	m_mp->PrintMonster();
}

void Dungeon::PrintDungeon()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "1. "<< m_sDG1 << " (권장레벨 = " << m_iDG1 << ")";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << " " << "2. " << m_sDG2 << " (권장레벨 = " << m_iDG2 << ")";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << " " << "3. " << m_sDG3 << " (권장레벨 = " << m_iDG3 << ") ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "4. 마을" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "선택 : ";
}

void Dungeon::DG1()
{
	m_sDG1 = "머크우드";
	m_sDG2 = "그락카락";
	m_sDG3 = "어둠의선더랜드";
	m_iDG1 = 1;
	m_iDG2 = 3;
	m_iDG3 = 5;
}

void Dungeon::DG2()
{
	m_sDG1 = "신전외각";
	m_sDG2 = "백야";
	m_sDG3 = "제2척추";
	m_iDG1 = 10;
	m_iDG2 = 15;
	m_iDG3 = 20;
}

void Dungeon::DG3()
{
	m_sDG1 = "거미소굴";
	m_sDG2 = "용암굴";
	m_sDG3 = "언더풋입구";
	m_iDG1 = 25;
	m_iDG2 = 30;
	m_iDG3 = 40;
}

Dungeon::Dungeon()
{
}


Dungeon::~Dungeon()
{
}
