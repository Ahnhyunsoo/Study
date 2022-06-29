#include "..\Public\Base.h"



CBase::CBase()
	:dwRefCnt(0)
{
}

unsigned long CBase::Add_Ref(void)
{
	return ++dwRefCnt;
}

unsigned long CBase::Release(void)
{
	if (dwRefCnt == 0)
	{
		Free();

		delete this;

		return 0;
	}
	return dwRefCnt--;
}