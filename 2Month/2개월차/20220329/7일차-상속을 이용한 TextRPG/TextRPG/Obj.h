#pragma once

#include "Define.h"

class CObj
{
protected:
	INFO		m_tInfo;

public:
	INFO		Get_Info(void)				{ return m_tInfo; }
	void		Set_Damage(int _iAttack)	{ m_tInfo.iHp -= _iAttack; }

public:
	void		Render(void);

public:
	CObj();
	CObj(char* _pName, int _iAttack, int _iMaxHp, int _iLevel = 1);
	~CObj();
};

