#include <iostream>

using namespace std;

void main(void)
{
	//메모리함수 : 메모리 대 메모리 단위로 데이터들을 초기화 또는 복사를 수행하는 함수

	// void* memset(void* pDest, int Value, size_t Size) : 메모리 초기화 함수
	//1인자 : 초기화하고자하는 데이터의 주소
	//2인자 : 바이트 단위로 초기화할 값
	//3인자 : 얼마만큼의 크기를 초기화 할 것인지
	//바이트단위 초기화이므로 주의해야한다

	/*int iArray[5];
	memset(iArray, 0, sizeof(iArray));
	for (int i = 0; i < 5; ++i)
		cout << iArray[i] << endl;*/ 
// 바이트 단위로 2인자 값으로 초기화 하기 때문에 우리가 원하는 값이 안나온다.

	/*void* memcpy(void* pDest, const void* pSrc, size_t Size) : 메모리 복사 함수
	1인자 : 복사 받을 변수의 시작 주소
	2인자 : 복사를 수행할 원본 변수의 주소
	3인자 : 복사할 메모리*/

	/*int iSrc[5] = { 1,2,3,4,5 };
	int iDest[5] = {};

	memcpy(iDest, iSrc, sizeof(iSrc));
	for(int i = 0; i < 5; ++i)
	{
		cout << iDest[i] << endl;
	}*/

	//memmove = 메모리 복사함수

	//memcpy = 원본에서 사본에 바로바로 복사
	//memmove = 원본에서 임시공간에 옮기고 옮긴 임시데이터를 사본에 복사

	//memcpy의 경우 linux 운영체제에서 사용 불가,
	//memmove의 경우 window, linux 모두 사용가능한 표준 스팩
	
	

}