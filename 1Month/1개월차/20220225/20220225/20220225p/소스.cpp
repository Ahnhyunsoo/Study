#include <iostream>

using namespace std;

#pragma region 재귀함수
// 재귀 함수 : 자기 자신에게 돌아가는 함수라는 뜻으로 자신을 다시 호출하는 형태의 함수를 뜻하낟.
// 반드시 탈출 조건을 만들어야만 한다. 안그러면 무한 루프에 빠진다.
void Return(int iNumber);

void main(void)
{
	Return(5);
}

void Return(int iNumber)
{
	if (0 >= iNumber)
		return;

	cout << "재귀 호출" << endl;
	--iNumber;
		Return(iNumber);
}

#pragma region 메모리
int iTemp = 0;	// 데이터 영역에 할당되는 전역 변수 : 한 파일 안에서는 전역적으로 사용이 가능한 변수
int iTest = 4000;

void Plus(void)
{
	//int iTemp = 10; // 스택 메모리에 할당된 지역 변수(그 지역 안에서만 유효한 이름)
	iTemp = 100;

	cout << iTemp << endl;
}

void Minus(void)
{	
	iTemp = 200;
	cout << iTemp << endl;
}

void Add(void)
{
	static int iTest = 1000; // 데이터영역에 할당되는 정적 변수 : 지역 내에서 선언하며, 지속적으로 메모리 사용가능한 변수
	cout << ++iTest << endl;
}
#pragma endregion 메모리

void Render(int _iA , int _iB = 100);// 디폴트 매개변수 (맨 뒤쪽부터 차례대로 값을 채워서 사용함)
void Print(int); 

#pragma region 함수
//함수 오버로딩 : 이름이 같을 때 매개변수의 개수, 자료형 타입에 따라 어떤 함수가 호출될 지 결정되는 문법
//반환 타입이 다르다는 이유로 함수 오버로딩이 성립되지는 않는다.
//함수 오버로딩 시 디폴트 매개변수를 확용하는 함수와 호출 모호성을 발생시키지는 않는지 고려해야 한다.


//void Draw(int);


namespace A
{
	void Draw(void) { cout << "A" << endl; }
}

namespace B
{
	void Draw(void) { cout << "B" << endl; }
}

using namespace A;



void Render(int _iA , int _iB) 
{
	cout << _iA << endl;
	cout << _iB << endl;
}

void Draw()
{
	cout << "Draw" << endl;
}

void Draw(int _iTemp)
{
	cout << "int" << endl;
}

void Draw(float _fTemp)
{
	cout << "float" << endl;
}

void Draw(int _iTemp, int _iSour)
{
	cout << _iTemp << _iSour << endl;
}

void Print(int)
{
	cout << "출력" << endl;
}
#pragma endregion 함수

// 5 팩토리얼을 함수로 구현하라


// 5! = 5 * 4 * 3 * 2 * 1
// 재귀함수를 이용해서 구현하라

