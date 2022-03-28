#include "stdafx.h"
#include "Maingame.h"
#include "Item.h"

void Item::Weapon()
{
	m_sName = "��";
	m_iPrice = 100;
	m_iStats = 10;
}

void Item::Armor()
{
	m_sName = "����";
	m_iPrice = 100;
	m_iStats = 10;
}

void Item::Utility()
{
	m_sName = "����";
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
		cout << endl << "�̸� : " << m_sName << " / ���� : " << m_iPrice << "�� / ȿ�� : +" << m_iStats << endl << endl;

		cout << "1. ����, 2. �Ǹ� , 3. ���ư��� : ";
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
		cout << "���� �Ϸ�!!" << endl;
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
		cout << "�������� �����մϴ�" << endl;
	}
}

void Item::Sell()
{
	int Input = 0;
	while (true)
	{
		system("cls");
		Maingame::m_pp->PrintInventory();
		cout << endl <<"�Ǹ��Ͻ� �������� ��ȣ�� �Է����ּ��� : ";
		cin >> Input;
		Input = Input - 1;
		if (Input > 10)
		{
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			system("pause");
			continue;
		}
		else
		{
			if (Maingame::m_pp->GetSnum(Input) == 0)
			{
				Maingame::m_pp->SetInventory(m_sName, Input, 2);
				cout << "�ǸſϷ�" << endl;
				system("pause");
			}
			else
			{
				cout << "�󽽷��Դϴ�" << endl;
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
