#pragma once
#include "Obj.h"
class CPlayer :	public CObj
{
public:
	CPlayer();
	CPlayer(char* _pName, int _iAttack, int _iMaxHp, int _iLevel = 1);
	~CPlayer();

public:
	void		SelectJob(void);

public:
	void		Combat_Win(int _iExp, int _iMoney);
	void		Combat_Lose(void);
	void		Combat_Run(void);

	void		Equip_Item(CObj* pItem);
	void		Unequip_Item(CObj* pItem);
	void		Item_Ability(int _iAttack, int _iHp);

	void		Set_MinusMoney(int _iMoney) { m_tInfo.iMoney -= _iMoney; }
	void		Set_PlusMoney(int _iMoney) { m_tInfo.iMoney += _iMoney; }

private:
	void		Load_Data(void);

private:
	CObj*			m_pItem[ITEM_END];
};

