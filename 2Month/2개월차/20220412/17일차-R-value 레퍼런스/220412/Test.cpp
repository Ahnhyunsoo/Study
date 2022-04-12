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
	static int		iTemp = 10;	// 정적 변수(data영역)

	cout << (iTemp++) << endl;
}

void CTest::Print()
{
	//static int iTemp = 10;	// 지역 변수 사용 가능
								// static 함수 내에 선언된 static 변수 사용 가능
	//cout << iTemp << endl;

	//cout << m_iTest << endl;		// 멤버로 선언된 static 변수 사용 가능

	// cout << m_iTemp << endl;		// 동일 클래스 내의 일반 멤버 변수는 사용 불가능
}
