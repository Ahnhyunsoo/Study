#include "stdafx.h"
#include "Maingame.h"
#include "Item.h"

void Item::Weapon()
{
	m_sName = "검";
	m_iPrice = 100;
	m_iStats = 10;
}

void Item::Armor()
{
	m_sName = "갑옷";
	m_iPrice = 100;
	m_iStats = 10;
}

void Item::Utility()
{
	m_sName = "포션";
	m_iPrice = 20;
	m_iStats = 50;
}

void Item::PrintItem()
{
	system("cls");
	Maingame::m_pp->PrintInventory();
	cout << endl << "이름 : " << m_sName << " / 가격 : " << m_iPrice << "원 / 효과 : +" << m_iStats << endl << endl;
	
	cout << "1. 구매, 2. 돌아가기 : " << endl;
	
	
}

Item::Item()
{
}


Item::~Item()
{
}
