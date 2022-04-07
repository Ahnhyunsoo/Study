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
			Info();
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

void Field::Info()
{
	
	int Input;
	
	
	while (true)
	{
		system("cls");
		cout << "������" << endl;
		p->Print();
		cout << "�κ��丮" << endl;
		p->Getip()->Print();
		cout << "1. ����, 2. ����, 3. �ڷΰ��� : ";
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
		cout << "������" << endl;
		p->Print();
		cout << "�κ��丮" << endl;
		p->Getip()->Print();
		cout << "(0 = �ڷΰ���) ������ �������� ��ȣ : ";
		cin >> Input;
	
		if (Input == 0)
		{
			return;
		}
		else if (Input <= p->Getip()->GetInven().size())
		{
			if (p->Getip()->GetInven()[Input - 1].Name == "��")
			{
				if (p->GetWP() == "����")
				{
					p->Use(p->Getip()->GetInven()[Input - 1].Name, p->Getip()->GetInven()[Input - 1].Value);
					p->Getip()->UnLock(Input);
				}
				else
				{
					cout << "���⸦ �̹� �������Դϴ�" << endl;
					system("pause");
				}
			}
			else if(p->Getip()->GetInven()[Input - 1].Name == "����")
			{
				if (p->GetAM() == "����")
				{
					p->Use(p->Getip()->GetInven()[Input - 1].Name, p->Getip()->GetInven()[Input - 1].Value);
					p->Getip()->UnLock(Input);
				}
				else
				{
					cout << "���� �̹� �������Դϴ�" << endl;
					system("pause");
				}
			}
			else
			{
				cout << "������ ������ �� �����ϴ�" << endl;
				system("pause");
				continue;
			}
		}
		else
		{
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
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
		cout << "������" << endl;
		p->Print();
		cout << "�κ��丮" << endl;
		p->Getip()->Print();
		cout << "1. ��������, 2.������, 3. �ڷΰ��� : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			if (p->GetWP() != "����")
			{
				p->Remove(1);
			}
			else
			{
				cout << "������ ���Ⱑ �����ϴ�" << endl; 
				system("pause");
			}
			continue;

		case 2:
			if (p->GetAM() != "����")
			{
				p->Remove(2);
			}
			else
			{
				cout << "������ ���� �����ϴ�" << endl;
				system("pause");
			}
			continue;

		case 3:
			return;

		default :
			cout << "�߸��Է��ϼ̽��ϴ�" << endl;
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
