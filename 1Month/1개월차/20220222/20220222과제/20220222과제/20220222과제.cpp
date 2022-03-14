#include <iostream>
#include <ctime>
#include <random>

using namespace std;

void main(void)
{


#pragma region 과제1번

	//while문을 이용하여 구구단 2단부터 9단까지 출력
	
	//int iNum = 1; // 1부터 9까지 증가하는 변수
	//int iNum2 = 2; // 단수를 나타내는 변수

	//while (iNum2 < 10) //단수가 10보다 작을 때까지 즉 9까지 반복
	//{	
	//	cout << iNum2 << " * " << iNum << " = " << (iNum2*iNum) << endl;	 //iNum2 * iNum = (iNum2*iNum) 출력		
	//		if (iNum == 9) //만약 iNum가 9와 같다면 iNum2를 1증가시키고 iNum를 1로 초기화 (9까지 반복하면 단수를 증가시킴)
	//		{
	//			iNum2++; // iNum2 (단수)를 1증가
	//			iNum = 0; // 곱하는값 (1~9) 를 1로 초기화 사실상 1
	//			cout << "===========================" << endl; // 줄바꿈 출력
	//		}
	//		iNum++; // i를 1증가
	//}

#pragma endregion 과제1번


#pragma region 과제2번
	////do while문을 이용하여 숫자를 5번 입력받고 짝수인 경우만 합을 구해서 출력
	//int iNum = 0; // 숫자를 저장하는 변수
	//int iSum = 0; // 합계를 저장하는 변수
	//int iCount = 1; // 입력받은 횟수를 저장하는 변수

	//do
	//{	
	//	cout << "숫자를 입력해주세요 : ";
	//	cin >> iNum; // 입력받은 값을 iNum에 저장
	//	if ((iNum % 2) == 0) // 만약 iNum에 저장된 값의 나머지가 0이면 작동
	//	{
	//		iSum += iNum; // 나머지가 0이면 짝수니 합계에 iNum의 값을 저장
	//	}	

	//	if (iCount == 5) // 만약 iCount가 5라면 작동
	//	{
	//		cout << "입력한 숫자중 짝수의 합 : " << iSum << endl; // iCount가 5라면 저장된값이 5개이므로 합계를 출력
	//	}
	//	iCount++; // iCount의 값을 1개 증가시켜준다.

	//} while (iCount < 6); // iCount가 6보다 작다면 (5까지 반복한 후)반복문을 빠져나온다.
	//
	



#pragma endregion 과제2번


#pragma region 과제3번
	//while문을 이용하여 자판기 구현하기
	//소지금을 입력받아 현재 소지금을 잔액으로 표기하여 출력 
	//메뉴가 출력 1. 콜라 100원 2.사이다 200원 3. 환타 300원 4. 반환
	//선택에 의해 구매 시 잔액은 바뀌어야 함
	//소지금이 부족하면 구매 불가능하며 잔액이 부족합니다 출력
	//4번을 누르면 남은 잔액은 ~~입니다 출력후 종료
	//---------------------------코드시작
	//int iMoney = 0; //소지금을 저장하는 변수
	//int iNum = 0; //입력받은 메뉴 번호를 저장하는 변수

	//while (true) // 무한반복
	//{	
	//	if (iMoney == 0) //만약 소지금이 0원이라면 실행
	//	{
	//		cout << "환영합니다. 소지금을 입력해주세요 : "; 
	//		cin >> iMoney; // 소지금을 입력받아 저장

	//		if(iMoney <= 0) // 소지금이 0원이하라면
	//		{
	//		cout << "소지금이 부족합니다." << endl;  
	//		continue; //위의 if문으로 이동
	//		}
	//	}

	//	cout << "========================메뉴==========================" << endl;
	//	cout << "1.콜라(100원), 2.사이다(200원), 3.환타(300원), 4.종료 " << endl;
	//	cin >> iNum; // 번호를 입력받아 변수에 저장

	//	if (iNum == 1) // 번호가 1이라면 실행
	//	{
	//		if ((iMoney - 100) >= 0) // 소지금이 100원이상일때 실행
	//		{
	//			cout << "콜라를 주문하셨습니다." << endl;
	//			cout << "남은 잔액 : " << (iMoney -= 100) << "원" << endl;
	//		}
	//		else
	//		{
	//			cout << "잔액이 부족합니다." << endl;
	//			cout << "남은 잔액 : " << (iMoney -= 100) << "원" << endl;
	//			break; //반복문 종료
	//		}
	//	}

	//	if (iNum == 2) // 입력받은 번호가 2번이면 실행
	//	{
	//		if ((iMoney - 200) >= 0) // 소지금이 200원 이상일 때 실행
	//		{
	//			cout << "사이다를 주문하셨습니다." << endl;
	//			cout << "남은 잔액 : " << (iMoney -= 200) << "원" << endl;
	//		}
	//		else
	//		{
	//			cout << "잔액이 부족합니다." << endl;
	//			cout << "남은 잔액 : " << (iMoney -= 200) << "원" << endl;
	//			break; // 반복문 종료
	//		}
	//	}

	//	if (iNum == 3) // 입력받은 번호가 3번이면 실행
	//	{
	//		if ((iMoney - 300) >= 0) // 소지금이 300원 이상일 때 실행
	//		{
	//			cout << "환타를 주문하셨습니다." << endl;
	//			cout << "남은 잔액 : " << (iMoney -= 300) << "원" << endl;
	//		}
	//		else
	//		{
	//			cout << "잔액이 부족합니다." << endl;
	//			cout << "남은 잔액 : " << (iMoney -= 300) << "원" << endl;
	//			break; // 반복문 종료
	//		}
	//	}


	//	if (iNum == 4) // 입력받은 번호가 4번이면 실행
	//	{
	//		cout << "남은 잔액 : " << iMoney << "원" << endl;
	//		cout << "종료합니다." << endl;
	//		break; // 반복문 종료
	//	}
	//	if (iMoney == 0) // 소지금이 0원이면 실행
	//	{
	//		cout << "잔액이 없습니다." << endl;
	//		cout << "종료합니다." << endl;
	//		break; // 반복문 종료
	//	}
	//	system("pause"); // 콘솔창 잠시 정지
	//	system("cls"); // 콘솔창 내용 지우기
	//}
	

#pragma endregion 과제3번


#pragma region 과제4번
	/*
	- 난수를 뽑아내서 그 숫자가 홀인지 짝인지 판별하는 게임
	- 난수는 1~10까지 중 하나를 생성
	- 1. 홀수 2. 짝수 3. 종료
	- 총 5라운드를 실시하여 마지막 라운드 종료시 몇 승 몇 패를 출력
	- 매라운드마다 난수를 새로 뽑는다.
	*/

	/*
	난수를 생성하는 방법
	1. rand()함수를 이용한다. 0~32767 2바이트 short형
	seed(난수 표)에 따라서 고정된 난수를 생성 하므로
	srand(정수)를 이용해 난수 표를 수정해줘야한다.
	이 또한 랜덤으로 이용할라면 항상 바뀌는 정수인 시간을 이용하면 된다.
	시간은 time함수를 이용하여 구할 수 있다.
	#include <time.h> (c) || #include <ctime> (c++)
	cout << (unsigned int(time(NULL))); time(NULL) = 현재시간 unsigned int = 양의 정수값만 구하기
	단점 : 시간이 천천히 바뀐다 , 값이 1~99까지 균등하게 난수를 생성하지 않는다.
	*/

	/*
	2. <random> 함수 사용
	random_device random; 랜덤디바이스 생성
	mt19937 rd(random()); //난수 엔진 초기화
	uniform_int_distribution<int> range(1, 10); //균등분포 범위지정
	cout << range(rd); // 범위 내에서 랜덤하게 난수 생성
	*/


#pragma region ctime함수를 이용한 코드
	//---------------------------코드시작
	//int iNum = 0; // 사용자가 입력한 변수
	//int iRandom = 0; // 난수를 저장하는 변수
	//int iWin = 0; // 승수를 저장하는 변수
	//int iLose = 0; // 패배를 저장하는 변수
	//
	//while (true) // 무한 반복
	//{
	//	srand(unsigned int(time(NULL))); // 난수표에 현재 시간을 입력
	//	iRandom = (rand() % 10); // 10까지 표현하기위해 10으로 나눈 나머짓값을 구함
	//	cout << "1. 홀수 2. 짝수 3. 종료" << endl;
	//	cout << "문제 : " << iRandom << endl;
	//	cin >> iNum; // 입력받은 값을 iNum 변수에 저장
	//	system("cls"); //콘솔창 내용을 초기화함
	//	if (iNum <= 0 || iNum >= 4) //입력한 정수값이 1~3사이의 값이 아니면 실행
	//	{
	//		cout << "1부터 3까지의 숫자만 입력해주세요." << endl;
	//		cout << endl;
	//		continue; // 위의 if문으로 이동
	//	}


	//	
	//	if (iNum == 1) // iNum이 1이면 실행
	//	{
	//		if ((iRandom % 2) != 0) // iRandom의 나머지가 홀수면 실행
	//		{
	//			iWin += 1; // 승리에 +1
	//		}
	//		else // 홀수가 아닐 시 (짝수일 때) 실행
	//		{
	//			iLose += 1; // 패배에 +1
	//		}
	//	}

	//	if (iNum == 2) // iNum이 2이면 실행
	//	{
	//		if ((iRandom % 2) == 0) // iRandom의 나머지가 짝수면 실행
	//		{
	//			iWin += 1; // 승리에 +1
	//		}
	//		else // 짝수가 아닐 시 (홀수일 때) 실행
	//		{
	//			iLose += 1; // 패배에 +1
	//		}
	//	}

	//	if (iNum == 3) // iNum이 3일 때 실행
	//	{
	//		cout << "게임 결과 : " << iWin << " 승 " << iLose << " 패 " << endl;
	//		cout << "게임을 종료합니다." << endl;
	//		break; // 반복문 종료
	//	}

	//	if ((iWin + iLose) == 5) // 총전적이 5일 때 실행
	//	{
	//		cout << "게임 결과 : " << iWin << " 승 " << iLose << " 패 " << endl;
	//		cout << "게임을 종료합니다." << endl;
	//		break; // 반복문 종료
	//	}

	//	

	//}
	
#pragma endregion ctime함수를 이용한 코드	

#pragma region <random>함수를 이용한 코드
	//---------------------------코드시작
	//int iNum = 0; // 사용자가 입력한 변수
	//int iRandom = 0; // 난수를 저장하는 변수
	//int iWin = 0; // 승수를 저장하는 변수
	//int iLose = 0; // 패배를 저장하는 변수

	//while (true) // 무한반복
	//{
	//	random_device random; // 랜덤 디바이스 생성
	//	mt19937 rd(random()); // 난수엔진 초기화
	//	uniform_int_distribution<int> range(1, 10); // 균등분포 범위지정
	//	iRandom = range(rd); // 생성한 난수를 iRandom 변수에 대입
	//

	//	cout << "1. 홀수 2. 짝수 3. 종료" << endl;
	//	cout << "문제 : " << iRandom << endl;
	//	cin >> iNum;
	//	system("cls");
	//	if (iNum <= 0 || iNum >= 4) //입력한 정수값이 1~3사이의 값이 아니면 실행
	//	{
	//		cout << "1부터 3까지의 숫자만 입력해주세요." << endl;
	//		cout << endl;
	//		continue; // 위의 if문으로 이동
	//	}



	//	if (iNum == 1)
	//	{
	//		if ((iRandom % 2) != 0)
	//		{
	//			iWin += 1;
	//		}
	//		else
	//		{
	//			iLose += 1;
	//		}
	//	}

	//	if (iNum == 2)
	//	{
	//		if ((iRandom % 2) == 0)
	//		{
	//			iWin += 1;
	//		}
	//		else
	//		{
	//			iLose += 1;
	//		}
	//	}

	//	if (iNum == 3)
	//	{
	//		cout << "게임 결과 : " << iWin << " 승 " << iLose << " 패 " << endl;
	//		cout << "게임을 종료합니다." << endl;
	//		break;
	//	}

	//	if ((iWin + iLose) == 5)
	//	{
	//		cout << "게임 결과 : " << iWin << " 승 " << iLose << " 패 " << endl;
	//		cout << "게임을 종료합니다." << endl;
	//		break;
	//	}



	//}

#pragma endregion <random>함수를 이용한 코드

#pragma endregion 과제4번








	
}