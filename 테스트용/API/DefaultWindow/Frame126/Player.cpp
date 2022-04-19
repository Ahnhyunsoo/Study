#include "stdafx.h"
#include "Player.h"
#include "MainGame.h"



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

	m_myRect.fX = 400.f;
	m_myRect.fY = 300.f;
	m_myRect.fCX = 700.f;
	m_myRect.fCY = 500.f;

	
}

void CPlayer::Update(void)
{
	Key_Input();

	// ���ʿ��� ���� �Ǵ� �������� ��ȭ�� ���� ������ Update_Rect�Լ��� ȣ��
	Update_Rect();
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_myRt.left, m_myRt.top, m_myRt.right, m_myRt.bottom);
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	Rectangle(hDC, m_bullet.left, m_bullet.top, m_bullet.right, m_bullet.bottom);
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
	CMainGame main;
	if (GetAsyncKeyState('A'))
	{
		wchar_t lotation;
		lotation = wchar_t("��");
		
		
		m_bullet.left = m_tInfo.fX - 20;
		m_bullet.right = m_tInfo.fX + 20;
		m_bullet.top = m_tInfo.fY - 20;
		m_bullet.bottom = m_tInfo.fY + 20;
		
		main.CreateBullet(m_bullet);
		main.ShotBullet(lotation, m_myRt); 
	
	}
	if (main.GetBullet().empty == 0)
	{
		auto iter = main.GetBullet().begin();
		iter->top -= 10;
		iter->bottom -= 10;
	}
	
	// GetKeyState()
}

