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
	int GetHp() { return m_pp->m_iNowHp; }
	int GetDamage() { return m_pp->m_iDamage; }
	int GetGold() { return m_pp->m_iGold; }
	void SetGold(int _Price) { m_pp->m_iGold -= _Price; }
	void AddGold(int _Price) { m_pp->m_iGold += _Price; }
	int Kill(int _Exp, int _Gold);
	void LevelUp();
	void Die(int _Exp);
	void SetInventory(string _name, int _Cnum, int _num) { m_ip[_Cnum].SetInfo(_name, _num); }
	int GetSnum(int _Num) { return m_ip[_Num].GetSnum(); }
	Player();
	~Player();
};

