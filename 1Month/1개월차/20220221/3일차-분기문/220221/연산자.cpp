#include <iostream>
#include <bitset>

using namespace std;

void main(void)
{
#pragma region 시프트 연산자

	// 시프트 연산자 : 각 비트를 왼쪽, 오른쪽으로 이동시키는 연산자
	// 왼쪽 시프트 연산의 경우 2의 n제곱만큼 곱하기 연산을 수행하며, 오버플로우가 발생하지 않도록 유의해야 한다.
	// 오른쪽 시프트 연산의  경우 2의 n제곱만큼 나누기 연산을 수행한다.
	
	/*int		iTemp = 10;

	cout << bitset<8>(iTemp) << endl;
	cout << "=====================" << endl;
	cout << bitset<8>(iTemp << 2) << endl;*/

#pragma endregion 시프트 연산자

#pragma region 증감 연산자

	// ++, -- : 하나를 증가 또는 감소 시키는 연산자

	// 1. 상수는 증감 연산자를 사용할 수 없다.
	// ex) ++10;

	// 2. 증가 연산자가 붙어있는 위치에 따라 기능이 달라진다.

	/*int	iNumber = 10;

	++iNumber;		// 전위 연산 : 선 연산 후 대입

	iNumber++;		// 후위 연산 : 선 대입 후 연산

	cout << iNumber << endl;*/

	/*int iNumber = 3;

	while (iNumber--)
	{
	cout << 1 << endl;
	}*/

	// 3. 증감 연산자 또한 연달아서 사용이 가능하다.

// 	/*int iNumber = 3;
// 	cout << (++(++iNumber)) << endl;*/

#pragma endregion 증감 연산자

#pragma region 연산자 축약

	// 자기 자신의 값을 변화할 때 연산자의 상태를 줄여서 표기할 수 있다.

	// int	iNumber = 10;

	// iNumber = iNumber + 20;
	// iNumber += 20;	// -, *, /, % 등도 축약형으로 표현이 가능하다

	// cout << iNumber << endl;

#pragma endregion 연산자 축약

#pragma region 삼항 연산자

	// 간단한 조건을 이용하여 값을 도출하고자 할 때 또는 단순 조건식을 해결하고자 할 때 많이 사용된다.
	/*
	int		iNum = 10;
	int		iNum2 = 20;

	int		iResult = 0;

	// 결과  = 조건 ? 참일 경우 반환 : 거짓일 경우 반환
	iResult  = (iNum > iNum2) ? iNum : iNum2;

	cout << iResult << endl;*/

#pragma endregion 삼항 연산자


	int		iKor = 0, iEng = 0, iMath = 0, iTotal = 0;
	float	fAver = 0.f;

	cout << "국어 점수를 입력하세요 : ";
	cin >> iKor;

	cout << "영어 점수를 입력하세요 : ";
	cin >> iEng;

	cout << "수학 점수를 입력하세요 : ";
	cin >> iMath;

	// 형 변환(캐스팅) : 사용자가 프로그램 코드 진행에 따라 원하는 자료형으로 강제적으로 변환하는 것

	iTotal = iKor + iEng + iMath;
	// fAver  = iTotal / 3.f;			// 묵시적 형 변환

	fAver = (float)iTotal / 3.f;		// 명시적 형 변환

	cout << "국어\t영어\t수학\t총점\t평균" << endl;
	cout << iKor << "\t" << iEng << "\t" << iMath << "\t" << iTotal << "\t" << fAver << endl;


}