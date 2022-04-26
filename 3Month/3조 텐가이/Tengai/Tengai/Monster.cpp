#include "stdafx.h"
#include "Monster.h"



CMonster::CMonster()
	: m_bTurn(false)
{

}


CMonster::~CMonster()
{
}

void CMonster::Initialize(void)
{
	switch (m_tInfo.m_eType)
	{
	case NOMAL:
		m_tInfo.m_iHp = 10;
		break;

	case BOOM:
		m_tInfo.m_iHp = 12;
		break;

	case BOSS:
		m_tInfo.m_iHp = 50;
		break;
	}
	m_tInfo.fSpeed = 5.f;
	MTime = GetTickCount();
}

int CMonster::Update(void)
{
	if (m_tInfo.m_bDead)
	{
		return OBJ_DEAD;
	}

	switch (m_tInfo.m_eType)
	{
	case NOMAL:
		Update_Nomal();
		break;

	case BOOM:
		Update_Boom();
		break;

	case BOSS:
		Update_Boss();
		break;
	}

	return OBJ_ALIVE;
}

void CMonster::Late_Update(void)
{
	if (m_eType != BOOM)
	{
		if (m_tInfo.fY < 0 || m_tInfo.fY > WINCY)
			Set_Turn();
	}
	if (m_tInfo.m_iHp <= 0)
	{
		m_tInfo.m_bDead = true;
	}

}

void CMonster::Render(HDC _hDC)
{
	CPaint::Monster(_hDC, m_tInfo, m_tRect, m_tInfo.m_eType);
}

void CMonster::Release(void)
{

}

void CMonster::Update_Nomal()
{
	if (MTime + 300 < GetTickCount())
	{
		m_Bulletlist->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX, m_tInfo.fY, 180 * PI / 180));

		MTime = GetTickCount();
	}
		
		
	
	
		
	if (m_tInfo.fX > 1000)
	{
		m_tInfo.fX -= m_tInfo.fSpeed;
	}
	else
	{
		if (m_bTurn)
		{
			m_tInfo.fY += m_tInfo.fSpeed;
		}
		else
		{
			m_tInfo.fY -= m_tInfo.fSpeed;
		}
	}

	
}

void CMonster::Update_Boom()
{

	float fWidth = (m_tInfo.fToX - m_tInfo.fX);
	float fHeight = (m_tInfo.fToY - m_tInfo.fY);
	float fRadius = (fWidth*fWidth) + (fHeight*fHeight);
	float fDistance = sqrtf(fRadius);

	float _sinseta = asin(fHeight / fDistance);
	float _cosseta = acos(fWidth / fDistance);
	m_tInfo.fY += sinf(_sinseta);
	m_tInfo.fX += cosf(_cosseta);
}

void CMonster::Update_Boss()
{
	if (m_tInfo.fX > 1000)
	{
		m_tInfo.fX -= m_tInfo.fSpeed;
	}
	else
	{
		if (m_bTurn)
		{
			m_tInfo.fY += m_tInfo.fSpeed;
		}
		else
		{
			m_tInfo.fY -= m_tInfo.fSpeed;
		}
	}

	m_Bulletlist->push_back(CAbstractFactory<CBullet>::Create(m_tInfo.fX + 100, m_tInfo.fY + 100, 180 * PI / 180));
}