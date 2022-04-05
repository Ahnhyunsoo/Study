//Main.cpp
#include "stdafx.h"
#include "SList.h"


Node* head = NULL;
int main()
{
	SList l;
	l.Insert(&head, 4, 1);
	l.Insert(&head, 15, 2);
	l.Insert(&head, 1, 2);
	l.Insert(&head, 5, 2);
	l.Insert(&head, 99, 2);
	//l.Delete(&head, 1);
	
	l.PrintList(head);
	
	


	return 0;
}