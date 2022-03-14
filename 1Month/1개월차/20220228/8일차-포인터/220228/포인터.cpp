#include <iostream>

using namespace std;

void main(void)
{
#pragma region 포인터 기본 문법
	// 포인터 : 주소값을 저장하기 위하여 사용하는 변수이다.

	// 주소값을 사용해야 하는 이유
	// 메모리 공간에 접근하는 방법은 변수의 이름을 통한 접근(직접 접근)과 주소 값을 통한 접근이 있다(간접 접근)
	// 직접 접근의 경우 메모리의 특성에 맞게 하나의 파일 안에서만 사용 가능하거나(전역변수)
	// 중괄호 안에서만 유효성을 갖는 특징을 지닌다(지역변수)
	// 사용의 권한을 늘리고 여러 군데에서 사용 가능한 상태를 만들기 위해 포인터를 사용한다.

	// 참조 : 주소 값을 통해 메모리 공간에 접근하는 행위
	// 1바이트당 하나의 주소 값을 가진다. (ex)int 형 변수는 4바이트이기 때문에 주소 값을 네개 가진다.
	// 그 중에 가장 빠른 번지 수의 주소를 '대표 주소'라 한다.

	/*int	iA = 0;

	// iA = 10;

	//int    *p;
	//int  *  p;
	//int*	p = NULL;			// int 포인터 형 p(용도 : int형 변수의 주소값을 저장하는 용도)
	int*	p = nullptr;

	p = &iA;		// address 연산자 : 변수 명 앞에 표기할 경우 그 변수의 대표 주소를 추출하여 반환한다.

	*p = 10;		// 포인터 연산자(에스크립터) : 포인터가 가진 주소 공간의 값을 가리키는 연산자
					/ *	cout << (&iA) << endl;
					cout << (p) << endl;* /

	cout << "===========" << endl;
	cout << iA << endl;

	int		iB = 20;

	p = &iB;	// 포인터는 변수이기 때문에 코드 라인의 변화에 따라 저장하는 주소 값이 달라질 수 있다.

	*p = 400;

	cout << (*p) << endl;*/

#pragma endregion 포인터 기본 문법

#pragma region 포인터 기본 문법 2

	/*char*	p1 = nullptr;
	int*	p2 = nullptr;
	double*	p3 = nullptr;

	cout << sizeof(p3) << endl;*/

	// 32비트 기반에서 어떤 자료형의 포인터건 크기는 4바이트이다.
	// 운영체제의 발전에 따라 포인터의 크기도 항상 변해왔다.



	// 포인터 연산 : 포인터가 가진 주소를 포인터 자료형의 크기만큼 메모리 이동을 시키는 문법

	/*int	iA = 0;

	int* p = &iA;

	// (*p)++;		// 포인터가 가리키는 공간의 값을 증가

	cout << "전 : "<< p << endl;
	p++;			// 포인터 연산 : 포인터가 가진 값(주소 값)을 이동(증가)
	cout << "후 : " << p << endl;

	cout << iA << endl;*/

	/*short	sA = 0;

	short* p2 = &sA;

	*p2 = 10;

	cout << "전 : " << p2 << endl;
	cout << sA << endl;
	
	// p2++; // 2바이트만큼 이동한 위치

	p2 += 4;
	
	*p2 = 20;	// 위에서 이동한 위치만큼의 메모리 공간을 값을 변경해라(불허)
	
	cout << "후 : " << p2 << endl;
	cout << sA << endl;*/


#pragma endregion 포인터 기본 문법 2


	int	iA = 10, iB = 20;

	cout << iA << "\t" << iB << endl;

	// ? : 함수와 포인터를 통해 두 숫자를 교환하여 출력하라

	// 힌트 : swap을 이용하라

	int	iTemp	= iA;
		iA		= iB;
		iB		= iTemp;

	cout << iA << "\t" << iB << endl;
}