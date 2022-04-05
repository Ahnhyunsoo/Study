// List.h
#pragma once

struct Node
{
	Node* next;
	int data;

public:

};

class SList
{
private:
	Node* node;
	int Size;

public:
	void Insert(Node** head, int data, int position);
	void PrintList(struct Node* head);
	void Delete(Node** head, int position);
	SList();
	~SList();
};


