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
		if (A[i] != NULL)
		{
			count++;
			
		}	
	}
	cout << A << endl;
	cout << "���ڿ��� ���� : " << count << endl;
}