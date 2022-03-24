// 220324.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#pragma region 멤버 상수를 초기화하는 방법

/*
class CObj
{
private:
	const int			m_iA;
	int					m_iB;

public:
	void		Render(void) { cout << m_iA << endl; }

public:
	CObj();
	CObj(int _iA, int _iB);
};

CObj::CObj()
	: m_iA(10), m_iB(100) // 이니셜라이저를 이용한 초기화 기법
{
	//m_iB = 100;		// 생성된 메모리에 대입을 통한 초기화

}
CObj::CObj(int _iA, int _iB)
	: m_iA(_iA), m_iB(_iB)
{

}
*/

class Test
{
private:
	const int a;

public:
	void Print() { cout << a << endl; }
	Test(int a) : a(a) {}
};

int main()
{
	Test t;

	t.Print();


	return 0;
}


#pragma endregion 멤버 상수를 초기화하는 방법

#pragma region 클래스 안에서 존재하는 함수의 상수화

// 일반적인 재귀 함수의 경우 반환 타입 또는 매개 변수에 const와 &를 붙이게 되면 값 변경이 불가능하기 때문에 사용해서는 안 된다.

/*
class CObj
{
private:
	const int		m_iA = 10;
	int				m_iB = 0;

public:
	const int&		Get_A(void) const
	{ 
		return m_iA; 
	}
		
	void		Set_A(const int& _iB)	// 매개변수로 상수를 받아서 값 변경을 하지 않는 경우 사용하는 읽기 전용 매개변수
	{									// 메모리 복사가 발생할 일 없고, const가 붙어 있기 때문에 값 변경이 불가능하다.
		//_iB += 10;
		m_iB = _iB;
	}

public:
	void	Render(void) const			// 읽기 전용 함수
	{ 
		// m_iA = 20;					// 쓰기 기능을 수행하고 있는 코드, const 함수 내에서는 이와 같은 행위를 할 수 없다.

		cout << "Hello World" << endl;
		//cout << m_iA << endl; 

		Draw();						// draw함수내에서 데이터 변경 가능성이 열려 있기 때문에 컴파일러는 이와 같은 호출을 허용하지 않는다.
	}								// 만약 draw함수 또한 const가 붙은 읽기 전용이라면 컴파일러는 데이터 변경의 가능성이 없는 것을 인지하여 호출을 허용한다.

	void		Draw(void) const;
	void		Draw(void);
};

void	CObj::Draw() const
{
	cout << "jusin" << endl;
}

void	CObj::Draw()
{
	cout << "일반 함수" << endl;
}

void main(void)
{
	CObj	Obj;

	//Obj.Render();

	//Obj.Draw();

	cout << Obj.Get_A() << endl;

	int iTemp = 200;

	Obj.Set_A(iTemp);

	//const CObj		Temp;
	//Temp.Draw();


	/ *int	a = 10;

	int& r = a;

	const int& r2 = 10;
	
	cout << r2 << endl;* /

}*/

#pragma endregion 클래스 안에서 존재하는 함수의 상수화

