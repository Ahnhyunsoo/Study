#pragma once

#include "Player.h"
#include "Item.h"

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
	void			Set_Player(CPlayer* pPlayer) { m_pPlayer = pPlayer; }
	void			Buy_Item(CItem* pItem);

private:
	void			Render(CLASS eLevel);

private:
	CPlayer*		m_pPlayer = nullptr;

	CItem*			m_pItem[ITEM_END][CLASS_END];
};

