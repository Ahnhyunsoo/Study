#include "stdafx.h"
#include "Field.h"
#include "Maingame.h"


int CField::Update()
{
	while (true)
	{
		switch (iPlace)
		{
		case 1:
			Start();
			return 0;

		case 2:
			Dungeon();
			return 0;

		case 3:
			Shop();
			return 0;

		case 9:
			return 1;
			
		}
	}
}

void CField::Start()
{
	while (true)
	{
		int Input = 0;
		system("cls");
		Maingame::m_pp->Print();
		cout << "1. 던전, 2. 상점, 3. 종료 : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			iPlace = 2;
			return;

		case 2:
			iPlace = 3;
			return;

		case 3:
			iPlace = 9;
			return;
		}
	}
}
void CField::Dungeon()
{
	if (m_dp == NULL)

	{
		m_dp = new CDungeon;
		if (m_dp->CreateMonster() == 1)
		{
			SAVE_DELETE(m_dp);
			iPlace = 1;
		}
	}

}

void CField::Shop()
{

}


CField::CField()
	: iPlace(1)
{
}


CField::~CField()
{
}
