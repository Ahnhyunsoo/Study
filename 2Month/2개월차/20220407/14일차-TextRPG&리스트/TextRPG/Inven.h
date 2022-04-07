#pragma once

#include "Define.h"
#include "Player.h"

class CInven
{

public:
	CInven();
	~CInven();
public:
	void		Set_Player(CObj* pPlayer) { m_pPlayer = pPlayer; }
	bool		Buy_Item(CObj* _pItem);
	bool		Sell_Item(int _iIndex, int* pMoney);

	void		Equip_Item(void);
	void		Unequip_Item(void);

public:
	void		Initialize(void);
	void		Update(void);
	void		Render(void);
	void		Release(void);
	
private:
	CObj*			m_pPlayer;
	vector<CObj*>	m_vecInven;
	const size_t	m_iSize;
};

