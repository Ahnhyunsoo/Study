#pragma once
#include "Obj.h"
class Player :
	public Obj
{
private:
	int m_iNowExp;
	string m_sWP;
	string m_sAM;
public:
	void Print();
	void Create(string name, int level, int damage, int hp, int exp, int gold);
	Player();
	~Player();
};

