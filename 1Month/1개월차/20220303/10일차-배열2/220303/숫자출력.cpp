#include <iostream>

using namespace std;

void main(void)
{
	int		iArray[25] = { 0 };

	for (int i = 0; i < 25; ++i)
	{
		iArray[i] = i + 1;
	}

	for(int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int	iIndex = i * 5 + j;

			cout << iArray[iIndex] << "\t";
		}

		cout << endl;
	}

}