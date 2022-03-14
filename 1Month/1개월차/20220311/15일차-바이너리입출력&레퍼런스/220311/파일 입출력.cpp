#include <iostream>

using namespace std;

#pragma region 텍스트 모드 입출력 함수

/*
void main(void)
{
	// 버퍼 함수 : 버퍼(데이터를 저장하기 위한 메모리 블럭)를 비우기 위한 용도의 함수
	// 비우다 : 삭제의 의미가 아니라 버퍼 공간에서 목적지까지 강제로 이동시키는 것을 의미

	// 출력 버퍼 비우기 함수 : fflush(stdout);

	// 입력 버퍼를 비워야 하는 이유

	/ *char	szID[8] = "";
	char	szName[16] = "";

	fgets(szID, sizeof(szID), stdin);

	while ('\n' != getchar());

	fgets(szName, sizeof(szName), stdin);

	fputs(szID, stdout);
	fputs(szName, stdout);* /

}*/

#pragma endregion 텍스트 모드 입출력 함수

#pragma region 바이너리 모드 입출력 함수

void main(void)
{
	// 콘솔 입출력의 경우 스트림 생성, 소멸을 운영체제가 알아서 진행해줬다. 스트림 자체가 시스템 자원이기 때문에 가능하다.
	// 파일 입출력의 경우 핸들을 직접 생성, 소멸 해야하기 때문에 이와 관련된 함수들을 알아야 할 필요가 있다.

	// 바이너리 모드 입출력 : 여러 자료형을 저장 또는 불러오기 하기 위해 사용한다.

	// 파일 입출력의 기본 순서 : 개방 -> 쓰기 또는 읽기 -> 소멸

	// fopen_s();	// 스트림 생성 함수(파일 개방 함수)
	// 쓰기 전용 , 읽기 전용
	// fclose(); // 스트림 소멸 함수(파일 소멸 함수)


	//errno_t fopen_s(FILE** _Stream,		char const* _FileName, char const* _Mode);
					// 1인자 : output인자, 2인자 : 파일이 있는 위치까지의 경로와 파일명, 3인자 : 모드를 설정
	
#pragma region 파일 출력

	FILE*		pFile = nullptr;

	errno_t err = fopen_s(&pFile, "../Data/Test.txt", "wt");

	if (0 == err)	// 파일 개방 성공
	{
		fputs("World", pFile);

		cout << "파일 개방 성공" << endl;

		fclose(pFile);
	}
	else
		cout << "파일 개방 실패" << endl;

#pragma endregion 파일 출력
	
#pragma region 파일 입력

	/*FILE*	pFile = nullptr;

	errno_t err = fopen_s(&pFile, "../Data/Test.txt", "rt");

	char	szBuf[32] = "";

	if (0 == err)
	{
		fgets(szBuf, sizeof(szBuf), pFile);		// 파일 입력
		fputs(szBuf, stdout);					// 콘솔 출력

		cout << "파일 개방 성공" << endl;
		fclose(pFile);
	}
	else
		cout << "파일 개방 실패" << endl;*/


#pragma endregion 파일 입력
	
#pragma region 테스트

	/*FILE*		pFile = nullptr;

	char	szBuf[32] = "Hello";

	errno_t err = fopen_s(&pFile, "../Data/Test.txt", "wt");

	if (0 == err)	// 파일 개방 성공
	{
		fputs(szBuf, pFile);

		cout << "파일 개방 성공" << endl;

		fclose(pFile);
	}
	else
		cout << "파일 개방 실패" << endl;*/

	/*FILE*		pFile = nullptr;

	int		ch = 0;

	errno_t err = fopen_s(&pFile, "../Data/Test.txt", "rt");

	if (0 == err)	// 파일 개방 성공
	{
		ch = fgetc(pFile);
		fputc(ch, stdout);

		while ('\0' != ch)		// 파일 입출력에서 문자열의 끝은 null문자로 판단하는 것이 아니라 eof를 통해서 판단할 수 있다.
		{
			ch = fgetc(pFile);
			fputc(ch, stdout);
		}
		
		fclose(pFile);
	}
	else
		cout << "파일 개방 실패" << endl;*/
	
	//cout << "hello" << endl;
	//cout << "world" << endl;

	// c언어에서 텍스트 모드 출력 시 \n 운영체제마다 다른 기능을 갖게 된다.

	// 윈도우: "\r\n"(carriage return이 기본 제공)
	// unix : "\n"
	// Mac  : "\r" 

#pragma endregion 테스트

#pragma region 지원하는 파일 함수

/*
fseek(1, 2, 3) : 개방한 파일을 원하는 바이트 수만큼 시동시키는 함수

1인자 : 개방한 스트림
2인자 : 바이트 수
3인자 : 옵션(SEEK_SET 처음부터 SEEK_CUR 현재 프롬프트 위치부터 SEEK_END 파일의 끝부터)*/

// ftell(스트림) : 현재 프롬프트의 위치를 알려주는 함수
// feof(스트림) : 파일의 끝의 유무를 알려주는 함수

#pragma endregion 지원하는 파일 함수

int		iArray[5] = { 1, 2, 3, 4, 5 };

	/*FILE*		pFile = nullptr;

	errno_t err = fopen_s(&pFile, "../Data/Save.txt", "wb");


	// 바이너리 모드 쓰기 전용 함수
	// size_t fwrite(const void* pBuffer, size_t Size, size_t Count, FILE* stream);

	if (0 == err)	// 파일 개방 성공
	{
		fwrite(iArray, sizeof(iArray), 1, pFile);
		// fwrite(iArray, sizeof(int), 5, pFile);

		cout << "파일 개방 성공" << endl;

		fclose(pFile);
	}
	else
		cout << "파일 개방 실패" << endl;*/

	//FILE*		pLoadFile = nullptr;

	//errno_t errLoad = fopen_s(&pLoadFile, "../Data/Save.txt", "rb");

	//// 바이너리 모드 읽기 전용 함수
	//// size_t fread(const void* pBuffer, size_t Size, size_t Count, FILE* stream);
	//
	//int	iTemp[5] = {};

	//if (0 == errLoad)	// 파일 개방 성공
	//{
	//	fread(iTemp, sizeof(iTemp), 1, pLoadFile);
	//	// fwrite(iArray, sizeof(int), 5, pFile);

	//	cout << "파일 개방 성공" << endl;
	//	fclose(pLoadFile);
	//}
	//else
	//	cout << "파일 개방 실패" << endl;

	//for (int i = 0; i < 5; ++i)
	//	cout << iTemp[i] << endl; 
}

#pragma endregion 바이너리 모드 입출력 함수

// 1. textRPG에 저장. 불러오기 기능 구현하기
// 2.
