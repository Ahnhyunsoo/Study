#pragma once

#include "Define.h"

#include "Player.h"
#include "Monster.h"

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
	void			Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }

private:
	COMBAT			Fight(void);
	
private:
	CObj*			m_pPlayer = nullptr;
	CObj*			m_pMonster = nullptr;
};

