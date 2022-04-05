#pragma once

struct Node
{
	Node* next;
	Node* back;
	int data;
};

class DoublyList
{
private:
	int size;
public:
	void Insert(Node** head, int data, int position);
	void Print(struct Node* head);
	void Delete(Node** head, int position);
	DoublyList();
	~DoublyList();
};

