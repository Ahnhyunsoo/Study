// 220330.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#pragma region 오버라이딩과 순수 가상함수

// 1. 순수 가상함수가 단 하나라도 존재하는 클래스를 가리켜 '추상 클래스'라 한다.
// 2. 추상 클래스는 객체 생성이 불가능하다.
// 3. 부모 클래스에 선언한 순수가상함수가 있다면 모든 자식 클래스는 반드시 몸체를 구현해야 한다.

/*
class CObj abstract
{
public:
	virtual void	Render(void) = 0; // 순수 가상함수(오버라이딩을 위해 가상함수로써의 근거만 남기는 문법)
									  //virtual void	Render() { cout << "Obj" << endl; }
};


class CPlayer final : public CObj
{
	virtual void	Render() override { cout << "player" << endl; }
};

class CMonster : public CObj
{
	virtual void Render() {}
};


int main()
{

	// 동적 바인딩, 오버라이딩, 가상함수 작동원리
	// 오버라이딩 : 부모 클래스의 포인터로 자식 클래스의 기능을 사용하게하는 문법

	//1. 은닉화
	//2. 재정의

	CObj*		pObj = new CObj;

	pObj->CObj::Render();

	delete pObj;
	pObj = nullptr;

	CObj*		pMonster = new CMonster;
	
	return 0;
}
*/

#pragma endregion 오버라이딩과 순수 가상함수

#pragma region 가상 소멸자

// 만약 상속을 했다면(부모 클래스에 가상함수가 있다면) 부모클래스의 소멸자에는 virtual 키워드를 반드시 붙여라 

/*
class CObj
{
private:
	int*		m_pA;

public:
	CObj() 
	{
		m_pA = new int;
		cout << "부모 생성자" << endl;
	}
	virtual ~CObj()
	{
		delete  m_pA;
		m_pA = nullptr;
		cout << "부모 소멸자" << endl;
	}
};

class CPlayer : public CObj 
{
private:
	int*		m_pB;

public:
	CPlayer()
	{
		m_pB = new int;
		cout << "자식 생성자" << endl;
	}
	virtual ~CPlayer()
	{
		delete  m_pB;
		m_pB = nullptr;
		cout << "자식 소멸자" << endl;
	}
};

void main(void)
{
	CObj*		pObj = new CPlayer;

	delete pObj;
	pObj = nullptr;

	//CPlayer		Player;
	//CObj*		pObj = &Player;

}*/


#pragma endregion 가상 소멸자

#pragma region 캐스팅

/*
class CObj abstract
{
public:
	virtual void	Render(void) = 0;									 
};

class CPlayer final : public CObj
{
public:
	virtual void	Render() override { cout << "player" << endl; }

public:
	void			Print() { cout << "일반 자식 함수" << endl; }
};

class CMonster final : public CObj
{
public:
	virtual void Render() { cout << "Monster" << endl; }
};

void main(void)
{
	// 1. 캐스팅은 내부적인 동작 비용이 많이 발생하여 프로그램 전반의 속도를 저하시킨다.
	// 2. c캐스팅은 무조건 형 변환을 허용하기 때문에 위험성이 다분이 높다.

	CObj*		pObj = new CPlayer; // 이게 업캐스팅 부모자료형에 자식객체를 담겠다

	((CPlayer*)pObj)->Print(); // down 캐스팅, c시절부터 캐스팅(형 변환)

	delete pObj;
	pObj = nullptr;
}*/
#pragma endregion 캐스팅

#pragma region C++ 캐스팅 연산자

class CObj
{
private:
	int		m_iA = 0;
public:
	virtual void Render() {}
};

class CPlayer : public CObj
{
private:
	int		m_iB = 0;
public:
	virtual void Render() { cout << m_iB << endl; }
};

void main(void)
{
	/*static_cast<변환하고 싶은 자료형>(변환할 데이터)
	dynamic_cast<>()
	const_cast<>()
	reinterpret_cast<>()*/

#pragma region static Cast
	// 1. static_cast : 논리적인 형변환을 수행, 우리가 늘 써오던 c스타일 캐스팅, 형변환 시점이 컴파일 시점이기 때문에 static이란 명칭이 붙고 정적 캐스팅이라고 불린다.

	//int	iNumber = static_cast<int>(3.14f);

	// 논리적이지 않은 캐스팅 상태 1
	//CPlayer*	pPlayer = new CPlayer;

	//CObj*		pObj = (CObj*)pPlayer;
	//CObj*		pObj = static_cast<CObj*>(pPlayer); // 상속이 아닌 상태에서 강제적인 형 변환은 불가능하다. 상속 관계 유무를 논리적으로 따지는 캐스팅

	// 논리적이지 않은 캐스팅 상태 2

	//CObj*		pObj = new CObj;
	//CPlayer*	pPlayer = pObj;		// 객체 포인터는 부모, 자식을 판단할 수 없다. 지금처럼 서로 알 수 없는 상황에서 단순 대입 시 컴파일 에러가 발생
	//CPlayer*	pPlayer = static_cast<CPlayer*>(pObj); // 다운 캐스팅

	// static_cast의 장점
	// 1. 속도가 빠름
	// 2. 일반적으로 손쉽게 사용(원시 데이터 캐스팅에도 사용 가능)

	// static_cast의 단점
	// 1. 자식 객체 포인터에 부모 객체의 정보를 넣도록 허용하는 행위가 과연 코드적으로 논리적인지 의문이 생김(위험한 형 변환)
	// 2. 컴파일 시점인 정적 캐스팅에 해당하다 보니 런타임 시에 타입 체크를 하지 않아 위험한 형변환의 인지가 불가능


#pragma endregion static Cast

#pragma region dynamic Cast

	// 2. dynamic_cast : 반드시 가상 함수를 하나 이상 포함한 상속관계일 때 다운 캐스팅을 하기 위한 용도로 사용
	// 안전하지 않은 캐스팅을 허용할 경우 nullptr 를 반환한다. 안전한지 불안전한지 런타임 시에 체크를 해주기 때문에 static_cast에 비하면 안전하다.
	
	// 주의 사항 : 일반 자료형이나 일반 포인터는 사용할 수 없다
	
	// 안전하지 않은 다운 캐스팅
	/*CObj*		pObj = new CObj;
	CPlayer*	pPlayer = dynamic_cast<CPlayer*>(pObj);

	if (nullptr == pPlayer)
	{
	cout << "안전하지 않은 캐스팅" << endl;
	}*/

	// 안전한 다운 캐스팅
	//CObj*		pObj = new CPlayer;
	//CPlayer*	pPlayer = dynamic_cast<CPlayer*>(pObj);
	//pPlayer->Render();

	// 업 캐스팅의 예
	//CPlayer*	pPlayer = new CPlayer;
	//CObj*		pObj = pPlayer;		// 묵시적 업 캐스팅

	//CObj* pObj = dynamic_cast<CObj*>(pPlayer);
	//CObj* pObj = static_cast<CObj*>(pPlayer);

#pragma endregion dynamic Cast

#pragma region const Cast

	// const_cast : 포인터가 참조하고 있는 원본 값 변경이 불가능할 때 다른 포인터를 통한 원본 값 변경을 위해 일시적으로 const 성격을 벗겨낼 수 있다.
	// 단, 포인터 또는 레퍼런스 형만 사용할 수 있다.

	/*int	iNum = 10;
	
	const int* p = &iNum;

	// *p = 20;

	int* pTemp = const_cast<int*>(p);

	*pTemp = 20;*/

#pragma endregion const Cast

#pragma region reinterpret Cast

	// reinterpret_cast : const 포인터를 제외한 모든 포인터의 형변환을 허용, 심지어 비 논리적인 형 변환마저 허용
	// 예측할 수 없는 결과를 초래하기 때문에 사용을 자제하는 편이다.

	/*void	Render(void* pTemp)
	{
		int* pDest = (int*)pTemp;
		int* pDest = reinterpret_cast<int*>(pTemp);
		
		cout << (*pDest) << endl;
	}

	int		iTemp = 10;

	Render(&iTemp);*/


	int	iNum = 65;

	char*		p = reinterpret_cast<char*>(&iNum);

	cout << p << endl;


#pragma endregion reinterpret Cast	
}

#pragma endregion C++ 캐스팅 연산자


