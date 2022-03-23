#pragma once
#include "stdafx.h"
#include "Student.h"
#include "Define.h"

class CStudent
{
private:
	PInfo sp = nullptr;
	int size = 0;

		
public:
	void Input();
	void Output();
	void Search(string name);
	CStudent();
	~CStudent();


};


