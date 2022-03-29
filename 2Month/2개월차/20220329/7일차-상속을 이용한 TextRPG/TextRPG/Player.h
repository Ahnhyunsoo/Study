#pragma once
#include "Obj.h"
class CPlayer :	public CObj
{
public:
	void		SelectJob(void);

public:
	void		Combat_Win(int _iExp, int _iMoney);
	void		Combat_Lose(void);
	void		Combat_Run(void);

public:
	CPlayer();
	CPlayer(char* _pName, int _iAttack, int _iMaxHp, int _iLevel = 1);
	~CPlayer();
};

