#include <iostream>
#include <random>
#include <time.h>

using namespace std;

//void Bubble_Sort(int* pArray, int iSize);

void main(void)
{
	srand(unsigned(time(NULL)));

	int iArray[45] = { 0 };
	int iLotto[6] = { 0 };

	for (int i = 0; i < 45; ++i)
	{
		iArray[i] = i + 1;
	}

	int iDest = 0, iSour = 0, iTemp = 0;

	for (int i = 0; i < 500; ++i)
	{
		iDest = rand() % 45;
		iSour = rand() % 45;

		iTemp = iArray[iDest];
		iArray[iDest] = iArray[iSour];
		iArray[iSour] = iTemp;
	}

	for (int j = 0; j < 6; ++j)
	{
		iLotto[j] = iArray[j];

		//Bubble_Sort(iLotto, sizeof(iArray) / sizeof(int));

			cout << iArray[j] << "\t";
	}
}





	/*random_device random;
	mt19937 rd(random());
	uniform_int_distribution<int> range(1, 45);

	int a[6]{};

	for (int k = 0; k < 5; k++)
	{	
		for (int i = 0; i < 6; i++)
		{
			if (i == 0)
			{
				a[i] = range(random);					
			}
			if (i != 0)
			{
				int c = range(random);
				int* p = &c;
				for (int j = i; j > 0;)
				{
					if (a[j - 1] != c)
					{
						--j;
					}
					else if (a[j - 1] == c)
					{
						int c = range(random);
						*p = c;
						j = i;
					}
				}
				a[i] = c;	
			}			
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 6; j++)
			{
				if (a[i] > a[j])
				{
					int Temp = a[i];
					a[i] = a[j];
					a[j] = Temp;
				}
			}
		}
		for (int i = 0; i < 6; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;		
	}*/
	


void Bubble_Sort(int* pArray, int iSize)
{
	int iTemp = 0;

	for (int i = 0; i < iSize - 1; i++)
	{
		for (int j = 0; j < iSize - 1 - i; ++j)
		{
			if (pArray[j] > pArray[j + 1])
			{
				/*iTemp = pArray[j];
				pArray[j] = pArray[j + 1];
				pArray[j + 1] = iTemp;*/
			}
		}
	}
}