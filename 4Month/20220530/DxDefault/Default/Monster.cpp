#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(void)
{
	m_tInfo.vPos = { 200.f, 100.f, 0.f };
	m_tInfo.vDir = { 1.f,0.f,0.f };
	m_vForword = { 1.f,0.f,0.f };
	m_fSpeed = 3.f;
}

void CMonster::Update(void)
{
	
	//
	//*float fDot = D3DXVec3Dot(&m_tInfo.vDir,&m_pPlayer->Get_Info().vDir);

	//float a = acos(fDot);
	
	//플레이어 포지션을 다이렉션으로 나눈걸 포지션에 넣어라 

	/*float Diagonal = sqrtf((m_tInfo.vPos.x * m_tInfo.vPos.x) + (m_tInfo.vPos.y * m_tInfo.vPos.y));

	m_tInfo.vDir.x = m_tInfo.vPos.x / Diagonal;
	m_tInfo.vDir.y = m_tInfo.vPos.y / Diagonal;
	m_tInfo.vDir.z = 0.f;

	float DiagonalP = sqrtf(m_pPlayer->Get_Info().vPos.x * m_pPlayer->Get_Info().vPos.x + m_pPlayer->Get_Info().vPos.y * m_pPlayer->Get_Info().vPos.y);
	
	D3DXVECTOR3 Temp;

	Temp.x = m_pPlayer->Get_Info().vPos.x / DiagonalP;
	Temp.y = m_pPlayer->Get_Info().vPos.y / DiagonalP;
	Temp.z = 0.f;

	float a = D3DXVec3Dot(&m_tInfo.vDir, &Temp);

	float angle = acosf(a);
	float angle2 = asinf(a);

	m_tInfo.vPos.x += cosf(angle)*3;
	m_tInfo.vPos.y -= sinf(angle2);*/
	m_tInfo.vDir = m_pPlayer->Get_Info().vPos - m_tInfo.vPos;

	float	fLength = sqrtf(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	m_tInfo.vDir.x /= fLength;
	m_tInfo.vDir.y /= fLength;
	m_tInfo.vDir.z = 0.f;
//	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);

	//float a = D3DXVec3Dot(&m_tInfo.vDir,  &m_vForword);

	float a = (m_tInfo.vDir.x * m_vForword.x) + (m_tInfo.vDir.y * m_vForword.y) + (m_tInfo.vDir.z * m_vForword.z);

	float angle = acosf(a);
	//float angle2 = asinf(a);


	/*m_tInfo.vDir.x += cos(angle);
	m_tInfo.vDir.y += cos(angle);*/

	if (m_tInfo.vPos.y < m_pPlayer->Get_Info().vPos.y)
	{
		angle *= -1.f;
	}
	m_tInfo.vPos.x +=  cosf(angle)*m_fSpeed;
	m_tInfo.vPos.y -= sinf(angle)*m_fSpeed;
	//m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
}

void CMonster::Render(HDC hDC)
{
	//m_tInfo.vDir = m_pPlayer->Get_Info().vPos - m_tInfo.vPos;

	//float	fLength = sqrtf(m_tInfo.vDir.x * m_tInfo.vDir.x + m_tInfo.vDir.y * m_tInfo.vDir.y);

	//m_tInfo.vDir.x /= fLength;
	//m_tInfo.vDir.y /= fLength;
	//m_tInfo.vDir.z = 0.f;
	////	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);

	////float a = D3DXVec3Dot(&m_tInfo.vDir,  &m_vForword);

	//float a = (m_tInfo.vDir.x * m_vForword.x) + (m_tInfo.vDir.y * m_vForword.y) + (m_tInfo.vDir.z * m_vForword.z);


	//float angle = acosf(a);
	//if (m_tInfo.vPos.y < m_pPlayer->Get_Info().vPos.y)
	//{
	//	angle *= -1.f;
	//}

	//Ellipse(hDC,
	//	int(m_tInfo.vPos.x - 50.f),
	//	int(m_tInfo.vPos.y - 50.f),
	//	int(m_tInfo.vPos.x + 50.f),
	//	int(m_tInfo.vPos.y + 50.f));

	//MoveToEx(hDC, m_tInfo.vPos.x, m_tInfo.vPos.y, nullptr);
	//LineTo(hDC, m_tInfo.vPos.x+cosf(angle)*100, m_tInfo.vPos.y - sinf(angle)*100);
}

void CMonster::Release(void)
{
}


/*
 '
*/

