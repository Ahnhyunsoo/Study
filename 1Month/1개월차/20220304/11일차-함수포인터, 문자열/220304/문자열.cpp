#include <iostream>

using namespace std;

void main(void)
{
	// 문자 : 아스키 코드 한 글자, ''묶어서 표현
	// 문자열 : 2바이트 이상의 글자, ""묶어서 표현


	// char	szName[6] = {'j', 'u', 's', 'i', 'n'};
	// '\0' = null문자(문자열의 끝을 알려주는 기호)

	//char	szName[6] = "jusin";
	/*for (int i = 0; i < 10; ++i)
		cout << szName[i] << endl;*/
	
	// cout << szName << endl;

	// 문자열 상수

	/*char	szName[128] = "";

	cout << "글자 입력 : ";
	cin >> szName;

	cout << szName << endl;*/
	
	// char* pName = "jusin"; jusin 컴파일타이밍에 jusin 문자열을 어딘가에 주소를 할당을해놔
	// cout << pName << endl;

	// 포인터를 통해 널문자를 만날 때까지 반복문을 실행한 예
	/*for (int i = 0; '\0' != pName[i]; ++i)
		cout << pName[i];

	pName[2] = 'A';	// 상수인 문자열을 바꿀 수 없다(읽기 전용이기 때문)

	cout << "=============================" << endl;
	for (int i = 0; '\0' != pName[i]; ++i)
		cout << pName[i];*/


	// 문자열 상수 포인터 배열

	char*	pArray[3] = { "jusin", "game", "academy" };

	for (int i = 0; i < 3; ++i)
		cout << pArray[i]; 


	// 문자 배열과 문자열 상수의 차이점

	// 둘 다 문자열의 시작 주소를 갖고 있다는 측면은 동일
	// 문자 배열의 경우 글자 하나하나를 배열의 원소로 담음
	// 문자 배열의 이름은 const가 * 뒤에 붙은 경우와 동일 (int* const p)와 동일
	
	// 문자열 상수는 데이터 영역에 등록된 문자열의 시작 주소를 담고 있다.
	// 문자열 상수는 const 가 * 앞에 붙은 경우와 동일 (const int* p)와 동일
}

/*
1. 0 숫자 이동

- 5 * 5 배열로 0~24까지 출력
- 2(아래) 4(왼쪽) 6(오른쪽) 8(위쪽)으로 숫자 0을 이동

0	1	2				1	0	2				1	4	2				1	4	2
3	4	5	-> 6번 입력	3	4	5 -> 2번 입력		3	0	5 -> 4번 입력		0	3	5
6	7	8				6	7	8				6	7	8				6	7	8

2. 문자열을 입력 받아 null문자를 제외한 순수 문자열의 길이를 구하는 함수를 만들어라(strlen 사용 금지)

3. 입력 받은 문자열을 뒤집는 함수 만들기
- jusin -> nisuj 

4. 3명의 입력 가능한 성적표 프로그램 만들기(이름, 국어, 영어, 수학, 총점, 평균)(구조체 사용 금지)
- 1. 입력 2. 전체 출력 3. 검색 출력 4. 종료

*/

