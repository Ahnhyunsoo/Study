#include <iostream>
#include <stdlib.h>
using namespace std;


typedef struct Class1 
{
	char Ctype[6] = {"����"};
	int IAttack = 10;
	int IMaxHp = 200;
	int INowHp = 200;
	int ILevel = 1;
	int IMaxExp = 100;
	int INowExp = 0;
}Warrior , *PWarrior;

typedef struct Class2
{
	char Ctype[10] = {"������"};
	int iAttack = 100;
	int iHp = 100;
	int iLevel = 1;
}Wizard, *PWizard;

typedef struct Class3
{
	char Ctype[10] = {"����"};
	int iAttack = 20;
	int iHp = 50;
	int iLevel = 1;
}Thief, *PThief;

typedef struct Stage1
{
	char Ctype[10] = {"�ʱ�"};
	int IAttack = 5;
	int IMaxHp = 50;
	int INowHp = 50;
	int ILevel = 1;
	int IExe = 10;
}Easy, *PEasy;

typedef struct Stage2
{
	char Ctype[10] = {"�߱�"};
	int IAttack = 10;
	int IMaxHp = 100;
	int INowHp = 100;
	int ILevel = 3;
	int IExe = 20;
}Nomal, *PNomal;

typedef struct Stage3
{
	char Ctype[10] = {"���"};
	int IAttack = 20;
	int IMaxHp = 200;
	int INowHp = 200;
	int ILevel = 5;
	int IExe = 50;
}Hard, *PHard;

typedef struct Save {
	char Ctype[10] = {};
	int IAttack = 0;
	int IMaxHp = 0;
	int INowHp = 0;
	int ILevel = 0;
	int IMaxExp = 0;
	int INowExp = 0;
}Save , *PSave;

void FuncW();

void exe();

int Menu();

int ClassSelect();

void WPrint(PWarrior WP);

void WBattle(int Snum, PWarrior WP);

void main(void)
{
	exe();
}

void exe()
{

	while (true)
	{
		if (ClassSelect() == 1)
		{
			FuncW();
		}
	}
}


int Menu()
{
	int iMenu = 0;
	cout << "1.����� 2. ���� 3. ���� : ";
	cin >> iMenu;
	return iMenu;
}

int Stage()
{
	int Stage = 0;
	cout << "1.�ʱ� 2.�߱� 3.��� 4.���ܰ� : " << endl;
	cin >> Stage;
	return Stage;
}

int ClassSelect()
{
	int iClass = 0;
	cout << "1. ���� 2. ������ 3. ���� 4. �ҷ����� 5. ���� : ";
	cin >> iClass;
	return iClass;
}

void FuncW()
{
	PWarrior WCP = new Warrior;
	while (true)
	{
		system("cls");
		WPrint(WCP);
		cout << "================================" << endl;

		int iNum = Menu();

		if (iNum == 1)
		{
			system("cls");
			WPrint(WCP);
			cout << "================================" << endl;
			int ISnum = Stage();
			WBattle(ISnum, WCP);

		}
		if (iNum == 2)
		{
			system("cls");
			cout << "���忡 �����Ͽ����ϴ�" << endl;
			system("pause");
			continue;
		}
		if (iNum == 3)
		{
			system("cls");
			cout << "������ �����մϴ�" << endl;
			delete(WCP);
			WCP = nullptr;
			exit(0);
		}

	}
}

void WPrint(PWarrior WP)
{
	cout << "���� : " << WP->Ctype << endl;
	cout << "���ݷ� : " << WP->IAttack << endl;
	cout << "ü�� : " << WP->INowHp << "\t" << WP->IMaxHp << endl;
	cout << "���� : " << WP->ILevel << " ( " << WP->INowExp << " / " << WP->IMaxExp << " )" << endl;
}

void S1Print(PEasy PE)
{
	cout << "���� : " << PE->Ctype << endl;
	cout << "���ݷ� : " << PE->IAttack << endl;
	cout << "ü�� : " << PE->INowHp << "\t" << PE->IMaxHp << endl;
	cout << "���� : " << PE->ILevel << endl;
}


void WBattle(int Snum, PWarrior WP)
{
	while (true)
	{
		WPrint(WP);
		if (Snum == 1)
		{
			while (true)
			{
				system("cls");
				PEasy PE = new Easy;
				WPrint(WP);
				cout << "================================" << endl;
				S1Print(PE);
				cout << "================================" << endl;
				int Num = 0;
				cout << "1.���� 2. ���� : ";
				cin >> Num;
				
				if (Num == 1)
				{

				}
				if (Num == 2)
				{
					return;
				}

				
			}
		}
		if (Snum == 2)
		{

		}
		if (Snum == 3)
		{

		}
		if (Snum == 4)
		{
			return;
		}
	}
}

/*
1.���� 2. ������ 3. ���� 4. �ҷ����� 5. ����

���� = ���ݷ�10 ü�� 200
������ = ���ݷ�100 ü�� 100
���� = ���ݷ�20 ü�� 50

����
���ݷ�
ü��
����

1.����� 2. ���� 3. ����

1. �ʱ� 2. �߱� 3. ��� 4. ���ܰ�
���� �ʱ�
���ݷ� 5
ü�� 30 30

1. ���� 2. ����

*/