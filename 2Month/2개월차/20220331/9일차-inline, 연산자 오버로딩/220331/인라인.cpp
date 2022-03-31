// 220331.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#define			SQUARE(x) x * x

inline int		Square(int iX)		
{
	return iX * iX;
}

int main()
{
	// 일반화 프로그래밍 : 데이터 형식에 의존하지 않고, 하나의 값이 여러 다른 데이터 타입들을 가질 수 있는 기술에 중점을 두어 재사용성을 높일 수 있는 프로그래밍 방식

	// 인라인 함수 : 컴파일 시점에 함수 호출위치에 바로 함수 코드를 삽입하는 형태의 함수
	// 매크로와 달리 자료형에 자유로울 수 없다.

	// 인라인 함수를 선언했더라도 일반 함수로 바뀌는 경우
	
	// 1. 인라인 함수를 함수 포인터로 활용할 때
	// 2. 인라인 함수를 재귀 형태로 호출할 때


	cout << SQUARE(10) << endl;	// 매크로는 단순 치환의 기능을 갖고 있다.

	cout << Square(20) << endl;


    return 0;
}

