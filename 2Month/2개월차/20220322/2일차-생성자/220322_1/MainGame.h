#pragma once

#include "Student.h"

class CMainGame
{
private:
	CStudent*			m_pStudent;

public:
	void			Initialize(void);
	void			Update(void);
	void			Release(void);

public:
	CMainGame();
	~CMainGame();

};

