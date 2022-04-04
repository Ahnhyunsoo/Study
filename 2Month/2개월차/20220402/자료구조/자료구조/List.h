// List.h
#pragma once
class List
{
private:
	Node* node;
public:
	void InsertInLinkedList(Node**head, int data, int position);
	void PrintList(struct Node* head);
	
	List();
	~List();
};


struct Node
{
	Node* next;
	int data;

public:

};