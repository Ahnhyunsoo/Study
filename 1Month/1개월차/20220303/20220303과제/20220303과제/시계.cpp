#include <iostream>

using namespace std;



void zero();
void one();
void two();
void three();
int aArray[3][3] = { 1,2,3,4,5,6,7,8,9 };

void main(void)
{
	
	cout << "\t 0ȸ��" << endl;
	zero();
	cout << "\t 1ȸ��" << endl;
	one();	
	cout << "\t 2ȸ��" << endl;
	two();
	cout << "\t 3ȸ��" << endl;
	three();
	cout << "\t 4ȸ��" << endl;
	zero();
	
}
void zero()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << aArray[i][j] << "\t";  //���� 0��
		}
		cout << endl;
	}
}

void one()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 2; j >= 0; --j)
		{
			cout << aArray[j][i] << "\t"; // 90��
		}
		cout << endl;
	}
}

void two()
{
	for (int i = 2; i >= 0; --i)
	{
		for (int j = 2; j >= 0; --j)  // 180��
		{
			cout << aArray[i][j] << "\t";
		}
		cout << endl;
	}
}

void three()
{
	for (int i = 2; i >= 0; --i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << aArray[j][i] << "\t"; // 270��
		}
		cout << endl;
	}
}

//i = 0 < 3

//	->							l		<-
//	1	2	3		7	4	1   v	9	8	7		3	6	9
//	4	5	6		8	5	2		6	5	4		2	5	8	 ^
//	7	8	9		9	6	3		3	2	1		1	4	7	 l
//	
//	0.0 0.1 0.2		2.0 1.0 0.0		2.2 2.1 2.0		0.2 1.2 2.2
//	1.0 1.1 1.2		2.1 1.1 0.1		1.2 1.1 1.0		0.1 1.1 2.1
//	2.0 2.1 2.2		2.2 1.2 0.2		0.2 0.1 0.0		0.0 1.0 2.0    ���ڱ� �������ǵ� index �� = Ÿ��
//}

//i j



