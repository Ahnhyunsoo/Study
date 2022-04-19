#pragma once

#include "Include.h"

class CObj abstract
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void		Initialize(void)PURE;
	virtual void		Update(void)PURE;
	virtual void		Render(HDC hDC)PURE;
	virtual void		Release(void)PURE;

public:
	void			Update_Rect(void);

protected:
	INFO			m_tInfo;
	INFO			m_myRect;
	RECT			m_myRt;
	RECT			m_tRect;
	RECT			m_bullet;

	float			m_fSpeed;
};

