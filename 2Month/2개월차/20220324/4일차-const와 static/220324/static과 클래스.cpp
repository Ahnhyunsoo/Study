#include "stdafx.h"

#pragma region 멤버로써 존재하는 static변수

/*
static int		g_iA = 10;		// 전역변수(외부에서 접근 가능한 정적변수)

class CObj
{
public:
	static int		m_iA; // = 10; 선언과 동시에 초기화 실패

private:
	int				m_iB;

public:
	void	Render()
	{
		//static int		iA = 10; // 정적변수(내부에서 접근 가능한 정적변수)
		//cout << (++iA) << endl;

		m_iA++;
		cout << (m_iA) << endl;
	}
	CObj()// : m_iA(10) 이니셜라이저를 이용한 초기화 실패
	{
		// m_iA = 10;	대입을 통한 초기화 실패
	}
};

// Obj.cpp

int		CObj::m_iA = 100;		// 멤버로 존재하는 정적변수 초기화 문법




void main(void)
{
	// 같은 객체 타입끼리는 STATIC 멤버 변수의 메모리 공간을 공유하여 사용한다.
	// STATIC 멤버 변수는 각 객체의 소유가 아니라는 증거


	CObj	Obj;
	Obj.Render();

	//Obj.m_iA = 200;

	CObj::m_iA = 200;		// 객체 생성이 필요 없이도 멤버로 접근이 가능하다.


							/ *CObj	Temp;
							Temp.Render();

							CObj	Dest;
							Dest.Render();* /

}*/

#pragma endregion 멤버로써 존재하는 static변수

#pragma region 멤버로써 존재하는 static 함수

int	g_iNumber = 10;

class CObj
{
private:
	int			m_iNormal = 20;
	static int  m_iStatic;

public:
	static void Render(void)		// static이 붙은 함수는 클래스 내의 일반 멤버 변수를 사용할 수 없다.
	{								// 같은 클래스 내에 있더라도 일반 멤버 함수 또한 static 함수 내에서 호출 할 수 없다.
		// ++m_iNormal;
		// Draw();
		
		//cout << (++m_iStatic) << endl;	// static 변수는 사용가능하다.
		
		//int	iTemp = 10;				// 일반적인 함수 내 지역변수를 사용하는 것은 문제가 되지 않는다.
		//cout << (++iTemp) << endl;

		// cout << (++g_iNumber) << endl;	// 전역변수의 경우도 사용이 가능하다.
	}
	void		Draw(void)
	{
		//cout << (++m_iStatic) << endl;
		cout << m_iNormal << endl;
	}
};

int CObj::m_iStatic = 10;

void main(void)
{
	CObj	Obj;

	//Obj.Render();
	
	CObj::Render();

	Obj.Draw();

}

/*
namespace MyStd
{
	static void Print();
}*/

// 1. static 멤버 함수는 static 멤버 변수와 동일한 기능을 가진다.
// 2. static으로 선언된 변수와 함수는 해당 클래스로 생성된 모든 객체가 공유한다.
// 3. 각 객체의 소유가 아니다
// 4. stiatic 멤버 함수 내부에서 일반적인 멤버 변수, 함수를 접근할 수 없다.
// 5. namespace를 통해 객체를 생성하지 않고 호출할 수 있다.
// 6. 프로그램 시작 시(컴파일 시점) 메모리가 할당되고 프로그램 종료 시 메모리가 해제된다.
// 7. 할당되는 메모리 공간은 data 영역에 해당한다.

#pragma endregion 멤버로써 존재하는 static 함수

