#include <iostream>

using namespace std;

void main(void)
{
	// 분기문 : 기준을 잡아서 나누는 문법
	// if문, switch문, goto문

#pragma region if문
	//int iTemp = 0;
	//cin >> iTemp;

	/*if (iTemp > 10)
	cout << 1 << endl;		// 단일 코드(한 줄짜리 코드)의 경우 중괄호를 생략할 수 있다.
	else						// else 를 사용하려면 반드시 if문이 먼저 만들어져 있어야 가능하다.
	cout << 2 << endl;*/

	/*int	iInput = 0;

	cout << "숫자를 입력하세요(1. 빨강 2. 노랑 3. 파랑) : ";
	cin >> iInput;

	if (1 == iInput)
		cout << "빨강" << endl;

	else if (2 == iInput)		// else if 또한 먼저 if문이 있어야 사용 가능하다
		cout << "노랑" << endl;

	else if (3 == iInput)
		cout << "파랑" << endl;

	else
		cout << "잘못된 입력입니다" << endl;*/

#pragma endregion if문

#pragma region switch문

	// 상수를 이용하여 분기하는 문법, 상수 조건 분기문이라고도 한다.
	// 조건으로 상수 또는 정수만 취급하며, 실수로는 분기 할 수 없다.

	int		iSelect = 0;
	cin >> iSelect;

	/*int	iA = 1, iB = 2, iC = 3;*/

	// switch 문 사용시 case 옆의 값은 반드시 상수가 와야 한다.

	switch (iSelect)
	{
	case 1 :
		cout << "콜라" << endl;
		break;

	case 2 :
		cout << "사이다" << endl;
		break;

	case 3 :
		cout << "환타" << endl;
		break;

	default:
		cout << "잘못 입력하셨습니다" << endl;
		break;
	}
	


#pragma endregion switch문

	


}

// 성적표 입출력 프로그램

// 1.  국,영,수, 총점,평균 구하기
// 2.  if문을 이용하여 평균 점수에 따라 성적 등급을 매긴다.
/*
90점이상 100점 이하인 경우 'A'
80점이상 90점 미만인 경우 'B'
70점이상 80점 미만인 경우 'C'
60점이상 70점 미만인 경우 'D'
나머지 경우 'F'
*/
