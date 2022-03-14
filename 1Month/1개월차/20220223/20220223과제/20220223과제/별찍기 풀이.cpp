#include <iostream>

using namespace std;

void main(void)
{
	
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if ((i + j) >= 4)
				cout << "*";
			else
			cout << " ";
		}
		cout << endl;
	}
	
	

}