#pragma once
#include "Item.h"
class Inventory
{
private:
	vector<Item> Inven;
	vector<Item>::iterator iter;
	int size; �̰� �κ��丮�� 
public:
	void Push(Item);
	void Pop(Item);
	int Size() { return size; }
	Inventory();
	~Inventory();
};

