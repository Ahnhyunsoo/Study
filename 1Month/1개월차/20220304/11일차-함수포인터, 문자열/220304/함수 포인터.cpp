#include <iostream>

using namespace std;

void	Render();

int		Add(int iA, int iB);
int		Minus(int iA, int iB);
int		Mul(int iA, int iB);
int		Div(int iA, int iB);

int		Get_A(int iA);

void main(void)
{
	// 함수 포인터 : 함수의 이름을 저장하기 위한 포인터

	// 배열의 이름은 배열 전체 원소 중 첫 번째 원소의 주소 값
	// 함수의 이름 또한 함수가 등록된 메모리 영역(code영역)의 주소 값에 해당한다.

	// 함수 포인터의 선언

	// 타입(*변수명)(매개변수) : 중간 공백이 있어도 상관없음

	/*void(*ptrVoid)(void) = Render;
	ptrVoid();

	int(*ptrGet_A)(int) = Get_A;
	cout << ptrGet_A(10) << endl;

	int(*ptrAdd)(int, int) = Add;
	cout << ptrAdd(20, 30) << endl;*/

	
#pragma region 함수포인터 사용 예

	/*int iInput = 0;
	int iResult = 0;

	int(*ptrAdd)(int, int) = nullptr;

	cout << "1. 덧셈 2. 뺄셈 3. 곱셈 4.나눗셈 : ";
	cin >> iInput;

	/ *switch (iInput)
	{
	case 1:
		iResult = Add(10, 20);
		break;
	case 2:
		iResult = Minus(10, 20);
		break;
	case 3:
		iResult = Mul(10, 20);
		break;
	case 4:
		iResult = Div(10, 20);
		break;
	}* /

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
	}

	cout << "결과 : " << ptrAdd(10, 20) << endl;*/


#pragma endregion 함수포인터 사용 예

#pragma region 함수 포인터 사용 예 2

	/*int iInput = 0;
	int iResult = 0;

	// 함수 포인터 배열
	int(*ptr[4])(int, int) = { Add, Minus, Mul, Div };

	cout << "1. 덧셈 2. 뺄셈 3. 곱셈 4.나눗셈 : ";
	cin >> iInput;

	cout << "결과 : " << ptr[iInput - 1](10, 20) << endl;*/
	
#pragma endregion 함수 포인터 사용 예 2


}
void	Render()
{
	cout << 1 << endl;
}
int		Get_A(int iA)
{
	return iA;
}


int		Add(int iA, int iB)
{
	return iA + iB;
}
int		Minus(int iA, int iB)
{
	return iA - iB;
}
int		Mul(int iA, int iB)
{
	return iA * iB;
}
int		Div(int iA, int iB)
{
	return iA / iB;
}







