#include "stdafx.h"
#include "Student.h"

CStudent::CStudent()
{
}


CStudent::~CStudent()
{
}

void CStudent::Input_Data(void)
{
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> m_tInfo.strName;

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> m_tInfo.iKor;

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> m_tInfo.iEng;

	cout << "���� ������ �Է��ϼ��� : ";
	cin >> m_tInfo.iMath;

	m_tInfo.iTotal = m_tInfo.iKor + m_tInfo.iEng + m_tInfo.iMath;
	m_tInfo.fAver = (float)m_tInfo.iTotal / 3.f;
}

void CStudent::Output_Data(void)
{
	cout << "====================================" << endl;
	cout << "�̸� : " << m_tInfo.strName << endl;
	cout << "���� : " << m_tInfo.iKor << endl;
	cout << "���� : " << m_tInfo.iEng << endl;
	cout << "���� : " << m_tInfo.iMath << endl;
	cout << "���� : " << m_tInfo.iTotal << endl;
	cout << "��� : " << m_tInfo.fAver << endl;
}