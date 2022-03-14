#include <iostream>
#include <time.h>

using namespace std;

//void	Bubble_Sort(int* pArray, int iSize);
void	Bubble_Sort(int iArray[], int iSize);	// 배열의 이름을 매개변수로 받는 문법적 허용
												// 함수의 매개변수로만 사용 가능한 문법
void main(void)
{
	srand(unsigned(time(NULL)));

	int	iArray[45] = { 0 };
	int iLotto[6] = { 0 };

	for (int i = 0; i < 45; ++i)
	{
		iArray[i] = i + 1;
	}

	int	iDest = 0, iSour = 0, iTemp = 0;

	for (int k = 0; k < 5; ++k)
	{

		for (int i = 0; i < 500; ++i)
		{
			iDest = rand() % 45;	// 20
			iSour = rand() % 45;	// 36

			iTemp = iArray[iDest];
			iArray[iDest] = iArray[iSour];
			iArray[iSour] = iTemp;
		}

		for (int j = 0; j < 6; ++j)
			iLotto[j] = iArray[j];

		// 정렬
		Bubble_Sort(iLotto, sizeof(iLotto) / sizeof(int));

		for (int i = 0; i < 6; ++i)
		{
			cout << iLotto[i] << "\t";
		}
		cout << endl;
	}
}

/*
void	Bubble_Sort(int* pArray, int iSize)
{
	int		iTemp = 0;

	for (int i = 0; i < iSize - 1; ++i)
	{
		for (int j = 0; j < iSize - 1 - i; ++j)
		{
			if (pArray[j] > pArray[j + 1])
			{
				iTemp = pArray[j];
				pArray[j] = pArray[j + 1];
				pArray[j + 1] = iTemp;
			}
		}
	}
}*/
void	Bubble_Sort(int iArray[], int iSize)
{
	int		iTemp = 0;

	for (int i = 0; i < iSize - 1; ++i)
	{
		for (int j = 0; j < iSize - 1 - i; ++j)
		{
			if (iArray[j] > iArray[j + 1])
			{
				iTemp = iArray[j];
				iArray[j] = iArray[j + 1];
				iArray[j + 1] = iTemp;
			}
		}
	}
}