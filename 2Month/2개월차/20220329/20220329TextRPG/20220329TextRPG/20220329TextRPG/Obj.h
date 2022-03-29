#pragma once
class CObj
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
	virtual void CreateObj(string _Name, int _Damage, int _MaxHp, int _Exp);
	virtual void PrintObj();
	//virtual int SetHp(int _Damage);
	//virtual void Die(int _Exp);
	//virtual void Kill(int _Exp, int _Gold);
	CObj();
	~CObj();
};

