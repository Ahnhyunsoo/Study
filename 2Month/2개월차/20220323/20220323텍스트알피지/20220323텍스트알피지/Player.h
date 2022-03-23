#pragma once
#include "stdafx.h"
#include "Define.h"
#include "Field.h"


class Player
{
private:
	PPInfo pp;
public:
	void Warrior(PPInfo pp);
	void Wizard(PPInfo pp);
	void Thief(PPInfo pp);
	void Create(Field* m_fp);
	void Output();
	void Release();
	void PlayerHp(MMInfo _mp);
	PPInfo GetP();
	Player();
	~Player();
};

