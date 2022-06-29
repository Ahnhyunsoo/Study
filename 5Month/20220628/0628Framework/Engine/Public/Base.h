#pragma once
#include "Engine_Defines.h"
BEGIN(Engine)

class ENGINE_DLL CBase abstract
{
protected:
	CBase() { dwRefCnt = 0; }
	virtual ~CBase() = default;

public:
	unsigned long Release();
	unsigned long AddRef();

protected:
	unsigned long dwRefCnt;

public:
	virtual void Free() = 0;
};

END