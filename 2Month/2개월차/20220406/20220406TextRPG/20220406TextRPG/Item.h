#pragma once
#include "stdafx.h"
struct Item
{
	string Name;
	int Value;
	int Price;
	int Sell; 

	void Weapon() 
	{
	Name = "��";
	Value = 10;
	Price = 100;
	Sell = 55;
	}

	void Armor()
	{
		Name = "����";
		Value = 50;
		Price = 150;
		Sell = 80;
	}

	void potion()
	{
		Name = "����";
		Value = 60;
		Price = 50;
		Sell = 28;
	}
	
};
