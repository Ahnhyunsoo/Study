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

public:
	const INFO& Get_Info() const { return m_tInfo; }

protected:
	INFO		m_tInfo;
	

	float		m_fSpeed;

};

