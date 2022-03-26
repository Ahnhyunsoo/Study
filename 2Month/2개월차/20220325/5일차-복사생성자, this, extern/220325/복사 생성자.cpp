// 220325.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


#pragma region 복사 생성자

/*
class CObj
{
private:
	int		m_iA;

public:
	void	Render() { cout << m_iA << endl; }
	void	Print(CObj Test)		// 2. 함수의 매개 변수가 객체 타입인 경우 복사 생성자를 호출
	{
		Test.Render();
	}
	CObj	Get_Obj(void)			// 3. 함수의 반환 타입이 객체 타입인 경우 복사 생성자를 호출
	{
		CObj		Sour(1000);
		return Sour;
	}

public:
	CObj(int _iA) : m_iA(_iA)
	{
		cout << "매개 변수가 있는 생성자 호출" << endl;
	}

	CObj(CObj& rObj)		// 원본에 해당하는 데이터를 사본에 데이터로 복사를 수행
	{
		m_iA = rObj.m_iA;

		cout << "복사 생성자 호출" << endl;
	}

};

// 복사 생성자를 사용해야 하는 이유 


int main()
{


	
	CObj		Obj(50);

	//CObj		Temp(Obj);	// default 복사 생성자 호출
	// 1. 먼저 만든 원본 객체를 사본 객체의 생성자 매개변수로 넣어서 객체를 생성하는 경우 복사 생성자 호출

	//Temp.Render();

	//CObj		Temp(10);
	//Temp.Print(Obj);

	Obj.Get_Obj().Render();


	return 0;
}*/




#pragma endregion 복사 생성자

/*
class CName
{
private:
	char*		m_pName;

public:
	void		Print(CName Name)	{	printf("%s", Name.m_pName);	}

public:
	CName(char* pName)
	{
		int iLength = strlen(pName);

		m_pName = new char[iLength + 1];
		strcpy_s(m_pName, iLength + 1, pName);
	}

	CName(CName& rName)			// 얕은 복사(shallow copy) 생성자
	{
		//m_pName = rName.m_pName;

		int iLength = strlen(rName.m_pName);	// 깊은 복사(deep copy) 생성자

		m_pName = new char[iLength + 1];
		strcpy_s(m_pName, iLength + 1, rName.m_pName);
	}

	~CName()
	{
		delete[]m_pName;
	}	
};

void main(void)
{
	CName		Name("neo-peple");
	CName		Test("neo-peple");

	Name.Print(Test);		// 복사 생성자

}
*/


class Test
{
private:
	int m_a;

public:
	Test()
	{

	}

	Test(int _a) : m_a(_a)
	{
		cout << "기본 생성자 호출" << endl;
	}

	Test(Test& t)
	{
		m_a = t.m_a;
		cout << "복사생성자 호출" << endl;
	}

	void Print() { cout << m_a << endl;	}
};




void main(void)
{
	Test t;
	t.Print();
}


