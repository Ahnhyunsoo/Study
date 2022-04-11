#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <algorithm>

using namespace std;



struct taginfo
{
	int a;
	int b;
};

class CObj
{
public:
	taginfo Get_info() {
		return{ 300,400 };
	}

private:
	taginfo m_tinfo;
public:
	CObj(taginfo _tinfo)
		:m_tinfo(_tinfo)
	{

	}
};


#pragma region mutable
//class CObj
//{
//private:
//	mutable int m_iA;  //읽기 전용 함수 내에서 값 변경이 가능하도록 해주는 함수
//	int m_iB;
//
//public:
//	void Render() const // 읽기 전용(데이터 변경 불가능)
//	{
//		m_iA = 30;
//		//m_iB = 40;
//	}
//
//public:
//	CObj() : m_iA(10)//m_iB(20)
//	{
//
//	}
//};
#pragma endregion mutable

#pragma region 예외처리
//// 컴퓨터는 나누기0을 수행할 수 없다.
//	// if문의 경우 일반적인 프로그램의 논리를 구현하는데 주 목적을 둔다.
//int iNum1, iNum2;
//cout << "숫자 입력 : ";
//cin >> iNum1 >> iNum2;
//
///*if (0 == iNum2)
//	cout << "0으로 나눌 수 없습니다" << endl;
//else
//{
//	cout << "몫 : " << (iNum1 / iNum2) << endl;
//	cout << "나머지 : " << (iNum1 % iNum2) << endl;
//}*/
//
//try
//{
//	if (0 == iNum2) // 예외처리
//		throw iNum2; //catch로 던져라
//
//	//위에서 정한 예외가 발생하면 나머지 코드 블록은 실행하지 않고 건너 뛴다.
//	cout << "몫 : " << (iNum1 / iNum2) << endl;
//	cout << "나머지 : " << (iNum1 % iNum2) << endl;
//}
//catch (int iNum2)
//{
//	cout << "0으로 나눌 수 없습니다." << endl;
//}
#pragma endregion 예외처리


void main(void)
{
#pragma region C++11
	//auto 키워드 : 사용자가 직접 타임을 지정하지 않아도 되는 문법
	//auto는 꼭 초기화를 해줘야 한다.
	//auto는 컴파일러가 타입을 판단하게 한다.
	//auto일 경우 판별이 애매해진다. 타입구분이 힘듬

	/*auto i = 10;
	cout << sizeof(i) << endl;
	auto f = 3.14f;
	cout << sizeof(f) << endl;
	auto p = new int;
	cout << sizeof(p) << endl;
	*/

	// 범위 기반 for문 : C# 이나 자바에서 이미 제공했던 기능, C++11에서도 지원하게 됨
	// 간단하고, 배열 인덱스 범위를 넘어가는 행동을 방지할 수 있다.
	
	/*int iArray[5] = { 1,2,3,4,5 };

	for (int i : iArray)
		cout << i << endl;*/

	//vector<int> vec;
	//vec.push_back(10);
	//vec.push_back(20);
	//vec.push_back(30);
	//vec.push_back(40);
	//vec.push_back(50);
	//
	//for (auto& iter : vec)
	//	cout << iter << endl;

	//유니폼 초기화
	//int iArray[5] = { 0,1,2,3,4 };
	/*int iArray[5]{ 1,2,3,4,5 };
	taginfo t{ 10,20 };

	vector<int> vec{ 1,2,3,4,5 };

	cout << vec.size() << " " << vec.capacity() << endl;*/

	/*map<int, int> MyMap{ {1,100},{2,200},{3,300} };
	for (auto mapiter : MyMap)
		cout << mapiter.second << endl;*/

	//어노드맵 과 맵의 차이점 

	// std::array (stl제공)
	// : 기존에 사용하던 정적 배열을 객체화 함, 생성자, 소멸자, 복사 생성자, 대입연산자가 지원되어 좀 더 객체지향 다운 배열로 생성 가능하다
	// 백터는 동적 배열이어서 사용 비용이 크다.
	//정적배열이 컴파일시점에 정해지기때문에 속도가 더빠르다. 용량도 더 적다.
	//int iArray[5]{ 10,20,30,40,50 };
	//int iTemp[5]{};
	////cout << sizeof(iArray) / sizeof(int) << endl;

	//array<int, 5> arrEx{ 1,2,3 };
	//array<int, 5> arrTemp;
	//int* p = arrTemp.data(); // 배열의 첫 주소를 반환하는 함수
	//arrEx.fill(999); // 배열의 모든 변수를 인자값으로 채우는 함수
	//arrTemp = arrEx;
	//for (int i : arrTemp) // 서로 간의 대입을 통한 값 복사가 가능하다
	//	cout << i << endl;

	//반복자, empty, swap, front, back 함수를 제공함
	//push_back, clear 함수는 제공하지 않음 정적배열이기 때문에

	//cout << arrEx.size() << endl;

#pragma endregion C++11
	
#pragma region 람다 표현식

	// 람다식 : 함수 객체 때문에 발생한 문법,
	
	// 함수 객체의 단점 : 작성에 용이하지 못하다, 일반 사용 시점에 함수인지 객체인지 구분이 어렵다.
	// 람다식의 장점 : 작성이 편리하고, 가동성이 증가 된다, 작동 속도가 빠르다(인정).
	// 람다식은 인라인 함수라서 메모리공간에 올라가지않고 그즉시 호출되고 소멸된다.
	// 함수 선언부나 몸체를 따로 찾을 필요가 없기 때문에 가독성이 증가된다.

	//vector<int> vec{ 10,20,30,40,50 };
	//for_each(vec.begin(), vec.end(), [](int n) {cout << n << endl; });

	/*vector<int> vec{ 10,20,33,40,50 };

	auto iter = find_if(vec.begin(), vec.end(), [](int n)->bool {return 0 != n % 2; });

	cout << (*iter) << endl;*/

	/*vector<int> vec{ 1,2,3,4,5 };

	int iEvenSum = 0;
	int iOddSum = 0;

	for_each(vec.begin(), vec.end(), [&](int n) { 값으로 복사하여 캡처 (const 성향이 되어복사한다)
		if (0 == n % 2)
			iEvenSum += n;

		else
			iOddSum += n;
		});
	
	cout << iEvenSum << endl;
	cout << iOddSum << endl;*/
	// 람다식 문법
	/*[] : '람다 소개자', 컴파일러가 이 기호를 만나면 람다식으로 인지하게 됨
	() : '파라미터 지정자', 일반 함수의 파라미터왇 동일함
	{} : '람다 몸체', 일반 함수의 몸체와 같은 의미*/

	//[]() {cout << "hello world" << endl; } (); // 호출 // 람다식

	//람다식은 함수포인터가 아니다. 그즉시 생성되고 소멸되는 문법이기 때문에.
	//묵시적 변환 : 람다 함수 몸체 내부에서 발생한 결과값으로 컴파일러가 추론하여 반환 타입을 결정
	//int iResult = [](int iTemp, int iSour) { return iTemp + iSour; } (10, 20);
	//cout << iResult << endl;
	
	//명시적 반환
	//int Result = [](int iTemp, int iSour)->int { return iTemp + iSour; }(10, 20);

	// 캡처절 : 람다 소개자를 다르게 부르는 표현, 외부에 있는 데이터를 참조하는 방식을 기호화 한 것
	
	int a = 10, b = 20, c = 30, d = 40;
	[&a,&b](int n) // 레퍼런스로 캡처 a,b로 했을 땐 a,b만 레퍼런스로 캡처다.
		//&해주면 전부다 레퍼런스로 캡처하겠다는 말이다.
		//static변수와 전역변수는 캡처불가
		//람다식은 인라인 함수기 때문에 static변수와 전역변수는 사라지면 안된다.
		//반복적은 작업과 은닉성 측면에서 함수객체가 좋고
		// 속도가 중요한 작업이면 람다식이 빠르기때문에 람다식이 좋다.
	{
		a += n;
		b += n;
		c += n;
		d += n;
	}(100);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;



#pragma endregion 람다 표현식
	
}