#include "stdafx.h"

#pragma region 연산자 오버로딩 문법과 예

/*
class CObj
{
private:
int		m_iX;
int		m_iY;

public:
void		Render() { cout << m_iX << "\t" << m_iY << endl; }

CObj		operator + (CObj& rObj)	// + 연산자를 오버로딩한 예
{
CObj	Test(m_iX + rObj.m_iX, m_iY + rObj.m_iY);

return Test;
}

CObj		operator + (int _iMove)	// + 연산자를 오버로딩한 예
{
CObj	Test(m_iX + _iMove, m_iY + _iMove);

return Test;
}

CObj& operator =(CObj& rObj)
{
m_iX = rObj.m_iX;
m_iY = rObj.m_iY;

return *this;
}

CObj& operator ++(void)
{
m_iX += 1;
m_iY += 1;

return *this;
}

CObj operator ++(int)			// int 형 데이터를 받는 것이 아니라 오버로딩을 위한 구분 문법
{
CObj	Test(*this);

m_iX += 1;
m_iY += 1;

return Test;
}


public:
CObj() {}
CObj(int _iX, int _iY) : m_iX(_iX), m_iY(_iY) {}
~CObj(){}
};

// 교환 법칙 해결 시 전역 함수 만들어줘야 함. 객체 타입에는 객체 포인터가 아닌 순수 객체 타입과 객체의 레퍼런스 타입이 와야한다.
// operator+에는 클래스 형식의 정식 매개 변수가 적어도 하나는 있어야 한다.
CObj	operator +(int _iMove, CObj& rObj)
{
CObj		Test(rObj + _iMove);


return Test;
}


void main(void)
{
// 연산자 오버로딩 : 연산자에 적용을 시킨 함수 오버로딩의 문법

// 1. 본래 연산자의 기능을 뒤바꿀 순 없다.
// 2. 사용자 정의 자료형일 때 성립하는 문법이다.
// 3. 클래스 멤버로만 존재할 수 있는 연산자 =, (), [], -> (좌측 기준으로만 연산을 수행하는 연산자들)


CObj	Temp(100, 200);
CObj	Sour(300, 400);


//CObj	Dest = Temp + Sour;
//Dest.Render();

//Temp = Temp + 10;
//Temp = 10 + Temp;

//Temp.Render();

CObj	Dest = Temp = Sour;

Dest.Render();

//++(++Dest);
Dest++;

Dest.Render();

}*/

#pragma endregion 연산자 오버로딩 문법과 예

#pragma region cout과 연산자 오버로딩

/*
namespace MyStd
{
	class Ostream
	{
	public:
		Ostream&	operator <<(int iDest)
		{
			printf("%d", iDest);

			return *this;
		}

		Ostream&	operator <<(char* pDest)
		{
			printf("%s", pDest);

			return *this;
		}
	};

	Ostream		COUT;
	char*		ENDL = "\n";

}

using namespace MyStd;

void main(void)
{
	COUT << 100 << ENDL;
}
*/

#pragma endregion cout과 연산자 오버로딩

#pragma region 실제 사용 예

// 함수 객체(fuctor) : ()연산자 오버로딩을 통해 객체를 함수처럼 사용하는 문법

// 장점
// 1. 같은 호출문장이라도 실제 어떤 객체냐에 따라 각기 다른 상태를 표현할 수 있다.
// 2. 함수 객체가 클래스 선언부에 몸체까지 정의되어 있다면 해당 멤버 함수는 자동 inline화 되어 일반 함수에 비해 속도가 빠르다.

/*
class CObj
{
public:
	int	operator() (int iTemp, int iSour)
	{
		return iTemp + iSour;
	}
};

void main(void)
{
	CObj	Obj;
	cout << Obj(10, 20) << endl;
}*/

/*
class CSortRule
{
public:
	virtual bool	operator()(int iTemp, int iSour) = 0;
};

// 오름차순
class CAsendingSort : public CSortRule
{
public:
	virtual bool operator()(int iTemp, int iSour)
	{
		if (iTemp > iSour)
			return true;

		return false;
	}

};

// 내림차순
class CDesendingSort : public CSortRule
{
public:
	virtual bool operator()(int iTemp, int iSour)
	{
		if (iTemp < iSour)
			return true;

		return false;
	}
};

void	Bubble_Sort(int* pArray, int iSize, CSortRule& Functor)
{
	for (int i = 0; i < iSize; ++i)
	{
		for (int j = 0; j < iSize - 1; ++j)
		{
			if (Functor(pArray[j], pArray[j+1]))
			{
				int	iTemp = pArray[j];
				pArray[j] = pArray[j + 1];
				pArray[j + 1] = iTemp;
			}
		}
	}
}

void main(void)
{
	int		iArray[5] = { 1, 3, 4, 2, 5 };

	CAsendingSort		Asen;
	CDesendingSort		Desen;

	Bubble_Sort(iArray, 5, Desen);

	for (int i = 0; i < 5; ++i)
	{
		cout << iArray[i] << endl;
	}

}*/


#pragma endregion 실제 사용 예

#pragma region 임시 객체

/*
class CObj
{
private:
	char		m_pStr[256];

public:
	CObj(char* pStr)
	{
		strcpy_s(m_pStr, sizeof(m_pStr), pStr);
		cout << m_pStr << "생성자" << endl;
	}
	~CObj()
	{		
		cout << m_pStr << "소멸자" << endl;
	}
};


void main(void)
{
	//int iA = 3 + 4;

	CObj		Obj("일반");
	cout << "===============임시 객체 생성================" << endl;
	
	CObj("임시 객체");		// 임시 객체는 해당 코드라인을 벗어나는 즉시 소멸된다.

	cout << "===============임시 객체 소멸================" << endl;

}*/

#pragma endregion 임시 객체


// ==(strcmp), +(strcat), =(strcpy)