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
	Inventory();
	~Inventory();
};

