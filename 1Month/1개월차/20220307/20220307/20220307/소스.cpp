#include <iostream>

using namespace std;

struct tagInfo
{
	char szName[64]; // 구조체 안의 변수 = 맴버변수
	int iA;
	float fB;
	bool bChoice;
	double db;
	//구조체의 크기 = 24 가장큰 자료형으로 하나씩 할당하면서 넣는다.
};

tagInfo* pInfo = &tInfo;

tInfo.sT;
(*pInfo).sT;
pInfo->sT;    pInfo의 맴버인 sT

struct tagTemp
{
	char cName;
	short sBB;
	int iAA;
	long long llCC; //메모리 할당은 기본 자료형일때만 해당
	//long long 2번 + 24byte

	tagInfo tInfo; // 40byte
};

void main(void)
{
	tagInfo tInfo{ "홍길동", 100, 6.27 };
	cout << "이름입력 : ";
	cin >> tInfo.szName; //. : 맴버 접근 연산자
	cout << "int형 변수 입력 : ";
	cin >> tInfo.iA;

	//문자열 역사
	//SBCS ->					MBCS ->		WBCS
//single byte character set		multi		wide byte

	//문자열 길이 반환 함수

	//size_t strlen(char*)
	//size_t strlen(char const* pstr);
	//Null문자를 제외한 순수한 문자열의 길이를 반환하는 함수
	//char szName[64] = "hello";

	//cout << strlen(szName) << endl;
	
	//문자열 복사 함수
	//char szTemp[64] = "";
	//szTemp = "hello"; 문자열 대입은 불가능
	//int strcpy_s(char* _Destination, rsize_t _SizeInBytes, char const* _Source);
	//1인자 : 어디에 복사할 것인가
	//2인자 : 얼마만큼의 크기 공간에 복사할 것인가
	//3인자 : 복사하고자 하는 원본 문자열

	/*strcpy_s(szTemp, sizeof(szTemp), "hello");
	cout << szTemp << endl;*/

	//문자열 결합 함수

	//1인자 : 어디에 복사할 것인가
	//2인자 : 얼마만큼의 크기 공간에 결합할 것인가
	//3인자 : 결합하고자 하는 원본 문자열

	//strcat_s();

	//문자열 비교 함수
	//strcmp

	//구조체 : 여러 자료형을 한데 묶어서 관리하는 사용자 정의 자료형
	//C언어 사용자 정의 자료형 = 구조체 열거체 공용체
							  //Struct enum union
	//c++ 에서는 C언어 3개 + 클래스 해서 총 4개

	
}


/*

char "abcd" = 5byte null값이 생략되어 있기 때문
strcmp = 문자비교 함수인데 문자가 서로 같으면 false를 리턴
그래서 앞에 !(not)연산자를 붙여서 사용한다.

숙제 성적프로그램 구조체를 이용해서 만들기

*/
