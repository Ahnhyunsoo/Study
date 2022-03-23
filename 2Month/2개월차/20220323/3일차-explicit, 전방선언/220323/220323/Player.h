#pragma once

#include "Define.h"

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

public:
	INFO		Get_Info(void)				{ return m_tInfo; }
	void		Set_MinusHp(int _iAttack)	{ m_tInfo.iHp -= _iAttack; }
	void		Set_Hp(int _iMaxHp)			{ m_tInfo.iHp = _iMaxHp; }

public:
	void		SelectJob(void);
	void		Render(void);

private:
	INFO		m_tInfo;
};

