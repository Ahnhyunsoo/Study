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
	RECT			m_tRect;	

	float			m_fSpeed;
};

