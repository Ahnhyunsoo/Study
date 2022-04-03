// Test.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

void main(void)
{
	int iArray[2];
	delete[] iArray;
	

	cout << sizeof(iArray)/4 << endl;
}

