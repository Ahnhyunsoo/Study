#pragma once

#include "Include.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual		void	Initialize(void)	PURE;
	virtual		int	Update(void)		PURE;
	virtual		void	Late_Update(void)	PURE;
	virtual		void	Render(HDC hDC)		PURE;
	virtual		void	Release(void)		PURE;
	void Set_Pos(float fX, float fY) { m_tInfo.fX = fX; m_tInfo.fY = fY; }

	void Set_PosX(float _fX) { m_tInfo.fX += _fX; }
	void Set_PosY(float _fY) { m_tInfo.fY += _fY; }

	bool		Get_Dead() { return m_bDead; }
	const INFO&		Get_Info(void) const { return m_tInfo; }
protected:
	void		Update_Rect(void);
	

protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	bool m_bDead;
	float		m_fSpeed;

};

