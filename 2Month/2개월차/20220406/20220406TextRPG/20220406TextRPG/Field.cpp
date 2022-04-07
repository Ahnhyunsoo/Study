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
			Info();
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

void Field::Info()
{
	
	int Input;
	
	
	while (true)
	{
		system("cls");
		cout << "내정보" << endl;
		p->Print();
		cout << "인벤토리" << endl;
		p->Getip()->Print();
		cout << "1. 장착, 2. 해제, 3. 뒤로가기 : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			Use();
			continue;

		case 2:
			Remove();
			continue;

		case 3:
			return;

		default:
			continue;
		}

	}
	
}

void Field::Use()
{
	int Input;
	
	while (true)
	{
		system("cls");
		cout << "내정보" << endl;
		p->Print();
		cout << "인벤토리" << endl;
		p->Getip()->Print();
		cout << "(0 = 뒤로가기) 장착할 아이템의 번호 : ";
		cin >> Input;
	
		if (Input == 0)
		{
			return;
		}
		else if (Input <= p->Getip()->GetInven().size())
		{
			if (p->Getip()->GetInven()[Input - 1].Name == "검")
			{
				if (p->GetWP() == "없음")
				{
					p->Use(p->Getip()->GetInven()[Input - 1].Name, p->Getip()->GetInven()[Input - 1].Value);
					p->Getip()->UnLock(Input);
				}
				else
				{
					cout << "무기를 이미 장착중입니다" << endl;
					system("pause");
				}
			}
			else if(p->Getip()->GetInven()[Input - 1].Name == "갑옷")
			{
				if (p->GetAM() == "없음")
				{
					p->Use(p->Getip()->GetInven()[Input - 1].Name, p->Getip()->GetInven()[Input - 1].Value);
					p->Getip()->UnLock(Input);
				}
				else
				{
					cout << "방어구를 이미 장착중입니다" << endl;
					system("pause");
				}
			}
			else
			{
				cout << "포션은 장착할 수 없습니다" << endl;
				system("pause");
				continue;
			}
		}
		else
		{
			cout << "잘못 입력하셨습니다" << endl;
			system("pause");
			continue;
		}

	}
}

void Field::Remove()
{
	int Input;

	while (true)
	{
		system("cls");
		cout << "내정보" << endl;
		p->Print();
		cout << "인벤토리" << endl;
		p->Getip()->Print();
		cout << "1. 무기해제, 2.방어구해제, 3. 뒤로가기 : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			if (p->GetWP() != "없음")
			{
				p->Remove(1);
			}
			else
			{
				cout << "장착한 무기가 없습니다" << endl; 
				system("pause");
			}
			continue;

		case 2:
			if (p->GetAM() != "없음")
			{
				p->Remove(2);
			}
			else
			{
				cout << "장착한 방어구가 없습니다" << endl;
				system("pause");
			}
			continue;

		case 3:
			return;

		default :
			cout << "잘못입력하셨습니다" << endl;
			system("pause");
			continue;
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
