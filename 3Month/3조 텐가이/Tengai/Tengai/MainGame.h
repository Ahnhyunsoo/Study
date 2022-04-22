#pragma once
#include "stdafx.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize(void);
	void Update(void);
	void Late_Update(void);
	void Render(void);
	void Release(void);

private:
	int m_Time;
	int m_Score;
	list<CObj*> m_Obj_List[OBJ_END];

	HDC m_hDC;
};