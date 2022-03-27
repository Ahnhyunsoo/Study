#include "stdafx.h"
#include "Maingame.h"
#include "Shop.h"



int Shop::CreateShop()
{
	if (m_ip == NULL)
	{
		m_ip = new Item;
	}
	while (true)
	{
		int Input = 0;
		Maingame::m_pp->PrintInfo();
		cout << "1. 무기상점, 2.방어구상점, 3.포션상점, 4.세리아방 : ";
		cin >> Input;
		switch (Input)
		{
		case 1:
				WeaponShop();
				return 0;
			
		case 2:
				ArmorShop();
				return 0;
			
		case 3:
				UtilityShop();
				return 0;
		
		case 4:
				return 1;
			
		default :
			continue;
		}
	}

}

void Shop::PrintShop()
{
	m_ip->PrintItem();
}

void Shop::DeleteItem()
{
	SAVE_DELETE(m_ip);
}

void Shop::WeaponShop()
{
	m_ip->Weapon();
}

void Shop::ArmorShop()
{
	m_ip->Armor();
}

void Shop::UtilityShop()
{
	m_ip->Utility();
}

Shop::Shop()
{
}


Shop::~Shop()
{
}
