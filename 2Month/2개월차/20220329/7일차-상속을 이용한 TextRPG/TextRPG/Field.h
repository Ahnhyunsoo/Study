#pragma once

#include "Define.h"

class CPlayer;
class CMonster;
class CField
{
public:
	CField();
	~CField();

public:
	void			Initialize(void);
	void			Update(void);
	void			Release(void);

public:
	void			Set_Player(CPlayer* pPlayer) { m_pPlayer = pPlayer; }

private:
	COMBAT			Fight(void);
	
private:
	CPlayer*			m_pPlayer = nullptr;
	CMonster*			m_pMonster = nullptr;
};

