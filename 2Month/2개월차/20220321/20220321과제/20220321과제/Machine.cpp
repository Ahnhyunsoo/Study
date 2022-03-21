#include "stdafx.h"
#include "Student.h"
#include "Machine.h"

void CMachine::exe()
{
	CStudent* sp = NULL;
	while (true)
	{
		system("cls");
		switch (CMachine::Menu())
		{
		case 1:		
			if (sp == NULL)
			{
				sp = CMachine::Create();
	
				system("pause");
			}
			else if (sp != NULL)
			{
				delete[] sp;
				sp = NULL;
				sp = CMachine::Create();
			}
			break;
		case 2:
			CMachine::Add(sp);
			break;
		case 3:
			CMachine::PrintAll(sp);
			break;
		case 4:
			CMachine::PrintSearch(sp);
			break;
		case 5:
			return;
		}
	}
}

int CMachine::Menu()
{
	int iNum = 0;
	cout << "1. 등록, 2. 추가등록, 3. 전체출력, 4. 검색출력, 5. 종료 : ";
	cin >> iNum;
	return iNum;
}

CStudent* CMachine::Create()
{	
	CStudent* Sp = new CStudent[input];
	sp = new CStudent[2];

	for (int i = 0; i < 3; ++i)
	{
		Sp[i].InputStudent();
		Length++;
		
		
		
	}

}


void CMachine::Add(CStudent* sp)
{
	while (true)
	{
		int iStudent = 0;
		cout << "추가할 학생의 수 : ";
		cin >> iStudent;
		값
		sp 
		Sp
		sp 
		CStudent* nsp = new CStudent[Length]

			<Length
			nsp[i] = sp[i]
			sp
		sp = new CStudent[Length + iStudent]; 5
			
		if (iStudent > 0)
		{
			
			for (int i = 0; i < index; ++i)  
			{

				

			}
			
			Sp = sp;
		}
		else
		{
			cout << "잘못입력하셨습니다" << endl;
			continue;
		}
	}

}

void CMachine::PrintAll(CStudent* sp)
{


}

void CMachine::PrintSearch(CStudent* sp)
{

}

void CMachine::InputStudent(CStudent* sp)
{

}


