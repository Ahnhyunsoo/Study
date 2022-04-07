#include "stdafx.h"
#include "Inventory.h"
#include "Game.h"

void Inventory::Push(Item item) 
{
	Inven.push_back(item);  
}

void Inventory::Pop(int Index)
{
		iter = Inven.begin() + Index - 1;
		if ((*iter).Value != NULL)
		{
			p->Sell(iter->Sell);
			iter = Inven.erase(iter);

			cout << "판매완료" << endl;
			system("pause");
			return;
		}
		cout << "판매할 아이템이 없습니다" << endl;
		system("pause");	
}

void Inventory::UnLock(int Index)
{
	iter = Inven.begin() + Index - 1;
	if ((*iter).Value != NULL)
	{
		iter = Inven.erase(iter);
		return;
	}
}

void Inventory::Print()
{
	for (size_t i = 0; i < Inven.size(); ++i)
	{
		
		if (Inven[i].Name == "검")
		{
			
			cout << i+1 << ". " << Inven[i].Name << " | 공격력 : " << Inven[i].Value << endl;
		}

		else if (Inven[i].Name == "갑옷")
		{
			cout << i + 1 << ". " << Inven[i].Name << " | 체력 : +" << Inven[i].Value << endl;
		}
		
		else
		{
			cout << i + 1 << ". " << Inven[i].Name << " | 회복 : +" << Inven[i].Value << endl;
		}
		
		
	}
	cout << "========================================" << endl;
	


}



Inventory::Inventory()
	:size(5)
{
	Inven.reserve(5);
}


Inventory::~Inventory()
{
}
