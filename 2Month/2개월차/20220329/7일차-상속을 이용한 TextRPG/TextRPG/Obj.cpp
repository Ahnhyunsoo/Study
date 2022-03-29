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
	cout << "�̸� : " << m_tInfo.szName << endl;
	cout << "ü�� : " << m_tInfo.iHp << " / " << m_tInfo.iMaxHp << endl;
	cout << "���ݷ� : " << m_tInfo.iAttack << endl;
	cout << "���� : " << m_tInfo.iLevel << " ( " << m_tInfo.iExp << " / " << m_tInfo.iMaxExp << " ) " << endl;
	cout << "������ : " << m_tInfo.iMoney << endl;
	cout << "===================================" << endl;
}
