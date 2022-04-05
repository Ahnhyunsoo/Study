// 양방향리스트.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "DoublyList.h"

Node* head = NULL;

int main()
{
	DoublyList d;
	d.Insert(&head, 1, 2);
	d.Insert(&head, 2, 1);
	d.Insert(&head, 5, 2);
	d.Insert(&head, 11, 2);
	d.Insert(&head, 7, 2);
	d.Delete(&head, 3);

	d.Print(head);
    return 0;
}

