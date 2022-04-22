#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(void)
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_fSpeed = 5.f;
}

int CMonster::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	
	
	
	Update_Rect();

	return OBJ_NOEVENT;
}

void CMonster::Late_Update(void)
{
	
}

void CMonster::Set_xy(float Seta)
{
	m_tInfo.fX += (cos(Seta)*m_tInfo.fCX/2) - 1;
	m_tInfo.fY = sin(Seta);
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release(void)
{
	
}
