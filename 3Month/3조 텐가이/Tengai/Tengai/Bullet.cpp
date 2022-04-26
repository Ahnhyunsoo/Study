#include "stdafx.h"
#include "Bullet.h"



CBullet::CBullet()
{
}


CBullet::~CBullet()
{
}

void CBullet::Initialize(void)
{
	m_tInfo.fSpeed = 5.0f;
	m_tInfo.m_iHp = 1;
}

int CBullet::Update(void)
{
	if (m_tInfo.m_bDead)
	{
		return OBJ_DEAD;
	}

	m_tInfo.fY += sinf(m_tInfo.fAngle)*m_tInfo.fSpeed;
	m_tInfo.fX += cosf(m_tInfo.fAngle)*m_tInfo.fSpeed;
	
	return OBJ_ALIVE;
}

void CBullet::Late_Update(void)
{

	if (
			m_tRect.left < 0 ||
			m_tRect.top < 0 ||
			m_tRect.right > WINCX ||
			m_tRect.bottom > WINCY
		
		)
	{
		m_tInfo.m_bDead = true;
	}
	if (m_tInfo.m_iHp <= 0)
	{
		m_tInfo.m_bDead = true;
	}

}

void CBullet::Render(HDC _hDC)
{
	CPaint::Bullet(_hDC, m_tInfo, m_tRect);
}

void CBullet::Release(void)
{
}