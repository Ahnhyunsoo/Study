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

			cout << "�ǸſϷ�" << endl;
			system("pause");
			return;
		}
		cout << "�Ǹ��� �������� �����ϴ�" << endl;
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
		
		if (Inven[i].Name == "��")
		{
			
			cout << i+1 << ". " << Inven[i].Name << " | ���ݷ� : " << Inven[i].Value << endl;
		}

		else if (Inven[i].Name == "����")
		{
			cout << i + 1 << ". " << Inven[i].Name << " | ü�� : +" << Inven[i].Value << endl;
		}
		
		else
		{
			cout << i + 1 << ". " << Inven[i].Name << " | ȸ�� : +" << Inven[i].Value << endl;
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
