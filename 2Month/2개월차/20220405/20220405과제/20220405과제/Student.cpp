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
	cout << "��ϿϷ�" << endl;
	system("pause");
}

void Student::PrintStudent()
{
	cout << "�̸� : " << m_sName << endl;
	cout << "�������� : " << m_iKor << endl;
	cout << "�������� : " << m_iEn << endl;
	cout << "�������� : " << m_iMath << endl;
	cout << "���� : " << m_iSum << endl;
	cout << "��� : " << m_fAvg << endl;
}

Student::Student()
{
}


Student::~Student()
{
}
