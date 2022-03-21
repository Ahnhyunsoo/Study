#include "stdafx.h"
#include "Student.h"

using namespace std;



void CStudent::InputStudent()
{
	cout << "학생의 이름을 입력하세요 : ";
	cin >> m_sName;
	cout << m_sName << "학생의 국어 점수 : ";
	cin >> m_iKorea;
	cout << m_sName << "학생의 수학 점수 : ";
	cin >> m_iMath;
	cout << m_sName << "학생의 영어 점수 : ";
	cin >> m_iEnglish;

	m_iSum = m_iKorea + m_iMath + m_iEnglish;
	m_fAvg = m_iKorea + m_iMath + m_iEnglish / 3.f;

}

void CStudent::Length()
{
	m_iLength += 1;
}