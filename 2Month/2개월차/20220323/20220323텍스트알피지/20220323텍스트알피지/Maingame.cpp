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
		case 사냥터 :
			fp->SetPlace(던전입구);
			DungeonEntry();
			continue;

		case 저장 :
			cout << "아직 미구현입니다." << endl;
			system("pause");
			continue;

		case 종료-2:
			cout << "게임을 종료합니다" << endl;
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
			fp->SetPlace(던전);
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
		case 공격 :
			p.PlayerHp(m.GetM());
			break;

		case Hp회복 :
			break;

		case Mp회복 :
			break;

		case 도망가기 :
			fp->SetPlace(던전입구);
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
