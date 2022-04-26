#pragma once
#include "Obj.h"
#include "Paint.h"
#include "Bullet.h"

class CMonster :
	public CObj
{
public:
	CMonster();
	virtual ~CMonster();

public:
	virtual void Initialize(void) override;
	virtual int     Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC _hDC) override;
	virtual void Release(void) override;

	void Update_Nomal();
	void Update_Boom();
	void Update_Boss();

	void Set_BulletList(list<CObj*>* pBullet) { m_Bulletlist = pBullet; }

	void Set_Turn()
	{
		if (m_bTurn)
			m_bTurn = false;
		else
			m_bTurn = true;
	}

private:
	TYPE m_eType;
	bool m_bTurn;

	list<CObj*>* m_Bulletlist;
	DWORD MTime;
};