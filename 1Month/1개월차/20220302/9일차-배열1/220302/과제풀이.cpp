#include <iostream>

using namespace std;

void	Swap(int* pTemp, int* pSour);

void main(void)
{
	int		iA = 10, iB = 20;

	cout << iA << "\t" << iB << endl;
		
	Swap(&iA, &iB);

	cout << iA << "\t" << iB << endl;

}
void	Swap(int* pTemp, int* pSour)
{
	int	iDest = 0;

	iDest = *pTemp;
	*pTemp = *pSour;
	*pSour = iDest;
}
