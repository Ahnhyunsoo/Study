#include <iostream>

using namespace std;
//�ܼ��� ���� �ʿ��ϴ�

void GuGu(int _dan, int _gob);



void main(void)
{
	int iDan = 0;
	int iGob = 0;

	cout << "���ϴ� �ܼ� : ";
	cin >> iDan;
	cout << "���ϴ� ���� : ";
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



