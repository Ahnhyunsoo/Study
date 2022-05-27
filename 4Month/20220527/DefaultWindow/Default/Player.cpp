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
	m_tInfo.vPos = { 400.f,300.f,0.f };
	m_tInfo.vDir = { 1.f,0.f,0.f };  

	m_fSpeed = 3.f;
}

void CPlayer::Update(void)
{
	// 연산을 진행
	
	m_tInfo.vPos += m_tInfo.vDir;


	// 모든 연산이 끝난 뒤에 최종적인 좌표를 완성

}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC,
		int(m_tInfo.vPos.x - 50.f),
		int(m_tInfo.vPos.y - 50.f),
		int(m_tInfo.vPos.x + 50.f),
		int(m_tInfo.vPos.y + 50.f));
}

void CPlayer::Release(void)
{
	
}

void CPlayer::Key_Input(void)
{
	// GetKeyState
	
}
