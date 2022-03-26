#include "stdafx.h"
#include "Dungeon.h"

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

void Dungeon::PringDungeon()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << m_sDG1 << " 권장레벨 = " << m_iDG1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << "\t" << m_sDG2 << " 권장레벨 = " << m_iDG2;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "\t" << m_sDG3 << " 권장레벨 = " << m_iDG3 << endl;
	cout << "입장할 던전 : ";
}

void Dungeon::DG1()
{
	m_sDG1 = "머크우드";
	m_sDG2 = "그락카락";
	m_sDG3 = "어둠의선더랜드";
	m_iDG1 = 1;
	m_iDG1 = 3;
	m_iDG1 = 5;
}

void Dungeon::DG2()
{
	m_sDG1 = "신전외각";
	m_sDG2 = "백야";
	m_sDG3 = "혈옥";
	m_iDG1 = 10;
	m_iDG1 = 15;
	m_iDG1 = 20;
}

void Dungeon::DG3()
{
	m_sDG1 = "거미소굴";
	m_sDG2 = "용암굴";
	m_sDG3 = "언더풋입구";
	m_iDG1 = 25;
	m_iDG1 = 30;
	m_iDG1 = 40;
}

Dungeon::Dungeon()
{
}


Dungeon::~Dungeon()
{
}
