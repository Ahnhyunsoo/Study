#include "stdafx.h"
#include "Player.h"
#include "Paint.h"
#include "Bullet.h"



CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

void CPlayer::Initialize(void)
{
	m_tInfo.fX = 100;
	m_tInfo.fY = 360;
	m_Posin.fX = m_tInfo.fX;
	m_Posin.fY = m_tInfo.fY;
	m_Posin.fAngle = 0.f;
	m_tInfo.m_iHp = 10;
	Time = GetTickCount();
}

int CPlayer::Update(void)
{
	if (m_tInfo.m_bDead)
		return OBJ_DEAD;

	Key_Input();
	
	return OBJ_ALIVE;
}

void CPlayer::Late_Update(void)
{
	m_Posin.fX = m_tInfo.fX;
	m_Posin.fY = m_tInfo.fY;

	if (m_tInfo.m_iHp <= 0)
	{
		m_tInfo.m_bDead = true;
	}
	
}

void CPlayer::Render(HDC m_hDC)
{
	CPaint::Player(m_hDC,m_tInfo, m_tRect);
	CPaint::Posin(m_hDC, m_Posin);
	
}

void CPlayer::Key_Input()
{
	if (GetAsyncKeyState(VK_UP))
	{
		if (m_tInfo.fY - 50 > 0)
		m_tInfo.fY -= 5;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (m_tInfo.fY + 50 < WINCY)
		m_tInfo.fY += 5;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (m_tInfo.fX + 40 < WINCX)
		m_tInfo.fX += 5;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (m_tInfo.fX - 40 > 0)
			m_tInfo.fX -= 5;	
	}

	if (GetAsyncKeyState('Z'))
	{
		if(m_Posin.fAngle >= -1.f)
			m_Posin.fAngle -= 0.03f; /*앵글이 -60도보다 크면 앵글을 - 해라 
									앵글을 -하면 팔이 위로가고
									앵글을 +하면 팔이 아래로감 */
	}

	if (GetAsyncKeyState('X'))
	{
		if (m_Posin.fAngle <= 1.f) //앵글이 60도 보다 작으면 앵글을 더해라
			m_Posin.fAngle += 0.03f;
		
	}

	

	if (Time + 300 < GetTickCount())
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			m_Bulletlist->push_back(CAbstractFactory<CBullet>::Create(m_Posin.fX , m_Posin.fY , m_Posin.fAngle));
		}
		Time = GetTickCount();

	}
	//+ sin(m_Posin.fAngle) +cos(m_Posin.fAngle)
		
	
	

}

void CPlayer::Release(void)
{
}
