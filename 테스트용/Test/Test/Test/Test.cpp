// Test.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class Test
{
public:
	Test() : m_pArray(nullptr), m_iSize(10) {}
	Test(int iSize) : m_pArray(new int[iSize]), m_iSize(iSize) {}

	Test(Test& r)
	{
		cout << "복사생성자 호출" << endl;
		m_pArray = new int[r.m_iSize];
		memcpy(m_pArray, r.m_pArray, sizeof(m_pArray));
		m_iSize = r.m_iSize;
	}
	 
	
	
	Test(Test&& r)
	{
		cout << "이동생성자 호출" << endl;
		m_pArray = r.m_pArray;
		m_iSize = r.m_iSize;
		r.m_pArray = nullptr;
	}

	~Test() 
	{
		if (m_pArray)
		{
			delete[]m_pArray;
			m_pArray = nullptr;
		}
	}
	void Set(int a) { m_pArray = new int[a]; }
	void Render() { cout << m_pArray << endl; }
private:
	int* m_pArray;
	int m_iSize;
};

void main(void)
{
	Test t;
	t.Set(5);
	
	Test a(std::move(t));
	t.Render();
	a.Render();
}

