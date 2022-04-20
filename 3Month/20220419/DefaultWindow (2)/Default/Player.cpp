#include "stdafx.h"
#include "Player.h"

DWORD PrevTime = GetTickCount();

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


	
	
	Update_Rect();
	Update_Bullet();
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_rRect.left, m_rRect.top, m_rRect.right, m_rRect.bottom);
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	for (auto iter = MyBullet.begin(); iter != MyBullet.end(); ++iter)
	{
		Rectangle(hDC, iter->GetBl().left, iter->GetBl().top, iter->GetBl().right, iter->GetBl().bottom);
	}
	
}

void CPlayer::Release(void)
{
	
}

void CPlayer::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	m_tRect.top = LONG(m_tInfo.fY - (m_tInfo.fCY * 0.5f));
	m_tRect.right = LONG(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	m_tRect.bottom = LONG(m_tInfo.fY + (m_tInfo.fCY * 0.5f));

	m_rRect.left = LONG(m_rInfo.fX - (m_rInfo.fCX * 0.5f));
	m_rRect.top = LONG(m_rInfo.fY - (m_rInfo.fCY * 0.5f));
	m_rRect.right = LONG(m_rInfo.fX + (m_rInfo.fCX * 0.5f));
	m_rRect.bottom = LONG(m_rInfo.fY + (m_rInfo.fCY * 0.5f));
}

void CPlayer::Update_Bullet()
{
	for (auto iter = MyBullet.begin(); iter != MyBullet.end(); ++iter)
	{
		if (iter->GetLc() == 4)
		{
			iter->SetA();
			if (iter->GetBl().left < m_rRect.left)
			{
				MyBullet.erase(iter);
				break;
			}
		}
		else if (iter->GetLc() == 2)
		{
			iter->SetS();
		}
		else if (iter->GetLc() == 6)
		{
			iter->SetD();
		}
		else
			iter->SetW();
	}
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

	if (PrevTime + 100 < GetTickCount())
	{
		if (GetAsyncKeyState('A'))
		{
			
			MyBullet.push_back(CBullet(m_tRect,4));

			PrevTime = GetTickCount();
		}
		else if (GetAsyncKeyState('S'))
		{
			m_pb = new CBullet(m_tRect, 2);
			MyBullet.push_back(*m_pb);

			PrevTime = GetTickCount();
		}
		else if (GetAsyncKeyState('D'))
		{
			m_pb = new CBullet(m_tRect, 6);
			MyBullet.push_back(*m_pb);

			PrevTime = GetTickCount();
		}
		else if (GetAsyncKeyState('W'))
		{
			m_pb = new CBullet(m_tRect, 8);
			MyBullet.push_back(*m_pb);

			PrevTime = GetTickCount();
		}
	}

	


}
