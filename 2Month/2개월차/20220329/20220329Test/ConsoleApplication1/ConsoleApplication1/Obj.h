#pragma once
class CObj
{
protected:
	string m_sName;
	int m_iLevel;
	int m_iDamage;
	int m_iMaxHp;
	int m_iNowHp;
public:
	virtual void Create(string _Name, int _Damage, int _Hp);
	virtual void Print();
	virtual void Test();
	CObj();
	~CObj();
};

