#include "stdafx.h"
#include "Machine.h"
#include "Player.h"
#include "Monster.h"
#include "Stage.h"

void CMachine::exe()
{
	int Stage = 전직선택;

	CStage cs;
	while (true)
	{
		system("cls");
		int Choice = 0;
		switch (Stage)
		{
		case 전직선택:
			cp = new CPlayer;
			cs.Menu(Stage);
			cin >> Choice;
			if (Choice == 1 || Choice == 2 || Choice == 3)
			{
				cp->Character(Choice);
				Stage = 마을;
			}
			else if (Choice == 4)
			{
				cout << "아직 미구현입니다" << endl;
				system("pause");
				continue;
			}
			else if (Choice == 5)
			{
				cout << "종료합니다" << endl;
				return;
			}
			else
			{
				cout << "잘못입력하셨습니다" << endl;
				system("pause");
				continue;
			}
			break;

		case 마을:
			cp->PrintPlayer();
			cs.Menu(Stage);
			cin >> Choice;
			if (Choice == 1)
			{
				Stage = 던전입구;
				break;
			}
			else if (Choice == 2)
			{
				cout << "아직 미구현입니다" << endl;
				system("pause");
				continue;
			}
			else if (Choice == 3)
			{
				cout << "종료합니다" << endl;
				return;
			}
			else
			{
				cout << "잘못입력하셨습니다" << endl;
				system("pause");
				continue;
			}
		case 던전입구 :
			cp->PrintPlayer();
			cs.Menu(Stage);
			cin >> Choice;
			if (Choice == 1 || Choice == 2 || Choice == 3)
			{
				mp = new CMonster;
				mp->Monster(Choice);
				Stage = 던전;
				break;
			}
			if (Choice == 4)
			{
				Stage = 마을;
				break;
			}
		case 던전:
			int kill = 0;
			cp->PrintPlayer();
			mp->PrintMonster();
			cs.Menu(Stage);
			cin >> Choice;
			if (Choice == 1)
			{
				int kill = 0;
				kill = mp->State(cp->GetDamage(), cp->GetHp());
				cp->State(mp->GetDamage(), mp->GetExp(), kill);
				if (kill == 1 && cp->GetHp() > 0)
				{					
					Stage = 던전입구;
				}			
				break;
			}
			else if (Choice == 2)
			{
				cout << "도망갑니다" << endl;
				system("pause");
				Stage = 던전입구;
				break;
			}
			else if (Choice == 3)
			{

			}
		}	
	}
}