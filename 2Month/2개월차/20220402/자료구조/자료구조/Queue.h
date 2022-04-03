#pragma once
class Queue
{
private:
	int* pa;
	int Length;
	int size;
public:
	void Push();
	void Pop();

	Queue();
	Queue(int a);
	~Queue();
};

