#pragma once
#include "Obj.h"

template <typename T>
class CAbstractFactory
{
public:
	CAbstractFactory()
	{
	}

	~CAbstractFactory()
	{
	}

public:
	static CObj* Create()
	{
		CObj* _Temp = new T;
		_Temp->Initialize();
		return _Temp;
	}
	static CObj* Create(float _fX, float _fY, DIR _Dir = DIR_END)
	{
		CObj* _Temp = new T;
		_Temp->Initialize();
		_Temp->Set_Dir(_Dir);
		_Temp->Set_Pos(_fX, _fY);
		return _Temp;
	}
};