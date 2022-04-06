#pragma once
#include "Item.h"
class Inventory
{
private:
	vector<Item> Inven;
	vector<Item>::iterator iter;
	int size; 
public:
	void Push(Item);
	void Pop(int Index);
	void Print();
	vector<Item>& GetInven() { return Inven; }
	int Size() { return size; }
	Inventory();
	~Inventory();
};

