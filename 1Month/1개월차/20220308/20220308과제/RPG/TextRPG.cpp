#include <iostream>
#include <stdlib.h>
using namespace std;


typedef struct Class1 
{
	char Ctype[6] = {"전사"};
	int IAttack = 10;
	int IMaxHp = 200;
	int INowHp = 200;
	int ILevel = 1;
	int IMaxExp = 100;
	int INowExp = 0;
}Warrior , *PWarrior;

typedef struct Class2
{
	char Ctype[10] = {"마법사"};
	int iAttack = 100;
	int iHp = 100;
	int iLevel = 1;
}Wizard, *PWizard;

typedef struct Class3
{
	char Ctype[10] = {"도적"};
	int iAttack = 20;
	int iHp = 50;
	int iLevel = 1;
}Thief, *PThief;

typedef struct Stage1
{
	char Ctype[10] = {"초급"};
	int IAttack = 5;
	int IMaxHp = 50;
	int INowHp = 50;
	int ILevel = 1;
	int IExe = 10;
}Easy, *PEasy;

typedef struct Stage2
{
	char Ctype[10] = {"중급"};
	int IAttack = 10;
	int IMaxHp = 100;
	int INowHp = 100;
	int ILevel = 3;
	int IExe = 20;
}Nomal, *PNomal;

typedef struct Stage3
{
	char Ctype[10] = {"상급"};
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
	cout << "1.사냥터 2. 저장 3. 종료 : ";
	cin >> iMenu;
	return iMenu;
}

int Stage()
{
	int Stage = 0;
	cout << "1.초급 2.중급 3.상급 4.전단계 : " << endl;
	cin >> Stage;
	return Stage;
}

int ClassSelect()
{
	int iClass = 0;
	cout << "1. 전사 2. 마법사 3. 도적 4. 불러오기 5. 종료 : ";
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
			cout << "저장에 성공하였습니다" << endl;
			system("pause");
			continue;
		}
		if (iNum == 3)
		{
			system("cls");
			cout << "게임을 종료합니다" << endl;
			delete(WCP);
			WCP = nullptr;
			exit(0);
		}

	}
}

void WPrint(PWarrior WP)
{
	cout << "직업 : " << WP->Ctype << endl;
	cout << "공격력 : " << WP->IAttack << endl;
	cout << "체력 : " << WP->INowHp << "\t" << WP->IMaxHp << endl;
	cout << "레벨 : " << WP->ILevel << " ( " << WP->INowExp << " / " << WP->IMaxExp << " )" << endl;
}

void S1Print(PEasy PE)
{
	cout << "직업 : " << PE->Ctype << endl;
	cout << "공격력 : " << PE->IAttack << endl;
	cout << "체력 : " << PE->INowHp << "\t" << PE->IMaxHp << endl;
	cout << "레벨 : " << PE->ILevel << endl;
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
				cout << "1.전투 2. 도망 : ";
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
1.전사 2. 마법사 3. 도둑 4. 불러오기 5. 종료

전사 = 공격력10 체력 200
마법사 = 공격력100 체력 100
도둑 = 공격력20 체력 50

직업
공격력
체력
레벨

1.사냥터 2. 저장 3. 종료

1. 초급 2. 중급 3. 상급 4. 전단계
직업 초급
공격력 5
체력 30 30

1. 전투 2. 도망

*/