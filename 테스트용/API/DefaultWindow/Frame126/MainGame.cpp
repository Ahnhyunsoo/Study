#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"

CMainGame::CMainGame()
	: m_pPlayer(nullptr)
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_DC = GetDC(g_hWnd);

	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}

}

void CMainGame::Update(void)
{
	m_pPlayer->Update();
}

void CMainGame::Render(void)
{
	//RECT rc{ 0, 0, WINCX, WINCY };

	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	//InvalidateRect(g_hWnd, &rc, TRUE);
	m_pPlayer->Render(m_DC);
}

void CMainGame::Release(void)
{
	Safe_Delete<CObj*>(m_pPlayer);
	ReleaseDC(g_hWnd, m_DC);
}
