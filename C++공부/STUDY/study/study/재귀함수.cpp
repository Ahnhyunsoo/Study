#include <iostream>

using namespace std;

void Func(int a);

void main(void)
{
	//����Լ��� �̿��� 10������ 2������ �ٲ㼭 ����ϱ�

	Func(255);


}

void Func(int a)
{
	if (a > 1)
	{
		Func(a / 2);
	}

	cout << a % 2;

	
	return;
}