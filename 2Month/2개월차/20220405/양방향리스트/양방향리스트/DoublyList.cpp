#include "stdafx.h"
#include "DoublyList.h"

void DoublyList::Insert(Node** head, int data, int position)
{
	Node* node = new Node; // 노드생성
	node->data = data; // 노드 데이터 초기화
	if (position == 1 || *head == NULL) // 삽입위치가 1이거나 헤더가 널일 때 (첫삽입일 때)
	{	
		node->next = *head; // 1번지 기준이니 노드가 가르키는거는 기존의 노드 (기존의 노드를 밀어내고 삽입함)
		node->back = NULL; // 1번지니 back = NULL head = 자기 자신이기 때문
		if (*head != NULL) {
			(*head)->back = node;
		}
		*head = node; // 헤더에 노드를 삽입
		
		++size; // 원소 갯수 +1
	}
	else // 위치가 1도 아니고 첫 삽입도 아닐 때
	{
		Node* prev = *head; // 1번 객체 = prev
		Node* next;
		for (int i = 1; (prev->next != NULL) && (i < position - 1); ++i) // position = 2로 가정
		{ // 1번객체의 다음객체가 존재하면서 포지션 -1보다 작을 경우 ++i
			prev = prev->next; // 1번객체를 2번객체로 만듬 이 포문을 진행하다보면 prev = 포지션-1번지의 객체가됨
		}

		next = prev->next; //next = 현재위치번지의 객체를 대입
		if (next == NULL) // 만약 현재위치다음번지의 데이터가 없다면
		{
			prev->next = node; // 1번지다음데이터를 노드로
			node->back = prev; // 노드의 이전데이터를 1번지로
			node->next = NULL; // 노드의 다음 데이터를 널로 다음데이터가 없다는건 1개만 있기때문에 노드의 넥스트를 설정할 필요가없음
			++size; // 원소 갯수 +1
		}

		else//삽입위치 다음 데이터가 존재할 때
		{
			prev->next = node; //1번객체 next에 노드를 대입
			next->back = node; // 기존객체 이전위치에 노드를 대입
			node->back = prev; // 노드의 이전위치에 1번객체 삽입
			node->next = next; // 노드의 다음데이터에 기존객체 대입
			++size; // 원소 갯수 +1
		}
	}
}

void DoublyList::Print(struct Node* head)
{
	while (head != NULL)
	{
		cout << head->data << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
}

void DoublyList::Delete(Node** head, int position)
{	
	Node* prev = *head;
	Node* next;
	
	if (*head != NULL && position <= size)
	{
		for (int i = 1; (*head != NULL) && (i < position - 1); ++i)
		{
			prev = prev->next;
		}
		next = prev->next; // next = 현재객체
		if (next->next == NULL) //삭제할위치가 마지막 번지일 때
		{
			prev->next = NULL;
			delete next;
			next = nullptr;
		}
		else //삭제할위치 앞뒤 데이터가 있을 때
		{
			prev->next = next->next;
			next->next->back = prev;
			delete next;
			next = nullptr;
		}
		

		//삭제할 이전 번지
		


	}

	else if (position > size)
	{
		cout << "리스트의 크기를 초과했습니다." << endl;
	}

	else
	{
		cout << "삭제할 데이터가 없습니다" << endl;
	}
}

DoublyList::DoublyList()
	:size(0)
{
}


DoublyList::~DoublyList()
{
}

