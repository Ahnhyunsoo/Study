#pragma once

#include "Define.h"
#include "Player.h"
#include "Field.h"
#include "Shop.h"
#include "Inven.h"

class CMainGame
{
public:
	void	Initialize(void);
	void	Update(void);
	void	Release(void);

private:
	void			Save_Data(void);

private:
	CObj*			m_pPlayer = nullptr;
	CField*			m_pField = nullptr;
	CShop*			m_pShop = nullptr;
	CInven*			m_pInven = nullptr;

public:
	CMainGame();
	~CMainGame();



};

