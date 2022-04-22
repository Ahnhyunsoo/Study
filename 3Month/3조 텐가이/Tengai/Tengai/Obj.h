#pragma once

#include "include.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:

	virtual        void    Initialize(void)PURE;
	virtual        int    Update(void)PURE;
	virtual        void    Late_Update(void)PURE;
	virtual        void    Render(HDC _hDC)PURE;
	virtual        void    Release(void)PURE;

public:

	void    Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;        // fX ÀÇ ÁßÁ¡ÁÂÇ¥ _fX
		m_tInfo.fY = _fY;        // fY ÀÇ ÁßÁ¡ÁÂÇ¥ _fY
	}

	const    RECT&    Get_Rect(void) { return m_tRect; }
	const	 INFO&	  Get_Info(void) { return m_tInfo; }
	void Set_Dead()
	{
		m_bDead = true;
	}
protected:
	void        Update_Rect(void);


protected:

	INFO        m_tInfo;
	RECT        m_tRect;

	float        m_fSpeed;

	float        m_fAngle;

	bool        m_bDead;


};