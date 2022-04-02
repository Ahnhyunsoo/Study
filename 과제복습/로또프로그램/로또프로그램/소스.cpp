#include <iostream>
#include <time.h>

using namespace std;

void main(void)
{
	srand(unsigned(time(NULL)));

	
		int iArray1[20] = {0};
		int iArray[6] = {0};

		for (int j = 0; j < 20; j++)
		{
			iArray1[j] = j + 1;
		}


	
		int j = 1;
			int r = rand();
		for (int i = 0; i < 6;)
		{
			if (iArray[i] == 0)
			{
				iArray[i] = r;
			}




			++i;
		}
	


		int iDest = 0, iSour = 0;	int iTemp = 0;

		for (int i = 0; i < 5; ++i)
		{
			for (int k = 0; k < 50; ++k)
			{

				iDest = rand() % 20;
				iSour = rand() % 20;


				iTemp = iArray1[iDest];
				iArray1[iDest] = iArray1[iSour];
				iArray1[iSour] = iTemp;
			}

			for (int j = 0; j < 6; ++j)
			{
				iArray[j] = iArray1[j];
				cout << iArray[j] << " ";
			}
			cout << endl;
		}
	
}