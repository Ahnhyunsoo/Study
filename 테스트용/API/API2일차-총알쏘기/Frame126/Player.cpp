#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{
	m_tInfo.fX = 400.f;		// ���� X
	m_tInfo.fY = 300.f;		// ���� Y

	m_tInfo.fCX = 100.f;	// �÷��̾� ���� ������
	m_tInfo.fCY = 100.f;	// �÷��̾� ���� ������

	m_fSpeed = 10.f;
}

void CPlayer::Update(void)
{
	Key_Input();



	// ���ʿ��� ���� �Ǵ� �������� ��ȭ�� ���� ������ Update_Rect�Լ��� ȣ��
	Update_Rect();
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
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.fX -= m_fSpeed;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.fX += m_fSpeed;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.fY -= m_fSpeed;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.fY += m_fSpeed;
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		m_pBullet->push_back(Create_Bullet());
	}
	
	// GetKeyState()
}

CObj* CPlayer::Create_Bullet(void)
{
	CObj*		pBullet = new CBullet;
	pBullet->Initialize();

	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);

	return pBullet;
}
