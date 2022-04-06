#pragma once
#include "Monster.h"
class Dungeon
{
private:
	Monster* m_mp;
public:
	bool Update();
	void Release() { SAVE_DELETE(m_mp);}
	void Battle();
	void Inven();
	Dungeon();
	~Dungeon();
};

