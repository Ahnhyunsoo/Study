#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet(RECT r, int _lc)
{
	Bullet.left = r.left + 30;
	Bullet.right = r.right - 30;
	Bullet.top = r.top + 30;
	Bullet.bottom = r.bottom - 30;
	lc = _lc;
}


CBullet::~CBullet()
{
}

void CBullet::Initialize(void)
{
	
}

void CBullet::Update(void)
{
}

void CBullet::Render(HDC hDC)
{
	Rectangle(hDC, Bullet.left, Bullet.top, Bullet.right, Bullet.bottom);
}

void CBullet::Release(void)
{
}
