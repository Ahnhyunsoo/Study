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


	m_fSpeed = 3.f;
}

void CPlayer::Update(void)
{
	// 연산을 진행
	//Key_Input();

	Key_Input();

	D3DXMATRIX	matScale, matRotZ, matTrans;

	// dx에서 제공하는 행렬 함수는 매개 변수로 넣어주는 행렬을 먼저 항등 행렬로 초기화 한 후, 값 적용을 수행한다.

	// 크기 변환 행렬 생성 함수
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);

	// z축 회전 행렬 생성 함수
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(45.f));
	
	// 이동 행렬 생성 함수
	D3DXMatrixTranslation(&matTrans, 1.f, 1.f, 0.f);
	//
	m_tInfo.matWorld = matScale* matRotZ * matTrans;

	D3DXVec3TransformCoord(&m_tInfo.vPos, &m_tInfo.vPos, &matScale);

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

	MoveToEx(hDC, m_tInfo.vPos.x-50, m_tInfo.vPos.y-50, nullptr);
	LineTo(hDC, m_tInfo.vPos.x + 50, m_tInfo.vPos.y - 50);
	MoveToEx(hDC, m_tInfo.vPos.x +50, m_tInfo.vPos.y - 50, nullptr);
	LineTo(hDC, m_tInfo.vPos.x + 50, m_tInfo.vPos.y + 50);
	MoveToEx(hDC, m_tInfo.vPos.x + 50, m_tInfo.vPos.y + 50, nullptr);
	LineTo(hDC, m_tInfo.vPos.x - 50, m_tInfo.vPos.y + 50);
	MoveToEx(hDC, m_tInfo.vPos.x - 50, m_tInfo.vPos.y + 50, nullptr);
	LineTo(hDC, m_tInfo.vPos.x -50, m_tInfo.vPos.y - 50);
}

void CPlayer::Release(void)
{
	
}

void CPlayer::Key_Input(void)
{
	if (GetAsyncKeyState(VK_LEFT))
		m_tInfo.vPos.x -= m_fSpeed;

	if (GetAsyncKeyState(VK_RIGHT))
		m_tInfo.vPos.x -= m_fSpeed;

	if (GetAsyncKeyState(VK_UP))
		m_tInfo.vPos.x -= m_fSpeed;

	if (GetAsyncKeyState(VK_DOWN))
		m_tInfo.vPos.x -= m_fSpeed;
}
