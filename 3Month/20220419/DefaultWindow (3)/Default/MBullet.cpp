#include "stdafx.h"
#include "MBullet.h"
#include <random>


CMBullet::CMBullet()
{
}

CMBullet::CMBullet(RECT b)
{
	m_bl.left = b.left + 30;
	m_bl.right = b.right - 30;
	m_bl.top = b.top + 15;
	m_bl.bottom = b.bottom - 15;
}

CMBullet::~CMBullet()
{
}

void CMBullet::Initialize(void)
{
}

void CMBullet::Update(void)
{
	random_device random;
	mt19937 rd(random());
	uniform_int_distribution<int> range(1, 10);
	
		m_bl.left -= 5;
		m_bl.right -= 5;
		m_bl.top += 10;
		m_bl.bottom += 10;
	
	
}

void CMBullet::Render(HDC hDC)
{
	Rectangle(hDC, m_bl.left, m_bl.top, m_bl.right, m_bl.bottom);
}

void CMBullet::Release(void)
{
}

void CMBullet::Update_Rect(void)
{
}
