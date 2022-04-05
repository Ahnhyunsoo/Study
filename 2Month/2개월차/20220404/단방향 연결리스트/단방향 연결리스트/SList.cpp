//List.cpp
#include "stdafx.h"
#include "SList.h"


void SList::Insert(Node** head, int data, int position) // 객체포인터 헤더를 받음
{
	Node* node = new Node; // 객체를 동적할당하고 그 객체를 가르키는 포인터 node
	node->data = data; // 동적할당한 객체의 데이터 삽임

	if (position == 1 || *head == NULL) //삽입할 위치가 1이거나 첫 삽입일 때
	{
		node->next = *head;	// 새로생성한 객체가 가르키는 객체의 주소 = 기존에 있던 객체의주소
							// 만약 널일경우 데이터가1개뿐이니 널을 대입해줌 다음값이 없다

		*head = node;				// 0번지가 가르키는 주소를 할당한 객체의주소로 
		Size += 1;
	}
	else
	{
		Node* inserted_prev = *head;  // 삽입위치가 1도 아니고 데이터가 이미있을 때 1번지의 객체주소를 가르키는 객체포인터
		for (int i = 1; (inserted_prev->next != NULL) && (i < position - 1); i++)  // 1번지가 가르키는주소가 있고 삽입위치가 3보다 이상일 때
		{
			inserted_prev = inserted_prev->next; //1번지의 객체 = 2번지객체
												 /*1 1번지객체 = 2번지객체
												 2 2번지 객체 = 3번지객체
												 3 3번지객체 = 4번지객체
												 삽입 위치가 5일 때 헤더는 4번지객체*/
		}
		//객체를 새로 생성해서 그 객체를 5번객체로 만들어줌 prev = 4번지
		Node* inserted_next = inserted_prev->next;  //next 기존5번지
		inserted_prev->next = node; // 5번객체를 만들어둔 객체를 넣어줌 // 5번지에 새로만든걸 넣어줌
		node->next = inserted_next; //  5번객체가 가르키는 객체를 넣어줌  // 5번지가 가르키는거에 기존 5번지를 넣어줌
		Size += 1;
	}
}

void SList::Delete(Node** head, int position)
{
	if (Size >= position)
	{
		if (position == 1 && head != NULL)
		{
			Node* prev = *head;

			*head = prev->next;

			delete prev;
			prev = nullptr;
			Size -= 1;
		}
		else
		{
			Node* prev = *head; //1번지
			for (int i = 1; (prev->next != NULL && i < position - 1); ++i)
			{

				prev = prev->next;

			}
			Node* next = prev->next;
			prev->next = next->next;
			delete next;
			next = nullptr;
			Size -= 1;


		}
	}
	else
	{
		cout << "삭제 불가" << endl;
	}
}

void SList::PrintList(struct Node* head) {
	struct Node* current = head;
	while (current != NULL)
	{
		cout << current->data << " -> ";
		current = current->next;
	}
	cout << "NULL\n";
}

SList::SList()
	:Size(0)
{

}


SList::~SList()
{
}