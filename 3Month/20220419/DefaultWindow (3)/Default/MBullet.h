#pragma once
#include "Obj.h"
class CMBullet :
	public CObj
{
public:
	CMBullet();
	CMBullet(RECT b);
	virtual ~CMBullet();

public:
	virtual		void	Initialize(void);
	virtual		void	Update(void);
	virtual		void	Render(HDC hDC);
	virtual		void	Release(void);
	
protected:
	virtual void		Update_Rect(void);

private:
	RECT m_bl;
	int random;
	


};

