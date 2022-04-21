#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_hDC = GetDC(g_hWnd);
	
	OBJ_LIST[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	OBJ_LIST[OBJ_BARREL].push_back(CAbstractFactory<CBarrel>::Create(400.f,300.f));
	dynamic_cast<CPlayer*>(OBJ_LIST[OBJ_PLAYER].front())->Set_BulletList(&OBJ_LIST[OBJ_BULLET]);

}

void CMainGame::Update(void)
{
	Key_Input();

	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter = OBJ_LIST[i].begin(); iter != OBJ_LIST[i].end();)
		{
			int Result = (*iter)->Update();
			if (Result == 1)
			{
				Safe_Delete<CObj*>(*iter);
				iter = OBJ_LIST[i].erase(iter);
			}
			else
				++iter;
		}
		
	}

	for (auto& iter : OBJ_LIST[OBJ_BULLET])
	{
		(OBJ_LIST[OBJ_PLAYER].front()->Get_fX() +
			dynamic_cast<CBarrel*>(OBJ_LIST[OBJ_BARREL].front())->Get_Cos()
	}
}

void CMainGame::Key_Input(void)
{
	if (GetAsyncKeyState('R'))
	{
		OBJ_LIST[OBJ_MONSTER].push_back(CAbstractFactory<CMonster>::Create());
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		dynamic_cast<CBarrel*>(OBJ_LIST[OBJ_BARREL].front())->SetAngle(0.01);
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		dynamic_cast<CBarrel*>(OBJ_LIST[OBJ_BARREL].front())->SetAngle(-0.01);
	}

	if (GetAsyncKeyState(VK_UP))
	{
		dynamic_cast<CPlayer*>(OBJ_LIST[OBJ_PLAYER].front())
			->Set_Pos
			(OBJ_LIST[OBJ_PLAYER].front()->Get_fX()+
			dynamic_cast<CBarrel*>(OBJ_LIST[OBJ_BARREL].front())->Get_Cos()
			,OBJ_LIST[OBJ_PLAYER].front()->Get_fY()+
			dynamic_cast<CBarrel*>(OBJ_LIST[OBJ_BARREL].front())->Get_Sin());		
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		dynamic_cast<CPlayer*>(OBJ_LIST[OBJ_PLAYER].front())
			->Set_Pos
			(OBJ_LIST[OBJ_PLAYER].front()->Get_fX() -
				dynamic_cast<CBarrel*>(OBJ_LIST[OBJ_BARREL].front())->Get_Cos()
				, OBJ_LIST[OBJ_PLAYER].front()->Get_fY() -
				dynamic_cast<CBarrel*>(OBJ_LIST[OBJ_BARREL].front())->Get_Sin());
	}

	
}

void CMainGame::Late_Update(void)
{

	for (auto& iter = OBJ_LIST[OBJ_BULLET].begin(); iter != OBJ_LIST[OBJ_BULLET].end();)
	{
		for (auto& iter2 = OBJ_LIST[OBJ_MONSTER].begin(); iter2 != OBJ_LIST[OBJ_MONSTER].end();)
		{
			
			if (1 == IntersectRect(&rc, &(*iter)->Get_RECT(), &(*iter2)->Get_RECT()))
			{
				(*iter)->Set_Dead();
				(*iter2)->Set_Dead();
			}
			++iter2;
		}
		++iter;
	}

	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter = OBJ_LIST[i].begin(); iter != OBJ_LIST[i].end();)
		{
			(*iter)->Late_Update();
			++iter;
		}
	}

	OBJ_LIST[OBJ_BARREL].back()->Set_Pos(OBJ_LIST[OBJ_PLAYER].front()->Get_fX(), OBJ_LIST[OBJ_PLAYER].front()->Get_fY());
}

void CMainGame::Render(void)
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	Rectangle(m_hDC, 100, 100, WINCX - 100, WINCY - 100);

	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter = OBJ_LIST[i].begin(); iter != OBJ_LIST[i].end();)
		{
			(*iter)->Render(m_hDC);
			++iter;
		}
	}
	
}

void CMainGame::Release(void)
{
	
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (auto& iter : OBJ_LIST[i])
			Safe_Delete<CObj*>(iter);

		OBJ_LIST[i].clear();
	}
	ReleaseDC(g_hWnd, m_hDC);	
}

// 1. w,a,s,d 키를 눌러 4방향 총알쏘기
// 2. 가로 세로가 100씩 작은 렉트를 만들고 사각형 범위를 벗어나면 미사일을 삭제하라