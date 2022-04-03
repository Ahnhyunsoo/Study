#include "stdafx.h"
#include "Queue.h"



void Queue::Push()
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
		cout << "배열크기 꽉참 배열 크기를 늘림" << endl;
		Length += 3;
		int* pb = new int[Length];

		memcpy(pb, pa, sizeof(int)*size);

		delete[] pa;
		pa = nullptr;

		pa = pb;

		pa[size] = Input;
		++ size;

	}

}

void Queue::Pop()
{
	for (int i = 0; i < Length; ++i)
	{
		cout << pa[i] << endl;
	}
}

Queue::Queue()
{
}

Queue::Queue(int a)
	: Length(a), size(0)
{
	pa = new int[a];
	
}


Queue::~Queue()
{
}
