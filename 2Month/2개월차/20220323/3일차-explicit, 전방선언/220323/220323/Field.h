#pragma once

#include "Player.h"
#include "Monster.h"

class CField
{
public:
	CField();
	~CField();

public:
	void	Set_Player(CPlayer* pPlayer) { m_pPlayer = pPlayer; }

public:
	void	Update(void);
	void	Release(void);
	int		Fight(void);

private:
	CPlayer*		m_pPlayer;
	CMonster*		m_pMonster;
};

