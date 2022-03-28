#include "stdafx.h"
#include "Maingame.h"
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

void Inventory::SetInfo(string _name, int _num)
{
	if (_num == 1)
	{
		m_sName = _name;
		m_iCount += 1;
	}
	else 
	{
		if (_name == "°Ë")
		{
			Maingame::m_pp->AddGold(50);
			if (m_iCount <= 1)
			{
				m_sName = "ºó½½·Ô";
				m_iCount -= 1;
			}
			else
			{
				m_iCount -= 1;
			}
		}
		else if (_name == "°©¿Ê")
		{
			Maingame::m_pp->AddGold(50);
			if (m_iCount <= 1)
			{
				m_sName = "ºó½½·Ô";
				m_iCount -= 1;
			}
			else
			{
				m_iCount -= 1;
			}
		}
		else
		{
			Maingame::m_pp->AddGold(10);
			if (m_iCount <= 1)
			{
				m_sName = "ºó½½·Ô";
				m_iCount -= 1;
			}
			else
			{
				m_iCount -= 1;
			}
		}
		
		
	}
}


Inventory::~Inventory()
{
}
