#include "stdafx.h"
#include "Define.h"
#include "Student.h"

void CStudent::Input()
{
	int num = 0;
	cout << "�Է��� �л��� �� : ";
	cin >> num;

	if (sp == nullptr)
	{
		sp = new Info[num];
		for (int i = 0; i < num; ++i)
		{
			cout << "�л��� �̸� : ";
			cin >> sp[i].Name;
			sp->Name[i];
			cout << sp[i].Name << "�л��� �������� : ";
			cin >> sp[i].Kor;
			cout << sp[i].Name << "�л��� �������� : ";
			cin >> sp[i].Math;
			cout << sp[i].Name << "�л��� �������� : ";
			cin >> sp[i].En;
		}
	}
	else
	{
		PInfo nsp = new Info[size + num];
		memcpy(nsp, sp, sizeof(Info) * size);
		delete[] sp;
		sp = nullptr;
		sp = nsp;
		for (int i = size; i < size+num; ++i)
		{
			cout << "�л��� �̸� : ";
			cin >> sp[i].Name;
			sp->Name[i];
			cout << sp[i].Name << "�л��� �������� : ";
			cin >> sp[i].Kor;
			cout << sp[i].Name << "�л��� �������� : ";
			cin >> sp[i].Math;
			cout << sp[i].Name << "�л��� �������� : ";
			cin >> sp[i].En;
		}
	}
	size += num;
	

}

void CStudent::Output()
{
	for (int i = 0; i < size; ++i)
	{
		cout << sp[i].Name << endl;
		cout << sp[i].Kor << endl;
		cout << sp[i].Math << endl;
		cout << sp[i].En << endl;
	}
}

void CStudent::Search(string name)
{

}

CStudent::CStudent()
{
	Input();
	Output();
	cout << "�׽�Ʈ" << endl;
}

CStudent::~CStudent()
{
	cout << "�׽�Ʈ" << endl;
}




#include <iostream>

using namespace std;

void main(void)
{
	int a = 10;
	int b = 20;
	int c = 30;

	if (a == b == c)
	{
		cout << (a + b + c) / 3 << endl;
	}
	else
	{
		if (a > b && a > c)
		{
			b = a+10;
			c = a+10;
			a = a + 10;
		}
		else if (b > a && b > c)
		{
			a = b+10;
			c = b+10;
			b = b + 10;
		}
		else
		{
			a = c+10;
			b = c+10;
			c = c + 10;
		}
	}
}

