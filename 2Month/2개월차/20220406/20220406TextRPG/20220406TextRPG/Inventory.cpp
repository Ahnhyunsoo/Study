#include "stdafx.h"
#include "Inventory.h"

void Inventory::Push(Item item) 
{
	Inven.push_back(item);  
}

void Inventory::Pop(Item item)
{
	for (iter = Inven.begin(); iter != Inven.end();) 
	{
		if (iter->Name == item.Name) 
		{
			iter = Inven.erase(iter); 
			
			�� ���� �ø��� ������ ��ϰ� �乬�� ��ž���� �ҰԿ� ���Ϻ��� ��.�� 

		}
	}	
}

Inventory::Inventory()
	:size(5)
{
	Inven.reserve(5);
}


Inventory::~Inventory()
{
}
