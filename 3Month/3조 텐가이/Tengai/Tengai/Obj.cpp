#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	m_tInfo.m_iHp = 1;
	ZeroMemory(&m_tRect, sizeof(RECT));
}


CObj::~CObj()
{
}

