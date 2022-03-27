#pragma once
#include "Inventory.h"
class Player
{
private:
	PPInfo m_pp;
	Inventory* m_ip;
public:
	int CreatePlayer();
	void PrintInfo();
	void PrintInventory();
	void Knight();
	void Fighter();
	void Mage();
	int Hp(int _Damage);
	int GetDamage() { return m_pp->m_iDamage; }
	int Kill(int _Exp, int _Gold);
	void LevelUp();
	void Die(int _Exp);
	Player();
	~Player();
};

