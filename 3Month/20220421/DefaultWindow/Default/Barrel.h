#pragma once
#include "Obj.h"
class CBarrel :
	public CObj
{
public:
	CBarrel();
	virtual ~CBarrel();

public:
	virtual		void	Initialize(void);
	virtual		int		Update(void);
	virtual		void	Late_Update(void);
	virtual		void	Render(HDC hDC);
	virtual		void	Release(void);
public:
	void SetAngle(float a) { m_Angle += a;}
	float Get_Cos() { return cos(m_Angle)*(1); }
	float Get_Sin() { return sin(m_Angle)*(1); }
	
private:
	float m_Angle;
};

