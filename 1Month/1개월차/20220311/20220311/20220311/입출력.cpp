#include <iostream>

using namespace std;

void main(void)
{
	/*버퍼 함수 : 버퍼(데이터를 저장하기 위한 메모리 블럭)를 비우기 위한 용도의 함수
	비우다 : 삭제의 의미가 아니라 버퍼 공간에서 목적지까지 강제로 이동시키는 것을 의미

	출력 버퍼 비우기 함수 : fflust(stdout);
	입력 버퍼를 비워야 하는 이유

	char szID[7] = "";
	char szName[16] = "";

	fgets(szID, sizeof(szID), stdin);

	while ('\n' != getchar());

	fgets(szName, sizeof(szName), stdin);

	fputs(szID, stdout);
	fputs(szName, stdout);*/

	//바이너리모드 입출력 함수
	//
	//파일 입출력의 기본 순서 : 개방 -> 쓰기 or 읽기 -> 소멸

	// 콘솔 입출력의 경우 스트림(핸들) 생성, 소멸을 운영체제가 알아서 진행해줬다. 스트림 자체가 시스템 자원이기 때문에 가늫하다.
	// 파일 입출력의 경우 핸들을 직접 생성, 소멸 해야하기 때문에 이와 관련된 함수들을 알아야 할 필요가 있다.
	//바이너리 모드 입출력 : 여러 자료형을 저장 또는 불러오기 하기 위해 사용한다.
	//fopen_s(); // 스트림 생성함수 (파일 개방 함수)
	//
	//쓰기 전용, 읽기 전용

	//fclose(); // 스트림 소멸함수(파일 소멸 함수)
	//fopen_s 
	//\r = carrige return = 공백을 땡겨라 (텍스트모드일때는 자동으로 지원해준다)
	//	바이너리 모드일땐 캐리지 리턴이 실행되면 안된다.

	/*
	파일 함수 fseek 
	마지막의 기준은 마지막원소가 아닌 eof기준이다.
	ftll 현재 파일 지시자의 위치를 알려주는 함수
	*/

	//바이너리 파일
	int iArray[5] = { 1,2,3,4,5 };
	
	FILE*  pFile = nullptr;

	//errno_t err = fopen_s(&pFukem "../Data/Save.txt", "wt");

	//바이너리 모드 쓰기 전용 함수
		

}