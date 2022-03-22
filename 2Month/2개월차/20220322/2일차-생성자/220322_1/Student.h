#pragma once

#include "Define.h"

class CStudent
{
private:
	INFO*		m_pInfo;
	int			m_iSize;

public:
	void		Initialize(void);
	void		Release(void);

public:
	void		Input_Data(void);
	void		Output_Data(void);

public:
	CStudent();					// 생성자 : 객체가 생성되는 시점에 반드시 호출
	CStudent(int _iSize);		// 매개변수 있는 생성자
	~CStudent();
};


// 객체가 생성될 때 내부적으로 자동생성되는 네 가지

// default 생성자, 소멸자, default 복사 생성자, default 대입 연산자

// default 생성자는 프로그래머가 직접적으로 구현한 생성자가 단 한계라도 존재하면 생성, 호출되지 않는다.

// 소멸자를 구현해주지 않을 경우 자동 default 소멸자가 호출된다.
// 소멸자는 반드시 기본타입 하나 밖에 없다.(오버로딩이 불가능)

// 객체 생성과정은 다음과 같다.
// 1. 메모리 할당 -> 2. 생성자 호출

// 객체 소멸과정은 다음과 같다.
// 1. 소멸자 호출 2. 메모리 반환