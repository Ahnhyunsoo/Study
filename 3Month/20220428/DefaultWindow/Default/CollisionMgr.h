#pragma once
#include "Obj.h"
class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static bool Check_Rect(CObj* _pDest, CObj* _pSour, float *pX, float *pY);
	static void Collision_RectEx(list<CObj*> _Dest, list<CObj*> _Sour);
};

