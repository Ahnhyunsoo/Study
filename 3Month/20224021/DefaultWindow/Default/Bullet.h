#pragma once
#include "Obj.h"
class CBullet :
	public CObj
{
public:
	CBullet();
	virtual ~CBullet();

public:
	virtual		void	Initialize(void);
	virtual		int	Update(void);
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC);
	virtual		void	Release(void);
	RECT	GetB() { return m_tRect; }
	void Setf(float Cos, float Sin) { m_tInfo.fX += Cos, m_tInfo.fY += Sin; }
	
};

