#include "stdafx.h"
#include "MainGame.h"
#include "Obj.h"
#include "CollisionMgr.h"
#include "Player.h"
#include "CAbstractFactory.h"
#include "Functor.h"
#include "Monster.h"

DWORD WTime = GetTickCount();
TCHAR mName[30];
TCHAR Time[100];
TCHAR Stop[30];
int Count;


CMainGame::CMainGame()
	: m_bStop(false)
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Initialize(void)
{
	m_Time = 0;
	m_Score = 0;
	m_Gen = 0;
	m_MTMax = 0;
	int Count = 0;
	m_Obj_List[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	static_cast<CPlayer*>(m_Obj_List[OBJ_PLAYER].front())->Set_BulletList(&(m_Obj_List[OBJ_BULLET]));
	m_hDC = GetDC(g_hWnd);
}

void CMainGame::Update(void)
{

	KeyInput();
	
	if (!m_bStop)
	{
		Count += 1;
		if (Count == 64)
		{
			SetTime();
			SetGen();
			Count = 0;
		}
		if (m_Gen >= 3 && m_MTMax <= 2)
		{
			m_Obj_List[OBJ_MONSTER].push_back(CAbstractFactory<CMonster>::Create(WINCX + 50, 300, NOMAL));	
			
			dynamic_cast<CMonster*>(m_Obj_List[OBJ_MONSTER].back())->Set_BulletList(&(m_Obj_List[OBJ_MON_BULLET]));
		
			m_Gen = 0;
			m_MTMax += 1;
		}
	
		for (int i = 0; i < OBJ_END; ++i)
		{
			for (list<CObj*>::iterator& iter = m_Obj_List[i].begin(); iter != m_Obj_List[i].end();)
			{
				if ((*iter)->Update() == OBJ_DEAD)
				{
					Safe_Delete<CObj*>(*iter);
					iter = m_Obj_List[i].erase(iter);

					if (i == OBJ_PLAYER)
					{
						m_bStop = true;
						//나중에 루즈로 바꿀거임 
					}
				}
				else
				{
					++iter;
				}
			}
		}

	}
	

	
}

void CMainGame::Late_Update(void)
{
	if (!m_bStop)
	{
		for (int i = 0; i < OBJ_END; ++i)
		{
			for (list<CObj*>::iterator& iter = m_Obj_List[i].begin(); iter != m_Obj_List[i].end(); ++iter)
			{
				(*iter)->Set_ToPos(m_Obj_List[OBJ_PLAYER].front()->Get_Info());
				(*iter)->Late_Update();
			}
		}
		CCollisionMgr::Collision_Rect(m_Obj_List[OBJ_BULLET], m_Obj_List[OBJ_MONSTER]);
		CCollisionMgr::Collision_Rect(m_Obj_List[OBJ_MON_BULLET], m_Obj_List[OBJ_PLAYER]);
	}
	
	

}

void CMainGame::Render(void)
{
	if (!m_bStop)
	{
		Rectangle(m_hDC, 0, 0, WINCX, WINCY);

		for (int i = 0; i < OBJ_END; ++i)
		{
			for (list<CObj*>::iterator& iter = m_Obj_List[i].begin(); iter != m_Obj_List[i].end(); ++iter)
			{
				(*iter)->Render(m_hDC);
			}
		}
		wsprintf(mName, TEXT("시간 : "));
		TextOut(m_hDC, 10, 10, mName, lstrlen(mName));

		wsprintf(Time, TEXT("%d초"), m_Time);
		TextOut(m_hDC, 60, 10, Time, lstrlen(Time));

		

		Rectangle(m_hDC, WINCX, 0, WINCX+100, WINCY);
	}
	else
	{
		//TextOut(m_hDC)
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

void CMainGame::KeyInput()
{
	if (WTime + 150 < GetTickCount())
	{
		if (GetAsyncKeyState('R'))
		{
			if (m_bStop)
				m_bStop = false;
			else
				m_bStop = true;
		}
		WTime = GetTickCount();
	}
}
