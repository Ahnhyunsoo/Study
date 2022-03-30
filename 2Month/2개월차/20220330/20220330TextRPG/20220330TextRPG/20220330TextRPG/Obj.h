#pragma once
class CObj
{
protected:
	string m_sName;
	int m_iLevel;
	int m_iDamage;
	int m_iMaxHp;
	int m_iNowHp;
	int m_iMaxExp;
	int m_iGold;
public:
	virtual void Create(string _Name, int Level, int Damage, int Hp, int Exp, int Gold);
	virtual void Print();
	virtual int SetHp(int _Damage);
	virtual int GetDamage() { return m_iDamage; }
	virtual int GetGold() { return m_iGold; }
	CObj();
	virtual ~CObj();
};

