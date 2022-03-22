#pragma once

#define SAFE_DELETE(p) if(p)	   { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) if(p) { delete [] p; p = nullptr; }

// c������ �����Ҵ��� �޸𸮸� �����ϴ� �Լ� free�� ��ü�� �Ҹ��ڸ� ȣ���� �� ����.

typedef struct tagInfo
{
	char		szName[128];
	int			iKor;
	int			iEng;
	int			iMath;
	int			iTotal;
	float		fAver;

}INFO;

