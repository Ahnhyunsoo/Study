#include <iostream>

using namespace std;

void menu();
void Input(int* p);
int Number();
int Check(int* p, int n);

void main(void)
{
	int iMoney = 0;
	Input(&iMoney);

	while (true)
	{
		menu();
		Number();

	}
}

void menu()
{
	cout << "1. �ݶ�(100��) 2. ���̴�(200��) 3. ȯŸ(300��) 4. ���� " << endl;
}

void Input(int* p)
{
	cout << "�������� �Է��ϼ��� : ";
	cin >> *p;
}

int Number()
{
	int a = 0;
	cin >> a;
	return a;
}

int Check(int* p, int n)
{
	if (n == 1)
	{

	}
	else if (n == 2)
	{

	}
	else if (n == 3)
	{

	}
	else if (n == 4)
	{

	}
	
	else
	{

	}
}

