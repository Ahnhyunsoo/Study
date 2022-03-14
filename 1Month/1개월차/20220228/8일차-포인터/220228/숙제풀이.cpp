#include <iostream>

using namespace std;

int	Factorial(int iNumber);

void main(void)
{
	cout << Factorial(100) << endl;
}

int	Factorial(int iNumber)
{
	if (0 == iNumber)
		return 1;

	return iNumber * Factorial(iNumber - 1);
}