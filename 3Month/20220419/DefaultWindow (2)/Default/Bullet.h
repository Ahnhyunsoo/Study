#pragma once
#include "Obj.h"
class CBullet :
	public CObj
{
public:
	CBullet(RECT r, int _lc);
	virtual ~CBullet();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
public:
	int GetLc() { return lc; }
	RECT GetBl() { return Bullet; }
	void SetA() { Bullet.left -= 10; Bullet.right -= 10; }
	void SetS() { Bullet.top += 10; Bullet.bottom += 10; }
	void SetD() { Bullet.left += 10; Bullet.right += 10; }
	void SetW() { Bullet.top -= 10; Bullet.bottom -= 10; }

private:
	RECT Bullet;
	int lc;
};

