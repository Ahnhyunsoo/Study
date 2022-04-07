#pragma once
#include "Obj.h"
#include "Inventory.h"
class Player :
	public Obj
{
private:
	Inventory* m_ip;
	int m_iDie;
	int m_iKill;
	int m_iNowExp;
	int m_iAttack;
	int m_igetdamage;
	string m_sWP;
	string m_sAM;
	int Wvalue;
	int Avalue;
public:
	Inventory* Getip() { return m_ip; }
	void Use(string name, int value);
	void Remove(int type);
	void Print();
	void Die() { cout << "ав╬З╫ю╢о╢ы" << endl; system("pause"); m_iDie += 1; m_iNowHp = m_iMaxHp; }
	void Kill(int Exp, int Gold);
	void LevelUp();
	bool Create();
	int GetDamage() { return m_iDamage;}
	void Fighter();
	void Wizard();
	void Attack() { m_iAttack += 1; }
	void HitDamage() { m_igetdamage += 1; }
	int GetAttack() { return m_iAttack; }
	int GetHit() { return m_igetdamage; }
	int GetKill() { return m_iKill; }
	int GetDie() { return m_iDie; }
	int GetGold() { return m_iGold; }
	string GetWP() { return m_sWP; }
	string GetAM() { return m_sAM; }
	void SetGold(int price) { m_iGold -= price; }
	void Sell(int price) { m_iGold += price; }


	Player();
	~Player();
};

