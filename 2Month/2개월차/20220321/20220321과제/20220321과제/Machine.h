#pragma once
#include "stdafx.h"
#include "Student.h"

class CMachine
{	
	CStudent* sp = NULL;
	int Length = 0;
public:
	void exe();
	int Menu();
	CStudent* Create();
	void Add(CStudent*);
	void PrintAll(CStudent*);
	void PrintSearch(CStudent*);
	void InputStudent(CStudent*);

	//1.��� 2.�߰���� 3.��ü��� 4.�˻���� 5.����
		//����� �ҽ� ó���� ������3�� ������ �����ʹ� ����
};