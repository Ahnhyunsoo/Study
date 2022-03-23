#pragma once
#include "stdafx.h"
#define SAFE_DELETE(p) if(p) {delete p; p = nullptr};

typedef struct tagInfo
{
	string strName;
	int iHp;
	int iAttack;
}INFO;
