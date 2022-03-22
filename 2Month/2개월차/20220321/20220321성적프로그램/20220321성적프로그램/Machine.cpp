#include "stdafx.h"
#include "Student.h"
#include "Machine.h"

void CMachine::exe()
{
	int Num = 0;
	
	while (true)
	{
		system("cls");
		cout << "1.등록 2. 전체출력 3. 검색출력 4. 종료 : ";
		cin >> Num;
		int student = 0;
		switch (Num)
		{
		case 1:
			//기존의 랭스만큼 값을 복사하고 삭제 근데 만약 랭스가 0이면 안한다 복사하는함수
			cout << "등록할 학생의 수 : ";
			cin >> student;
			if (Length == 0)
			{
				sp = new CStudent[Length + student];
				sp = new CStudent[5];
				for (int i = 0; i < student; ++i)
				{
					sp[Length].InputStudent();
					Length += 1;
				}
			}
			else
			{
				CStudent* spTemp = new CStudent[Length];
				for (int i = 0; i < Length; ++i)
				{
					spTemp[i] = sp[i];
				}

				delete[] sp;
				sp = nullptr;

				sp = new CStudent[Length + student];
				for (int i = 0; i < Length; ++i)
				{
					sp[i] = spTemp[i];
				}

				delete[] spTemp;
				spTemp = nullptr;

				for (int i = 0; i < student; ++i)
				{
					sp[Length].InputStudent();
					Length += 1;
				}

			}
			break;
		case 2:
			for (int i = 0; i < Length; ++i)
			{
				sp[i].PrintAll();				
			}
			system("pause");
			break;	
		case 3:
			string Search;
			cout << "검색할 학생의 이름 : ";
			cin >> Search;
			for (int i = 0; i < Length; ++i)
			{
				if (sp[i].Search(Search) == 1)
				{
					sp[i].PrintAll();
					system("pause");
					break;
				}
				else if(i+1 == Length)
				{
					cout << "찾는 학생이 없습니다" << endl;
					system("pause");
				}
			}
			break;
		}
		
	}
}

int CMachine::Get()
{
	return Length;
}

