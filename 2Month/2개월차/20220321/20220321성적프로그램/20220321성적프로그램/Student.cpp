#include "stdafx.h"
#include "Student.h"

void CStudent::InputStudent()
{
	cout << "학생 이름 : ";
	cin >> m_sName;
	cout << m_sName << "의 국어 점수 : ";
	cin >> m_iKorea;
	cout << m_sName << "의 영어 점수 : ";
	cin >> m_iMath;
	cout << m_sName << "의 수학 점수 : ";
	cin >> m_iEnglish;	

}

void CStudent::PrintAll()
{
	cout << m_sName << "의 국어점수 : " << m_iKorea << endl;
	cout << m_sName << "의 영어점수 : " << m_iEnglish << endl;
	cout << m_sName << "의 수학점수 : " << m_iMath << endl;
	cout << "==================================" << endl;
}

int CStudent::Search(string Search)
{
	
	if (Search == m_sName)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

