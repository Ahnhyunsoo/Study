#include <iostream>

using namespace std;

void main(void)
{
	int iKor = 0;
	int iEn = 0;
	int iMath = 0;
	int iSum = 0;
	int iAvg = 0;
	

	cout << "국어 점수를 입력하세요 : ";
	cin >> iKor;
	cout << "영어 점수를 입력하세요 : ";
	cin >> iEn;
	cout << "수학 점수를 입력하세요 : ";
	cin >> iMath;

	cout << fixed;
	cout.precision(4);

	cout << "=========================" << endl;
	
	iSum = iKor + iEn + iMath;
	iAvg = (iKor + iEn + iMath) / 3;
	
	cout << "세 과목의 총합 : " << iSum << endl;    
	cout << "세 과목의 평균 : " << iAvg << endl;


#pragma region 스위치문
	switch (iAvg/10) 
	{

	case 10: case 9: 
		cout << "A입니다" << endl;
		break;
	case 8:
		cout << "B입니다" << endl;
		break;
	case 7:
		cout << "C입니다" << endl;
		break;
	case 6:
		cout << "D입니다" << endl;
		break;
	default :
		cout << "F입니다" << endl;
		break;

	}
	
	//ABCD F 100 90 80 90
#pragma endregion 스위치문


#pragma region if문

	if (iAvg >= 90 && iAvg < 100)
	{
		cout << "A" << endl;
	}
	else if (iAvg >= 80 && iAvg < 90)
	{
		cout << "B" << endl;
	}
	else if (iAvg >= 70 && iAvg < 80)
	{
		cout << "C" << endl;
	}
	else if (iAvg >= 60 && iAvg < 70)
	{
		cout << "D" << endl;
	}
	else if(iAvg >= 0 && iAvg < 60)
	{
		cout << "F" << endl;
	}
	else
	{
		cout << "점수를 잘못입력하셨습니다" << endl;
	}
	
		
	
#pragma endregion if문




}