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
	// ������ ����
	//Key_Input();

	Key_Input();

	D3DXMATRIX	matScale, matRotZ, matTrans;

	// dx���� �����ϴ� ��� �Լ��� �Ű� ������ �־��ִ� ����� ���� �׵� ��ķ� �ʱ�ȭ �� ��, �� ������ �����Ѵ�.

	// ũ�� ��ȯ ��� ���� �Լ�
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);

	// z�� ȸ�� ��� ���� �Լ�
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(45.f));
	
	// �̵� ��� ���� �Լ�
	D3DXMatrixTranslation(&matTrans, 1.f, 1.f, 0.f);
	//
	m_tInfo.matWorld = matScale* matRotZ * matTrans;

	D3DXVec3TransformCoord(&m_tInfo.vPos, &m_tInfo.vPos, &matScale);

	// ���Ϳ� ����� ������ �������ִ� dx �Լ�

	// ��ġ ���Ϳ� ����� �����Ͽ� �������� ��ġ ���͸� ��ȯ�ϴ� �Լ�
	//D3DXVec3TransformCoord(&vPos, &vPos, &m_tInfo.matWorld);

	// ��ġ ���Ϳ� ����� �����Ͽ� �������� ���� ���͸� ��ȯ�ϴ� �Լ�
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
