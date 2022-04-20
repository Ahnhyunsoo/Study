#include "stdafx.h"
#include "MainGame.h"

DWORD WTime = GetTickCount();
TCHAR mName[30];
TCHAR Time[100];

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
	m_Time = 0;
	m_Score = 0;
	m_hDC = GetDC(g_hWnd);

	m1.left = 380;
	m1.right = 420;
	m1.top = 20;
	m1.bottom = 70;

	m2.left = 360;
	m2.right = 440;
	m2.top = 20;
	m2.bottom = 100;

	boss.left = 250;
	boss.right = 550;
	boss.top = 20;
	boss.bottom = 200;


	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();
	}


}

void CMainGame::Update(void)
{
	m_pPlayer->Update();
	
	if (WTime + 1000 <= GetTickCount())
	{
		if (m_Time % 5 == 0 && Gen < 5)
		{
			if (m_Score <= 10)
			{
				CMonster M(m1);
				MyMonster.push_back(M);
				Gen += 1;
			}

			else if (m_Score > 10)
			{
				CMonster M(m2);
				MyMonster.push_back(M);
				Gen += 1;
			}
			else
			{
				CMonster M(boss);
				MyMonster.push_back(M);
				Gen += 1;
			}
		}
		WTime = GetTickCount();		
	}
	for (auto iter = MyMonster.begin(); iter != MyMonster.end(); ++iter)
	{
		iter->Update();
	}
	
}

void CMainGame::Render(void)
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	m_pPlayer->Render(m_hDC);
	for (auto iter = MyMonster.begin(); iter != MyMonster.end(); ++iter)
	{
		iter->Render(m_hDC);
	}
	
	wsprintf(mName, TEXT("시간 : "));
	TextOut(m_hDC, 10, 10, mName, lstrlen(mName));

	wsprintf(Time, TEXT("%d초"), m_Time);
	TextOut(m_hDC, 60, 10, Time, lstrlen(Time));
	
}

void CMainGame::Release(void)
{
	Safe_Delete<CObj*>(m_pPlayer);

	ReleaseDC(g_hWnd, m_hDC);	
}

// 1. w,a,s,d 키를 눌러 4방향 총알쏘기
// 2. 가로 세로가 100씩 작은 렉트를 만들고 사각형 범위를 벗어나면 미사일을 삭제하라