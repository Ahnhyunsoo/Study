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
	void    KeyInput(void);
	void	SetTime() { m_Time += 1; }
	void	SetGen() { m_Gen += 1; }
	
private:
	int m_Time;
	int m_Gen;
	int m_Score;
	int m_MTMax;
	bool m_bStop;
	list<CObj*> m_Obj_List[OBJ_END];

	HDC m_hDC;
};