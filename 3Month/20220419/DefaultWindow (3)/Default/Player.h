#pragma once
#include "Obj.h"
#include "Bull.h"
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
	virtual void		Update_Rect(void);

private:
	void		Key_Input(void);
	std::list<Bull> MyBullet;
};

