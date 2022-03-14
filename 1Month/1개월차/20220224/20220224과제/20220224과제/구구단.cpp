#include <iostream>

using namespace std;
//단수와 곱이 필요하다

void GuGu(int _dan, int _gob);



void main(void)
{
	int iDan = 0;
	int iGob = 0;

	cout << "원하는 단수 : ";
	cin >> iDan;
	cout << "원하는 곱수 : ";
	cin >> iGob;
	
	GuGu(iDan, iGob);

	

	
	
}

void GuGu(int _dan, int _gob)
{
	for (int i = 2; i <= _dan; ++i)
	{
		for (int j = 1; j <= _gob; ++j)
		{
			cout << i << " * " << j << " = " << (i*j) << endl;
		}
	}
}



