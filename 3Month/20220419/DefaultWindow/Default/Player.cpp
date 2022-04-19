#include "stdafx.h"
#include "Player.h"

DWORD		dwOldTime = GetTickCount();

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;

	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_rInfo.fX = 400.f;
	m_rInfo.fY = 300.f;

	m_rInfo.fCX = 700.f;
	m_rInfo.fCY = 500.f;

	

	m_fSpeed = 10.f;
}

void CPlayer::Update(void)
{
	
	// 연산을 진행
	Key_Input();
	ShotBullet();
	// 모든 연산이 끝난 뒤에 최종적인 좌표를 완성
	Update_Rect();
	
	
}

void CPlayer::Render(HDC hDC)
{
	
	Rectangle(hDC, m_myRect.left, m_myRect.top, m_myRect.right, m_myRect.bottom);
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	
		for (auto iter = MyBullet.begin(); iter != MyBullet.end(); ++iter)
		{
			Rectangle(hDC, iter->b.left, iter->b.top, iter->b.right, iter->b.bottom);
		}

	
	
	
	
	
}

void CPlayer::Release(void)
{
	
}

void CPlayer::Key_Input(void)
{
	
	// GetKeyState
	if (GetAsyncKeyState(VK_LEFT))
		m_tInfo.fX -= m_fSpeed;

	if (GetAsyncKeyState(VK_RIGHT))
		m_tInfo.fX += m_fSpeed;

	if (GetAsyncKeyState(VK_UP))
		m_tInfo.fY -= m_fSpeed;

	if (GetAsyncKeyState(VK_DOWN))
		m_tInfo.fY += m_fSpeed;

	if (GetAsyncKeyState('A'))
	{
		if (dwOldTime + 100 < GetTickCount())
		{		
			Update_Bullet(4);
			dwOldTime = GetTickCount();
		}
	}

	if (GetAsyncKeyState('S'))
	{
		if (dwOldTime + 100 < GetTickCount())
		{
			Update_Bullet(2);
			dwOldTime = GetTickCount();
		}
	}

	if (GetAsyncKeyState('D'))
	{
		if (dwOldTime + 100 < GetTickCount())
		{
			Update_Bullet(6);
			dwOldTime = GetTickCount();
		}
	}

	if (GetAsyncKeyState('W'))
	{
		if (dwOldTime + 100 < GetTickCount())
		{
			Update_Bullet(8);
			dwOldTime = GetTickCount();
		}
	}
}



