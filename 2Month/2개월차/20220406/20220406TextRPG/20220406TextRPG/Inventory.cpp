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
			
			형 저도 올만에 집가서 운동하고 밥묵고 데탑으로 할게용 내일봐요 ㅎ.ㅎ 

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
