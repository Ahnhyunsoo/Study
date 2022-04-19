#pragma once

#include "Include.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual		void	Initialize(void)	PURE;
	virtual		void	Update(void)		PURE;
	virtual		void	Render(HDC hDC)		PURE;
	virtual		void	Release(void)		PURE;


protected:
	INFO		m_tInfo;
	RECT		m_tRect;

	INFO		m_rInfo;
	RECT		m_rRect;

	float		m_fSpeed;

};

