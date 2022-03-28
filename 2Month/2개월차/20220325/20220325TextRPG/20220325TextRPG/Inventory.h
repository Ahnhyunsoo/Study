#pragma once
class Inventory
{
	string m_sName;
	int m_iSlot;
	int m_iUse;
	int m_iCount;
public:
	void PrintInventory();
	void Slot(int _iSlot);
	void SetInfo(string _name, int _num);
	int GetSnum() { if (m_sName == "ºó½½·Ô") { return m_iSlot; } else { return 0; } }
	Inventory();
	~Inventory();
};

