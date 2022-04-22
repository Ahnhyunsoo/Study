#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize(void)
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;
	m_fSpeed = 5.f;

	
}

int CBullet::Update(void)
{
	if (m_bDead)
		return 1;
	
	/*if (m_eDir == DIR_LEFT)
	{
		m_tInfo.fX -= m_fSpeed;
		
	}
	else if (m_eDir == DIR_RIGHT)
	{
		m_tInfo.fX += m_fSpeed;
	}
	else if (m_eDir == DIR_TOP)
	{
		m_tInfo.fY -= m_fSpeed;
	}
	else if (m_eDir == DIR_BOTTOM)
	{
		m_tInfo.fY += m_fSpeed;
	}*/

	Update_Rect();

	return 0;

	
}

void CBullet::Late_Update(void)
{
	if (m_tRect.left <= 100 || m_tRect.right >= WINCX - 100
		|| m_tRect.top <= 100 || m_tRect.bottom >= WINCY - 100)
		m_bDead = true;
		
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	/*Ellipse(hDC,m_tInfo.fX - m_tInfo.fCX * 0.5, m_tInfo.fY - m_tInfo.fCY * 0.5
	, m_tInfo.fX + m_tInfo.fCX * 0.5, m_tInfo.fY + m_tInfo.fCY * 0.5);*/
}

void CBullet::Release(void)
{
}
