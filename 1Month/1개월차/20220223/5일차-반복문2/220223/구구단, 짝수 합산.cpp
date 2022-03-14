#include <iostream>

using namespace std;

void main(void)
{
	/*int	i = 2, j = 1;

	while (10 > i)
	{	
		cout << i << " * " << j << " = " << i * j << endl;
		++j;
		
		if (9 < j)
		{
			++i;
			j = 1;
			cout << "=======================" << endl;
		}

	}*/

	int		iCount = 5, iInput = 0, iSum = 0;

	do 
	{
		cout << "숫자를 입력하세요 : ";
		cin >> iInput;
		--iCount; 

		if (0 == iCount)
			break;

		/*if(0 != iInput % 2)
			continue;*/

		if(0 == iInput % 2)
			iSum += iInput;

	} while (-1 != iInput);

	cout << "짝수의 합 : " << iSum << endl;
}