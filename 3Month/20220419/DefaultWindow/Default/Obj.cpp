#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
	: m_fSpeed(0.f)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}

CObj::~CObj()
{
}

void CObj::Update_Rect(void)
{

	m_myRect.left = LONG(m_rInfo.fX - (m_rInfo.fCX * 0.5f));
	m_myRect.top = LONG(m_rInfo.fY - (m_rInfo.fCY * 0.5f));
	m_myRect.right = LONG(m_rInfo.fX + (m_rInfo.fCX * 0.5f));
	m_myRect.bottom = LONG(m_rInfo.fY + (m_rInfo.fCY * 0.5f));

	m_tRect.left   = LONG(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	m_tRect.top    = LONG(m_tInfo.fY - (m_tInfo.fCY * 0.5f));
 	m_tRect.right  = LONG(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	m_tRect.bottom = LONG(m_tInfo.fY + (m_tInfo.fCY * 0.5f));	
}

void CObj::Update_Bullet(int lc)
{
	m_bullet.b.left = (m_tInfo.fX - 20);
	m_bullet.b.top = (m_tInfo.fY - 20);
	m_bullet.b.right = (m_tInfo.fX + 20);
	m_bullet.b.bottom = (m_tInfo.fY + 20);
	m_bullet.lc = lc;
	MyBullet.push_back(m_bullet);	
}

void CObj::ShotBullet()
{
	for (auto iter = MyBullet.begin(); iter != MyBullet.end(); ++iter)
	{
		if (iter->lc == 4)
		{
			iter->b.left -= 10;
			iter->b.right -= 10;
			if (iter->b.left < m_rInfo.fX - m_rInfo.fCX / 2)
			{
				MyBullet.erase(iter);
				break;
			}
			
		}
		else if (iter->lc == 6)
		{
			iter->b.left += 10;
			iter->b.right += 10;
			if (iter->b.right > m_rInfo.fX + m_rInfo.fCX / 2)
			{
				MyBullet.erase(iter);
				break;
			}
			
		}
		if (iter->lc == 8)
		{
			iter->b.top -= 10;
			iter->b.bottom -= 10;
			if (iter->b.top < m_rInfo.fY - m_rInfo.fCY / 2)
			{
				MyBullet.erase(iter);
				break;
			}
			
		}
		if (iter->lc == 2)
		{
			iter->b.top += 10;
			iter->b.bottom += 10;
			if (iter->b.bottom > m_rInfo.fY + m_rInfo.fCY / 2)
			{
				MyBullet.erase(iter);
				break;
			}
			
		}
	}
	
	
}
