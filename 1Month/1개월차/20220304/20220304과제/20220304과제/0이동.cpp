#include <iostream>

using namespace std;

void exe();
void Output(int(*p)[3]);
int Input();
void Change(int a, int(*p)[3]);


void main(void)
{
	exe();
}


void exe()
{
	int a[3][3] = { 0,1,2,3,4,5,6,7,8 };
	Output(a);
	while (true)
	{
		Change(Input(), a);
		Output(a);
	}
}

void Output(int(*p)[3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << p[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

int Input()
{
	int iInput = 0;
	cout << "2 4 6 8 숫자 입력 : ";
	cin >> iInput;
	return iInput;
}

void Change(int a, int(*p)[3])
{
	int iTemp = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (p[i][j] == 0)
			{
				if (a == 2 && i < 2)
				{
					p[i][j] = p[i + 1][j];
					p[i + 1][j] = iTemp;
					return;
				}
				if (a == 4 && j > 0)
				{
					p[i][j] = p[i][j - 1];
					p[i][j - 1] = iTemp;
					return;
				}
				if (a == 6 && j < 2)
				{
					p[i][j] = p[i][j + 1];
					p[i][j + 1] = iTemp;
					return;
				}
				if (a == 8 && i > 0)
				{
					p[i][j] = p[i - 1][j];
					p[i - 1][j] = iTemp;
					return;
				}
			}
		}
	}
}

//0	1	2	2 = +i  if i<2
//3	4	5	4 = -j  if j>0
//6	7	8	6 = +j  if j<2
//			8 = -i  if i>0