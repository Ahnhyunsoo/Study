#pragma once

struct Node
{
	int data;
	Node* next;
	Node* back;
};

class DList
{
private:
	int size;
public:
	void PushFront(Node** head, int data, int position);
	void PushBack(Node** head, int data, int position);
	DList();
	~DList();
};

