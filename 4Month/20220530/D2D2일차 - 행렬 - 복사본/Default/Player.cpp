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
	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	m_tInfo.vDir = { 1.f, 0.f, 0.f };
	m_fangle = 1.f;
	
	m_fSpeed = 6.f;

	TankRight = 1;
	TankLeft = -1;
	TankTop = -1;
	TankBottom = 1;

	ZeroMemory(&Origin, sizeof(D3DXVECTOR3)*4);

	Origin[0].x = TankLeft;
	Origin[0].y = TankTop;
	Origin[1].x = TankRight;
	Origin[1].y = TankTop;
	Origin[2].x = TankRight;
	Origin[2].y = TankBottom;
	Origin[3].x = TankLeft;
	Origin[3].y = TankBottom;

}				

void CPlayer::Update(void)
{
	// 연산을 진행
	//Key_Input();

	Key_Input();
	Update_Rect();
	//D3DXMATRIX	matScale, matRotZ, matTrans;

	//

	//// 크기 변환 행렬 생성 함수
	//D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);

	//// z축 회전 행렬 생성 함수
	//D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(45.f));
	//
	//// 이동 행렬 생성 함수
	//D3DXMatrixTranslation(&matTrans, 1.f, 1.f, 0.f);
	////
	//m_tInfo.matWorld = matScale* matRotZ * matTrans;

	//D3DXVec3TransformCoord(&m_tInfo.vPos, &m_tInfo.vPos, &matScale);

	// 벡터와 행렬의 곱셈을 수행해주는 dx 함수

	// 위치 벡터와 행렬을 곱셈하여 최종적인 위치 벡터를 반환하는 함수
	//D3DXVec3TransformCoord(&vPos, &vPos, &m_tInfo.matWorld);

	// 위치 벡터와 행렬을 곱셈하여 최종적인 방향 벡터를 반환하는 함수
	//D3DXVec3TransformNormal(&vDir, &vDir, &m_tInfo.matWorld);

}

void CPlayer::Render(HDC hDC)
{

	/*MoveToEx(hDC, m_tInfo.vPos.x, m_tInfo.vPos.y, nullptr);
	LineTo(hDC, m_tInfo.vPos.x, m_tInfo.vPos.y);
	MoveToEx(hDC, m_tInfo.vPos.x, m_tInfo.vPos.y , nullptr);
	LineTo(hDC, m_tInfo.vPos.x , m_tInfo.vPos.y);
	MoveToEx(hDC, m_tInfo.vPos.x , m_tInfo.vPos.y , nullptr);
	LineTo(hDC, m_tInfo.vPos.x , m_tInfo.vPos.y );
	MoveToEx(hDC, m_tInfo.vPos.x , m_tInfo.vPos.y , nullptr);
	LineTo(hDC, m_tInfo.vPos.x , m_tInfo.vPos.y );*/



	MoveToEx(hDC, vLeftTop.x,vLeftTop.y ,nullptr);
	LineTo(hDC, vRightTop.x, vRightTop.y);	
	LineTo(hDC,vRightBottom.x,vRightBottom.y);	
	LineTo(hDC,vLeftBottom.x,vLeftBottom.y );
	LineTo(hDC, vLeftTop.x, vLeftTop.y);
	Ellipse(hDC, vRightTop.x - 5, vRightTop.y - 5, vRightTop.x + 5, vRightTop.y + 5);
	Ellipse(hDC, vRightBottom.x - 5, vRightBottom.y - 5, vRightBottom.x + 5, vRightBottom.y + 5);


}

void CPlayer::Release(void)
{
	
}

void CPlayer::Key_Input(void)
{
	if (GetAsyncKeyState('A'))
		m_fangle -= 5.f;

	if (GetAsyncKeyState('D'))
		m_fangle += 5.f;

	if (GetAsyncKeyState('W'))
	{
		m_tInfo.vDir.x = cosf(D3DXToRadian(m_fangle));
		m_tInfo.vDir.y = sinf(D3DXToRadian(m_fangle));
		D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);

		m_tInfo.vPos.x += m_tInfo.vDir.x * m_fSpeed;
		m_tInfo.vPos.y += m_tInfo.vDir.y * m_fSpeed;

	}
	if (GetAsyncKeyState('S'))
	{
		m_tInfo.vDir.x = cosf(D3DXToRadian(m_fangle));
		m_tInfo.vDir.y = sinf(D3DXToRadian(m_fangle));
		D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);

		m_tInfo.vPos.x -= m_tInfo.vDir.x * m_fSpeed;
		m_tInfo.vPos.y -= m_tInfo.vDir.y * m_fSpeed;
	}
}

void CPlayer::Update_Rect()
{
	

	
	D3DXMATRIX	matScale, matRotZ, matTrans;
	// 크기 변환 행렬 생성 함수
	D3DXMatrixScaling(&matScale, 40.f, 40.f, 1.f);

	// z축 회전 행렬 생성 함수
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fangle));
	
	// 이동 행렬 생성 함수
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 1.f);
	//
	m_tInfo.matWorld = matScale* matRotZ * matTrans;

	D3DXVec3TransformCoord(&vLeftTop, &Origin[0], &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&vRightTop, &Origin[1], &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&vRightBottom, &Origin[2], &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&vLeftBottom, &Origin[3], &m_tInfo.matWorld);
	D3DXVec3TransformCoord(&vLeftTop, &Origin[0], &m_tInfo.matWorld);

	//D3DXVec3TransformCoord(&m_tInfo.vPos, &m_tInfo.vPos, &matScale);

	 //벡터와 행렬의 곱셈을 수행해주는 dx 함수

	 //위치 벡터와 행렬을 곱셈하여 최종적인 위치 벡터를 반환하는 함수
	

	// 위치 벡터와 행렬을 곱셈하여 최종적인 방향 벡터를 반환하는 함수
	//D3DXVec3TransformNormal(&vDir, &vDir, &m_tInfo.matWorld);
}