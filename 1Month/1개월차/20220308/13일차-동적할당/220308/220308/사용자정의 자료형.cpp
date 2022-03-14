#include <iostream>
#include <windows.h>

using namespace std;

#pragma region 구조체

/*
struct tagInfo
{
	int		iA;		// 멤버 변수

	void	Render()		// 멤버 함수(c++에서 허용하는 문법으로 c시절에는 선언조차 할 수 없었다)
	{
		cout << iA << endl;
	}

};
void main(void)
{
	tagInfo	tInfo;

	tInfo.iA = 100;
	tInfo.Render();

	tagInfo*		pInfo = &tInfo;

	pInfo->iA = 200;
	pInfo->Render();

	//cout << tInfo.iA << endl;
}
*/

#pragma endregion 구조체

#pragma region 공용체
/*

union uniTemp
{
	//short	a;
	int		b;
	//long long c;
	float	d;
};

struct tagInfo
{
	int		iA;
	int		iB;
};

union uniDest
{
	tagInfo	tInfo;
};


void main(void)
{
	uniTemp		uTemp = {10};		// 공용체는 연속된 메모리 공간을 사용하는 자료형이 아니라 가장 큰 메모리 블록크기 만큼만 할당하고 공유하여 사용한다.

	cout << sizeof(uniTemp) << endl;

	//uTemp.c = 200;
	
	// cout << uTemp.a << endl;
	// cout << uTemp.b << endl;
	// cout << uTemp.c << endl;
	// cout << uTemp.d << endl;
}*/

#pragma endregion 공용체

#pragma region 열거체

/*
enum NUMBER
{
	ONE = 1,
	TWO = 110,
	THREE
};

void main(void)
{
	//cout << ONE << endl;
	//cout << TWO << endl;
	//cout << THREE << endl;

	/ *NUMBER		eType = ONE;
	int			iA = THREE;

	cout << sizeof(NUMBER) << endl;
	
	//cout << ONE + TWO << endl;

	for(int i = 0;i < 3; ++i)
		cout << NUMBER(i) << endl;* /
}*/


#pragma endregion 열거체

