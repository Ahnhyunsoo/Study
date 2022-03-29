#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
	: m_tInfo()
{
}

CObj::CObj(char* _pName, int _iAttack, int _iMaxHp, int _iLevel /*= 1*/)
	: m_tInfo(_pName, _iAttack, _iMaxHp, _iLevel)
{

}

CObj::~CObj()
{
}
void CObj::Render(void)
{
	cout << "===================================" << endl;
	cout << "이름 : " << m_tInfo.szName << endl;
	cout << "체력 : " << m_tInfo.iHp << " / " << m_tInfo.iMaxHp << endl;
	cout << "공격력 : " << m_tInfo.iAttack << endl;
	cout << "레벨 : " << m_tInfo.iLevel << " ( " << m_tInfo.iExp << " / " << m_tInfo.iMaxExp << " ) " << endl;
	cout << "소지금 : " << m_tInfo.iMoney << endl;
	cout << "===================================" << endl;
}
