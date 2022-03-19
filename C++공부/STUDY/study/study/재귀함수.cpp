#include <iostream>

using namespace std;

void Func(int a);

void main(void)
{
	//재귀함수를 이용해 10진수를 2진수로 바꿔서 출력하기

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