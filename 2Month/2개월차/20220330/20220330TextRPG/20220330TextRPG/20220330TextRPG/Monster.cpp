#include "stdafx.h"
#include "Monster.h"
#include "Maingame.h"

void CMonster::Create(string _Name, int Level, int Damage, int Hp, int Exp, int Gold)
{
	CObj::Create(_Name,Level,Damage,Hp,Exp,Gold);
}

void CMonster::Print()
{
	CObj::Print();
	cout << "����ġ : " <<m_iMaxExp << endl;
	cout << "������ : " << m_iGold << endl;
	cout << "=======================================" << endl;
	
}



CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}
