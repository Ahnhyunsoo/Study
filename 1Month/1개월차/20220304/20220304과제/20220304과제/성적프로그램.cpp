#include <iostream>

using namespace std;

void exe();
int menu();
//int Check(char* C, char* B);

void main(void)
{
	exe();
}

void exe()
{
	char* Name[3] = {};
	int Korean[3] = {};
	int Math[3] = {};
	int English[3] = {};
	char cTemp[4][100] = {};
	char* B[1] = {};

	while (true)
	{
		switch (menu())
		{
		case 1:
			for (int i = 0; i < 3; ++i)
			{
				cout << i + 1 << "번 학생의 이름을 입력하세요 : ";
				cin >> cTemp[i];
				Name[i] = cTemp[i];

				cout << Name[i] << " 학생의 국어 점수를 입력하세요 : ";
				cin >> Korean[i];
				cout << Name[i] << " 학생의 수학 점수를 입력하세요 : ";
				cin >> Math[i];
				cout << Name[i] << " 학생의 영어 점수를 입력하세요 : ";
				cin >> English[i];

			}



		case 2:
			for (int i = 0; i < 3; ++i)
			{
				int Sum = Korean[i] + Math[i] + English[i];
				int Avg = (Korean[i] + Math[i] + English[i]) / 3;
				cout << Name[i] << "학생의 국어점수 : " << Korean[i] << " 수학점수 : " << Math[i] << " 영어점수 : " << English[i] << " 총점 : " << Sum << " 평균 : " << Avg << endl;
			}
			break;

		case 3:
			cout << "학생 이름 입력 : ";
			cin >> cTemp[4];
			B[0] = cTemp[4];

			for (int i = 0; i < 3; ++i)
			{ 
				if (*Name[i] == *B[0]) 
				{
					int Sum = Korean[i] + Math[i] + English[i];
					int Avg = (Korean[i] + Math[i] + English[i]) / 3;
					cout << Name[i] << "학생의 국어점수 : " << Korean[i] << " 수학점수 : " << Math[i] << " 영어점수 : " << English[i] << " 총점 : " << Sum << " 평균 : " << Avg << endl;
				}
			}
			break;
		case 4:
			cout << "프로그램을 종료합니다" << endl;
			return;
		}
	}
}



int menu()
{
	int iInput = 0;
	cout << "1. 입력 2. 전체 출력 3. 검색 출력 4. 종료 : ";
	cin >> iInput;
	return iInput;
}


//int Check(char C[3], char B[1])
//{
//	cout << C[0] << endl;
//	return 1;
//	
//}










/*
4. 3명의 입력 가능한 성적표 프로그램 만들기(이름, 국어, 영어, 수학, 총점, 평균)
(구조체 사용금지)
// 1. 입력 2. 전체 출력 3. 검색 출력 4. 종료
입력할 때 마다 3명씩 점수 입력
입력 후 전체 출력 검색 출력
*/