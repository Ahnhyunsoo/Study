#include "stdafx.h"
#include "Machine.h"
#include "Player.h"
#include "Monster.h"
#include "Stage.h"

void CMachine::exe()
{
	int Stage = ��������;

	CStage cs;
	while (true)
	{
		system("cls");
		int Choice = 0;
		switch (Stage)
		{
		case ��������:
			cp = new CPlayer;
			cs.Menu(Stage);
			cin >> Choice;
			if (Choice == 1 || Choice == 2 || Choice == 3)
			{
				cp->Character(Choice);
				Stage = ����;
			}
			else if (Choice == 4)
			{
				cout << "���� �̱����Դϴ�" << endl;
				system("pause");
				continue;
			}
			else if (Choice == 5)
			{
				cout << "�����մϴ�" << endl;
				return;
			}
			else
			{
				cout << "�߸��Է��ϼ̽��ϴ�" << endl;
				system("pause");
				continue;
			}
			break;

		case ����:
			cp->PrintPlayer();
			cs.Menu(Stage);
			cin >> Choice;
			if (Choice == 1)
			{
				Stage = �����Ա�;
				break;
			}
			else if (Choice == 2)
			{
				cout << "���� �̱����Դϴ�" << endl;
				system("pause");
				continue;
			}
			else if (Choice == 3)
			{
				cout << "�����մϴ�" << endl;
				return;
			}
			else
			{
				cout << "�߸��Է��ϼ̽��ϴ�" << endl;
				system("pause");
				continue;
			}
		case �����Ա� :
			cp->PrintPlayer();
			cs.Menu(Stage);
			cin >> Choice;
			if (Choice == 1 || Choice == 2 || Choice == 3)
			{
				mp = new CMonster;
				mp->Monster(Choice);
				Stage = ����;
				break;
			}
			if (Choice == 4)
			{
				Stage = ����;
				break;
			}
		case ����:
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
					Stage = �����Ա�;
				}			
				break;
			}
			else if (Choice == 2)
			{
				cout << "�������ϴ�" << endl;
				system("pause");
				Stage = �����Ա�;
				break;
			}
			else if (Choice == 3)
			{

			}
		}	
	}
}