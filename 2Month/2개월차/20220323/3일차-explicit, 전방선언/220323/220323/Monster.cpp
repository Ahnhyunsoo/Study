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
	cout << "�̸� : " << m_tInfo.strName << endl;
	cout << "ü�� : " << m_tInfo.iHp << "\t���ݷ� : " << m_tInfo.iAttack << endl;
}
