#include "stdafx.h"
#include "Item.h"


CItem::CItem()
	: CObj(), m_eType(ITEM_END), m_eState(STATE_UNEQUIP)
{
}


CItem::CItem(char* _pName, int _iAttack, int _iMaxHp, int _iLevel /*= 1*/)
	:CObj(_pName, _iAttack, _iMaxHp, _iLevel), m_eType(ITEM_END), m_eState(STATE_UNEQUIP)
{

}

CItem::CItem(INFO& rInfo)
	: CObj(rInfo), m_eType(ITEM_END), m_eState(STATE_UNEQUIP)
{

}

CItem::~CItem()
{
}

void CItem::Initialize(CLASS eLevel)
{
	m_tInfo.iMoney = 50 + (eLevel * 5000);
}

void CItem::Render(void)
{
	cout << "===================================" << endl;
	cout << "이름 : " << m_tInfo.szName << endl;
	cout << "체력 : " << m_tInfo.iMaxHp << endl;
	cout << "공격력 : " << m_tInfo.iAttack << endl;
	cout << "가격 : " << m_tInfo.iMoney << endl;
	cout << "===================================" << endl;
}
