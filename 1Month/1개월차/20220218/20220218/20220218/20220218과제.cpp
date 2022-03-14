#include <iostream>

using namespace std;

#pragma region 과제
void main(void)
{
	int iKorean = 0, iEnglish = 0, iMath = 0, iSum = 0; //정수형 변수선언 및 초기화
	float fAvg = 0.f; // 실수형 변수 선언 및 초기화
	
	cout << "=========================" << endl;
	cout << "국어 점수를 입력하세요 : ";
	cin >> iKorean; // 값을 입력받아 변수에 저장
	cout << "영어 점수를 입력하세요 : ";
	cin >> iEnglish; // 값을 입력받아 변수에 저장
	cout << "수학 점수를 입력하세요 : ";
	cin >> iMath; // 값을 입력받아 변수에 저장
	cout << '\n';
	
	iSum = iKorean + iMath + iEnglish; // 처음에 선언하면 입력받은 값이 없으니 값을 입력 받은 후 변수 초기화
	fAvg = (iKorean + iMath + iEnglish) / 3.0f; // 처음에 선언하면 입력받은 값이 없으니 값을 입력 받은 후 변수 초기화
						//3으로 나누면 결과가 정수값만 나오므로 소수로 나누기
						//소수의 기본자료형은 double이므로 f를 붙혀서 float형으로 만들어주기


	cout << fixed; 
	cout.precision(4); //precision(소숫점몇자리까지표현)

	cout << "세 과목의 총합 : " << iSum << "점" << endl;
	cout << "세 과목의 평균 : " << fAvg << "점" << endl;
	cout << "=========================" << endl;
	

}
#pragma endregion 과제