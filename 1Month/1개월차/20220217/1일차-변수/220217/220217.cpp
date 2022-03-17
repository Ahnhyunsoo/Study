#include <iostream>

using namespace std;

void main(void)
{
	/*int sjw = 10;

	cout << sjw << endl;*/
	// 상수 : 사회 구성원들의 결정 하에 변하지 않는 숫자고 약속해 놓은 것
	
	// 리터럴 상수 :  10, 'A'
	// 심볼릭 상수 : 프로그램 코드에 의해서 문법적으로 상수화되어진 숫자를 의미 (ex) #define, const, enum

	// 변수 : 코드의 흐름에 따라 값이 변할 수 있는 숫자
	// 프로그래밍 시 숫자를 메모리 공간에 저장을 해둬야 하는데 이때 메모리 공간의 값은 코드의 흐름에 따라 바뀔 수 있다.

	// 자료형 : 어떤 데이터를 얼마만큼의 메모리 공간을 저장할지 나누기위한 형태

	// 기본 자료형의 종류(원시 데이터 형)

	// 정수 타입 : short(2byte), int(4byte), long(4byte), longlong(8byte)
	// 실수 타입 : float(4byte), double(8byte), (long double(8byte))
	// 글자 타입 : char 'A' 'B' 'C'   글자 1개씩 'A' 'ABC'
	// 논리 타입 : bool 값이 있으면 참 없으면 거짓 
	
	


	// 컴퓨터의 기본적인 용량 단위

	// int형 변수 iTemp를 '선언'하다.
	//int	iTemp;

	//cout << iTemp << endl;

	// short형 변수 sDest를 '선언과 동시에 초기화'하다.
	// 65536개 : -32768 ~ 32767
	//			0 ~65535

	// 정수 타입 자료형 앞에는 signed가 생략되어 있다. 그래서 음수, 양수 모두 표기 및 저장이 가능하다.
	// 만약 양수 타입의 값만 저장하고 싶을 경우 unsigned를 붙여서 의식적으로 양수를 저장하겠다고 알려줘야 한다.
	
	// unsigned short	sDest = 40000;
	// cout << sDest << endl;
	//	long	dTemp = 10l;

	// 실수 타입 자료형 앞에는 표식을 붙일 수 없다.
	// 일반적으로 게임 제작 시에는 float 변수를 많이 사용하고 사용 시점에 f를 붙여서 float형의 실수 값인 것을 알려주자.

	// float		fDelta = 3.14f;
	//float		fDelta = 2.f;
	//cout << fDelta << endl;

	//double		dTest = 6.2865;
	//double		dTest = 0.0;
	//cout << dTest << endl;

	/*char name = 'A';
	char name2 = 'B';
	
	cout << name + name2 << endl;*/
		

	// 문자 타입 자료형 : 아스키 코드표와 연동되어 0~127번에 해당하는 문자 값을 사용할 수 있다.
	// 아스키코드에 존재하는 단 한 글자만 저장할 수 있는 1byte 용량을 가지고 있다.
	
		0101010
		char 'A' 65 << 1byte 8bit
		00000010 10 1 2
		00100010 2 34
		11111111
		0~255 255
		1byte = 8bit
		1kbyte
		1024byte
		1m 
		1024kb

	// char cName = 'a';
	// cout << cName << endl;

	// 논리 자료형 : 참과 거짓을 표현하기 위한 자료형, 1byte 자료형

	// bool	bChoice = 0.100231;
	// cout << bChoice << endl;


	// 변수의 속성 : 코드의 흐름에 따라 최종적으로 갖는 값이 바뀔 수 있다.
	/*int		iTest = 0;
	cout << iTest << endl;
	iTest = 10;
	cout << iTest << endl;*/


	0
		/*int		iInput = 0;

		cin >> iInput;
		cou


		t << iInput << endl;*/
		;
}