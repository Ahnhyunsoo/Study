#include <iostream>
#include <time.h>

using namespace std;

void main(void)
{
#pragma region 자판기 만들기

	/*int		iCoin = 0, iInput = 0;
	int		iCoke = 100, iCider = 200, iFanta = 300;
	bool	bExit = true;

	cout << "금액을 입력하세요 : ";
	cin >> iCoin;

	while (bExit)
	{
		system("cls");
		cout << "소지금 : " << iCoin << endl;
		cout << "1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환 : ";
		cin >> iInput;

		/ *if (1 == iInput)
		{
		if (iCoin >= iCoke)
		{
		cout << "콜라 구매 완료!" << endl;
		iCoin -= iCoke;
		}
		else
		cout << "소지금이 부족합니다" << endl;
		}
		else if (2 == iInput)
		{
		if (iCoin >= iCider)
		{
		cout << "사이다 구매 완료!" << endl;
		iCoin -= iCider;
		}
		else
		cout << "소지금이 부족합니다" << endl;
		}
		else if (3 == iInput)
		{
		if (iCoin >= iFanta)
		{
		cout << "환타 구매 완료!" << endl;
		iCoin -= iFanta;
		}
		else
		cout << "소지금이 부족합니다" << endl;
		}
		else if (4 == iInput)
		{
		cout << "거스름 돈은 " << iCoin << "원 입니다. " << endl;
		bExit = false;
		}
		else
		cout << "잘못 입력하셨습니다" << endl;* /

		switch (iInput)
		{
		case 1:

			if (iCoin >= iCoke)
			{
				cout << "콜라 구매 완료!" << endl;
				iCoin -= iCoke;
			}
			else
				cout << "소지금이 부족합니다" << endl;

			break;

		case 2:

			if (iCoin >= iCider)
			{
				cout << "사이다 구매 완료!" << endl;
				iCoin -= iCider;
			}
			else
				cout << "소지금이 부족합니다" << endl;

			break;

		case 3:

			if (iCoin >= iFanta)
			{
				cout << "환타 구매 완료!" << endl;
				iCoin -= iFanta;
			}
			else
				cout << "소지금이 부족합니다" << endl;

			break;

		case 4:

			cout << "거스름 돈은 " << iCoin << "원 입니다. " << endl;
			bExit = false;
			break;

		default:
			cout << "잘못 입력하셨습니다" << endl;
			break;
		}

		system("pause");
	}*/

#pragma endregion 자판기 만들기

#pragma region 홀짝 판별하기

/*
int	iInput = 0, iCount = 5, iWin = 0, iLose = 0, iRandom = 0;
bool bExit = true;

srand(unsigned(time(NULL)));

while ((0 < iCount) && bExit)
{
	system("cls");

	iRandom = rand() % 10 + 1;
		
	cout << "정답은 " << iRandom << "입니다. 알고 맞추는 게임이에요" << endl;
	cout << "1. 홀 2. 짝 3. 종료 : ";
	cin >> iInput;

	--iCount;

	iRandom %= 2;

	if (1 == iInput)
	{
		if (1 == iRandom)
		{
			cout << "컴퓨터 : 홀" << endl;
			cout << "사용자 : 홀" << endl;
			cout << "정답입니다" << endl;
			++iWin;
		}
		else
		{
			cout << "컴퓨터 : 짝" << endl;
			cout << "사용자 : 홀" << endl;
			cout << "오답입니다" << endl;
			++iLose;
		}
	}

	else if (2 == iInput)
	{
		if (1 == iRandom)
		{
			cout << "컴퓨터 : 홀" << endl;
			cout << "사용자 : 짝" << endl;
			cout << "오답입니다" << endl;
			++iLose;
		}
		else
		{
			cout << "컴퓨터 : 짝" << endl;
			cout << "사용자 : 짝" << endl;
			cout << "정답입니다" << endl;
			++iWin;
		}

	}

	else if (3 == iInput)
	{
		bExit = false;
	}
	else
	{
		cout << "잘못 입력하였습니다" << endl;
		++iCount;
	}

	system("pause");
}

system("cls");
cout << "승 : " << iWin << "\t패 : " << iLose << endl;
system("pause");*/

#pragma endregion 홀짝 판별하기

	
}
