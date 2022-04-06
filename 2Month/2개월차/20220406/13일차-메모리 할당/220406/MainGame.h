#pragma once

#include "Student.h"

class CMainGame
{
private:
	vector<CStudent*>		m_vecStu;

public:
	void		Initialize(void);
	void		Update(void);
	void		Release(void);

private:
	void		Add_Data(void);
	void		Render_Data(void);
	void		Search_Data(void);
	void		Delete_Data(void);

public:
	CMainGame();
	~CMainGame();
};

