#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
	
}




CMonster::~CMonster()
{
}

void CMonster::Initialize(void)
{
	m_tRect.left = 400;
	m_tRect.top = 200;
	m_tRect.right = 450;
	m_tRect.bottom = 250;
	Dir = DIR_LEFT;
}

int CMonster::Update(void)
{
	if (m_tRect.left < WINCX - 700)
	{
		SetDir(DIR_RIGHT);
	}
	else if (m_tRect.right > WINCX - 100)
	{
		SetDir(DIR_LEFT);
	}
	if (Dir == DIR_LEFT)
	{
		m_tRect.left -= 3;
		m_tRect.right -= 3;
	}
	else if (Dir == DIR_RIGHT)
	{
		m_tRect.left += 3;
		m_tRect.right += 3;
	}
	return 0;
}

void CMonster::SetDir(int _Dir)
{
	Dir = _Dir;
}

void CMonster::Late_Update(void)
{
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release(void)
{
}
