#include "stdafx.h"
#include "Student.h"


void Student::SetStudent(string _name, int _kor, int _en, int _math)
{
	m_sName = _name;
	m_iKor = _kor;
	m_iEn = _en;
	m_iMath = _math;
	m_iSum = _kor + _en + _math;
	m_fAvg = (_kor + _en + _math) / 3.f;
	cout << "등록완료" << endl;
	system("pause");
}

void Student::PrintStudent()
{
	cout << "이름 : " << m_sName << endl;
	cout << "국어점수 : " << m_iKor << endl;
	cout << "영어점수 : " << m_iEn << endl;
	cout << "수학점수 : " << m_iMath << endl;
	cout << "총점 : " << m_iSum << endl;
	cout << "평균 : " << m_fAvg << endl;
}

Student::Student()
{
}


Student::~Student()
{
}
