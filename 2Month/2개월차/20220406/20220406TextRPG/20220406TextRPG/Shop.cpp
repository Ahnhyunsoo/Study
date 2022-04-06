#include "stdafx.h"
#include "Shop.h"
#include "Game.h"

void Shop::Update()
{
	int Input;
	while (true)
	{
		system("cls");
		cout << "================상품목록================" << endl;
		cout << "1. 검\t" << " 공격력 + 10\t" << " 가격 : 100원" << endl;
		cout << "2. 갑옷\t" << " 최대체력 + 50\t" << " 가격 : 150원" << endl;
		cout << "3. 포션\t" << " HP회복 + 60\t" << " 가격 : 20원" << endl;
		cout << "================인벤토리================" << endl;
		p->Getip()->Print();
		cout << "1. 구매, 2. 판매, 3. 마을 : ";
		cin >> Input;
		switch (Input)
		{
		case 1:		
			Buy();
			continue;

		case 2:
			Sell();
			continue;

		case 3:
			return;

		default:
			continue;

		}
	}
}

void Shop::Buy()
{
	int Input;
	while (true)
	{
		system("cls");
		cout << "================상품목록================" << endl;
		cout << "1. 검\t" << " 공격력 + 10\t" << " 가격 : 100원" << endl;
		cout << "2. 갑옷\t" << " 최대체력 + 50\t" << " 가격 : 150원" << endl;
		cout << "3. 포션\t" << " HP회복 + 60\t" << " 가격 : 20원" << endl;
		cout << "========================================" << endl;
		cout << "(뒤로가기 = 4)구매할 아이템의 번호 입력 : " << endl;
		cin >> Input;
		switch (Input)
		{
		case 1:
			if (p->GetGold() >= 100)
			{
				p->SetGold(100);
				ip = new Item;
				ip->Weapon();
				p->Getip()->GetInven().push_back(*ip);
				cout << "구매 완료" << endl;
				
			}
			else
			{
				cout << "잔액이 부족합니다" << endl;
			}
			system("pause");
			continue;

		case 2:
			if (p->GetGold() >= 150)
			{
				p->SetGold(150);
				ip = new Item;
				ip->Armor();
				p->Getip()->GetInven().push_back(*ip);
				cout << "구매 완료" << endl;
				
			}
			else
			{
				cout << "잔액이 부족합니다" << endl;
			}
			system("pause");
			continue;

		case 3:
			if (p->GetGold() >= 50)
			{
				p->SetGold(50);
				ip = new Item;
				ip->potion();
				p->Getip()->GetInven().push_back(*ip);
				cout << "구매 완료" << endl;
			}
			else
			{
				cout << "잔액이 부족합니다" << endl;
			}
			system("pause");
			continue;

		case 4:
			return;

		}
	}
}

void Shop::Sell()
{
	int Input;
	while (true)
	{
		system("cls");
		cout << "================인벤토리================" << endl;
		p->Getip()->Print();
		cout << "(뒤로가기 : 0)판매할 아이템의 번호 : ";
		cin >> Input;
		if (Input == 0)
		{
			return;
		}
		if (p->Getip()->GetInven().size() < Input)
		{
			cout << "잘못된 입력입니다" << endl;
			system("pause");
			continue;
		}
		p->Getip()->Pop(Input);
		
	}
}

Shop::Shop()
{
}


Shop::~Shop()
{
}
