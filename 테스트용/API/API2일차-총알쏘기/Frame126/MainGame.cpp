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
	dynamic_cast<CPlayer*>(m_pPlayer)->Set_Bullet(&m_BulletList);

}

void CMainGame::Update(void)
{
	m_pPlayer->Update();

	for (auto& iter : m_BulletList)
		iter->Update();
}

void CMainGame::Render(void)
{
	//RECT rc{ 0, 0, WINCX, WINCY };
	//InvalidateRect(g_hWnd, &rc, TRUE);

	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	m_pPlayer->Render(m_DC);

	for (auto& iter : m_BulletList)
		iter->Render(m_DC);
}

void CMainGame::Release(void)
{
	Safe_Delete<CObj*>(m_pPlayer);

	for_each(m_BulletList.begin(), m_BulletList.end(), CDeleteObj());
	m_BulletList.clear();

	ReleaseDC(g_hWnd, m_DC);
}
