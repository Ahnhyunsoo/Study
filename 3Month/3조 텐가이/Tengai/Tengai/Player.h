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
	void Set_BulletList(list<CObj*>* b) {};
private:
	list<CObj*> m_Bulletlist;
	

	
};

