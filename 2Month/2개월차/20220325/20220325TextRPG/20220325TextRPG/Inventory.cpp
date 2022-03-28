#include "stdafx.h"
#include "Maingame.h"
#include "Inventory.h"


void Inventory::PrintInventory()
{
	cout << m_iSlot << ". " << m_sName << " " << m_iCount << "��" << endl;

}

void Inventory::Slot(int _iSlot)
{
	m_iSlot = _iSlot;
}

Inventory::Inventory()
{
	m_sName = "�󽽷�";
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
		if (_name == "��")
		{
			Maingame::m_pp->AddGold(50);
			if (m_iCount <= 1)
			{
				m_sName = "�󽽷�";
				m_iCount -= 1;
			}
			else
			{
				m_iCount -= 1;
			}
		}
		else if (_name == "����")
		{
			Maingame::m_pp->AddGold(50);
			if (m_iCount <= 1)
			{
				m_sName = "�󽽷�";
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
				m_sName = "�󽽷�";
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
