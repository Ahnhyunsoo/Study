#include "stdafx.h"
#include "Student.h"

using namespace std;



void CStudent::InputStudent()
{
	cout << "�л��� �̸��� �Է��ϼ��� : ";
	cin >> m_sName;
	cout << m_sName << "�л��� ���� ���� : ";
	cin >> m_iKorea;
	cout << m_sName << "�л��� ���� ���� : ";
	cin >> m_iMath;
	cout << m_sName << "�л��� ���� ���� : ";
	cin >> m_iEnglish;

	m_iSum = m_iKorea + m_iMath + m_iEnglish;
	m_fAvg = m_iKorea + m_iMath + m_iEnglish / 3.f;

}

void CStudent::Length()
{
	m_iLength += 1;
}