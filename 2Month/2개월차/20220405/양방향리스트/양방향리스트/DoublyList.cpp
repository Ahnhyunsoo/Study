#include "stdafx.h"
#include "DoublyList.h"

void DoublyList::Insert(Node** head, int data, int position)
{
	Node* node = new Node; // ������
	node->data = data; // ��� ������ �ʱ�ȭ
	if (position == 1 || *head == NULL) // ������ġ�� 1�̰ų� ����� ���� �� (ù������ ��)
	{	
		node->next = *head; // 1���� �����̴� ��尡 ����Ű�°Ŵ� ������ ��� (������ ��带 �о�� ������)
		node->back = NULL; // 1������ back = NULL head = �ڱ� �ڽ��̱� ����
		if (*head != NULL) {
			(*head)->back = node;
		}
		*head = node; // ����� ��带 ����
		
		++size; // ���� ���� +1
	}
	else // ��ġ�� 1�� �ƴϰ� ù ���Ե� �ƴ� ��
	{
		Node* prev = *head; // 1�� ��ü = prev
		Node* next;
		for (int i = 1; (prev->next != NULL) && (i < position - 1); ++i) // position = 2�� ����
		{ // 1����ü�� ������ü�� �����ϸ鼭 ������ -1���� ���� ��� ++i
			prev = prev->next; // 1����ü�� 2����ü�� ���� �� ������ �����ϴٺ��� prev = ������-1������ ��ü����
		}

		next = prev->next; //next = ������ġ������ ��ü�� ����
		if (next == NULL) // ���� ������ġ���������� �����Ͱ� ���ٸ�
		{
			prev->next = node; // 1�������������͸� ����
			node->back = prev; // ����� ���������͸� 1������
			node->next = NULL; // ����� ���� �����͸� �η� ���������Ͱ� ���ٴ°� 1���� �ֱ⶧���� ����� �ؽ�Ʈ�� ������ �ʿ䰡����
			++size; // ���� ���� +1
		}

		else//������ġ ���� �����Ͱ� ������ ��
		{
			prev->next = node; //1����ü next�� ��带 ����
			next->back = node; // ������ü ������ġ�� ��带 ����
			node->back = prev; // ����� ������ġ�� 1����ü ����
			node->next = next; // ����� ���������Ϳ� ������ü ����
			++size; // ���� ���� +1
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
		next = prev->next; // next = ���簴ü
		if (next->next == NULL) //��������ġ�� ������ ������ ��
		{
			prev->next = NULL;
			delete next;
			next = nullptr;
		}
		else //��������ġ �յ� �����Ͱ� ���� ��
		{
			prev->next = next->next;
			next->next->back = prev;
			delete next;
			next = nullptr;
		}
		

		//������ ���� ����
		


	}

	else if (position > size)
	{
		cout << "����Ʈ�� ũ�⸦ �ʰ��߽��ϴ�." << endl;
	}

	else
	{
		cout << "������ �����Ͱ� �����ϴ�" << endl;
	}
}

DoublyList::DoublyList()
	:size(0)
{
}


DoublyList::~DoublyList()
{
}

