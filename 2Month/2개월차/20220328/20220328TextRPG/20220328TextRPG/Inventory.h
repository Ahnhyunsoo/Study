#pragma once
class CInventory
{
private :
	string m_sName;
	int m_iSlot;
	int m_iCount;
public:
	void PrintInventory();
	string GetName() { return m_sName; }
	void InitSlot(int _Slot) { m_iSlot = _Slot+1; }
	int SetInven();
	CInventory();
	~CInventory();
};

