#include <iostream>

using namespace std;

void main(void)
{
#pragma region 숙제 풀이
	/*float		fAver = 0.f;
	cout << "평균 값 : ";
	cin >> fAver;

	//int iResult = 0;

	if ((90.f <= fAver) && (100.f >= fAver))
	{
	cout << "A학점" << endl;
	//iResult = 1;
	}

	else if ((80.f <= fAver) && (90.f > fAver))
	{
	cout << "B학점" << endl;
	//iResult = 2;
	}

	else if ((70.f <= fAver) && (80.f > fAver))
	{
	cout << "C학점" << endl;
	}

	else if ((60.f <= fAver) && (70.f > fAver))
	{
	cout << "D학점" << endl;
	}

	else
	cout << "F학점" << endl;*/
#pragma endregion 숙제 풀이

#pragma region if문과 switch문 사용 시 주의 사항

	//int	iTemp = 10, iSour = 20;
	/*if ((iTemp < iSour) && (iSour = 3000))
	cout << iSour << endl;*/

	/*if ((iTemp < iSour) || (iSour = 3000))
	cout << iSour << endl;*/

	/*if ()
	{
	if ()
	{
	switch ()
	{

	}
	}
	}*/

	/*int	iInput = 0;

	cin >> iInput;

	switch (iInput)
	{
	case 1:
		if (1)
		{
			int	iTemp = 10;
			cout << iTemp << endl;
		}
		break;

	case 2:
		/ *iTemp = 20;
		cout << iTemp << endl;
		cout << iSour << endl;* /

		/ *	int		iTemp = 10;
		int		iSour = 20;* /

		/ *iTemp = 20;
		cout << iTemp << endl;* /

		break;
	}*/
	
#pragma endregion if문과 switch문 사용 시 주의 사항

#pragma region goto문

	// goto문은 키워드를 기준으로 실행할 코드와 실행시키지 않을 코드로 분기가 발생한다.
	// 다만 코드 흐름을 강제로 변환하다보니 프로그램 전반에 문제를 야기할 가능성이 커서 프로그래머들이 사용을 꺼려한다.

// 	/*if (1)
// 		goto Home;
// 
// 	if (1)
// 		goto Home;
// 
// 	if (1)
// 		goto Home;
// 
// Home:
// 	cout << "삭제" << endl;*/

#pragma endregion goto문
	


}