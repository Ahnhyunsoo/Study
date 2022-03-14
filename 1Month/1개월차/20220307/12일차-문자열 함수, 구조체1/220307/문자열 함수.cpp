#include <iostream>

using namespace std;

void main(void)
{
	// 문자열 역사
	// SBCS -> MBCS -> WBCS

	// 문자열 길이 반환 함수
	// size_t strlen(char const* pstr);
	// null문자를 제외한 순수한 문자열 길이를 반환하는 함수

	// char	szName[64] = "hello";
	// cout << strlen(szName) << endl;


	// 문자열 복사 함수

	//char	szTemp[64] = "asdgasdgsadgsdagsdagsadgsdagsadg";
	//char	szSour[64] = "hello";
	/* szTemp = "hello"; 문자열 대입은 불가능

	 int strcpy_s(char* _Destination, rsize_t     _SizeInBytes,  char const* _Source);
	 1인자 : 어디에 복사할 것인가
	 2인자 : 얼마만큼의 크기 공간에 복사할 것인가
	 3인자 : 복사하고자하는 원본 문자열*/

	//strcpy_s(szTemp, sizeof(szTemp), szSour);
	//cout << szTemp << endl;
	//cout << szSour << endl;


	// 문자열 결합 함수

	//char	szSour[64] = "hello";
	//char	szTemp[64] = "world";

	//errno_t strcat_s(char*       _Destination, rsize_t     _SizeInBytes, char const* _Source)
	
	// 1인자 : 어디에 결합할 것인가
	// 2인자 : 얼마만큼의 크기 공간에 결합할 것인가
	// 3인자 : 결합하고자하는 원본 문자열
	
	//strcat_s(szSour, sizeof(szSour), szTemp);

	//cout << szSour << endl;
	//cout << szTemp << endl;


	// 문자열 비교 함수
	// int __cdecl strcmp(char const* _Str1,char const* _Str2)
	// 인자값 두개를 비교하여 일치할 경우 0을, 불일치인 경우 1을 반환
/*

	char	szSour[64] = "hello";
	char	szTemp[64] = "hello";

	if (!strcmp(szSour, szTemp))
	{
		cout << "일치" << endl;
	}
	else
		cout << "불일치" << endl;*/

}