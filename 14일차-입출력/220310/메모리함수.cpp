#include <iostream>

using namespace std;

void main(void)
{
	// 메모리 함수 : 메모리 대 메모리 단위로 데이터들을 초기화 또는 복사를 수행하는 함수

	// void* memset(void* pDest, int Value, size_t Size) : 메모리 초기화 함수
	// 1인자 : 초기화하고자하는 데이터의 주소, 2인자 : 바이트 단위로 초기화할 값, 3인자 : 얼마만큼의 크기 공간을 초기화할 것인가
	
	/*int	iArray[5];
	memset(iArray, 0, sizeof(iArray));

	for (int i = 0; i < 5; ++i)
		cout << iArray[i] << endl;*/

	/*int	iA = 0;
	memset(&iA, 1, sizeof(int));

	cout << iA << endl;*/			// 바이트 단위로 2인자 값으로 초기화 하기 때문에 우리가 원하는 결과와 다른 결과값이 도출된다.

	// void* memcpy(void* pDest, const void* pSrc, size_t Size) : 메모리 복사 함수
	// 1인자 : 복사 받을 변수의 시작 주소 2인자 : 복사를 수행할 원본 변수의 주소, 3인자 : 복사할 메모리 크기

	//int	iSrc[5] = { 1, 2,3,4,5 };
	//int	iDest[5] = {};

	/*for (int i = 0; i < 5; ++i)
	{
		iDest[i] = iSrc[i];
		cout << iDest[i] << endl;
	}*/

	/*memcpy(iDest, iSrc, sizeof(iSrc));

	for (int i = 0; i < 5; ++i)
	{
		cout << iDest[i] << endl;
	}*/


	// void* memmove(void* pDest, const void* pSrc, size_t Size) : 메모리 이동 함수
	// 1인자 : 복사 받을 변수의 시작 주소 2인자 : 복사를 수행할 원본 변수의 주소, 3인자 : 복사할 메모리 크기

	//int	iSrc[5] = { 1, 2,3,4,5 };
	//int	iDest[5] = {};

	/*for (int i = 0; i < 5; ++i)
	{
	iDest[i] = iSrc[i];
	cout << iDest[i] << endl;
	}*/

	/*memmove(iDest, iSrc, sizeof(iSrc));

	for (int i = 0; i < 5; ++i)
	{
		cout << iDest[i] << endl;
	}*/

//	memcpy와 memmove의 차이점

// - memcpy는 바로 복사, memmove는 임시 버퍼에 이동 후에 복사를 수행
// - memcpy의 경우 linux 운영체제에서 사용 불가, memmove의 경우 window, linux 모두 사용 가능한 표준 스펙

}