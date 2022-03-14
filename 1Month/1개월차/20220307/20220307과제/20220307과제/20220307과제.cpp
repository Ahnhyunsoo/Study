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
	cout << "1. 입력 2. 전체출력 3. 검색출력 4. 종료 : ";
	cin >> iInput;
	return iInput;
}

void Input(tagInfo* ptag)
{
	for (int i = 0; i < 3; ++i)
	{
		system("cls");
		cout << i + 1 << "번 학생의 이름 : ";
		cin >> ptag->Name[i];
		cout << ptag->Name[i] << "학생의 국어점수 : ";
		cin >> ptag->Kor[i];
		cout << ptag->Name[i] << "학생의 영어점수 : ";
		cin >> ptag->En[i];
		cout << ptag->Name[i] << "학생의 수학점수 : ";
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
		cout << ptag->Name[i] << "학생의 점수" << endl;
		cout << "국어 : " << ptag->Kor[i] << " 영어 : " << ptag->En[i] << " 수학 : " << ptag->Math[i] << " 총점 : " << ptag->Sum[i] << " 평균 : " << ptag->Avg[i] << endl;
		cout << endl;
	}
}

void Search(tagInfo* ptag)
{
	system("cls");
	cout << "검색할 학생의 이름 : ";
	cin >> ptag->Name[3];
	for (int i = 0; i < 3; ++i)
	{
		if (!strcmp(ptag->Name[i], ptag->Name[3]))
		{
			cout << ptag->Name[i] << "학생의 성적" << endl;
			cout << "국어 : " << ptag->Kor[i] << " 영어 : " << ptag->En[i] << " 수학 : " << ptag->Math[i] << " 총점 : " << ptag->Sum[i] << " 평균 : " << ptag->Avg[i] << endl;
			break;
		}
	}
}