#pragma once
class Stack
{
private:
	int Length;
	int* pa;
	int size;
	
public:
	
	void Push();
	void Pop();
	Stack();
	Stack(int a);
	~Stack();
};

