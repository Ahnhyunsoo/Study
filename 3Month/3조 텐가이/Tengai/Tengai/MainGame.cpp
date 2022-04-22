#include "stdafx.h"
#include "MainGame.h"
#include "Obj.h"
#include "CollisionMgr.h"
#include "Player.h"
#include "CAbstractFactory.h"
#include "Functor.h"

DWORD WTime = GetTickCount();
TCHAR mName[30];
TCHAR Time[100];

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Initialize(void)
{
	m_Time = 0;
	m_Score = 0;
	m_Obj_List[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	// 플레이어한테 총알 넘겨주기
	static_cast<CPlayer*>(m_Obj_List[OBJ_PLAYER].front())->Set_BulletList(&(m_Obj_List[OBJ_BULLET]));
	m_hDC = GetDC(g_hWnd);
}

void CMainGame::Update(void)
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (list<CObj*>::iterator& iter = m_Obj_List[i].begin(); iter != m_Obj_List[i].end();)
		{
			if ((*iter)->Update() == OBJ_DEAD)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_Obj_List[i].erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
}

void CMainGame::Late_Update(void)
{
	for (int i = 0; i < OBJ_END; ++i)
	{
		for (list<CObj*>::iterator& iter = m_Obj_List[i].begin(); iter != m_Obj_List[i].end(); ++iter)
		{
			(*iter)->Late_Update();
		}
	}

	//충돌처리 : 몬스터 vs 불릿
	CCollisionMgr::Collision_Rect(m_Obj_List[OBJ_BULLET], m_Obj_List[OBJ_MONSTER]);

}

void CMainGame::Render(void)
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	for (int i = 0; i < OBJ_END; ++i)
	{
		for (list<CObj*>::iterator& iter = m_Obj_List[i].begin(); iter != m_Obj_List[i].end(); ++iter)
		{
			(*iter)->Render(m_hDC);
		}
	}
}

void CMainGame::Release(void)
{

	for (int i = 0; i < OBJ_END; ++i)
	{
		for (list<CObj*>::iterator& iter = m_Obj_List[i].begin(); iter != m_Obj_List[i].end(); ++iter)
		{
			Safe_Delete<CObj*>(*iter);
		}
	}

	ReleaseDC(g_hWnd, m_hDC);
}