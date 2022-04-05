#pragma once
#include "Student.h"

class School
{
private:
	vector<Student> vecStu;
	vector<Student>::iterator iter;
public:
	void Input();
	void PrintAll();
	void Search();
	void Delete();
	void Exe();
	School();
	~School();
};

