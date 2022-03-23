#pragma once

#include "Define.h"

class CMonster
{
public:
	CMonster();
	CMonster(string _strName, int _iAttack, int _iHp);
	~CMonster();

public:
	INFO		Get_Info(void) { return m_tInfo; }
	void		Set_MinusHp(int _iAttack) { m_tInfo.iHp -= _iAttack; }

public:
	void		Render(void);

private:
	INFO		m_tInfo;
};

