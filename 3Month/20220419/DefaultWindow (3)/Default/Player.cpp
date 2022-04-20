#include "stdafx.h"
#include "Player.h"

DWORD PlayTime = GetTickCount();

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
	m_tInfo.fY = 900.f;

	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_fSpeed = 5.f;
}

void CPlayer::Update(void)
{
	// 연산을 진행
	Key_Input();
	for (auto iter = MyBullet.begin(); iter != MyBullet.end(); ++iter)
	{
		iter->Update();
	}
	// 모든 연산이 끝난 뒤에 최종적인 좌표를 완성
	Update_Rect();
}

void CPlayer::Render(HDC hDC)
{	
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
		for (auto iter = MyBullet.begin(); iter != MyBullet.end(); ++iter)
		{
			iter->Render(hDC);
		}
}

void CPlayer::Release(void)
{
	
}

void CPlayer::Update_Rect(void)
{

	m_tRect.left = LONG(m_tInfo.fX - (m_tInfo.fCX * 0.2f));
	m_tRect.top = LONG(m_tInfo.fY - (m_tInfo.fCY * 0.2f));
	m_tRect.right = LONG(m_tInfo.fX + (m_tInfo.fCX * 0.2f));
	m_tRect.bottom = LONG(m_tInfo.fY + (m_tInfo.fCY * 0.2f));
}


void CPlayer::Key_Input(void)
{
	// GetKeyState
	if (GetAsyncKeyState(VK_LEFT))

		if (m_tRect.left > m_fSpeed)
			m_tInfo.fX -= m_fSpeed;
		
		else if (m_tRect.left <= m_fSpeed)		
			m_tInfo.fX = 23;
		

	if (GetAsyncKeyState(VK_RIGHT))
		if (m_tRect.right + m_fSpeed < WINCX)		
			m_tInfo.fX += m_fSpeed;
		
		else if (m_tRect.right + m_fSpeed >= WINCX)		
			m_tInfo.fX = 777;
		

	if (GetAsyncKeyState(VK_UP))
		if (m_tRect.top > m_fSpeed)
			m_tInfo.fY -= m_fSpeed;	

		else if (m_tRect.top <= m_fSpeed)
			m_tInfo.fY = 23;
		

	if (GetAsyncKeyState(VK_DOWN))
		if(m_tRect.bottom+m_fSpeed < WINCY)
		m_tInfo.fY += m_fSpeed;

		else if (m_tRect.bottom+m_fSpeed >= WINCY)
			m_tInfo.fY = 977;

	if (GetAsyncKeyState(VK_SPACE))
	{
		if (PlayTime + 100 < GetTickCount())
		{
			Bull bullet(m_tRect);
			MyBullet.push_back(bullet);
			PlayTime = GetTickCount();
		}		
	}
		

	
}



