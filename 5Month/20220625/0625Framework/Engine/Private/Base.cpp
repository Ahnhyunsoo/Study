#include "..\Public\Base.h"





unsigned int CBase::AddRef()
{
	return ++dwRefCnt;
}

unsigned int CBase::Release()
{
	if (dwRefCnt == 0)
	{
		delete this;
		return 0;
	}
	else
	return dwRefCnt--;
}
