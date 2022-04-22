#pragma once
#include "Obj.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Late_Update() override;
	virtual void Release(void) override;

public:
	void Set_BulletList(list<CObj*>* pBullet)
	{
		m_pBullet = pBullet;
	}

	

private:
	void		Key_Input(void);
	list<CObj*>* m_pBullet;
};

