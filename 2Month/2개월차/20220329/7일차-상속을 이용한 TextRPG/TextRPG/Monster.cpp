#include "stdafx.h"
#include "Monster.h"




CMonster::CMonster()
	: CObj()
{
}


CMonster::CMonster(char* _pName, int _iAttack, int _iMaxHp, int _iLevel /*= 1*/)
	: CObj(_pName, _iAttack, _iMaxHp, _iLevel)
{

}

CMonster::~CMonster()
{
}
void CMonster::Initialize(void)
{
	m_tInfo.iExp   = rand() % 50 + ((m_tInfo.iLevel - 1) * 50);
	m_tInfo.iMoney = rand() % 50 + ((m_tInfo.iLevel - 1) * 5000);
	m_tInfo.iMaxExp = m_tInfo.iExp;
}