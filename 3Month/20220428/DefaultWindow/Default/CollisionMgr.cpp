#include "stdafx.h"
#include "CollisionMgr.h"


CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

bool CCollisionMgr::Check_Rect(CObj* _Dest, CObj* _Sour, float* fX, float* fY)
{
	float fWidth = abs(_Dest->Get_Info().fX - _Sour->Get_Info().fX);
	float fHeight = abs(_Dest->Get_Info().fY - _Sour->Get_Info().fY);

	float fCX = (_Dest->Get_Info().fCX + _Sour->Get_Info().fCX) * 0.5f;
	float fCY = (_Dest->Get_Info().fCY + _Sour->Get_Info().fCY) * 0.5f;

	if ((fCX > fWidth) && (fCY > fHeight))
	{
		*fX = fCX - fWidth;
		*fY = fCY - fHeight;

		return true;
	}
	
	return false;

}

void CCollisionMgr::Collision_RectEx(list<CObj*> _Dest, list<CObj*> _Sour)
{
	for (auto& Dest : _Dest)
	{
		for (auto& Sour : _Sour)
		{
			float	fX = 0.f, fY = 0.f;

			if (Check_Rect(Dest, Sour, &fX, &fY))
			{
				if (fX > fY)
				{
					if (Dest->Get_Info().fY > Sour->Get_Info().fY)
						Sour->Set_PosY(-fY);
					else
						Sour->Set_PosY(fY);				
				}
				else
				{
					// 좌 충돌
					if (Dest->Get_Info().fX > Sour->Get_Info().fX)
						Sour->Set_PosX(-fX);

					// 우 충돌
					else
						Sour->Set_PosX(fX);
				}
			}
		}
	}
}
