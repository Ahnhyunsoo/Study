#include "stdafx.h"
#include "Field.h"
#include "Game.h"

bool Field::Update()
{
	while (true)
	{
		system("cls");
		switch(place)
		{
		case 1:
			Menu();
			return 0;

		case 2:
			DungeonFront();
			return 0;

		case 3:
			Shoping();
			return 0;

		case 4:
			Mypage();
			return 0;

		case 9:
			return 1;
		}
	}




}

void Field::Menu()
{
	int Input;
	while (true)
	{	
		system("cls");
		Game::m_pp->Print();
		cout << "1. ����, 2. ����, 3.����������, 4. ���� : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			place = 2;
			return;

		case 2:
			place = 3;
			return;

		case 3:
			place = 4;
			return;

		case 4:
			place = 9;
			return;

		default :
			continue;
		}
	}
}

void Field::DungeonFront()
{
	m_dp = new Dungeon;
	if (m_dp->Update() == 1)
	{
		SAVE_DELETE(m_dp);
		place = 1;
	}
}

void Field::Shoping()
{
	m_sp = new Shop;
	m_sp->Update();
	SAVE_DELETE(m_sp);
	place = 1;
}

void Field::Mypage()
{
	while (true)
	{
		int Input;
		system("cls");
		cout << "1. ������, 2. ����, 3. �ڷΰ��� : ";
		cin >> Input;
		switch(Input)
		{
		case 1:
			system("cls");
			cout << "������" << endl;
			p->Print();
			cout << "�κ��丮" << endl;
			p->Getip()->Print();
			
			system("pause");
			continue;

		case 2:
			system("cls");
			cout << "����Ƚ�� : " << p->GetAttack() << "ȸ" << endl;
			cout << "�ǰ�Ƚ�� : " << p->GetHit() << "ȸ" << endl;
			cout << "Kill : " << p->GetKill() << "Kill" << endl;
			cout << "����Ƚ�� : " << p->GetDie() << "ȸ" << endl;
			system("pause");
			continue;

		case 3:
			place = 1;
			return;
		}
	}
}

Field::Field()
	:place(1)
{
}


Field::~Field()
{
}
