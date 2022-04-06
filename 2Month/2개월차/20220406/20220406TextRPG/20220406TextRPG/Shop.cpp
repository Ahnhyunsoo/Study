#include "stdafx.h"
#include "Shop.h"
#include "Game.h"

void Shop::Update()
{
	int Input;
	while (true)
	{
		system("cls");
		cout << "================��ǰ���================" << endl;
		cout << "1. ��\t" << " ���ݷ� + 10\t" << " ���� : 100��" << endl;
		cout << "2. ����\t" << " �ִ�ü�� + 50\t" << " ���� : 150��" << endl;
		cout << "3. ����\t" << " HPȸ�� + 60\t" << " ���� : 20��" << endl;
		cout << "================�κ��丮================" << endl;
		p->Getip()->Print();
		cout << "1. ����, 2. �Ǹ�, 3. ���� : ";
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
		cout << "================��ǰ���================" << endl;
		cout << "1. ��\t" << " ���ݷ� + 10\t" << " ���� : 100��" << endl;
		cout << "2. ����\t" << " �ִ�ü�� + 50\t" << " ���� : 150��" << endl;
		cout << "3. ����\t" << " HPȸ�� + 60\t" << " ���� : 20��" << endl;
		cout << "========================================" << endl;
		cout << "(�ڷΰ��� = 4)������ �������� ��ȣ �Է� : " << endl;
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
				cout << "���� �Ϸ�" << endl;
				
			}
			else
			{
				cout << "�ܾ��� �����մϴ�" << endl;
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
				cout << "���� �Ϸ�" << endl;
				
			}
			else
			{
				cout << "�ܾ��� �����մϴ�" << endl;
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
				cout << "���� �Ϸ�" << endl;
			}
			else
			{
				cout << "�ܾ��� �����մϴ�" << endl;
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
		cout << "================�κ��丮================" << endl;
		p->Getip()->Print();
		cout << "(�ڷΰ��� : 0)�Ǹ��� �������� ��ȣ : ";
		cin >> Input;
		if (Input == 0)
		{
			return;
		}
		if (p->Getip()->GetInven().size() < Input)
		{
			cout << "�߸��� �Է��Դϴ�" << endl;
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
