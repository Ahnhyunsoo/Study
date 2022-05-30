#include "stdafx.h"
#include "Player.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize(void)
{

	D3DXMatrixIdentity(&m_tInfo.matWorld);

	m_tInfo.vPos = { 400.f,300.f,0.f };
	m_tInfo.vDir = { 1.f,0.f,0.f };  


	Tank[0].x = -1.f;
	Tank[0].y = -1.f;
	Tank[1].x = 1.f;
	Tank[1].y = -1.f;
	Tank[2].x = 1.f;
	Tank[2].y = 1.f;
	Tank[3].x = -1.f;
	Tank[3].y = 1.f;

	m_fAngle = 5.f;
	m_fSpeed = 5.f;
}

void CPlayer::Update(void)
{
	Tank[0].x = -1.f;
	Tank[0].y = -1.f;
	Tank[1].x = 1.f;
	Tank[1].y = -1.f;
	Tank[2].x = 1.f;
	Tank[2].y = 1.f;
	Tank[3].x = -1.f;
	Tank[3].y = 1.f;
	
	Key_Input();
	m_tInfo.vDir = { 1.f,0.f,0.f };
	Update_Rect();
	
	


	
}

void CPlayer::Render(HDC hDC)
{
	MoveToEx(hDC, Tank[0].x, Tank[0].y, nullptr);
	LineTo(hDC, Tank[1].x, Tank[1].y);
	LineTo(hDC,Tank[2].x,Tank[2].y);
	LineTo(hDC,Tank[3].x, Tank[3].y);
	LineTo(hDC,Tank[0].x, Tank[0].y);
	Ellipse(hDC, Tank[1].x - 5, Tank[1].y - 5, Tank[1].x + 5, Tank[1].y + 5);
	Ellipse(hDC, Tank[2].x - 5, Tank[2].y - 5, Tank[2].x + 5, Tank[2].y + 5);
}

void CPlayer::Release(void)
{
	
}

void CPlayer::Key_Input(void)
{
	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	if (GetAsyncKeyState('A'))
	{
		m_fAngle -= 3.f;
	}
	if (GetAsyncKeyState('D'))
	{
		m_fAngle += 3.f;
	}
	if (GetAsyncKeyState('W'))
	{
		m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;
		m_tInfo.vPos.y += m_tInfo.vDir.y *m_fSpeed;
	}
	if (GetAsyncKeyState('S'))
	{
		m_tInfo.vPos.x -= m_tInfo.vDir.x * m_fSpeed;
		m_tInfo.vPos.y -= m_tInfo.vDir.y * m_fSpeed;
	} 
	
}

void CPlayer::Update_Rect()
{
	D3DXMATRIX	matScale, matRotZ, matTrans;

	// dx에서 제공하는 행렬 함수는 매개 변수로 넣어주는 행렬을 먼저 항등 행렬로 초기화 한 후, 값 적용을 수행한다.

	// 크기 변환 행렬 생성 함수
	D3DXMatrixScaling(&matScale, 30.f, 30.f, 1.f); 

	// z축 회전 행렬 생성 함수  
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));

	// 이동 행렬 생성 함수 스케일이 속도높여주는지 테스트할방법찾음
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x,m_tInfo.vPos.y, 1.f);
	//m_tInfo.vPos.x, m_tInfo.vPos.y
	m_tInfo.matWorld = matScale* matRotZ * matTrans;

	D3DXVec3TransformCoord(&Tank[0], &Tank[0], &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&Tank[1], &Tank[1], &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&Tank[2], &Tank[2], &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&Tank[3], &Tank[3], &m_tInfo.matWorld);
	D3DXVec3TransformNormal(&m_tInfo.vDir, &m_tInfo.vDir, &m_tInfo.matWorld);
}
