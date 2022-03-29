#include "stdafx.h"
#include "Item.h"


CItem::CItem()
	: CObj()
{
}


CItem::CItem(char* _pName, int _iAttack, int _iMaxHp, int _iLevel /*= 1*/)
	:CObj(_pName, _iAttack, _iMaxHp, _iLevel)
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
