#include <iostream>
#include <time.h>

using namespace std;

void main(void)
{
	int	iInput = 0, iComputer = 0, iCount = 5;
	int iWin = 0, iDraw = 0, iLose = 0;
	bool	bExit = true;

	srand(unsigned(time(NULL)));

	while (bExit && (0 < iCount))
	{
		system("cls");
		iComputer = rand() % 3 + 1;
		cout << "1. 가위 2. 바위 3. 보 4. 종료 : ";
		cin >> iInput;
		--iCount;

		switch (iInput)
		{
		case 1:
			if (1 == iComputer)
			{
				cout << "컴퓨터 : 가위" << endl;
				cout << "플레이어 : 가위" << endl;
				cout << "무승부입니다" << endl;
				++iDraw;				
			}

			else if (2 == iComputer)
			{
				cout << "컴퓨터 : 바위" << endl;
				cout << "플레이어 : 가위" << endl;
				cout << "졌습니다" << endl;
				++iLose;
			}

			else
			{
				cout << "컴퓨터 : 보" << endl;
				cout << "플레이어 : 가위" << endl;
				cout << "이겼입니다" << endl;
				++iWin;
			}

			break;

		case 2:
			if (1 == iComputer)
			{
				cout << "컴퓨터 : 가위" << endl;
				cout << "플레이어 : 바위" << endl;
				cout << "이겼습니다" << endl;
				++iWin;
			}

			else if (2 == iComputer)
			{
				cout << "컴퓨터 : 바위" << endl;
				cout << "플레이어 : 바위" << endl;
				cout << "무승부입니다" << endl;
				++iDraw;
			}

			else
			{
				cout << "컴퓨터 : 보" << endl;
				cout << "플레이어 : 바위" << endl;
				cout << "졌습니다" << endl;
				++iLose;
			}
			break;

		case 3:
			if (1 == iComputer)
			{
				cout << "컴퓨터 : 가위" << endl;
				cout << "플레이어 : 보" << endl;
				cout << "졌습니다" << endl;
				++iLose;
			}

			else if (2 == iComputer)
			{
				cout << "컴퓨터 : 바위" << endl;
				cout << "플레이어 : 보" << endl;
				cout << "이겼습니다" << endl;
				++iWin;
			}

			else
			{
				cout << "컴퓨터 : 보" << endl;
				cout << "플레이어 : 보" << endl;
				cout << "무승부입니다" << endl;
				++iDraw;
			}
			break;

		case 4:
			bExit = false;
			break;

		default:
			cout << "잘못 누르셨습니다" << endl;
			++iCount;
			continue;
		}

		system("pause");
	}

	system("cls");
	cout << "승 : " << iWin << "\t무 : " << iDraw << "\t패 : " << iLose << endl;
	system("pause");
}