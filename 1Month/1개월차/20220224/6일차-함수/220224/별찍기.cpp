#include <iostream>

using namespace std;

void main(void)
{
	/*for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i >= j)
				cout << " * " << "\t";
			else
				cout << " " << "\t";
		}

		cout << endl;
	}*/

	/*for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (i <= j)
				cout << " * " << "\t";
			else
				cout << " " << "\t";
		}

		cout << endl;
	}*/

	/*for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (4 >= i + j)
				cout << " * " << "\t";
			else
				cout << " " << "\t";
		}

		cout << endl;
	}*/

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (4 <= i + j)
				cout << " * " << "\t";
			else
				cout << " " << "\t";
		}

		cout << endl;
	}

	

}