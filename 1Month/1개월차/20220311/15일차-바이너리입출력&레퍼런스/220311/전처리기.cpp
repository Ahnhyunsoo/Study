#include <iostream>

using namespace std;

void Swap(int* pA, int* pB)
{
	int iTemp = 0;

	iTemp = *pA;
	*pA = *pB;
	*pB = iTemp;
}

void SwapR(int& _A, int& _B)
{
	int iTemp = 0;

	iTemp = _A;
	_A = _B;
	_B = iTemp;
}



void main(void)
{
#pragma region 레퍼런스

	// 레퍼런스 : C++에 와서 등장한 문법, 변수 이름에 또다른 이름을 부여하는 문법, 동작은 포인터와 유사하게 동작

	// 레퍼런스는 자료형이지 변수가 아니다.

	//int	iA = 10;
	//int	iB = 20;

	//int&	r = iA;			// 레퍼런스는 선언만 행위는 불가능하다, 반드시 선언과 동시에 초기화 형태를 만들어줘야 한다.
						// 레퍼런스는 참조만 하기 위해 탄생한 문법, 상수 형태로 오로지 하나의 데이터만 참조하며, 따로 메모리 공간을 갖지도 않는다.
	/*r = 100;
	r = iB;
	r = 200;*/

	//cout << iB << endl;

	/*cout << sizeof(int&) << endl;
	cout << sizeof(short&) << endl;
	cout << sizeof(char&) << endl;*/

	//cout << (&iA) << endl;
	//cout << (&r) << endl;

	/*cout << iA << "\t" << iB << endl;

	//Swap(&iA, &iB);
	SwapR(iA, iB);


	cout << iA << "\t" << iB << endl;*/

	const	int iA = 20;
	const int& r = iA;	// const가 붙은 읽기 전용 변수를 레퍼런스로 참조를 시키면 값 변경에 가능성이 생기기 때문에 허용하지 않는다.
						// 레퍼런스 또한 const 붙여 참조는 하되 읽기 전용으로 사용할 수는 있다.
	// r = 999;

	// int& r2 = 30;		// 리터럴 상수는 임시 메모리 공간에 잠시 등록되었다고 코드라인을 벗어나면 소멸된다.
						// 주소 공간을 참조해야하는 레퍼런스는 임시 메모리의 주소를 참조하더라도 코드라인이 벗어나면 그 대상을 잃기 때문에 애초에 허용하지 않도록 설계되어 있다.

	const int& r2 = 30; // 문법적으로는 허용해선 안돼지만 c++에서는 성립할 수 있도록 '임시 변수'를 생성한다. 이때 임시 변수란 말 그대로 이름없는 변수를 뜻한다.

#pragma endregion 레퍼런스

}