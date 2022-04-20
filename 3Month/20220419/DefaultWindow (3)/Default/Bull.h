#pragma once
#include "Obj.h"
class Bull :
	public CObj
{
public:
	Bull();
	Bull(RECT rc);
	virtual ~Bull();

public:
	virtual		void	Initialize(void);
	virtual		void	Update(void);
	virtual		void	Render(HDC hDC);
	virtual		void	Release(void);
	virtual		void	Update_Rect(void);

private:
	RECT m_Bullet;

};

