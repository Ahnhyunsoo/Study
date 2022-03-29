#pragma once
#include "Obj.h"
class CItem :
	public CObj
{
public:
	CItem();
	CItem(char* _pName, int _iAttack, int _iMaxHp, int _iLevel = 1);
	~CItem();

public:
	void	Initialize(CLASS eLevel);
	void	Render(void);
};

