#include "stdafx.h"
#include "Student.h"
#include "Machine.h"

void CMachine::exe()
{
	int Num = 0;
	
	while (true)
	{
		system("cls");
		cout << "1.��� 2. ��ü��� 3. �˻���� 4. ���� : ";
		cin >> Num;
		int student = 0;
		switch (Num)
		{
		case 1:
			//������ ������ŭ ���� �����ϰ� ���� �ٵ� ���� ������ 0�̸� ���Ѵ� �����ϴ��Լ�
			cout << "����� �л��� �� : ";
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
			cout << "�˻��� �л��� �̸� : ";
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
					cout << "ã�� �л��� �����ϴ�" << endl;
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

