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
	Name = "°Ë";
	Value = 10;
	Price = 100;
	Sell = 55;
	}

	void Armor()
	{
		Name = "°©¿Ê";
		Value = 50;
		Price = 150;
		Sell = 80;
	}

	void potion()
	{
		Name = "Æ÷¼Ç";
		Value = 60;
		Price = 50;
		Sell = 28;
	}
	
};
