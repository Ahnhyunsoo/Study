//List.cpp
#include "stdafx.h"
#include "List.h"


void List::InsertInLinkedList(Node**head, int data, int position) {
	Node* inserted = new Node;
	inserted->data = data;

	if (position == 1 || *head == NULL) {
		inserted->next = *head;
		*head = inserted;
	}
	else {
		Node* inserted_prev = *head;
		for (int i = 1; (inserted_prev->next != NULL) && (i < position - 1); i++) {
			inserted_prev = inserted_prev->next;
		}

		Node* inserted_next = inserted_prev->next;
		inserted_prev->next = inserted;
		inserted->next = inserted_next;
	}
}

void List::PrintList(struct Node* head) {
	struct Node* current = head;
	while (current != NULL)
	{
		cout << current->data << " -> ";
		current = current->next;
	}
	cout << "NULL\n";
}

List::List()
	
{

}


List::~List()
{
}