#pragma region 전처리기

/*
#include <iostream>

// 강제 치환 : 컴파일 타임 이전에 해당 매크로 위치에 값이 그대로 치환된다.
// 상수 매크로
//#define			PI		3.14f

// 함수 매크로 : 자료형과 상관없이 그대로 치환(모든 자료형 호환)
// 연산자 우선순위를 생각하여 소괄호로 묶어줘야 한다.
// 한 줄짜리 코드를 만들 때 주로 사용(간단한 함수를 자주 사용할 때 만든다.)

// 단점 : 전처리기이다 보니 디버깅에 어려움이 있다.
// 복잡한 함수를 구성하기가 까다롭다.

//#define			SQUARE(X)	X * X
//#define			SQUARE(X)	((X) * (X))

// 두 줄 이상의 함수 매크로의 경우 역슬러쉬를 삽입하여 1줄 띄어쓰기가 가능하다.
// 만약 여러줄일 때 줄 끝에 역슬러쉬를 삽입하지 않으면 1줄만 매크로로 인식한다.
/ *
#define			SQUARE(X)	\
				((X) * (X))					
* /

//#define			SAFE_DELETE(p) if(p) { 	delete p; 	p = nullptr; }

// 함수 매크로를 이용한 문자열 치환
//#define			STRINGTEMP(A, B)		A"의 직업은" B "입니다."
//#define			STRINGTEMP(A, B)		#A"의 직업은" #B "입니다."
//#define		COMBINE(A, B)		A##00##B

using namespace std;

void main(void)
{
	//cout << PI << endl;

	//cout << SQUARE(5) << endl;
	//cout << SQUARE(0.1f) << endl;
	//cout << SQUARE(2 + 2) << endl;
	//cout << STRINGTEMP(이순신, 장군) << endl;
	//cout << COMBINE(11, 22) << endl;
}*/

#pragma endregion 전처리기

#pragma region 조건부 컴파일

/*
#if(조건) : if문의 시작과 동일한 기능
#elif(조건) : elseif문과 동일
#else
#endif : 조건부 컴파일 종료

#ifdef : define으로 정의되어 있다면 실행
#elif() : define으로 정의되어 있다면 실행
#else  : 모두 정의되어 있지 않다면 실행
#endif : 조건부 컴파일 종료

#ifndef 
#endif : 조건부 컴파일 종료*/

//#define		TEST 3

/*
void main(void)
{
#if 5 > TEST
	cout << "작다" << endl;

#elif 5 < TEST
	cout << "크가" << endl;

#else
	cout << "같다" << endl;

#endif

}*/



#include <iostream>

using namespace std;

void main(void)
{
/*
#ifdef _DEBUG
	cout << "Hello" << endl;

#endif // _DEBUG*/
}




#pragma endregion 조건부 컴파일

#pragma region 레퍼런스

/*
#include <iostream>

using namespace std;

void main(void)
{
	int			iA = 10;
	int			iB = 20;

	int&		r = iA;		// 레퍼런스는 오직 하나의 값만 참조한다.
	int&		r2 = iB;

	//int*	const p = &iA;

	r = 200;

	r = iB;

	//r = 4000;

	cout << iA << endl;
	cout << iB << endl;
}*/

#pragma endregion 레퍼런스