#pragma once
#include "Obj.h"
#include "Bullet.h"
class CPlayer :
	public CObj
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
public:
	void Update_Rect();
	void Update_Bullet();
private:
	void		Key_Input(void);
	CBullet* m_pb;
	list<CBullet> MyBullet;
};

