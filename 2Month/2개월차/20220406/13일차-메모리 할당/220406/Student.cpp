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
	cout << "이름을 입력하세요 : ";
	cin >> m_tInfo.strName;

	cout << "국어 점수를 입력하세요 : ";
	cin >> m_tInfo.iKor;

	cout << "영어 점수를 입력하세요 : ";
	cin >> m_tInfo.iEng;

	cout << "수학 점수를 입력하세요 : ";
	cin >> m_tInfo.iMath;

	m_tInfo.iTotal = m_tInfo.iKor + m_tInfo.iEng + m_tInfo.iMath;
	m_tInfo.fAver = (float)m_tInfo.iTotal / 3.f;
}

void CStudent::Output_Data(void)
{
	cout << "====================================" << endl;
	cout << "이름 : " << m_tInfo.strName << endl;
	cout << "국어 : " << m_tInfo.iKor << endl;
	cout << "영어 : " << m_tInfo.iEng << endl;
	cout << "수학 : " << m_tInfo.iMath << endl;
	cout << "총점 : " << m_tInfo.iTotal << endl;
	cout << "평균 : " << m_tInfo.fAver << endl;
}