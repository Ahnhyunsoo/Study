#include "stdafx.h"
#include "Stack.h"


void Stack::Push()
{
	system("cls");
	int Input;
	cout << "숫자 입력 : ";
	cin >> Input;

	if (size < Length)
	{
		pa[size] = Input;
		++size;
	}
	else
	{
		cout << "배열크기 꽉참 배열크기 증가" << endl;
		Length += 2;
		int* pb = new int[Length];
		
		memcpy(pb, pa, sizeof(int) * Length);

		delete[] pa;
		pa = nullptr;

		pa = pb;
	}

	
	
	
	
	
	
}

void Stack::Pop()
{
	
	for (int i = Length; i > 0; --i)
	{
		cout << pa[i-1] << endl;		
	}

}

Stack::Stack()
{

}

Stack::Stack(int a)
	: Length(a), size(0)
{
	pa = new int[a];

}


Stack::~Stack()
{
}
