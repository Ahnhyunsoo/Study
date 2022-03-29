#pragma once
#include "Obj.h"
class CMonster :
	public CObj
{
public:
	void Create();
	void Print();
	virtual void Test();
	CMonster();
	~CMonster();
};

