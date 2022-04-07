#pragma once
#include "Obj.h"
class CMonster : public CObj
{
public:
	void		Initialize(void);

public:
	CMonster();
	CMonster(char* _pName, int _iAttack, int _iMaxHp, int _iLevel = 1);
	~CMonster();
};

