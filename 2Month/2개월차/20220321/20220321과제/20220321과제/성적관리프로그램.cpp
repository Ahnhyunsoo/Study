// 20220321����.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
//����1 �������α׷�
//����2 �ؽ�Ʈrpg

#include "stdafx.h"
#include "Machine.h"

int* dd();

int main()
{
	
	int* p = dd();

	
		cout << sizeof(*p) << endl;
	
	//�Ȱ��� ��Ʈ������ �����ôµ� ��� ����ߵ� Ŭ������ �ȵ� ���� ŷ�޳� ...... ������ Ʋ���� ���µ� Ʋ�ȳ�?
		//���Ŷ� ���� �������� �߸��Ȱǰ� ����?

	//CMachine Machine;
	//Machine.exe();
	return 0;
}


int* dd()
{
	int iCount = 0;
	int* p = new int[5];
	int* a = p;
	for (int i = 0; i < 5; ++i)
	{
		p[i] = iCount;
		iCount++;
	}
	return a;
}

