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
	// ������ ����
	Key_Input();

	

	// ��� ������ ���� �ڿ� �������� ��ǥ�� �ϼ�
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
	
	
	
			// Y = �� * sin(����) * �ð� - 1/2(�߷°��(9.8) * �ð� * �ð�)
			// Y = �� * sin(����) * �ð� - 1/2(�߷°��(9.8) * �ð� * �ð�)

}