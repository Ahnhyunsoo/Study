#pragma once
#include "stdafx.h"
struct Item �������� Ŭ������ �ȸ���� �׳� define�� ����� �������� ����ü�� �׷��� �׳� ���� ���� �� �� �����
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
	string Name = "��";
	int Value = 10;
	int Price = 100;
	int sell = 50;
	}

	void Armor()
	{
		string Name = "����";
		int Value = 50;
		int Price = 100;
		int sell = 50;
	}

	void potion()
	{
		string Name = "����";
		int Value = 10;
		int Price = 20;
		int sell = 10;
	}
	
};
