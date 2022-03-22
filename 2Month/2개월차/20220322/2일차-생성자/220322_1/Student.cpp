#include "stdafx.h"
#include "Student.h"

CStudent::CStudent()
{
	//cout << "생성자 호출" << endl;

	m_pInfo = nullptr;
	m_iSize = 0;
}

CStudent::CStudent(int _iSize)
{
	m_pInfo = nullptr;
	m_iSize = _iSize;
}

void CStudent::Initialize(void)
{
	/*m_pInfo = nullptr;
	m_iSize = 0;*/
}

CStudent::~CStudent()
{
	//cout << "소멸자 호출" << endl;
	Release();
}

void CStudent::Release(void)
{
	SAFE_DELETE_ARRAY(m_pInfo);
}

void CStudent::Input_Data(void)
{
	int		iInput = 0;

	cout << "추가하고자 하는 학생 수 : ";
	cin >> iInput;

	if (nullptr == m_pInfo)		// 최초로 입력받을 타임
		m_pInfo = new INFO[iInput];

	else						// 추가 입력받을 타임
	{
		INFO*	pGrade = new INFO[iInput + m_iSize];

		memcpy(pGrade, m_pInfo, sizeof(INFO) * m_iSize);

		Release();

		m_pInfo = pGrade;		// 다른 멤버 함수 안에서도 학생들의 정보를 이용하려면 멤버 변수에 값을 채워줘야 한다.
	}

	for (int i = m_iSize; i < iInput + m_iSize; ++i)
	{
		cout << "이름 입력 : ";
		cin >> m_pInfo[i].szName;

		cout << "국어 입력 : ";
		cin >> m_pInfo[i].iKor;

		cout << "영어 입력 : ";
		cin >> m_pInfo[i].iEng;

		cout << "수학 입력 : ";
		cin >> m_pInfo[i].iMath;

		m_pInfo[i].iTotal = m_pInfo[i].iKor + m_pInfo[i].iEng + m_pInfo[i].iMath;
		m_pInfo[i].fAver = m_pInfo[i].iTotal / 3.f;
		cout << "=========================" << endl;
	}

	m_iSize += iInput;
}

void CStudent::Output_Data(void)
{
	for (int i = 0; i < m_iSize; ++i)
	{
		cout << "이름 : " << m_pInfo[i].szName << endl;
		cout << "국어 : " << m_pInfo[i].iKor << endl;
		cout << "영어 : " << m_pInfo[i].iEng << endl;
		cout << "수학 : " << m_pInfo[i].iMath << endl;
		cout << "총점 : " << m_pInfo[i].iTotal << endl;
		cout << "평균 : " << m_pInfo[i].fAver << endl;
		cout << "============================" << endl;
	}
}
