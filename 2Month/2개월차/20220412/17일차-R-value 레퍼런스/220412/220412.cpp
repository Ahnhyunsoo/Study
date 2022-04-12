// 220412.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Temp.h"
#include "Test.h"

#pragma region R-Value 레퍼런스
/*
void	Add(int&& a, int&& b)
{
	//a += 10;
	//b += 20;

	// cout << a << "\t" << b << endl;

	//Add(a, b);	// 무한루프
}

int main()
{


	// L - value : 연산자를 기준으로 왼쪽, 오른쪽 모두 등장할 수 있는 값
	// R - value : 연산자를 기준으로 오른쪽에만 존재할 수 있는 값

	// 데이터 복사 비용을 최소화 하기 위해 자주 사용하는 문법


	// int	iTemp = 10;
	// int	iDest = iTemp;

	// ex) iTemp 는 대입 연산자 기준으로 왼쪽, 오른쪽 모두 위치할 수 있기 때문에 l-value인 반면,
	// 숫자 10은 오른쪽에만 있을 수 있기 때문에 r-value라고 한다.

	//int		iTemp = 20;

	//const int&	r = 10;		// 일반적인 레퍼런스는 l-value만 참조할 수 있다.
	
	//int&& r2 = 10;		// R-value의 값도 주소값 참조 가능
	//r2 = iTemp;			// R-value 레퍼런스 자료형은 l-value 값 대입도 가능

	//r = 20;

	//cout << r2 << endl;

	//int iA = 10;
	//int	iB = 20;

	//Add(iA, iB);
	//Add(10, 20);

#pragma endregion R-Value 레퍼런스
    return 0;


}*/

#pragma region 이동 생성자

/*
class CObj
{
public:
	CObj() : m_pArray(nullptr), m_iSize(0) 
	{
	}
	CObj(int iSize) : m_pArray(new int[iSize]), m_iSize(iSize) 
	{
	}

	CObj(CObj& rObj)
	{
		m_pArray = new int[rObj.m_iSize];
		memcpy(m_pArray, rObj.m_pArray, sizeof(int) * rObj.m_iSize);
		m_iSize = rObj.m_iSize;
	}

	// 이동 생성자
	CObj(CObj&& rObj)
	{
		m_pArray = rObj.m_pArray;		// 소유권 이전
		m_iSize = rObj.m_iSize;

		// 소유권 이전 이후 댕글링 포인터가 되지 않도록 null로 초기화
		rObj.m_pArray = nullptr;
	}

	~CObj()
	{
		if (m_pArray)
		{
			delete[]m_pArray;
			m_pArray = nullptr;
		}		
	}

private:
	int*			m_pArray;
	int				m_iSize;
};

void main(void)
{
	/ *CObj		Obj(100000000);

	DWORD		dwTime = GetTickCount();

	//CObj		Temp(Obj);

	CObj		Temp(std::move(Obj));

	//std::move : 매개변수로 전달받은 대상을 R-Value 레퍼런스로 캐스팅해주는 함수
	//move 함수를 사용하여 이동생성자를 호출할 지 아니면 복사 생성자를 호출할지 구문하게 됨

	cout << (GetTickCount() - dwTime) << endl;* /

	//vector<CObj>		vec;
	//vec.push_back(CObj(100000000));

	// 1. 임시 객체 생성 및 할당
	// 2. 할당 과정에서 동적 멤버 할당
	// 3. 깊은 복사 생성자 호출, 복사 수행 시, 1억에 해당하는 데이터 복사 비용 소모
	// 4. 복사 수행 후 임시 객체 소멸자 호출
	// 5. 임시 객체 멤버 해제
	// 6. 임시 객체 소멸
	
	//vec.push_back(std::move(CObj(100000000)));

	// 1. 임시 객체를 할당
	// 2. 할당 과정에서 동적 멤버 할당
	// 3. 이동생성자를 통한 소유권 이전(1번 항목의 주소만 이동)
	// 4. 소유권 이전 후, 임시 객체 소멸자 호출
	// 5. 임시 객체 소멸


#pragma region 벡터와 벡터 간의 이동


	vector<int>		vec1(100000000);

	DWORD	dwTime = GetTickCount();

	cout << "vec1.capacity  : " << vec1.capacity() << endl;

	vector<int> vec2 = std::move(vec1);
	cout << "vec2.capacity  : " << vec2.capacity() << endl;
	cout << "시간 : " << (GetTickCount() - dwTime) << endl;
	

#pragma endregion 벡터와 벡터 간의 이동


}*/

#pragma endregion 이동 생성자

int		g_iNum = 100;

void main()
{
	//Add();
	//cout << g_iNum << endl;

	//CTest	Test;

	//Test.Render();
	//Test.Render();
	//Test.Render();

	//cout << CTest::m_iTest << endl;

	CTest::Print();
}

