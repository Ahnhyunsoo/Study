#include <iostream>

using namespace std;

void main(void)
{
	int		iArray[25] = { 0 };
	int		iInput = 0;
	int		iZeroIndex = 0;
	int		iTemp = 0;

	for (int i = 0; i < 25; ++i)
	{
		iArray[i] = i;
	}

	while (true)
	{
		system("cls");

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				int iIndex = i * 5 + j;

				cout << iArray[iIndex] << "\t";

			}
			cout << endl;
		}

		for (int i = 0; i < 25; ++i)
		{
			if (0 == iArray[i])
			{
				iZeroIndex = i;
				break;
			}
		}

		cout << "숫자 입력해(2. 아래 4. 왼쪽 6. 오른쪽 8. 위) : ";
		cin >> iInput;

		switch (iInput)
		{
		case 2:
			if (19 < iZeroIndex)
				break;

			iTemp = iArray[iZeroIndex];
			iArray[iZeroIndex] = iArray[iZeroIndex + 5];
			iArray[iZeroIndex + 5] = iTemp;

			break;

		case 4:
			if (0 == iZeroIndex % 5)
				break;

			iTemp = iArray[iZeroIndex];
			iArray[iZeroIndex] = iArray[iZeroIndex - 1];
			iArray[iZeroIndex - 1] = iTemp;
			break;

		case 6:
			if (4 == iZeroIndex % 5)
				break;

			iTemp = iArray[iZeroIndex];
			iArray[iZeroIndex] = iArray[iZeroIndex + 1];
			iArray[iZeroIndex + 1] = iTemp;
			break;

		case 8:
			if (5 > iZeroIndex)
				break;

			iTemp = iArray[iZeroIndex];
			iArray[iZeroIndex] = iArray[iZeroIndex - 5];
			iArray[iZeroIndex - 5] = iTemp;
			break;

		default:
			continue;
		}

	}

}
