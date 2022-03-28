#include "stdafx.h"
#include "Game.h"
#include "Field.h"

int CField::Game()
{

	while (true)
	{
		switch (iPlace)
		{
		case 1:
			if (Start() == 1)
			{
				return 1;
			}
			return 0;

		case 2:
			Dungeon();
			return 0;

		case 3:
			return 0;
		}
	}
}

int CField::Start()
{
	while (true)
	{
		int Input = 0;
		system("cls");
		CGame::m_pp->PlayerInfo();
		cout << "1. ����, 2. ����, 3. ���� : ";
		cin >> Input;

		switch (Input)
		{
		case 1:
			iPlace = 2;
			return 0;

		case 2:
			iPlace = 3;
			return 0;

		case 3:
			return 1;

		default:
			continue;
		}
	}
}

void CField::Dungeon()
{
	if (m_dp == NULL)
	{
		m_dp = new CDungeon;
	}
	
	while (true)
	{

		int Input = 0;
		system("cls");
		CGame::m_pp->PlayerInfo();
		cout << "1. �ʱ�, 2. �߱�, 3. ���, 4. ���ܰ� : ";
		cin >> Input;
		switch (Input)
		{
		case 1: case 2: case 3:
			m_dp->CreateMonster(Input);
			m_dp->Battle();
			return;

		case 4:
			iPlace = 1;
			return;
		}

	}
}

CField::CField()
{
}


CField::~CField()
{
}
