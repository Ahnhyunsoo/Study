#include <iostream>
#include <bitset>		// 정수값을 원하는 비트수로 표현하기 위해 포함

using namespace std;

void main(void)
{
	/*int		iKorean = 0;
	int		iEnglish = 0;
	int		iMath = 0;*/

	/*int	iKorean = 0, iEnglish = 0, iMath = 0;

	cout << "국어 점수를 입력하세요 : ";
	cin >> iKorean;

	cout << "영어 점수를 입력하세요 : ";
	cin >> iEnglish;

	cout << "수학 점수를 입력하세요 : ";
	cin >> iMath;

	cout << "=================================" << endl;
	cout << "국어\t영어" << '\t' << "수학" << endl;
	cout << iKorean << '\t' << iEnglish << '\t' << iMath << endl;*/

#pragma region 표기법
	// 변수 이름 짓기 규칙

	/*1. 변수 명은 알파벳과 숫자로 구성할 수 있다. 단, 숫자가 알파벳보다 먼저 올 수 없다. 숫자는 반드시 알파벳 한 개 이산 입력 후 사용 가능
	2. 변수 명은 대소문자를 확실히 구분해야 한다.
	3. 프로그래밍에서 제공하는 기본 키워드로는 이름을 지을 수 없다.
		ex) int	namespace; // 불가능
	4. 공백 또는 특수 문자가 올 수 없다. 단, _는 허용
	5. 같은 이름의 변수로 다시 선언할 수 없다.(재정의)*/
		
	// 1. 헝가리안 표기법 : 변수 명 앞에 각 자료형을 상징하는 문자를 삽입하는 방식
	// ex) int iTemp; float fTemp;

	// 2. 카멜 표기법 : 단어와 단어 사이를 대문자로 구분하는 방법
	// ex) int	playerHp;

	// 3. 파스칼 표기법 : 변수명이 무조건 대문자로 시작, 복합어일 경우 중간에 시작하는 새로운 단어의 첫 글자도 대문자로 표기
	// ex) int PlayerHp;

	// 4. 언더바 표기법 : 단어와 단어 사이에 _를 사용, 주로 함수 매개 변수에 사용
	// ex) void Func(int _iPlayerHp);

#pragma endregion 표기법

#pragma region 연산자

	// 산술 연산자(+, -, *, /, %)
	int a = 10;
	int b = 2;
	if (a % b != 0)


	// int		iTemp = 10 + 20;
	// cout << iTemp << endl;
	/*
	int		iResult = 20 % 6;
	cout << iResult << endl;

	iResult = 20 / 6;
	cout << iResult << endl;*/

	// sizeof 연산자 : 자료형의 크기를 바이트 단위로 계산해주는 연산자
	// 배열의 이름이 연산자를 이용하여 크기를 구할 경우 배열 전체의 크기를 계산해 준다.

	//int	iTemp = 10;

	/*cout << sizeof(char) << endl;
	cout << sizeof(bool) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(iTemp) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(long double) << endl;*/

	//char	A = 'A';
	//char	B = 'B';

	//cout << sizeof(A + B) << endl;	// 다음의 결과는 4바이트가 나온다. char는 정수값을 저장하는 자료형이기도 하다. 현재 수식은 65 + 66이란 상수식이고
									// 결과로 나오는 131은 일반적인 정수타입이기 때문에 컴파일러가 임시 메모리 공간에 int형 크기 만큼의 4바이트를 할당하고 저장한 것에 해당한다.

	// = 대입 연산자(할당 연산자)
	// 1. 연산자를 기준으로 좌항과 우항의 자료형이 반드시 일치해야 한다.
	// 2. 대입 연산자를 기준으로 오른쪽에 있는 데이터가 왼쪽으로 대입이 발생한다.
	
	/*int	iA = 10, iB = 20, iC = 30;
	
	//int iD(40);		// c++초기화 방식
	iA = iB = iC = 200;

	cout << iA << "\t" << iB << "\t" << iC << endl;

	int iTemp = 3.14f;
	cout << iTemp << endl;*/

	// 관계 연산자 : 연산자를 기준으로 좌항과 우항의 결과를 판단하는 연산자, 결과 값으로 참 또는 거짓을 판별
	// <, > <=, >=, ==, !=

	/*int	iTemp = 10, iSour = 20;

	cout << (iTemp < iSour) << endl;		// 1
	cout << (iTemp > iSour) << endl;		// 0 
	cout << (iTemp <= iSour) << endl;		// 1
	cout << (iTemp >= iSour) << endl;		// 0
	cout << (iTemp == iSour) << endl;		// 0	
	cout << (iTemp != iSour) << endl;		// 1*/

	// 논리 연산자 : 연산자를 기준으로 좌항과 우항의 값의 상태에 따라 참 또는 거짓을 반환하는 연산자
	// &&(and), ||(or), !(not)

	// and 연산자 :연산자를 기준으로 양쪽 다 참일 때 참을 반환하는 연산자
/*
	cout << (false && false) << endl;
	cout << (false && true) << endl;
	cout << (true && false) << endl;
	cout << (true && true) << endl;*/


	// or 연산자 : 연산자를 기준으로 한쪽이 참이면 무조건 참을 반환하는 연산자

	/*cout << (false || false) << endl;
	cout << (false || true) << endl;
	cout << (true  || false) << endl;
	cout << (true  || true) << endl;*/


	// not 연산자 : 참을 거짓으로 거짓을 참으로 만들어주는 연산자
	// bool		bChoice = true;
	// cout << (!bChoice) << endl;

#pragma endregion 연산자

#pragma region 비트 단위 연산자

// &(and), |(or), ~(not), ^(xor)

int		iTemp = 10;
int		iSour = 13;
			// <몇 비트로 표기할 것인가>(누구를)
cout << bitset<8>(iTemp) << endl;
cout << bitset<8>(iSour) << endl;

cout << "===========================" << endl;
//cout << bitset<8>(iTemp &iSour) << endl;
//cout << bitset<8>(iTemp |iSour) << endl;
// cout << bitset<8>(iTemp ^ iSour) << endl;
cout << bitset<8>(iTemp ^ iSour) << endl;
cout << (~iTemp) << endl;

#pragma endregion 비트 단위 연산자








		 

}