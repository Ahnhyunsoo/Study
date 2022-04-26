#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:

	virtual        void    Initialize(void);
	virtual        int     Update(void);
	virtual        void    Late_Update(void);
	virtual        void    Render(HDC _hDC);
	virtual        void    Release(void);
	
public:
	void Set_BulletList(list<CObj*>* pBullet) { m_Bulletlist = pBullet; }
	void Key_Input();
private:
	list<CObj*>* m_Bulletlist;
	INFO m_Posin;
	DWORD Time;

};

