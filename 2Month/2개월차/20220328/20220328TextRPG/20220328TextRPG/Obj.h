#pragma once
class CObj
{
protected:
	string m_sName;
	int m_iDamage;
	int m_iMaxHp;
	int m_iNowHp;
	int m_iLevel;
	int m_iGold;
	int m_iExp;
	
public:
	CObj();
	~CObj();
};

