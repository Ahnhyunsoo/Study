#include <iostream>
#include <windows.h>

using namespace std;

#pragma region ����ü

/*
struct tagInfo
{
	int		iA;		// ��� ����

	void	Render()		// ��� �Լ�(c++���� ����ϴ� �������� c�������� �������� �� �� ������)
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

#pragma endregion ����ü

#pragma region ����ü
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
	uniTemp		uTemp = {10};		// ����ü�� ���ӵ� �޸� ������ ����ϴ� �ڷ����� �ƴ϶� ���� ū �޸� ���ũ�� ��ŭ�� �Ҵ��ϰ� �����Ͽ� ����Ѵ�.

	cout << sizeof(uniTemp) << endl;

	//uTemp.c = 200;
	
	// cout << uTemp.a << endl;
	// cout << uTemp.b << endl;
	// cout << uTemp.c << endl;
	// cout << uTemp.d << endl;
}*/

#pragma endregion ����ü

#pragma region ����ü

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


#pragma endregion ����ü

