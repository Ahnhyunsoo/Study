#include <iostream>

using namespace std;

void main(void)
{
	// 문자 : 아스키 코드 한 글자, '' 묶어서 표현
	// 문자열 : 2바이트 이상의 글자, "" 묶어서 표현

	//char szName[5] = {'j','u','s','i','n'};
	////'\0' = null 문자(문자열의 끝을 알려주는 기호)


	//for (int i = 0; i < 5; ++i)
	//{
	//	cout << szName[i];
	//}

	//char* pName = "jusin"; //동해물과 백두산이 = 문자열 상수

	////cout << pName << endl;

	////포인터를 통해 널문자를 만날 때까지 반복문을 실행한 예
	//for (int i = 0; '\0' != pName[i]; ++i)
	//	cout << pName[i];
	//
	//pName[2] = 'A'; // 상수인 문자열을 바꿀 수 없다(읽기 전용이기 때문)

	//for (int i = 0; '\0' != pName[i]; ++i)
	//	cout << pName[i];

	//문자열 상수 포인터 배열

	/*char* pArray[3] = { "jusin", "game", "academy" };

	for (int i = 0; i < 3; ++i)
		cout << pArray[i];*/

	/*문자 배열과 문자열 상수의 차이점
	둘 다 문자열의 시작 주소를 갖고 있다는 측면은 동일
	문자 배열 : 글자 하나하나를 배열의 원소로 담음
	문자 배열은 const가 * 뒤에 붙은 경우와 동일 (int* const p) 와 동일

	문자열 상수 : 데이터 영역에 등록된 문자열의 시작 주소를 담고 있다.
	문자열 상수는 const가 * 앞에 붙은 경우와 동일 (const int* p)와 동일*/

}