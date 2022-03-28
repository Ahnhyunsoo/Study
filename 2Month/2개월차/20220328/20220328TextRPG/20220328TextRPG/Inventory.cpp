#include "stdafx.h"
#include "Inventory.h"

void CInventory::PrintInventory()
{
	cout << m_iSlot << "번: " << m_sName << " " << m_iCount << "개" << endl;
}

int CInventory::SetInven()
{
	if (m_iCount == 1)
	{
		m_sName = "빈슬롯";
		m_iCount -= 1;
		return 1;
	}
	else if (m_iCount > 1)
	{
		return 1;
		m_iCount -= 1;
	}
	else
	{
		cout << "아이템이 없습니다" << endl;
		system("pause");
		return 0;
	}


	string m_sName;
	int m_iSlot;
	int m_iCount;
}

CInventory::CInventory()
{
	m_sName = "포션";
	m_iCount = 1;
}



CInventory::~CInventory()
{
}
