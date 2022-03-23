// 220323_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Player.h"

class CObj
{
private:
	int		m_iA;

public:
	void		Render() { cout << m_iA << endl; }

public:
	explicit CObj()
	{
		cout << "기본 생성자" << endl;
	}

	explicit CObj(int _iA)		// 묵시적 형변환을 원하지 않을 때 사용하는 키워드
	{
		m_iA = _iA;
	}

	~CObj()
	{
		cout << "소멸자" << endl;
	}
};

/*
1. 컴파일 에러 
2. 쓰레기값 
3. 10 
4. 10 출력 이후 런타임 에러*/

int main()
{
	//CObj		Obj = 10;		// default 대입 연산자를 호출하여, int형 변수를 받는 매개변수가 있는 생성자로 자동 형변환하여 객체 생성이 가능하게 만들고 있다.

	//Obj.Render();


	//CObj		Obj[3];

/*
	CObj*		pObj = new CObj[3];

	delete[]pObj;
	pObj = nullptr;*/


	CPlayer		Player; // 메모리 할당, 생성자 호출

	Player.Render();
	Player.Draw();


    return 0;
}

