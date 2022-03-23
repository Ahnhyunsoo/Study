#include "stdafx.h"
#include "Maingame.h"
#include "Player.h"
#include "Field.h"
#include "Define.h"

void Maingame::exe()
{
	fp = new Field; 
	p.Create(fp);
	if (Contury() == false)
	{
		p.Release();
		SAVE_DELETE(fp);
		return;
	}
}

bool Maingame::Contury()
{
	
	while (true)
	{
		system("cls");
		p.Output();
		int place = fp->GetPlace();
		int input = fp->PrintMenu(place);
		switch (input)
		{
		case ����� :
			fp->SetPlace(�����Ա�);
			DungeonEntry();
			continue;

		case ���� :
			cout << "���� �̱����Դϴ�." << endl;
			system("pause");
			continue;

		case ����-2:
			cout << "������ �����մϴ�" << endl;
			return false;	

		default :
			continue;
		}
	}
}

void Maingame::DungeonEntry()
{
	int place = fp->GetPlace();
	while (true)
	{
		system("cls");
		p.Output();
				
		m.Create(fp);
		if (m.GetM() == NULL)
		{
			return;
		}
		else
		{
			fp->SetPlace(����);
			Dungeon();
		}
		
				
	}
}

void Maingame::Dungeon()
{
	int place = fp->GetPlace();
	
	while (true)
	{
		system("cls");
		p.Output();
		m.Output();
		int Input = fp->PrintMenu(place);
		switch (Input)
		{
		case ���� :
			p.PlayerHp(m.GetM());
			break;

		case Hpȸ�� :
			break;

		case Mpȸ�� :
			break;

		case �������� :
			fp->SetPlace(�����Ա�);
			m.Release();
			return;
		default :
			continue;
		}
		
	}
}

Maingame::Maingame()
{
}


Maingame::~Maingame()
{
}
