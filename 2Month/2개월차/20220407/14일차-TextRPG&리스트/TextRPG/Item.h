#pragma once
#include "Obj.h"
class CItem :
	public CObj
{
public:
	CItem();
	CItem(INFO& rInfo);
	CItem(char* _pName, int _iAttack, int _iMaxHp, int _iLevel = 1);
	~CItem();

public:
	ITEM		Get_Itemtype(void) { return m_eType; }
	void		Set_Itemtype(ITEM eType) { m_eType = eType; }
	void		Set_ItemState(STATE eState) { m_eState = eState; }

public:
	void	Initialize(CLASS eLevel);
	void	Render(void);

private:
	ITEM			m_eType;
	STATE			m_eState;
};

