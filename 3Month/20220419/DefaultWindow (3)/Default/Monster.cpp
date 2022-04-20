#include "stdafx.h"
#include "Monster.h"

DWORD t = GetTickCount();

CMonster::CMonster()
{
}

CMonster::CMonster(RECT m)
{
	m_Monster.left = m.left;
	m_Monster.right = m.right;
	m_Monster.top = m.top;
	m_Monster.bottom = m.bottom;

	m_Bl = m;
		

}

CMonster::~CMonster()
{
}

void CMonster::Initialize(void)
{
	
}

void CMonster::Update(void)
{
	/*m_Monster.left -= 10;
	m_Monster.right -= 10;*/
	if (Size < 30)
	{
		if (t + 200 < GetTickCount())
		{
			CMBullet bullet(m_Bl);
			m_Bullet.push_back(m_Bl);
			Size += 1;
			t = GetTickCount();
		}
	}
	
	
	{	
		for (auto iter = m_Bullet.begin(); iter != m_Bullet.end(); ++iter)
		{	
				iter->Update();
		}
	}
	
	
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC, m_Monster.left, m_Monster.top, m_Monster.right, m_Monster.bottom);

	for (auto iter = m_Bullet.begin(); iter != m_Bullet.end(); ++iter)
	{		
			iter->Render(hDC);
		
	}
	
}

void CMonster::Release(void)
{
}

void CMonster::Update_Rect(void)
{
}
