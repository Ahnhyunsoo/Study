#pragma once
class Deque
{
private:
	int* pa;
	int Length;
	int data;
	
public:
	void PushFront();
	void PushBack();
	void PopFront();
	void PopBack();

	Deque();
	Deque(int a);
	~Deque();
};

