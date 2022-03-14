#include <iostream>

using namespace std;

struct tagInfo			// 24
{
	//char		szName[64];		// 멤버 변수

	bool		bChoice;
	short		sT;
	int			iA;				// 멤버 변수
	float		fB;				// 멤버 변수
	double		dbTemp;
};

struct  tagTemp
{
	char	cName;
	short	sBB;
	long long llCC;

	tagInfo		tInfo;		// 사용자 정의 자료형은 구조체 메모리 할당 정책을 따르지 않는다.
};

void main(void)
{
	// 구조체 : 여러 자료형을 한데 묶어서 관리하는 사용자 정의 자료형

	//cout << sizeof(tagInfo) << endl;
	//cout << sizeof(tagTemp) << endl;

	tagInfo		tInfo = { "홍길동", 100, 6.27f };
	//tagInfo		tInfo = { "" };

	/*cout << "이름 입력 : ";
	cin >> tInfo.szName;		// . : 멤버 접근 연산자

	cout << "int형 변수 입력 : ";
	cin >> tInfo.iA;

	cout << "float형 변수 입력 : ";
	cin >> tInfo.fB;*/

	/*cout << tInfo.szName << endl;
	cout << tInfo.iA << endl;
	cout << tInfo.fB << endl;*/

// 	/*tagInfo*		pInfo = &tInfo;
// 
// 	tInfo.sT;
// 	(*pInfo).sT;
// 	pInfo->sT;
// */

}