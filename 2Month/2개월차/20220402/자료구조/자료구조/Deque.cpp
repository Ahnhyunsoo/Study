#include "stdafx.h"
#include "Deque.h"



void Deque::PushFront()
{
	int Input;
	cout << "숫자 입력 : ";
	cin >> Input;
	if (data < Length)
	{
		for (int i = 1; i < data; ++i) 
		{
			int size = data;
			pa[size] = pa[size - i]; 
			--size;
		}
		pa[0] = Input;
		++data;
	}
	
}

void Deque::PushBack()
{
	int Input;
	cout << "숫자 입력 : ";
	cin >> Input;
	if (data < Length)
	{
		pa[data] = Input;
		++data;
	}
	else
	{
		cout << "배열 꽉참 배열을 늘림" << endl;
		Length += 2;
		int* pb = new int[Length];

		memcpy(pb, pa, sizeof(int) * data);

		delete[] pa;
		pa = nullptr;

		pa = pb;
	}
}

void Deque::PopFront()
{
	for (int i = 0; i < data; ++i)
	{
		cout << pa[i] << endl;
	}
}

void Deque::PopBack()
{
	for (int i = data; i > 0; --i)
	{
		cout << pa[i-1] << endl;
	}
}

Deque::Deque()
{
}

Deque::Deque(int a)
	:Length(a),data(0)
{
	pa = new int[a];
}


Deque::~Deque()
{
}
