#include "stdafx.h"
#include "Barrel.h"


CBarrel::CBarrel()
{
}


CBarrel::~CBarrel()
{
}

void CBarrel::Initialize(void)
{	
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;
	m_Angle = 0;
}

int CBarrel::Update(void)
{
	
	return 0;
}

void CBarrel::Late_Update(void)
{
}

void CBarrel::Render(HDC hDC)
{
	MoveToEx(hDC, m_tInfo.fX, m_tInfo.fY,nullptr);
	LineTo(hDC, cos(m_Angle)*(m_tInfo.fCX) + m_tInfo.fX , sin(m_Angle)*(m_tInfo.fCY) + m_tInfo.fY);
}

void CBarrel::Release(void)
{
}
