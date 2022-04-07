#pragma once

#include "Player.h"
#include "Item.h"
#include "Inven.h"

class CShop
{
public:
	CShop();
	~CShop();

public:
	void			Initialize(void);
	void			Update(void);
	void			Release(void);

public:
	void			Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }
	void			Set_Inven(CInven* pInven) { m_pInven = pInven; }
	void			Buy_Item(CObj* pItem);
	void			Sell_Item(void);

private:
	void			Render(CLASS eLevel);

private:
	CObj*		m_pPlayer = nullptr;
	CObj*		m_pItem[ITEM_END][CLASS_END];
	CInven*		m_pInven = nullptr;
};

