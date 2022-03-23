#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}
CMonster::CMonster(string _strName, int _iAttack, int _iHp)
{
	m_tInfo.strName = _strName;
	m_tInfo.iAttack = _iAttack;
	m_tInfo.iHp = _iHp;
}

CMonster::~CMonster()
{
}

void CMonster::Render(void)
{
	cout << "===================================" << endl;
	cout << "이름 : " << m_tInfo.strName << endl;
	cout << "체력 : " << m_tInfo.iHp << "\t공격력 : " << m_tInfo.iAttack << endl;
}
