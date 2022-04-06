#pragma once
class Obj
{
protected:
	string m_sName;
	int m_iLevel;
	int m_iDamage;
	int m_iMaxHp;
	int m_iNowHp;
	int m_iExp;
	int m_iGold;
public:
	virtual void Print();
	virtual void Create(string name, int level, int damage, int hp, int exp, int gold);
	virtual bool SetHp(int Damage);
	Obj();
	virtual ~Obj();
};

