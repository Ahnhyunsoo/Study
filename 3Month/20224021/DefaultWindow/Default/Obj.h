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

public:
	void Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	void Set_Dir(DIR eDir) { m_eDir = eDir; }
	void Set_Dead() { m_bDead = true; }

	float Get_fX() { return m_tInfo.fX; }
	float Get_fY() { return m_tInfo.fY; }

	const INFO& Get_Info(void) const { return m_tInfo; }
	const RECT& Get_RECT(void) const { return m_tRect; }

protected:
	void		Update_Rect(void);

protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	DIR m_eDir;
	float		m_fSpeed;
	bool m_bDead;

};

