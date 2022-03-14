#include <iostream>

using namespace std;
void main(void)
{
#pragma region if문
	//분기문 : 기준을 잡아서 나누는 문법
	// if문, switch문, goto문

	/*
	int iTemp = 0;
	//cin >> iTemp;

	if (iTemp > 10)
		cout << 1 << endl; //단일 코드 (한 주라ㅉ리 코드)의 경우 중광호를 생략할 수 있다.
	else				   //else 를 사용하려면 반드시 if문이 먼저 만들어져 있어야 한다.
		cout << 2 << endl;
	*/

	int iInput = 0;

	cout << "숫자를 입력하세요(1. 빨강 2. 노랑 3. 파랑) : ";
	cin >> iInput;

	if (1 == iInput) // if = 개별적인 처리 하나가 true여도 다른값도 true 가능, else if = 공통적인 처리 하나가 true면 나머지 false
		cout << "빨강" << endl;
	else if (2 == iInput)	// else if 또한 먼저 if문이 있어야 사용 가능하다.
		cout << "노랑" << endl;
	else if (3 == iInput)
		cout << "파랑" << endl;
	else
		cout << "잘못된 입력입니다." << endl;
#pragma endregion if문

#pragma region switch문

	// 상수를 이용하여 분기하는 문법, 상수 조건 분기문이라고도 한다.
	// 조건으로 상수 또는 정수만 취급하며, 실수로는 분기할 수 없다.

	int iSelect = 0;
	cin >> iSelect;

	//int iA = 1, iB = 2, iC = 3;

	switch (iSelect) // switch문 사용시 case 옆의 값은 반드시 상수가 와야 한다.
	{
	case 1 :
		cout << "콜라 " << endl;
		break;
	case 2 :
		cout << "사이다 " << endl;
		break;
	case 3 :
		cout << "환타 " << endl;
		break;

	default :
		cout << "잘못입력하셨습니다." << endl;
		break;
	}

	/*
	if (1)
	{
		cout << 1 << endl;
		break;
		cout << 2 << endl;
		}
	*/

}


// 성적표 입출력 프로그램

// 1. 국,영,수 총점,평균 구하기
// 2. if문을 이용해서 평균 점수에 따라 성적 등급을 매긴다.
// 90점 이상 100점이하인 경우 'A'
// 80점 이상 90점미만인 경우 'B'
// 70점 이상 80점미만인 경우 'C'
// 60점 이상 70점미만인 경우 'D'
// 나머지의 경우 'F'
//디테일하게 조건 더 넣어도 된다. 예외처리


