#include <iostream>

using namespace std;

void main(void)
{
	int Array[25] = {};
	int count = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			Array[count] = count + 1;
			cout << Array[count] << " ";
			count++;			
		}
		cout << endl;
	}
}