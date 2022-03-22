#pragma once

#define SAFE_DELETE(p) if(p)	   { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) if(p) { delete [] p; p = nullptr; }

// c시절에 동적할당한 메모리를 해제하는 함수 free는 객체의 소멸자를 호출할 수 없다.

typedef struct tagInfo
{
	char		szName[128];
	int			iKor;
	int			iEng;
	int			iMath;
	int			iTotal;
	float		fAver;

}INFO;

