#include "stdafx.h"
#include "Inventory.h"

void CInventory::PrintInventory()
{
	cout << m_iSlot << "��: " << m_sName << " " << m_iCount << "��" << endl;
}

int CInventory::SetInven()
{
	if (m_iCount == 1)
	{
		m_sName = "�󽽷�";
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
		cout << "�������� �����ϴ�" << endl;
		system("pause");
		return 0;
	}


	string m_sName;
	int m_iSlot;
	int m_iCount;
}

CInventory::CInventory()
{
	m_sName = "����";
	m_iCount = 1;
}



CInventory::~CInventory()
{
}
