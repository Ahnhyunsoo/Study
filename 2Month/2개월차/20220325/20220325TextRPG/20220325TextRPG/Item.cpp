#include "stdafx.h"
#include "Maingame.h"
#include "Item.h"

void Item::Weapon()
{
	m_sName = "��";
	m_iPrice = 100;
	m_iStats = 10;
}

void Item::Armor()
{
	m_sName = "����";
	m_iPrice = 100;
	m_iStats = 10;
}

void Item::Utility()
{
	m_sName = "����";
	m_iPrice = 20;
	m_iStats = 50;
}

void Item::PrintItem()
{
	system("cls");
	Maingame::m_pp->PrintInventory();
	cout << endl << "�̸� : " << m_sName << " / ���� : " << m_iPrice << "�� / ȿ�� : +" << m_iStats << endl << endl;
	
	cout << "1. ����, 2. ���ư��� : " << endl;
	
	
}

Item::Item()
{
}


Item::~Item()
{
}
