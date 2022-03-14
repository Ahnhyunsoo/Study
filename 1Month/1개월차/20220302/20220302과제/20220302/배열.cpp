#include <iostream>

using namespace std;

void main(void)
{
	int iArray[25] = {};

	for (int i = 0; i < 25; ++i)
	{
		iArray[i] = i + 1;
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int iIndex = i * 5 + j; //(인덱스 구하는 공식)
			cout << iArray[i * 5 + j] << "\t";
		} // [i * (tile의 갯수) + j(세로 줄)
		cout << endl;
	}


	/*int iArray[25] = {};

	for (int i = 0; i < 5; ++i)
	{
		for (int j = i * 5; j < (i + 1) * 5; ++j)
		{
			iArray[j] = j + 1;
			cout << iArray[j] << " ";
		}
		cout << endl;
	}*/
}