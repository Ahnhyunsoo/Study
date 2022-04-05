#include "stdafx.h"
#include "School.h"



void School::Exe()
{
	while (true)
	{
		system("cls");
		int Num;
		cout << "1. 등록, 2. 전체 출력, 3. 검색 출력, 4. 삭제, 5. 종료 : ";
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
	cout << "등록할 학생의 이름 : ";
	cin >> name;
	cout << name << "학생의 국어 점수 : ";
	cin >> kor;
	cout << name << "학생의 영어 점수 : ";
	cin >> en;
	cout << name << "학생의 수학 점수 : ";
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
		cout << "학생이 없습니다" << endl;
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
		cout << "1. 검색, 2. 뒤로가기 : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			while (true)
			{
				system("cls");
				cout << "검색할 학생의 이름 : ";
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
						cout << "검색한 학생이 없습니다" << endl;
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
		cout << "1. 삭제, 2. 뒤로가기 : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
			while (true)
			{
				system("cls");
				cout << "삭제할 학생의 이름 : ";
				cin >> name;
				for (iter = vecStu.begin(); iter != vecStu.end(); ++iter)
				{ 
					if ((*iter).GetName() == name)
					{
						vecStu.erase(iter); 
						
						cout << "삭제 완료" << endl;
						system("pause");
						break;
					}
					
					if (++iter == vecStu.end())
					{
						cout << "삭제할 학생이 없습니다" << endl;
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
