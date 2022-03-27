#include "stdafx.h"
#include "Inventory.h"


void Inventory::PrintInventory()
{
	cout << m_iSlot << ". " << m_sName << " " << m_iCount << "°³" << endl;

}

void Inventory::Slot(int _iSlot)
{
	m_iSlot = _iSlot;
}

Inventory::Inventory()
{
	m_sName = "ºó½½·Ô";
	m_iUse = 0;
	m_iCount = 0;
}


Inventory::~Inventory()
{
}
