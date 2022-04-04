//Main.cpp
#include "stdafx.h"
#include "List.h"


Node* head = NULL;
int main()
{
	List l;
	l.InsertInLinkedList(&head, 4, 1);
	l.InsertInLinkedList(&head, 17, 1);
	l.InsertInLinkedList(&head, 1, 1);
	
	l.PrintList(head);
}