#pragma once
#include "stdafx.h"
#include "Machine.h"

class CStudent
{
	string m_sName;
	int m_iKorea;
	int m_iEnglish;
	int m_iMath;
	int m_iSum;
	float m_fAvg;
	
public:
	void InputStudent();
	void PrintAll();
	int Search(string Search);
	
	CStudent();
	~CStudent();

};

