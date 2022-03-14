#include <iostream>

using namespace std;

void main(void)
{
//스트림 : 장치들을 연결해주는 가상의 통로, 단 방향 스트림
//버퍼 : 데이터를 임시 저장하기 위한 메모리 블록을 의미
//
//콘솔 표준 입출력 스트림
	//stdin : 표준 입력 스트림 // 기본 키보드 대상
	//stdout : 표준 출력 스트림 // 기본 모니터 대상
	//stderr : 표준 에러 스트림 // 기본 모니터 대상이긴 하나 우리가 볼 수 없다.
	
	//Text mode = 문자열만 지원  binary mode = 정수형 등등

	// 입출력에는 텍스트 모드 함수와 바이너리 모두 함수가 존재한다.
	// 텍스트 모드 함수는 문자열만 지원하며, 바이너리 함수는 모든 자료형 또는 사용자 정의 자료형도 지원한다.
	// 스트림을 지정할 수 있는 함수는 곧, 핸들을 지정할 수 있는 함수를 의미하며, 핸들을 생성해주는 행동을 가리켜 '파일을 개방한다' 라고한다.

	// 현재 스트림을 지정하는 함수들인 f시리즈들의 함수는 콘솔에 입출력을 하기 위해 표준 스트림을 사용하고 있지만
	// 파일 입출력 시 직접 스트림을 생성하여 넣어주는 코드 작업을 진행해야 한다.


	//단일 문자 출력 함수
	//putchar, fputc

	//putchar('A'); // stdout 이란 출력 스트림을 기본값으로 고정
	//fputc('A', stdout); // stdout = 콘솔에 출력하는 스트림
	//handle(스트림)을 바꿔주면 출력되는곳이 달라진다.

	//window = 메모리와 프로그램을 관리하는 최고 관리자
	//handle 이라는 변수가 있다.
	//handle = 고유 식별번호 16진수 형태

	//단일 문자 입력 함수

	//getchar(), fgetc();

	//int ch = getchar(); // stdin이란 입력 스트림을 기본값으로 고정
	//putchar(ch);

	/*int ch = fgetc(stdin);
	fputc(ch, stdout);*/

	// 입출력 함수의 반환 값이 존재하는 이유 : char는 시스템에 따라 unsigned가 될 수도 있다.
	//char가 unsigned가 되면 EOF를 표현할 수 없다.

	//EOF(end of file) => -1 : 파일의 끝을 표현하기 위한 상수

	// 입출력 함수의 반환 값이 존재하는 이유 : char는 시스템에 따라 unsigned가 될 수도 있다.
	//char가 unsigned가 되면 EOF를 표현할 수 없다.
	//그래서 반환 타입을 INT타입을 만들고 signed를 유지시켜 eof를 표현할 수 있게 하려고 반환 값을 두었다.

	//while (true)
	//{
	//	char ch = getchar();

	//	if (EOF == ch) // 콘솔 입출력에서는 ctrl + z키가 eof를 의미한다.
	//	{
	//		break;
	//	}
	//	else
	//		putchar(ch);
	//}

	//while (true)
	//{
	//	char ch = getchar();

	//	if (EOF == ch)
	//		break;
	//		//65
	//		if ('A' <= ch && 'Z' >= ch)
	//			ch += 32;

	//		else if ('a' <= ch && 'z' >= ch)
	//			ch -= 32;
	//}


	//문자열 출력 함수 puts, fputs 두 함수 모두 호출 성공 시 출력된 문자를 반환하고
	// 실패 시 EOF를 반환

	//puts("Hello"); // 자동으로 개행(한줄 띄기)이 적용
	//fputs("HELLO", stdout);

	//문자열 입력 함수 gets_s, fgets

	//char szInput[16] = {};
	//gets_s(szInput, sizeof(szInput)); // 공백(스페이스)을 읽어들인다. 대신 엔터는 읽을 수 없다. 사이즈가 초과되면 메모리 오류가 발생한다.
	//puts(szInput);
	//fgets(szInput, sizeof(szInput), stdin); // 엔터가 나올 때까지 읽어온다. 설정한 사이즈만큼만 읽어온다. null문자를 고려한다.
	//fputs(szInput, stdout);


}