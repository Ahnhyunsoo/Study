#pragma once
#include "stdafx.h"
#include "Define.h"
#include "Field.h"


class Monster
{
private:
	MMInfo m_mp;
public:
	void Easy(MMInfo _mp);
	void Nomal(MMInfo _mp);
	void Hard(MMInfo _mp);
	void Create(Field* _fp);
	void Output();
	MMInfo GetM();
	void Release();
	Monster();
	~Monster();
};

