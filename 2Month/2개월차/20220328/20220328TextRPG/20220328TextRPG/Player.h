#pragma once
#include "Obj.h"
#include "Inventory.h"
class CPlayer : public CObj
{
private:
	CInventory* m_ivp;
	int m_iNowExp;
public:
	int CreatePlayer();
	int SetPHp(int _Damage);
	void Die(int _Exp);
	void Kill(int _Exp, int _Gold);
	void LevelUp();
	int GetDamage() { return m_iDamage; }
	void PlayerInfo();
	void InvenInfo();
	void SetInven(int _Slot);
	CPlayer();
	~CPlayer();
};

