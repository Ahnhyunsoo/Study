#include <iostream>
#include <time.h>

using namespace std;

void Initialize(int* pArray, int iSize);
int	 Check_Strike(int* pAnswer, int* pInput, int iSize);
int	 Check_Ball(int* pAnswer, int* pInput, int iSize);


void main(void)
{
	srand(unsigned(time(nullptr)));

	int		iArray[9] = {0};
	int		iInput[3] = { 0 };
	int		iAnswer[3] = { 0 };
	int		iStrike = 0, iBall = 0, iCount = 0;

	Initialize(iArray, sizeof(iArray) / sizeof(int));

	for (int i = 0; i < 3; ++i)
		iAnswer[i] = iArray[i];

	while (true)
	{
		system("cls");

		if (9 <= iCount)
		{
			cout << "패배" << endl;
			break;
		}
		if (3 == iStrike)
		{
			cout << "승리" << endl;
			break;
		}

		cout << "========================" << endl;
		cout << iAnswer[0] << "\t" << iAnswer[1] << "\t" << iAnswer[2] << endl;
		cout << "========================" << endl;
		
		cout << iCount + 1 << "회차, 숫자 입력 : ";
		cin >> iInput[0] >> iInput[1] >> iInput[2];
		++iCount;

		iStrike = Check_Strike(iAnswer, iInput, sizeof(iAnswer) / sizeof(int));
		iBall   = Check_Ball(iAnswer, iInput, sizeof(iAnswer) / sizeof(int));

		cout << iStrike << " 스트라이크\t" << iBall << " 볼" << endl;



		system("pause");
	}

}

void Initialize(int* pArray, int iSize)
{
	int iDest = 0, iSour = 0, iTemp = 0;

	for (int i = 0; i < iSize; ++i)
		pArray[i] = i + 1;

	for (int i = 0; i < 500; ++i)
	{
		iDest = rand() % 9;	// 20
		iSour = rand() % 9;	// 36

		iTemp = pArray[iDest];
		pArray[iDest] = pArray[iSour];
		pArray[iSour] = iTemp;
	}

}
int	 Check_Strike(int* pAnswer, int* pInput, int iSize)
{
	int	iStrike = 0;

	for (int i = 0; i < iSize; ++i)
	{
		if (pAnswer[i] == pInput[i])
			++iStrike;
	}


	return iStrike;
}
int	 Check_Ball(int* pAnswer, int* pInput, int iSize)
{
	int	iBall = 0;

	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			if(i == j)
				continue;

			if (pAnswer[i] == pInput[j])
				++iBall;
		}
		
	}
	return iBall;
}