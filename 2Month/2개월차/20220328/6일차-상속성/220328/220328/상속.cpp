// 220328.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Boy.h"

// base 클래스 : 데이터를 물려주는 클래스, 국내에서는 부모 클래스라고 표현을 많이 한다.
// derived 클래스 : 데이터를 물려받는 클래스, 자식 클래스라고 표현을 많이 한다.

class CObj
{
protected:
	int		m_iA;

public:
	CObj() { cout << "부모 생성자" << endl; }
	CObj(int _iA)
		: m_iA(_iA)
	{

	}
	~CObj() { cout << "부모 소멸자" << endl; }
};

// #include "Obj.h"

class CPlayer : public CObj
{
/*
private:
	int		m_iA = 200;*/

public:
	void	Render(void) 
	{ 
		cout << m_iA << endl;	// player 멤버 변수
		cout << CObj::m_iA << endl; // 부모에서 선언된 멤버 변수
	}
public:
	CPlayer() 
	{ 
		cout << "자식 생성자" << endl; 
	}
	CPlayer(int _iA)
		: CObj(_iA)
	{

	}

	~CPlayer() { cout << "자식 소멸자" << endl; }
};

class CMonster : public CObj
{
public:
	void	Render(void) { cout << this->m_iA << endl; }
public:
	CMonster() { cout << "몬스터 생성자 " << endl; }
};

int main()
{
	
	//CObj		Obj;

	//CPlayer		Player;

	// 상속의 조건

	// 1. is-a	
	// 2. has-a
	
    return 0;
}

