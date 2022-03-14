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
	cout << "1. 콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 종료 " << endl;
}

void Input(int* p)
{
	cout << "소지금을 입력하세요 : ";
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

