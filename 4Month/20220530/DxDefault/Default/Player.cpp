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
	TankPos = { 400.f,300.f,0.f };
	TankDir = { 1.f,0.f,0.f };
	GunPos = { 1.f,0.f,0.f }; 

	TankRight = 1;
	TankLeft = -1;
	TankTop = -1;
	TankBottom = 1;
	angle = 3.f;
	m_fSpeed = 5.f;

	m_TankAngle = 0.f;

	ZeroMemory(m_ptTank, sizeof(D3DXVECTOR3) * 4);
	ZeroMemory(m_ptOriginTank, sizeof(D3DXVECTOR3) * 4);
	ZeroMemory(&m_tInfo, sizeof(INFO));
	D3DXMatrixIdentity(&m_tInfo.matWorld);

	m_ptOriginTank[0].x = TankLeft;
	m_ptOriginTank[0].y = TankTop;

	m_ptOriginTank[1].x = TankRight;
	m_ptOriginTank[1].y = TankTop;

	m_ptOriginTank[2].x = TankRight;
	m_ptOriginTank[2].y = TankBottom;

	m_ptOriginTank[3].x = TankLeft;
	m_ptOriginTank[3].y = TankBottom;
}

void CPlayer::Update(void)
{
	Key_Input();
	
	Update_Tank();

	D3DXMATRIX	matScale, matRotZ, matTrans;

	// dx���� �����ϴ� ��� �Լ��� �Ű� ������ �־��ִ� ����� ���� �׵� ��ķ� �ʱ�ȭ �� ��, �� ������ �����Ѵ�.

	// ũ�� ��ȯ ��� ���� �Լ�
	D3DXMatrixScaling(&matScale, 30.f, 30.f, 1.f);

	// z�� ȸ�� ��� ���� �Լ�
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_TankAngle));

	//matScale**matTrans
	m_tInfo.matWorld = matScale * matRotZ;
	//D3DXVec3TransformNormal(&TankPos, &TankPos, &m_tInfo.matWorld);
	//D3DXVec3TransformCoord(&m_tInfo.vPos, &m_tInfo.vPos, &matScale);

	// ���Ϳ� ����� ������ �������ִ� dx �Լ�

	// ��ġ ���Ϳ� ����� �����Ͽ� �������� ��ġ ���͸� ��ȯ�ϴ� �Լ�
	//D3DXVec3TransformCoord(&Tank, &Tank, &m_tInfo.matWorld);
	//D3DXVec3TransformNormal(&Gun, &Gun, &m_tInfo.matWorld);

	// ��ġ ���Ϳ� ����� �����Ͽ� �������� ���� ���͸� ��ȯ�ϴ� �Լ�
	//D3DXVec3TransformNormal(&vDir, &vDir, &m_tInfo.matWorld);

}

void CPlayer::Render(HDC hDC)
{
	MoveToEx(hDC, int(m_ptTank[0].x),int(m_ptTank[0].y), nullptr);
	LineTo(hDC, int(m_ptTank[1].x), int(m_ptTank[1].y));
	LineTo(hDC, int(m_ptTank[2].x), int(m_ptTank[2].y));
	LineTo(hDC, int(m_ptTank[3].x), int(m_ptTank[3].y));
	LineTo(hDC, int(m_ptTank[0].x), int(m_ptTank[0].y));
	Ellipse(hDC, m_ptTank[1].x - 5, m_ptTank[1].y - 5, m_ptTank[1].x + 5, m_ptTank[1].y + 5);
	Ellipse(hDC, m_ptTank[2].x - 5, m_ptTank[2].y - 5, m_ptTank[2].x + 5, m_ptTank[2].y + 5);


	Rectangle(hDC, m_tInfo.vPos.x-20, m_tInfo.vPos.y-20, m_tInfo.vPos.x + 15, m_tInfo.vPos.y + 15);

	MoveToEx(hDC, TankPos.x, TankPos.y, nullptr);
	LineTo(hDC, TankPos.x + cosf(angle)*60, TankPos.y - sinf(angle)*60);
}

void CPlayer::Release(void)
{
	
}

void CPlayer::Update_Tank()
{
	D3DXMATRIX	matScale, matRotZ, matTrans;

	// dx���� �����ϴ� ��� �Լ��� �Ű� ������ �־��ִ� ����� ���� �׵� ��ķ� �ʱ�ȭ �� ��, �� ������ �����Ѵ�.

	// ũ�� ��ȯ ��� ���� �Լ�
	D3DXMatrixScaling(&matScale, 30.f, 30.f, 1.f);

	// z�� ȸ�� ��� ���� �Լ�
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_TankAngle));

	// �̵� ��� ���� �Լ�
	D3DXMatrixTranslation(&matTrans, TankPos.x, TankPos.y, 1.f);

	m_tInfo.matWorld = matScale * matRotZ * matTrans;

	for (int i = 0; i < 4; ++i)
		D3DXVec3TransformCoord(&m_ptTank[i], &m_ptOriginTank[i], &m_tInfo.matWorld);
}

void CPlayer::Key_Input(void)
{
	if (GetAsyncKeyState('E'))
	{
		angle -= 0.1f;
	}
	if (GetAsyncKeyState('Q'))
	{
		angle += 0.1f;
	}
	if (GetAsyncKeyState('W'))
	{
		
		TankDir.x = cosf(D3DXToRadian(m_TankAngle));
		TankDir.y = sinf(D3DXToRadian(m_TankAngle));

		D3DXVec3Normalize(&TankDir, &TankDir);

		TankDir *= m_fSpeed;
		TankDir.z = 1.f;
		
		TankPos.x += TankDir.x;
		TankPos.y += TankDir.y;
	}
	if (GetAsyncKeyState('S'))
	{
		TankDir.x = cosf(D3DXToRadian(m_TankAngle));
		TankDir.y = sinf(D3DXToRadian(m_TankAngle));

		D3DXVec3Normalize(&TankDir, &TankDir);

		TankDir *= m_fSpeed;
		TankDir.z = 1.f;

		TankPos.x -= TankDir.x;
		TankPos.y -= TankDir.y;
	}

	if (GetAsyncKeyState('A'))
	{
		m_TankAngle -= 5.f;
	}

	if (GetAsyncKeyState('D'))
	{
		m_TankAngle += 5.f;
	}
	
}
