#include "stdafx.h"
#include "Test.h"

int	CTest::m_iTest = 400;

CTest::CTest()
{

}
CTest::~CTest()
{
}
void CTest::Render(void)
{
	static int		iTemp = 10;	// ���� ����(data����)

	cout << (iTemp++) << endl;
}

void CTest::Print()
{
	//static int iTemp = 10;	// ���� ���� ��� ����
								// static �Լ� ���� ����� static ���� ��� ����
	//cout << iTemp << endl;

	//cout << m_iTest << endl;		// ����� ����� static ���� ��� ����

	// cout << m_iTemp << endl;		// ���� Ŭ���� ���� �Ϲ� ��� ������ ��� �Ұ���
}
