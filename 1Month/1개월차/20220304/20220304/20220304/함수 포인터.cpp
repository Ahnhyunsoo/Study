#include <iostream>

using namespace std;

void Render();
int Add(int iA, int iB);
int Minus(int iA, int iB);
int Mul(int iA, int iB);
int Div(int iA, int iB);


int Get_A(int iA);

void main(void)
{
	/*함수 포인터 : 함수의 이름을 저장하기 위한 포인터

	배열의 이름은 배열 전체 원소 중 첫 번째 원소의 주소 값
	함수의 이름 또한 함수가 등록된 메모리 영역(code영역)의 주소 값에 해당한다.*/
	//cout << Render;   //() = 함수 호출 연산자

	// 함수 포인터의 선언

	//타입(*변수명)(매개변수) : 중간 공백이 있어도 상관없음
	/*void(*ptrVoid)(void) = Render;
	ptrVoid();

	int(*ptrGet_A)(int) = Get_A;
	cout << ptrGet_A(10) << endl;

	int(*ptrAdd)(int, int) = Add;
	cout << ptrAdd(20, 30) << endl;*/

#pragma region 함수포인터 사용 예
	/*int iInput = 0;
	int iResult = 0;
	cout << "1. 덧셈 2. 뺄셈 3. 곱셈 4. 나눗셈 : ";
	cin >> iInput;

	int(*ptrAdd)(int, int) = Add;

	switch (iInput)
	{
	case 1:
		ptrAdd = Add;
		break;
	case 2:
		ptrAdd = Minus;
		break;
	case 3:
		ptrAdd = Mul;
		break;
	case 4:
		ptrAdd = Div;
		break;
	}*/
	int iInput = 0;
	+
	int(*ptr[4])(int, int) = { Add,Minus,Mul,Div }; // 16바이트

	cin >> iInput;
	cout << ptr[iInput - 1](10, 20) << endl;


	

}

void Render()
{
	cout << 1 << endl;
}

int Add(int iA, int iB)
{
	return iA + iB;
}

int Get_A(int iA)
{
	return iA;
}


int Minus(int iA, int iB)
{
	return iA - iB;
}
int Mul(int iA, int iB)
{
	return iA * iB;
}
int Div(int iA, int iB)
{
	return iA / iB;
}

/*
1. 0 숫자 이동
5 * 5 배열로 0 ~ 24 까지 출력
2(아래) 4(왼쪽) 6(오른쪽) 8(위쪽)으로 숫자 0을 이동

빙고 했으면 비슷하게 할 수 있다.

더이상 갈 공간이 없으면 이동하지 않는다.
0	1	2			1	0	2			1	4	2			1	4	2
3	4	5	6번입력 3	4	5 2번 입력	3	0	5 4번 입력  0	3	5
6	7	8			6	7	8			6	7	8			6	7	8


2. 문자열을 입력 받아 null문자를 제외한 순수 문자열의 길이를 구하는 함수를 만들어라(strlen 사용 금지)

3. 입력 받은 문자열을 뒤집는 함수 만들기
ex jusin 을 입력받으면 nisuj로 출력

종료 전엔 무한 반복
4. 3명의 입력 가능한 성적표 프로그램 만들기(이름, 국어, 영어, 수학, 총점, 평균) (구조체 사용 금지)

1. 입력 2. 전체 출력 3. 검색 출력 4. 종료






*/