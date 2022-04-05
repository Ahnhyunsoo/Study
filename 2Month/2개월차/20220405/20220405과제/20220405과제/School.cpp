#include "stdafx.h"
#include "School.h"



void School::Exe()
{
	while (true)
	{
		system("cls");
		int Num;
		cout << "1. ���, 2. ��ü ���, 3. �˻� ���, 4. ����, 5. ���� : ";
		cin >> Num;
		switch (Num)
		{
		case 1:
			Input();
			break;

		case 2:
			PrintAll();
			break;

		case 3:
			Search();
			break;

		case 4:
			Delete();
			break;

		case 5:
			return;

		default :
			continue;
		}
	}
}

void School::Input()
{
	string name;
	int kor, en, math;
	cout << "����� �л��� �̸� : ";
	cin >> name;
	cout << name << "�л��� ���� ���� : ";
	cin >> kor;
	cout << name << "�л��� ���� ���� : ";
	cin >> en;
	cout << name << "�л��� ���� ���� : ";
	cin >> math;

	Student t;
	t.SetStudent(name, kor, en, math);
	vecStu.push_back(t);

}

void School::PrintAll()
{
	if (vecStu.size() >= 1)
	{
		for (size_t i = 0; i < vecStu.size(); ++i)
		{
			vecStu[i].PrintStudent();
		}
		system("pause");
	}
	else
	{
		cout << "�л��� �����ϴ�" << endl;
		system("pause");
	}
}

void School::Search()
{
	while (true)
	{
		system("cls");
		int Input;
		string name;
		cout << "1. �˻�, 2. �ڷΰ��� : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			while (true)
			{
				system("cls");
				cout << "�˻��� �л��� �̸� : ";
				cin >> name;			
				for (size_t i = 0; i < vecStu.size(); ++i)
				{
					if (vecStu[i].GetName() == name)
					{

						system("cls");
						vecStu[i].PrintStudent();
						system("pause");
						break;
					}
					if (i + 1 == vecStu.size())
					{
						cout << "�˻��� �л��� �����ϴ�" << endl;
						system("pause");
						break;
					}
					
				}
				break;
			}


			break;
		case 2:
			return;

		default:
			continue;
		}
	}
}

void School::Delete()
{
	while (true)
	{
		system("cls");
		int Input;
		string name;
		cout << "1. ����, 2. �ڷΰ��� : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			while (true)
			{
				system("cls");
				cout << "������ �л��� �̸� : ";
				cin >> name;
				for (iter = vecStu.begin(); iter != vecStu.end(); ++iter)
				{ 
					if ((*iter).GetName() == name)
					{
						vecStu.erase(iter); 
						
						cout << "���� �Ϸ�" << endl;
						system("pause");
						break;
					}
					
					if (++iter == vecStu.end())
					{
						cout << "������ �л��� �����ϴ�" << endl;
						system("pause");
						break;
					}				
				}
				break;			
			}
			break;

		case 2:
			return;

		default:
			continue;
		}
	}
}

School::School()
{
}


School::~School()
{
}
