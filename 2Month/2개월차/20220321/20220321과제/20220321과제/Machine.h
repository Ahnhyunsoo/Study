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

	//1.등록 2.추가등록 3.전체출력 4.검색출력 5.종료
		//등록을 할시 처음엔 무조건3명 기존의 데이터는 삭제
};