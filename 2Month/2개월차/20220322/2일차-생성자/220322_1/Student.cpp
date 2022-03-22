#include "stdafx.h"
#include "Student.h"

CStudent::CStudent()
{
	//cout << "������ ȣ��" << endl;

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
	//cout << "�Ҹ��� ȣ��" << endl;
	Release();
}

void CStudent::Release(void)
{
	SAFE_DELETE_ARRAY(m_pInfo);
}

void CStudent::Input_Data(void)
{
	int		iInput = 0;

	cout << "�߰��ϰ��� �ϴ� �л� �� : ";
	cin >> iInput;

	if (nullptr == m_pInfo)		// ���ʷ� �Է¹��� Ÿ��
		m_pInfo = new INFO[iInput];

	else						// �߰� �Է¹��� Ÿ��
	{
		INFO*	pGrade = new INFO[iInput + m_iSize];

		memcpy(pGrade, m_pInfo, sizeof(INFO) * m_iSize);

		Release();

		m_pInfo = pGrade;		// �ٸ� ��� �Լ� �ȿ����� �л����� ������ �̿��Ϸ��� ��� ������ ���� ä����� �Ѵ�.
	}

	for (int i = m_iSize; i < iInput + m_iSize; ++i)
	{
		cout << "�̸� �Է� : ";
		cin >> m_pInfo[i].szName;

		cout << "���� �Է� : ";
		cin >> m_pInfo[i].iKor;

		cout << "���� �Է� : ";
		cin >> m_pInfo[i].iEng;

		cout << "���� �Է� : ";
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
		cout << "�̸� : " << m_pInfo[i].szName << endl;
		cout << "���� : " << m_pInfo[i].iKor << endl;
		cout << "���� : " << m_pInfo[i].iEng << endl;
		cout << "���� : " << m_pInfo[i].iMath << endl;
		cout << "���� : " << m_pInfo[i].iTotal << endl;
		cout << "��� : " << m_pInfo[i].fAver << endl;
		cout << "============================" << endl;
	}
}
