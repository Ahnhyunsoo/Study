#include <iostream>

using namespace std;

void main(void)
{
	// 포인터 배열 : 포인터를 여러개 선언할 때 사용하는 문법

	// int	iA = 10, iB = 20, iC = 30;
	// int *pA = &iA, *pB = &iB, *pC = &iC;
	// int*	pArray[3] = { &iA, &iB, &iC };

	// 배열 포인터 : 배열의 주소값을 저장하는 포인터

	// int		iArray[3] = { 1,2 ,3 };
	// int*	p = iArray;

	// cout << p[2] << endl;
	// cout << (p + 1) << endl;		// 포인터 연산
	// cout << *(p + 1) << endl;
	// cout << *(iArray + 1) << endl;
	// cout << *(++iArray) << endl;		// 상수인 배열의 이름은 사용할 수 없는 문법

	// 2차원 배열

	int	iArray[2][3] = 
	{ 
		{1, 2, 3}, // [0]
		{4, 5, 6}  // [1]
	 // [0] [1] [2]
	};

	// cout << iArray[1][1] << endl;

	/*cout << (*(iArray + 1))[1] << endl;
	cout << *(iArray[1] + 1) << endl;
	cout << *((*(iArray + 1)) + 1) << endl;*/


	// 2차원 배열의 포인터 형
		// 2차원 배열의 이름은 2중 포인터에 보관할 수 없다. 싱글포인터도 이중포인터도 아니다.

	 //자료형(*변수명)[열] 선언
	 int(*pArray)[3] = iArray;
	 //cout << pArray[1][2] << endl;

	 int*		p = iArray[0];
	 cout << p[1] << endl;
}

// 1. 2차원 배열을 이용하여 90도 시계방향으로 4회전하여 출력하기
/*
1	2	3			7	4	1			9	8	7
4	5	6	(1회전)	8	5	2 (2회전)	6	5	4
7	8	9			9	6	3			3	2	1	*/

// 2. 빙고 게임

/*
- 5 * 5 배열을 이용하여 1~25 숫자를 랜덤하게 출력
- 숫자를 선택해서 입력하면 일치하는 숫자는 *로 출력
- *로 표시된 숫자가 가로, 세로, 대각선으로 5개가 될때마다 빙고가 하나 증가
- 5빙고가 되면 승리로 종료

*/
/*
1	2	3				1	2	3
4	5	6	6을 입력		4	5	*
7	8	9				7	8	9
									*/