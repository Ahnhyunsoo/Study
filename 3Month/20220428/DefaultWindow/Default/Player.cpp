#include "stdafx.h"
#include "Player.h"

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

	m_fGravity = 1.f;
	m_fFall = 1.f;
	
	m_fSpeed = 10.f;
	Sky = 0;
	Time = 0;
	JTime = GetTickCount();
}

int CPlayer::Update(void)
{
	// 연산을 진행
	Key_Input();

	

	// 모든 연산이 끝난 뒤에 최종적인 좌표를 완성
	Update_Rect();
	return 0;
}

void CPlayer::Late_Update(void)
{
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
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

	if (GetAsyncKeyState(VK_SPACE))
	{		
		Jump();
	}
}

void CPlayer::Jump()
{
	
	if (m_tInfo.fY > 200)
	{
		m_tInfo.fY += 0 * sin(0.f) * Time - ((1 * Time*Time) / 2);
		Time += 0.04;
	}
	
	
	
			// Y = 힘 * sin(각도) * 시간 - 1/2(중력계수(9.8) * 시간 * 시간)
			// Y = 힘 * sin(각도) * 시간 - 1/2(중력계수(9.8) * 시간 * 시간)

}