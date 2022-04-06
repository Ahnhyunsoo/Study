#pragma once
#include "stdafx.h"
struct Item 아이템을 클래스로 안만들고 그냥 define에 헤더만 만들어놓음 구조체만 그래서 그냥 내가 원할 때 템 만들고
{
	string Name;
	int Value;
	int Price;
	int Sell; 

	string Name() { return Name; }
	int Value() { return Value; }
	int Price() { return Price; }
	int Sell() { return Sell; }

	void Weapon() 
	{
	string Name = "검";
	int Value = 10;
	int Price = 100;
	int sell = 50;
	}

	void Armor()
	{
		string Name = "갑옷";
		int Value = 50;
		int Price = 100;
		int sell = 50;
	}

	void potion()
	{
		string Name = "포션";
		int Value = 10;
		int Price = 20;
		int sell = 10;
	}
	
};
