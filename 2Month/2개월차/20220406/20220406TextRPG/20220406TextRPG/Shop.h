#pragma once
#include "Item.h"
class Shop
{
	Item* ip;
public:
	void Update();
	void Buy();
	void Sell();
	Shop();
	~Shop();
};

