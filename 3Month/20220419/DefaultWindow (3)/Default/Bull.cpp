#include "stdafx.h"
#include "Bull.h"

Bull::Bull()
{

}

Bull::Bull(RECT rc)
{
	m_Bullet.left = rc.left+30;
	m_Bullet.top = rc.top+30;
	m_Bullet.right = rc.right-30;
	m_Bullet.bottom = rc.bottom-30;
}


Bull::~Bull()
{
}

void Bull::Initialize()
{
}

void Bull::Update(void)
{
	m_Bullet.top -= 10;
	m_Bullet.bottom -= 10;
}

void Bull::Render(HDC hDC)
{
	Ellipse(hDC, m_Bullet.left, m_Bullet.top, m_Bullet.right, m_Bullet.bottom);
}

void Bull::Release(void)
{
}

void Bull::Update_Rect(void)
{
}
