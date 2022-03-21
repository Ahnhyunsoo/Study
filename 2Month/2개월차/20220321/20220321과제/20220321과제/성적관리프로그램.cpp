// 20220321과제.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
//과제1 성적프로그램
//과제2 텍스트rpg

#include "stdafx.h"
#include "Machine.h"

int* dd();

int main()
{
	
	int* p = dd();

	
		cout << sizeof(*p) << endl;
	
	//똑같이 인트형으로 만들어봤는데 얘는 출력잘됨 클래스만 안돼 왜지 킹받네 ...... 문법은 틀린게 없는데 틀렸나?
		//저거랑 같은 느낌으로 잘못된건가 지금?

	//CMachine Machine;
	//Machine.exe();
	return 0;
}


int* dd()
{
	int iCount = 0;
	int* p = new int[5];
	int* a = p;
	for (int i = 0; i < 5; ++i)
	{
		p[i] = iCount;
		iCount++;
	}
	return a;
}

