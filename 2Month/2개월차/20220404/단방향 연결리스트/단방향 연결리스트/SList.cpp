//List.cpp
#include "stdafx.h"
#include "SList.h"


void SList::Insert(Node** head, int data, int position) // ��ü������ ����� ����
{
	Node* node = new Node; // ��ü�� �����Ҵ��ϰ� �� ��ü�� ����Ű�� ������ node
	node->data = data; // �����Ҵ��� ��ü�� ������ ����

	if (position == 1 || *head == NULL) //������ ��ġ�� 1�̰ų� ù ������ ��
	{
		node->next = *head;	// ���λ����� ��ü�� ����Ű�� ��ü�� �ּ� = ������ �ִ� ��ü���ּ�
							// ���� ���ϰ�� �����Ͱ�1�����̴� ���� �������� �������� ����

		*head = node;				// 0������ ����Ű�� �ּҸ� �Ҵ��� ��ü���ּҷ� 
		Size += 1;
	}
	else
	{
		Node* inserted_prev = *head;  // ������ġ�� 1�� �ƴϰ� �����Ͱ� �̹����� �� 1������ ��ü�ּҸ� ����Ű�� ��ü������
		for (int i = 1; (inserted_prev->next != NULL) && (i < position - 1); i++)  // 1������ ����Ű���ּҰ� �ְ� ������ġ�� 3���� �̻��� ��
		{
			inserted_prev = inserted_prev->next; //1������ ��ü = 2������ü
												 /*1 1������ü = 2������ü
												 2 2���� ��ü = 3������ü
												 3 3������ü = 4������ü
												 ���� ��ġ�� 5�� �� ����� 4������ü*/
		}
		//��ü�� ���� �����ؼ� �� ��ü�� 5����ü�� ������� prev = 4����
		Node* inserted_next = inserted_prev->next;  //next ����5����
		inserted_prev->next = node; // 5����ü�� ������ ��ü�� �־��� // 5������ ���θ���� �־���
		node->next = inserted_next; //  5����ü�� ����Ű�� ��ü�� �־���  // 5������ ����Ű�°ſ� ���� 5������ �־���
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
			Node* prev = *head; //1����
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
		cout << "���� �Ұ�" << endl;
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