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
		cout << "1. 던전, 2. 상점, 3.마이페이지, 4. 종료 : ";
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
		cout << "1. 내정보, 2. 업적, 3. 뒤로가기 : ";
		cin >> Input;
		switch(Input)
		{
		case 1:
			system("cls");
			cout << "내정보" << endl;
			p->Print();
			cout << "인벤토리" << endl;
			p->Getip()->Print();
			
			system("pause");
			continue;

		case 2:
			system("cls");
			cout << "공격횟수 : " << p->GetAttack() << "회" << endl;
			cout << "피격횟수 : " << p->GetHit() << "회" << endl;
			cout << "Kill : " << p->GetKill() << "Kill" << endl;
			cout << "죽은횟수 : " << p->GetDie() << "회" << endl;
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
