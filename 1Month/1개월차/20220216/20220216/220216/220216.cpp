#include <iostream>		// 전처리기 : 컴파일 이전 시점에 수행하는 작업

// using std::cout;
// using std::endl;

 using namespace std;		// c++에서 제공하는 namespace를 이용하여 어느 공간에 만들어진 문법인지를 명시적으로 알려주는 문법
							// 단일 주석 : 한줄짜리 코드를 컴파일러가 인식하지 못하게 함
							/*  범위 주석 : 범위 내에 있는 코드들을 모두 주석화 함 */

// :: 스코프연산자(범위지정 연산자)
void main(void)
{
	std::cout << "Hello World" << std::endl;
	std::cout << "Hello World" << std::endl;

	cout << "Hello World" << '\n';
}



