#include "stdafx.h"
#include "Paint.h"


void CPaint::Initialize(void)
{
}

int CPaint::Update(void)
{
	return 0;
}

void CPaint::Late_Update(void)
{
}

void CPaint::Render(HDC _hDC)
{
}

void CPaint::Release(void)
{
}

CPaint::CPaint()
{
}


CPaint::~CPaint()
{
}

void CPaint::Player(HDC m_hDC, INFO& m_tInfo, RECT& m_tRect)
{
	MoveToEx(m_hDC,m_tInfo.fX, m_tInfo.fY,nullptr);
	LineTo(m_hDC, m_tInfo.fX-15 , m_tInfo.fY + 50);
	MoveToEx(m_hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(m_hDC, m_tInfo.fX + 15, m_tInfo.fY + 50);
	MoveToEx(m_hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(m_hDC, m_tInfo.fX - 40, m_tInfo.fY + 10);
	MoveToEx(m_hDC, m_tInfo.fX, m_tInfo.fY, nullptr);
	LineTo(m_hDC, m_tInfo.fX, m_tInfo.fY - 30);
	MoveToEx(m_hDC, m_tInfo.fX, m_tInfo.fY - 30, nullptr);
	Ellipse(m_hDC, m_tInfo.fX - 15, m_tInfo.fY-30 - 15, m_tInfo.fX + 15, m_tInfo.fY-30 + 15);

	m_tRect.left = m_tInfo.fX - 10;
	m_tRect.right = m_tInfo.fX + 10;
	m_tRect.top = m_tInfo.fY - 10;
	m_tRect.bottom = m_tInfo.fX + 10;

}

void CPaint::Posin(HDC m_hDC, INFO& m_Posin)
{

	MoveToEx(m_hDC, m_Posin.fX, m_Posin.fY, nullptr);
	LineTo(m_hDC, m_Posin.fX += cos(m_Posin.fAngle)*50 , m_Posin.fY += sin(m_Posin.fAngle)*50);
}


void CPaint::Bullet(HDC m_hDC, INFO& m_tInfo, RECT& m_tRect)
{
	Ellipse(m_hDC, m_tInfo.fX - 10, m_tInfo.fY - 10, m_tInfo.fX + 10, m_tInfo.fY + 10);

	m_tRect.left = m_tInfo.fX - 10;
	m_tRect.right = m_tInfo.fX + 10;
	m_tRect.top = m_tInfo.fY - 10;
	m_tRect.bottom = m_tInfo.fY + 10;
}

void CPaint::Monster(HDC m_hDC, INFO& m_tInfo, RECT& m_tRect, TYPE _MonsterType)
{
	switch(_MonsterType)
	{
	case NOMAL:

		Rectangle(m_hDC, m_tInfo.fX - 30, m_tInfo.fY - 30, m_tInfo.fX + 30, m_tInfo.fY + 30);
		break;

	case BOSS:
	m_tInfo.fX = 900;
	m_tInfo.fY = 300;

	Ellipse(m_hDC, m_tInfo.fX + 200, m_tInfo.fY + 130, m_tInfo.fX + 320, m_tInfo.fY + 200);
	Ellipse(m_hDC, m_tInfo.fX - 80, m_tInfo.fY + 130, m_tInfo.fX + 50, m_tInfo.fY + 200);
	Ellipse(m_hDC, m_tInfo.fX - 90, m_tInfo.fY - 200, m_tInfo.fX + 30, m_tInfo.fY + 50);
	Ellipse(m_hDC, m_tInfo.fX + 220, m_tInfo.fY - 200, m_tInfo.fX + 320, m_tInfo.fY + 50);
	Ellipse(m_hDC, m_tInfo.fX - 80, m_tInfo.fY - 200, m_tInfo.fX + 320, m_tInfo.fY + 200);
	Ellipse(m_hDC, m_tInfo.fX + 20, m_tInfo.fY + 0, m_tInfo.fX + 70, m_tInfo.fY - 150);
	Ellipse(m_hDC, m_tInfo.fX + 170, m_tInfo.fY + 0, m_tInfo.fX + 220, m_tInfo.fY - 150);
	Ellipse(m_hDC, m_tInfo.fX + 25, m_tInfo.fY - 75, m_tInfo.fX + 65, m_tInfo.fY - 140);
	Ellipse(m_hDC, m_tInfo.fX + 175, m_tInfo.fY - 75, m_tInfo.fX + 215, m_tInfo.fY - 140);
	Ellipse(m_hDC, m_tInfo.fX + 10, m_tInfo.fY - 10, m_tInfo.fX + 230, m_tInfo.fY + 150);
	Ellipse(m_hDC, m_tInfo.fX + 30, m_tInfo.fY + 50, m_tInfo.fX + 210, m_tInfo.fY + 146);
	break;

	}
}

void CPaint::Item(HDC m_hDC, INFO& m_tInfo, RECT& m_tRect, TYPE _ItemType)
{
}
