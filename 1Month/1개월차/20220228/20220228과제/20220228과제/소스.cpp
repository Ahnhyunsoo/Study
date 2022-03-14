#include <iostream>

using namespace std;

void Swap(int* a, int* b);

void main(void)
{
	int a = 10, b = 20;
	cout << a << "\t" << b << endl;
	Swap(&a, &b);
	cout << a << "\t" << b	<< endl;


}

void Swap(int* a, int* b)
{
	int Temp = *a;
	if (*a != *b)
	{
		*a = *b;
		*b = Temp;
	}
		
} 

//자판기를 포인터를 이용해서 짤수있게 바꾸기