// �ڷᱸ��.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

int main()
{
	/*Stack c(3);
	while (true)
	{
		system("pause");
		c.Push();
		c.Pop();
	}*/

	/*Queue q(3);
	while (true)
	{
		system("pause");
		q.Push();
		q.Pop();
	}*/

	Deque d(3);
	while (true)
	{
		system("cls");
		d.PushFront();
		d.PopFront();
		system("pause");
	}



	
	
	

		
	
    return 0;
}

