#pragma once

#include "Define.h"
#include "Player.h"
#include "Field.h"
#include "Shop.h"

class CMainGame
{
public:
	void	Initialize(void);
	void	Update(void);
	void	Release(void);

private:
	CPlayer*		m_pPlayer = nullptr;
	CField*			m_pField = nullptr;
	CShop*			m_pShop = nullptr;

public:
	CMainGame();
	~CMainGame();



};

