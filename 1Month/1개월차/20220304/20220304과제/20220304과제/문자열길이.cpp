#include <iostream>

using namespace std;

void main(void)
{
	char A[100] = "";
	cout << "문자열 입력 : ";
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
	cout << "문자열의 길이 : " << count << endl;
}