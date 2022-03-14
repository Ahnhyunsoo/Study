#include <iostream>

using namespace std;

void main(void)
{
	/*
	float fAver = 0.f;
	cout << "평균 값 : ";
	cin >> fAver;

	int iResult = 0;

	if ((90.f <= fAver) && (100.f > fAver))
	{
			cout << "A학점" << endl;
	}
	else if ((80.f <= fAver) && (90.f > fAver))
	{
		cout << "B학점" << endl;
	}
	if ((70.f <= fAver) && (80.f > fAver))
	{
		cout << "C학점" << endl;
	
	if ((60.f <= fAver) && (70.f >= fAver))
	{
		cout << "D학점" << endl;
	}
	else {
		cout << "F학점" << endl;
	}
	}
	*/

	/*
	int iTemp = 10, iSour = 20;

	if ((iTemp < iSour) && (iSour = 3000))
		cout << iSour << endl; //= 3000 // 둘다 참이여야 반환이니 뒤에값도 트루여서 뒤의값을 반환
	

	if ((iTemp < iSour) || (iSour = 3000))
		cout << iSour << endl; //= 20 둘중하나라도 참이면 반환이니 뒤에값을 볼필요없다.
	*/ //if문과 switch 사용시 주의사항

#pragma region 고투문
	//go to 문은 키워드를 기준으로 실행할 코드와 실행시키지 않을 코드로 분기가 발생한다.
	//다만 코드 흐름을 강제로 변환하다보니 프로그램 전반에 문제를 야기할 가능성이 커서 프로그래머들이 사용을 꺼린다.
	goto Temp;

	cout << 1 << endl;

Temp :

	cout << 2 << endl;

#pragma endregion 고투문


	

	

}
