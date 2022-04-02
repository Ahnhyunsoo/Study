#include "stdafx.h"

#define			SAFE_DELETE(p) if(p) { delete p; p =nullptr;}

template<typename T>
void	Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

// 템플릿의 장단점

/*
1. 모든 자료형을 호환한다.
2. 템플릿이 사용되는 형식은 컴파일 타임에 이뤄지기 때문에 오류가 발생하기 전에 컴파일러가 검사를 수행하여 안전하다.
3. 컴파일러가 함수 또는 클래스를 생성해주기 때문에 생성속도가 빠르다.

1. 자료형의 개수가 많아질수록 일일이 생성하기 때문에 코드 비대화를 불러온다.
2. 실행파일의 크기가 커진다.*/


#pragma region 템플릿

// 함수 템플릿의 예(단항 템플릿)
/*
template<typename T>
T		Add(T a, T b)
{
	return a + b;
}

// 템플릿 특수화 : 특정 자료형에 해당하는 템플릿 동작을 따로 정의하는 문법
// 조건 : 모든 자료형에 해당하는 템플릿이 우선 존재해야함
template<>
char* Add(char* a, char* b)
{
	int iLength = strlen(a) + strlen(b);

	char*		pString = new char[iLength + 1];

	strcpy_s(pString, iLength + 1, a);
	strcat_s(pString, iLength + 1, b);

	return pString;
}

// 특수화를 진행한 템플릿은 자료형이 명시되어 있기 때문에 함수 오버로딩 문법 또한 성립된다.
template<>
const char* Add(const char* a, const char* b)
{
	int iLength = strlen(a) + strlen(b);

	char*		pString = new char[iLength + 1];

	strcpy_s(pString, iLength + 1, a);
	strcat_s(pString, iLength + 1, b);

	return pString;
}

// 이항 템플릿 : 두 개 이상의 타입을 갖는 템플릿

template<typename T1, typename T2, typename T3>
T3		Add(T1 a, T2 b)
{
return a + b;
}

void main(void)
{
	// 템플릿 : 틀, 함수 또는 클래스를 생성하기 위한 문법

	// 기능은 결정되어 있지만 자료형은 결정되어 있지 않은 상태

	// 함수 템플릿 : 함수의 모양으로 이뤄져서 함수를 생성하는 템플릿
	// 템플릿 함수 : 템플릿에 의해 생성된 함수

	cout << Add<short>(5, 10) << endl;	// 템플릿 함수

	cout << Add<float>(3.14f, 6.27f) << endl;	// 템플릿 함수

	char* pStr = Add<char*>("a", "b");

	cout << pStr << endl;

	delete[]pStr;
	pStr = nullptr;

	const char* pConsStr = Add<const char*>("c", "d");

	cout << pConsStr << endl;

	delete[]pConsStr;
	pConsStr = nullptr;


	double		dNumber = Add<int, float, double>(10, 20.1f);
	cout << dNumber << endl;

}*/
#pragma endregion 템플릿

#pragma region 클래스 템플릿

/*
template<typename T>
class CObj
{
private:
	T		m_X;
	T		m_Y;

public:
	CObj() {}
	CObj(T _X, T _Y) : m_X(_X), m_Y(_Y) {}
	~CObj() {}
};

void main(void)
{
	CObj<int>		IntObj(10, 20);
	CObj<float>		FloatObj(10.f, 20.f);
}*/

/*
template<typename T>
class CObj
{
public:
	T Add(T a, T b)
	{
		return a + b;
	}
};

template<>
class CObj<char*>
{
public:
	char* Add(char* a, char* b)
	{
		int iLength = strlen(a) + strlen(b);

		char*		pString = new char[iLength + 1];

		strcpy_s(pString, iLength + 1, a);
		strcat_s(pString, iLength + 1, b);

		return pString;
	}
};

template<typename T1, typename T2>
class CTest
{

};

// 이항 템플릿의 부분 특수화
template<>
class CTest<int, char*>
{

};

template<typename T>
class CTest<T, char*>
{

};*/

/*
template<typename T>
class CObj
{
public:
	T Add(T a, T b);	
	void	Render(T a);
};

template<typename T>
T CObj<T>::Add(T a, T b)
{
	return a + b;
}

template<typename T>
void	CObj<T>::Render(T a)
{
	cout << a << endl;
}


void main(void)
{

}
*/





#pragma endregion 클래스 템플릿

#pragma region static과 템플릿의 관계

template<typename T>
T Func(T Num)
{
	static T Temp = 0;

	Temp += Num;

	return Temp;
}

template<typename T>
class CObj
{
public:
	T Func(T Num)
	{
		m_Temp += Num;

		return m_Temp;
	}

private:
	static T	m_Temp;
};

template<typename T>
T CObj<T>::m_Temp = 0;

template<typename T>
class CMonster : public CObj<T>
{

};


void main(void)
{
	// 템플릿 내에 선언한 static 변수는 같은 자료형의 템플릿인 경우에만 메모리를 공유한다.

	/*Func<int>(10);
	Func<double>(20.1);
	
	cout << Func<int>(5) << endl;
	cout << Func<double>(3.14) << endl;*/


	//CObj<int>		intObj;
	//CObj<int>		intObj2;

//	CObj<double>	doubleObj;

	//intObj.Func(10);
	//intObj2.Func(20);

	//cout << intObj.Func(0) << endl;
	
	/*doubleObj.Func(20.1);

	cout << intObj.Func(5) << endl;
	cout << doubleObj.Func(3.14) << endl;
*/
}



#pragma endregion static과 템플릿의 관계