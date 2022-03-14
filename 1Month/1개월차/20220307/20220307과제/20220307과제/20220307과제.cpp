#include <iostream>

using namespace std;

struct tagInfo
{
	char Name[4][20] = {};
	int Kor[3] = {};
	int En[3] = {};
	int Math[3] = {};
	int Sum[3] = {};
	float Avg[3] = {};
};


void exe();

int Num();

void Input(tagInfo* ptag);

void AllPrint(tagInfo* ptag);

void Search(tagInfo* ptag);

void main(void)
{
	exe();
}

void exe()
{
	tagInfo tag;
	tagInfo* ptag = &tag;
	while (true)
	{
		int Choice = Num();
		void(*pFunc[3])(tagInfo* ptag) = { Input, AllPrint, Search };

		if (Choice == 4)
			return;

		pFunc[Choice - 1](ptag);


		/*	switch (Num())
			{
			case 1:
				Input(ptag);
				break;

			case 2:
				AllPrint(ptag);
				break;

			case 3:
				Search(ptag);
				break;

			case 4:
				return;
				break;

			default:
				continue;
			}
		}*/
	}
}

int Num()
{
	int iInput = 0;
	cout << "1. �Է� 2. ��ü��� 3. �˻���� 4. ���� : ";
	cin >> iInput;
	return iInput;
}

void Input(tagInfo* ptag)
{
	for (int i = 0; i < 3; ++i)
	{
		system("cls");
		cout << i + 1 << "�� �л��� �̸� : ";
		cin >> ptag->Name[i];
		cout << ptag->Name[i] << "�л��� �������� : ";
		cin >> ptag->Kor[i];
		cout << ptag->Name[i] << "�л��� �������� : ";
		cin >> ptag->En[i];
		cout << ptag->Name[i] << "�л��� �������� : ";
		cin >> ptag->Math[i];
		ptag->Sum[i] = ptag->Kor[i] + ptag->En[i] + ptag->Math[i];
		ptag->Avg[i] = ptag->Kor[i] + ptag->En[i] + ptag->Math[i] / 3.f;
	}
}

void AllPrint(tagInfo* ptag)
{
	system("cls");
	for (int i = 0; i < 3; ++i)
	{
		cout << ptag->Name[i] << "�л��� ����" << endl;
		cout << "���� : " << ptag->Kor[i] << " ���� : " << ptag->En[i] << " ���� : " << ptag->Math[i] << " ���� : " << ptag->Sum[i] << " ��� : " << ptag->Avg[i] << endl;
		cout << endl;
	}
}

void Search(tagInfo* ptag)
{
	system("cls");
	cout << "�˻��� �л��� �̸� : ";
	cin >> ptag->Name[3];
	for (int i = 0; i < 3; ++i)
	{
		if (!strcmp(ptag->Name[i], ptag->Name[3]))
		{
			cout << ptag->Name[i] << "�л��� ����" << endl;
			cout << "���� : " << ptag->Kor[i] << " ���� : " << ptag->En[i] << " ���� : " << ptag->Math[i] << " ���� : " << ptag->Sum[i] << " ��� : " << ptag->Avg[i] << endl;
			break;
		}
	}
}