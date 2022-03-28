#include "stdafx.h"
#include "Maingame.h"
#include "Item.h"

void Item::Weapon()
{
	m_sName = "검";
	m_iPrice = 100;
	m_iStats = 10;
}

void Item::Armor()
{
	m_sName = "갑옷";
	m_iPrice = 100;
	m_iStats = 10;
}

void Item::Utility()
{
	m_sName = "포션";
	m_iPrice = 20;
	m_iStats = 50;
}

int Item::PrintItem()
{
	while (true)
	{
		system("cls");
		int Input = 0;
		Maingame::m_pp->PrintInventory();
		cout << endl << "이름 : " << m_sName << " / 가격 : " << m_iPrice << "원 / 효과 : +" << m_iStats << endl << endl;

		cout << "1. 구매, 2. 판매 , 3. 돌아가기 : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			return 1;

		case 2:
			return 2;
			
		case 3:
			return 0;
		}
	}	
}

void Item::Buy()
{
	if (m_iPrice <= Maingame::m_pp->GetGold())
	{
		cout << "구매 완료!!" << endl;
		int iSlot = 0;
		Maingame::m_pp->SetGold(m_iPrice);
		for (int i = 0; i < 10; ++i)
		{
			if (Maingame::m_pp->GetSnum(i) != 0)
			{
				iSlot = i;
				break;
			}
		}
		Maingame::m_pp->SetInventory(m_sName, iSlot, 1);
		
	}
	else
	{
		cout << "소지금이 부족합니다" << endl;
	}
}

void Item::Sell()
{
	int Input = 0;
	while (true)
	{
		system("cls");
		Maingame::m_pp->PrintInventory();
		cout << endl <<"판매하실 아이템의 번호를 입력해주세요 : ";
		cin >> Input;
		Input = Input - 1;
		if (Input > 10)
		{
			cout << "잘못 입력하셨습니다" << endl;
			system("pause");
			continue;
		}
		else
		{
			if (Maingame::m_pp->GetSnum(Input) == 0)
			{
				Maingame::m_pp->SetInventory(m_sName, Input, 2);
				cout << "판매완료" << endl;
				system("pause");
			}
			else
			{
				cout << "빈슬롯입니다" << endl;
				system("pause");
			}
			
		}
	}
}

Item::Item()
{
}


Item::~Item()
{
}
