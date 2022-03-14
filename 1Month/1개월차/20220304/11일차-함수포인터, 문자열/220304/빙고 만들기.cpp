#include <iostream>

using namespace std;

void main(void)
{
	int		iNumber[25] = {};
	int		iInput = 0;

	int		iCount = 0, iBingo = 0;

	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
	}

	while (true)
	{
		system("cls");

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				int iIndex = i * 5 + j;

				if (0 == iNumber[iIndex])
					cout << " * " << "\t";
				else
					cout << iNumber[iIndex] << "\t";
			}
			cout << endl;
		}

		if (5 <= iBingo)
		{
			cout << "승리" << endl;
			break;
		}

		cout << "빙고 : " << iBingo << endl;
		cout << "숫자 입력 : ";
		cin >> iInput;

		

		for (int i = 0; i < 25; ++i)
		{
			if (iInput == iNumber[i])
			{
				iNumber[i] = 0;
				break;
			}
		}

		iBingo = 0;

		// 가로줄 판정
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (0 == iNumber[i * 5 + j])
					++iCount;

				if (5 == iCount)
					++iBingo;
			}

			iCount = 0;
		}

		// 세로줄 판정
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (0 == iNumber[j * 5 + i])
					++iCount;

				if (5 == iCount)
					++iBingo;
			}

			iCount = 0;
		}

		// 오른쪽 대각선

		for (int i = 0; i < 5; ++i)
		{
			if(0 == iNumber[i * 6])
				++iCount;
			if (5 == iCount)
				++iBingo;
		}
		iCount = 0;

		// 왼쪽 대각선

		for (int i = 0; i < 5; ++i)
		{
			if (0 == iNumber[i * 4 + 4])
				++iCount;
			if (5 == iCount)
				++iBingo;
		}
		iCount = 0;


	}


}