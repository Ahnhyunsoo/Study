#include "stdafx.h"
#include "헤더.h"
#pragma region R-Value 레퍼런스

/*
L-value : 연산자를 기준으로 왼쪽,오른쪽 모두 등장할 수 있는 값
R-value : 연산자를 기준으로 오른쪽에만 존재할 수 있는 값
*/

//데이터 복사 비용을 최소화 하기 위해 자주 사용하는 문법

/*int iTemp = 10;
int iDest = iTemp;

ex) itemp는 대입 연산자 기준으로 왼쪽, 오른쪽 모두 위치할 수 있기 때문에 L-value인 반면
숫자 10은 오른쪽에만 있을 수 있기 때문에 R-value라고 한다.*/

//int iTemp = 30;
////const int& r = 10; // 일반적인 레퍼런스는 L-value만 참조할 수 있다.
////R-value는 임시메모리에 올라가있다.
////r = 20;
//int&& r2 = 10; // R-value의 값도 주소값 참조 가능
//r2 = iTemp; // R-value 레퍼런스 자료형은 L-value 값 대입도 가능
//cout << r2 << endl;

/*R-value레퍼런스는 상수를 이용하고 싶을 때 사용한다.
	복사를 안하기 때문에 메모리가 효율적이다.*/

#pragma endregion R-Value 레퍼런스

#pragma region 이동 생성자

//class CObj
//{
//public:
//	CObj() : m_pArray(nullptr), m_iSize(0) {}
//	CObj(int iSize) : m_pArray(new int[iSize]), m_iSize(iSize) {}
//	CObj(CObj& rObj)
//	{
//		m_pArray = new int[rObj.m_iSize];
//		memcpy(m_pArray, rObj.m_pArray, sizeof(int) * rObj.m_iSize);
//		m_iSize = rObj.m_iSize;
//	}
//
//	CObj(CObj&& rObj)
//	{
//		m_pArray = rObj.m_pArray;
//		m_iSize = rObj.m_iSize;
//		rObj.m_pArray = nullptr; // 원본값을 nullptr로 만들었다. 소유권 이전이라는 개념
//		//복사 생성자는 복사를 하는 복사본인데 이동생성자는 원본값을 다른 객체한테 이전시키는 개념
//		//원본에 데이터는 접근권한이 사라져버린다. 그래서 순수이동시켜서 이동생성자이다.
//		//소유권 ㅣㅇ전 이후 댕글링 포인터가 되지 않도록 null로 초기화
//	}
//
//	~CObj()
//	{
//		if (m_pArray)
//		{
//			delete[]m_pArray;
//			m_pArray = nullptr;
//		}
//	}
//private:
//	int* m_pArray;
//	int m_iSize;
//};

////CObj Obj(100000000);
//	//DWORD dwTime = GetTickCount(); // OS가 구동되는 시점에 알수없는숫자하나가 카운팅되며 증가한다
//	//								//대략 1000정도일 때 1초정도이다.
//	////CObj Temp(Obj);
//	//CObj Temp(std::move(Obj));
//	//cout << (GetTickCount() - dwTime) << endl;
//
//	////std::move 가 없으면 이동생성자가 호출이 안된다.
//	////std::move 매개변수로 전달받은 대상을 R-Value 레퍼런스로 캐스팅해주는 함수
//	////move 함수를 사용하여 이동생성자를 호출할지 아니면 복사생성자를 호출할지 구분하게 됨
//
//vector<CObj> vec;
//vec.push_back(CObj(100000000));
////1. 임시 객체 생성 및 할당
////2. 할당 과정에서 동적 맴버를 할당
////3. 깊은 복사 생성자 호출, 복사 수행 시 1억에 해당하는 데이터 복사 비용이 소모됨
////4. 복사 수행 후 임시 객체 소멸자 호출
////5. 임시 객체 맴버 해제
////6. 임시 객체 소멸
//
//vec.push_back(std::move(CObj(100000000)));
////1. 임시 객체를 할당
////2. 할당 과정에서 동적 맴버 할당
////3. 이동생성자를 통한 소유권 이전(1번 항목의 주소만 이동)
////4. 소유권 이전 후 임시객체 소멸자 호출
////5. 임시 객체 소멸

#pragma endregion 이동 생성자

int g_iNum = 100;

void main(void)
{
	
	ADD();
	//이동생성자는 복사를 수행하지않고 객체의 값을 넘겨줘야할 때 속도적인 측면때문에 사용한다.
	//복사를 안하고 소유권만 이전해준다.


}

#pragma region Exturn



#pragma endregion Exturn


static을 사용하는 이유
객체를 생성하지 않고 ::연산자를통해 직접 사용하면된다. 
대신 남발하면 은닉화와 캡슐화가 파괴된다.

정적함수내에서 지열 변수 사용가능
static 함수 내에 선언된 static 변수 사용 가능
static함수 내에서 맴버로 선언된 static변수 사용 가능
동일 클래스 내의 일반 맴버 변수는 사용 불가능 
맴버 변수는 객체가 생성되는 시점에 메모리가 할당되기 때문에 문제가 생긴다.