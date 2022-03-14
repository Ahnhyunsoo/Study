#include <iostream>

using namespace std;

void main(void)
{
	const int iSize = 3;

	int iArray[iSize][iSize] = {};
	int iRotation[iSize][iSize] = {};

	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize; ++j)
		{
			iArray[i][j] = (i*iSize + j) + 1;
			cout << iArray[i][j] << "\t";
		}
		cout << endl;
	}

	for (int k = 0; k < 4; ++k)
	{
		cout << "=======================" << endl;

		for (int i = 0; i < iSize; ++i)
		{
			for (int j = 0; j < iSize; ++j)
			{
				iRotation[j][(iSize - 1) - i] = iArray[i][j];
			}
		}

		for (int i = 0; i < iSize; ++i)
		{
			for (int j = 0; j < iSize; ++j)
			{
				iArray[i][j] = iRotation[i][j];
				cout << iArray[i][j] << "\t";
			}
			cout << endl;
		}
	}
}