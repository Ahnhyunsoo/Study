#include "..\Public\Base.h"

using namespace Engine;

unsigned long CBase::Release()
{
	if (dwRefCnt == 0)
	{
		delete this;
		return 0;
	}
	else
	return dwRefCnt--;
}

unsigned long CBase::AddRef()
{
	return ++dwRefCnt;
}
