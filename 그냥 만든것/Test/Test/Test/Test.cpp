// Test.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"




class CObj
{
private:
	char		m_pStr[256];

public:
	CObj()
	{

	}

	CObj(int a)
	{
		cout << a << " 임시생성자" << endl;
	}

	/*CObj(char* pStr)
	{
		strcpy_s(m_pStr, sizeof(m_pStr), pStr);
		cout << m_pStr << "생성자" << endl;
	}*/
	~CObj()
	{
		cout << "소멸자" << endl;
	}
};


void main(void)
{
	//int iA = 3 + 4;

	//CObj		Obj("일반");
	//cout << "===============임시 객체 생성================" << endl;

	//CObj("임시 객체");		// 임시 객체는 해당 코드라인을 벗어나는 즉시 소멸된다.

	//cout << "===============임시 객체 소멸================" << endl;

	CObj(1);

}

