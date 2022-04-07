#pragma once

#include "Define.h"

class CObj
{
protected:
	INFO		m_tInfo;

public:
	virtual void		SelectJob(void) {}
	virtual void		Combat_Win(int _iExp, int _iMoney){}
	virtual void		Combat_Lose(void){}
	virtual void		Combat_Run(void) {}
	
	virtual void		Initialize(void) {}

public:
	INFO		Get_Info(void)				{ return m_tInfo; }
	void		Set_Damage(int _iAttack)	{ m_tInfo.iHp -= _iAttack; }

public:
	void		Render(void);

public:
	CObj();
	CObj(INFO& rInfo);
	CObj(char* _pName, int _iAttack, int _iMaxHp, int _iLevel = 1);
	~CObj();
};

