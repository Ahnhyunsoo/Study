#include <iostream>

using namespace std;

void main(void)
{
	char A[100] = "";
	cout << "���ڿ� �Է� : ";
	cin >> A;
	int count = 0;
	for (int i = 0; i < 100; ++i)
	{
		if (A[i] != 0)
		{
			count++;
		}
	}
	for (int i = count; count >= 0; --count)
	{
		cout << A[count];
	}
	

}