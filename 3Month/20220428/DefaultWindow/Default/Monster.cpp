#include "stdafx.h"
#include "Monster.h"
#include "CollisionMgr.h"
#include "ObjMgr.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

void CMonster::Initialize(void)
{
	m_tInfo.fCX = 30;
	m_tInfo.fCY = 30;
}

int CMonster::Update(void)
{

	Update_Rect();
	return 0;

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
