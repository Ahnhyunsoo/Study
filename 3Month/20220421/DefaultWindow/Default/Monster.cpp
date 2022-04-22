#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

void CMonster::Initialize(void)
{
	m_tInfo.fX = 400;
	m_tInfo.fY = 300;
	m_tInfo.fCX = 20;
	m_tInfo.fCY = 20;

	m_fSpeed = 3.f;
	Update_Rect();
}

int CMonster::Update(void)
{
	if (m_bDead)
		return 1;
	m_tRect.left -= m_fSpeed;
	m_tRect.right -= m_fSpeed;

	return 0;
}

void CMonster::Late_Update(void)
{
	if (m_tRect.left <= 100)
		m_fSpeed *= -1;
	if (m_tRect.right >= WINCX - 100)
		m_fSpeed *= -1;
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release(void)
{
}
