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
			int iIndex = i * 5 + j; //(�ε��� ���ϴ� ����)
			cout << iArray[i * 5 + j] << "\t";
		} // [i * (tile�� ����) + j(���� ��)
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