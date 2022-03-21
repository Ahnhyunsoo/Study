// 220321.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include "Player.h"

// 객체 = 클래스(자료형) + 인스턴스(메모리 상태)

// 클래스의 4대 속성 : 은닉화, 캡슐화, 상속성, 다형성

// 은닉화 : 클래스 내의 데이터와 기능을 외부로 부터 보호하는(숨기는) 성질을 의미
// 접근 제어 지시자 : private, protected, public

// 캡슐화 : 관련있는 데이터와 기능을 한 클래스 안에 묶어서 관리하는 행위

struct	tagInfo
{
private:
	int			iA;		// 구조체 멤버 변수
};

class CObj
{
	int			m_iB;		// private 접근

public:						// 내부, 외부 모두 접근을 허용,  클래스 멤버 변수, public으로 접근 권한 변경
	int			m_iD;

private:					// 오로지 내부 접근만 허용하는 지시자
	int			m_iC;
	int			m_iA;

public:
	// access method 
	void		Set_A(int _iA)	{	m_iA = _iA;	 }
	int			Get_A(void)		{	return m_iA; }

public:
	void		Render()			// 멤버 함수
	{
		cout << m_iA << endl;		// 내부 접근
	}

};


int main()
{
	//tagInfo		tInfo;
	//tInfo.iA = 100;
	//cout << tInfo.iA << endl;

	//CObj		Obj;
	//Obj.m_iA = 100;		// 외부접근
	//Obj.Set_A(100);
	

	//cout << Obj.Get_A() << endl;
	//Obj.Render();
	//cout << Obj.m_iA << endl;*/

	CPlayer		Player;
	Player.Draw();

	/*CPlayer*	pPlayer = new CPlayer[3];

	delete[]pPlayer;
	pPlayer = nullptr;*/

    return 0;
}

// 1. 성적표 프로그램을 클래스로 만들고 동적 배열로 구현하자
// 2. textRpg 클래스로 만들기