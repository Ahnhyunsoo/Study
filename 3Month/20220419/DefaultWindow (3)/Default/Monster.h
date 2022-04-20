#pragma once
#include "Obj.h"
#include "MBullet.h"
class CMonster :
	public CObj
{
public:
	CMonster();
	CMonster(RECT m);
	virtual ~CMonster();

public:
	virtual		void	Initialize(void);
	virtual		void	Update(void);
	virtual		void	Render(HDC hDC);
	virtual		void	Release(void);

protected:
	virtual void		Update_Rect(void);

private:
	RECT m_Monster;
	RECT m_Bl;
	int Size = 0;
	list<CMBullet> m_Bullet;
};

