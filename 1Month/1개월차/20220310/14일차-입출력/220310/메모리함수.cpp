#include <iostream>

using namespace std;

void main(void)
{
	// 메모리 함수 : 메모리 대 메모리 단위로 데이터들을 초기화 또는 복사를 수행하는 함수

	// void* memset(void* pDest, int Value, size_t Size) : 메모리 초기화 함수
	// 1인자 : 초기화하고자하는 데이터의 주소, 2인자 : 바이트 단위로 초기화할 값, 3인자 : 얼마만큼의 크기 공간을 초기화할 것인가
	
	//memset(초기화하고싶은 데이터의 주소 , 바이트 단위로 초기화할 값 , 얼마만큼의 크기의 공간
	//memset = 초기화 해주는 메모리함수
	//memset(초기화할 변수의 대표주소, 초기화할바이트크기, 초기화할 크기)
	//ex) int iArray [5];
	// memset(iArray, 0, sizeof(iArray));

	//memcpy = 값을 복사해주는 메모리함수
	//memcpy = (복사받을 변수의 대표주소, 복사할 원본의 대표주소, 복사할 메모리크기)
	//memcpy (iA, iB, sizeof(iB));

	//memmove = memcpy랑 동작만 다르지 똑같음

	/*int	iarray[5];
	memset(iarray, 0, sizeof(iarray));

	for (int i = 0; i < 5; ++i)
		cout << iarray[i] << endl;*/

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
	//memcpy (복사받을 변수의 대표주소, 복사할 원본의 대표주소, 복사할 메모리크기
	//memmove 도 똑같지만 memcpy는 바로복사 memmove는 임시공간에 복사후 복사
	//memcpy는 윈도우에서만 사용가능 memmove는 윈도우, 리눅스 둘다 사용가능한 표준

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