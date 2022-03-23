#pragma once

#include "Define.h"

#include "Player.h"
#include "Field.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize(void);
	void		Update(void);
	void		Release(void);

private:
	CPlayer*	m_pPlayer;
	CField*		m_pField;
};

