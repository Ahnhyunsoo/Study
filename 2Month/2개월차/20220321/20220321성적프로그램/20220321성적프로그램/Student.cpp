#include "stdafx.h"
#include "Student.h"

void CStudent::InputStudent()
{
	cout << "�л� �̸� : ";
	cin >> m_sName;
	cout << m_sName << "�� ���� ���� : ";
	cin >> m_iKorea;
	cout << m_sName << "�� ���� ���� : ";
	cin >> m_iMath;
	cout << m_sName << "�� ���� ���� : ";
	cin >> m_iEnglish;	

}

void CStudent::PrintAll()
{
	cout << m_sName << "�� �������� : " << m_iKorea << endl;
	cout << m_sName << "�� �������� : " << m_iEnglish << endl;
	cout << m_sName << "�� �������� : " << m_iMath << endl;
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

