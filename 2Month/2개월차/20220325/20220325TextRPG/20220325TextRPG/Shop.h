#pragma once
#include "Item.h"
class Shop
{
private:
	Item* m_ip;
public:
	int CreateShop();
	void WeaponShop();
	void ArmorShop();
	void UtilityShop();
	void PrintShop();
	void DeleteItem();
	Shop();
	~Shop();
};

