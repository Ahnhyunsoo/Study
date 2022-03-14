#include <iostream>

using namespace std;

void main(void)
{
	int		iDan = 0, iGob = 0;

	cout << "단을 입력하세요 : ";
	cin >> iDan;

	cout << "곱을 입력하세요 : ";
	cin >> iGob;

	for (int i = 2; i <= iDan; ++i)
	{
		for (int j = 1; j <= iGob; ++j)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << "=========================" << endl;
	}

	

	

}