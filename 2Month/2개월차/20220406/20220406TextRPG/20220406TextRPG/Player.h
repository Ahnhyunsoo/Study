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
public:
	Inventory* Getip() { return m_ip; }
	void UseWP(string name, int damage) { m_sWP = name; m_iDamage += damage; }
	void RemoveWP(int damage) { m_sWP = "없음"; m_iDamage -= damage; }
	void UseAM(string name, int value) { m_sAM = name; m_iMaxHp += value; }
	void RemoveAM(int value) { m_sAM = "없음";  m_iMaxHp -= value; }
	void Print();
	void Die() { cout << "죽었습니다" << endl; system("pause"); m_iDie += 1; m_iNowHp = m_iMaxHp; }
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
	void SetGold(int price) { m_iGold -= price; }


	Player();
	~Player();
};

