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
	cout << "1. ���, 2. �߰����, 3. ��ü���, 4. �˻����, 5. ���� : ";
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
		cout << "�߰��� �л��� �� : ";
		cin >> iStudent;
		��
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
			cout << "�߸��Է��ϼ̽��ϴ�" << endl;
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


