#include <iostream>
#include <random>

using namespace std;

void main(void)
{

#pragma region 과제 1번
	/* 가위바위보 게임 
	난수 0~2 까지 생성
	1가위 2바위 3보 입력받아 승 패 무 판별
	총5라운드 진행(문법은 자율)
	*/
	//random_device random;
	//mt19937 rd(random());
	//uniform_int_distribution<int> range(1, 3);
	//

	//int iRandom = 0; // 난수를 저장하는 변수
	//int iNum = 0; // 가위바위보를 판별하는 변수
	//int iWin = 0; // 승리를 저장하는 변수
	//int iLose = 0; // 패배를 저장하는 변수
	//int iDraw = 0; // 무승부를 저장하는 변수

	//for (int i = 0; i < 5; ++i) {
	//	iRandom = range(rd);
	//	cout << "  가위바위보 게임입니다  " << endl;
	//	cout << "1.가위 2.바위 3.보 4.종료" << endl;
	//	cin >> iNum;
	//	system("cls");

	//	if (iNum == 1) {
	//		if (iRandom == 3)
	//		{
	//			iWin += 1;
	//		}
	//		if (iRandom == 2)
	//		{
	//			iLose += 1;
	//		}
	//		if (iRandom == 1)
	//		{
	//			iDraw += 1;
	//		}
	//	}
	//	
	//	if (iNum == 2) {
	//		if (iRandom == 1)
	//		{
	//			iWin += 1;
	//		}
	//		if (iRandom == 3)
	//		{
	//			iLose += 1;
	//		}
	//		if (iRandom == 2)
	//		{
	//			iDraw += 1;
	//		}
	//	}

	//	if (iNum == 3) {
	//		if (iRandom == 2)
	//		{
	//			iWin += 1;
	//		}
	//		if (iRandom == 1)
	//		{
	//			iLose += 1;
	//		}
	//		if (iRandom == 3)
	//		{
	//			iDraw += 1;
	//		}
	//	}

	//	if (iNum == 4) {
	//		cout << "전적 : " << iWin << "승 " << iDraw << "무 " << iLose << "패 " << endl;
	//		cout << "게임을 종료합니다." << endl;
	//		break;
	//	}

	//	if ((iWin + iLose + iDraw) == 5)
	//	{
	//		cout << "전적 : " << iWin << "승 " << iDraw << "무 " << iLose << "패 " << endl;
	//		cout << "게임을 종료합니다." << endl;
	//		break;
	//	}

	//}


#pragma endregion 과제 1번



#pragma region 과제 2번
	/*
	for문을 이용한 구구단 출력 이중for문 사용
	*/

	/*for (int i = 2; i < 10; ++i)
	{
		cout << "===================" << endl;
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << (i*j) << endl;
		}
	}*/

#pragma endregion 과제 2번

#pragma region 과제 3번
	/*
	for문을 이용하여 단수와 곱을 입력받아 구구단을 출력
	ex) 5단 4곱 = 2~5단 *4 
	*/
	
	//int iNum1 = 0; // 단을 저장하는 변수
	//int iNum2 = 0; // 곱을 저장하는 변수
	//int iCount = 0; // 0부터 iNum2까지 증가하는 변수

	//cout << "단수를 입력하세요 : " << endl;
	//cin >> iNum1;
	//cout << "곱을 입력하세요 : " << endl;
	//cin >> iNum2;
	//cout << endl;
	//
	//for (int i = 2; i <= iNum1; ++i)
	//{
	//	cout << "================" << endl;
	//	for (int j = 1; j <= iNum2; ++j)
	//	{		
	//		cout << i << " * " << j << " = " << (i*j) << endl;
	//	}
	//}



#pragma endregion 과제 3번

#pragma region 과제 4번
	/*
		이중포문을 사용하여 피라미드 출력
	*/



	/*for (int i = 1; i < 6; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 6; i > 1; --i)
	{
		for (int j = 1; j < i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}


	



	for (int i = 1; i < 6; ++i)
	{	
		for (int j = 5; j > i; --j)
		{
			cout << " ";			
		}
		for (int k = 0; k < i; ++k)
		{
			cout << "*";
		}
		cout << endl;
		
	}

	cout << endl;

	for (int i = 1; i < 6; ++i)
	{
		
		for (int j = 1; j < i; j++)
		{
		cout << " ";
		}
		for (int k = 6; k > i; --k)
		{
			cout << "*";
		}
		
		cout << endl;
	}*/
	
	
	
	

	
	


	
	


	

	

#pragma endregion 과제 4번


}