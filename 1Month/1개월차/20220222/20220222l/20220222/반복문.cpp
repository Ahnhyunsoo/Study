#include <iostream>
#include <time.h>
//#include <ctime>

using namespace std;

void main(void)
{
	//반복문 : 반복적인 코드를 생성하고 실행시키기 위해 사용하는 문법
	//while, do while, for
#pragma region while문
	//while문 : 무한 루프를 기본 전제로 삼는 반복문
	/*
	int iScore = 3;

	while (true)
	{
		if (0 == iScore) {
			break;
		}
		cout << 1 << endl;
		iScore--;
		

	}
	*/
	/*
	int i = 1;

	while (10 > i)
	{
		cout << 2 << " * " << i << " = " << i * 2 << endl;
		++i;
	}
	*/
#pragma endregion while문

#pragma region do while문

	// do while : 무한루프를 전제로 삼는 반복문으로 조건식이 아래쪽에 배치되어 있다.
	// 반복문에서만 사용할 수 있는 키워드 continue;
	/*
	do
	{
		cout << 1 << endl;

		

		continue;	//컨티뉴를 만나면 기존의 실행됐던 코드의 첫 위치로 이동시킨다.

		cout << 2 << endl;

	} while (true);
	*/
#pragma endregion do while문


#pragma region for문

#pragma endregion for문


#pragma region 난수 (랜덤한 값)
	
	//rand함수 : 0~32767범위 사이 값을 무작위로 추출하는 함수
	//srand함수 : rand함수의 seed(난수 표) 값을 변경하기 위한 함수
	//time함수 : 현재 시간을 초 단위로 불러오는 함수

	time_t Temp = 0;
	time(&Temp);
	cout << Temp << endl;
	
	
	srand(unsigned(time(NULL))); // 난수표를 바꿔주는 역할 NULL = 0; unsigned = 양수만

	int iA = rand();
	int iB = rand();

	cout << iA << endl;
	cout << iB << endl;
	
#pragma endregion 난수 (랜덤한 값)

}



/*
system("cls"); // 기존에 출력된 결과물을 지우는 함수

system("pause"; //출력상태를 일시 정지하는 함수
*/

//1. while 문을 이용하여 구구단 2~9단 출력하기
//2. do while문을 이용하여 숫자를 입력(5번)받고 짝수인 경우에만(짝수만더해서) 합을 구하는 프로그램 만들기
//3. 자판기 구현하기(while문)
/*
- 소지금 입력 받기
- 현재 소지금을 '잔액'으로 표기하여 출력
- 메뉴가 출력, 1.콜라(100원) 2. 사이다(200원) 3. 환타(300원) 4. 반환
- 선택에 의해 구매 시 잔액은 바뀌어야 함
-소지금이 부족할 경우 구매는 불가능하고, 잔액이 부족합니다 출력
- 4번을 누르면 잔액은 ~~원입니다. 출력 후 프로그램 종료
*/

//4. 홀짝 게임
/*
- 난수를 뽑아내서 그 숫자가 홀인지 짝인지 판별하는 게임
- 난수는 1~10까지 중 하나를 생성
- 1. 홀수 2. 짝수 3. 종료
- 총 5라운드 진행하여 마지막 라운드 종료시 몇 승 몇 패 출력
- 매라운드마다 난수를 새로 뽑는다.
*/