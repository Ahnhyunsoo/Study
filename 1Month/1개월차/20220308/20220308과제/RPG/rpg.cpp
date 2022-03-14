#include <iostream>
#include <stdlib.h>

using namespace std;


typedef struct CharacterInfo
{
	char Character[7][10] = {"전사", "마법사", "도적", "고블린", "루가루", "타우" ,""};
	int Damage[7] = { 10,100,20,5,10,20,0 };
	unsigned int MaxHp[7] = {200,100,50,50,100,200,0};
	unsigned int NowHp[7] = { 200,100,50,50,100,200,0 };
	int Level[7] = { 1,1,1,1,3,5,1 };
	int MaxExp[4] = { 50,50,50,0 };
	int NowExp[7] = { 0,0,0,5,10,20,0 };
}CInfo, *PCInfo;

enum Character  {전사 = 0, 마법사 = 1, 도적 = 2, 초급 = 3, 중급 = 4, 고급 = 5 };

enum Menu {사냥터 = 1, 저장 = 2, 전단계 = 4, 불러오기 = 4 , 종료 = 5};

enum Fight { 전투 = 1, 도망 = 2 , Hp회복 = 3 };

void exe();

int CSelect();

int Menu();

int StageSelect();

int Fight();

void InfoPrint(int Class, PCInfo PC);

void Game(int Cnum, PCInfo PC);

void Dungeon(int Class, PCInfo PC);

void Battle(int Cnum, int Mnum, PCInfo PC);

int Hp(int C, int M, PCInfo PC);

void Exp(int C, int M, int S, PCInfo PC);


void main(void)
{
	exe();
}



void exe()
{

	PCInfo PC = new CharacterInfo;

	while(true)
	{

		int Cnum = CSelect();
		if (Cnum == 전사 + 1)
		{
			Game(전사, PC);
		}
		else if (Cnum == 마법사 + 1)
		{
			Game(마법사, PC);
		}
		else if (Cnum == 도적 + 1)
		{
			Game(도적, PC);
		}
		else if (Cnum == 불러오기)
		{
			cout << "불러오기 완료" << endl;
		}
		else if (Cnum == 종료)
		{
			cout << "게임을 종료합니다" << endl;
			delete(PC);
			PC = nullptr;
			return;
		}
		else
			continue;
	}
		
}

int CSelect()
{
	int iClass = 0;
	cout << "1. 전사 2. 마법사 3. 도적 4. 불러오기 5. 종료 : ";
	cin >> iClass;
	return iClass;
}

int Menu()
{
	int iMenu = 0;
	cout << "1.사냥터 2. 저장 3. 종료 : ";
	cin >> iMenu;
	return iMenu;
}

int StageSelect()
{
	int Stage = 0;
	cout << "1.초급 2.중급 3.고급 4.전단계 : ";
	cin >> Stage;
	return Stage;
}

int Fight()
{
	int Choice = 0;
	cout << "1. 전투 2. 도망 3. Hp회복" << endl;
	cout << "================================" << endl;
	cout << "입력 : ";
	cin >> Choice;
	return Choice;
}



void InfoPrint(int Class, PCInfo PC)
{
	cout << "직업 : " << PC->Character[Class] << endl;
	cout << "공격력 : " << PC->Damage[Class] << endl;
	cout << "체력 : " << PC->NowHp[Class] << "\t" << PC->MaxHp[Class] << endl;
	cout << "레벨 : " << PC->Level[Class] << " ( " << PC->NowExp[Class] << " / " << PC->MaxExp[Class] << " )" << endl;
	cout << "================================" << endl;
}

void MonsterInfo(int Class, PCInfo PC)
{
	cout << "이름 : " << PC->Character[Class] << endl;
	cout << "공격력 : " << PC->Damage[Class] << endl;
	cout << "체력 : " << PC->NowHp[Class] << "\t" << PC->MaxHp[Class] << endl;
	cout << "레벨 : " << PC->Level[Class] << endl;
	cout << "경험치 : " << PC->NowExp[Class] << endl;
	cout << "================================" << endl;
}

void Game(int Cnum, PCInfo PC)
{
	while (true)
	{
		system("cls");
		InfoPrint(Cnum, PC);
		int Mnum = Menu();
		if (Mnum == 사냥터)
		{
			Dungeon(Cnum, PC);

			//사냥터를 했을때 함수 드가서 정보 뿌려주면서 입력받고
			//입력받으면 함수 호출하면서 그거에 해당하는 던전 하고
		}
		else if (Mnum == 저장)
		{
			cout << "저장을 완료했습니다" << endl;
			system("pause");
		}
		else if (Mnum == 종료 - 2)
		{
			cout << "게임을 종료합니다" << endl;
			delete(PC);
			PC = nullptr;
			exit(0);
		}
		else
			continue;
	}
}

void Dungeon(int Class, PCInfo PC)
{
	while (true)
	{
		system("cls");
		InfoPrint(Class, PC);
		int Snum = StageSelect();
		if (Snum == 초급 - 2)
		{
			Battle(Class, 초급, PC);
		}
		else if (Snum == 중급 - 2)
		{
			Battle(Class, 중급, PC);
		}
		else if (Snum == 고급 - 2)
		{
			Battle(Class, 고급, PC);
		}
		else if (Snum = 4)
		{
			return;
		}
		else
			continue;
	
	}
}

void Battle(int Cnum, int Mnum, PCInfo PC)
{
	while (true)
	{
		system("cls");
		InfoPrint(Cnum, PC);
		MonsterInfo(Mnum, PC);
		int Choice = Fight();
		if (Choice == 전투)
		{	
			if (0 == Hp(Cnum, Mnum, PC))
			{
				return;
			}
		}
		else if (Choice == 도망)
		{
			PC->NowHp[Mnum] = PC->MaxHp[Mnum];
			return;
		}
		else if (Choice == Hp회복)
		{
			if (PC->NowHp[Cnum] + 50 <= PC->MaxHp[Cnum])
			{
				PC->NowHp[Cnum] += 50;
			}
			else if (PC->NowHp[Cnum] + 50 > PC->MaxHp[Cnum])
			{
				PC->NowHp[Cnum] = PC->MaxHp[Cnum];
			}
		}
	}
}

int Hp(int C, int M, PCInfo PC)
{

	if (PC->NowHp[C] <= PC->Damage[M])
	{
		PC->NowHp[M] -= PC->NowHp[C];
		PC->NowHp[C] = 0;		
	}
	else if (PC->NowHp[M] <= PC->Damage[C])
	{
		PC->NowHp[C] -= PC->Damage[M];
		PC->NowHp[M] = 0;
	}
	else 
	{
		PC->NowHp[C] -= PC->Damage[M];
		PC->NowHp[M] -= PC->Damage[C];
		return 1;
	}

	if (PC->NowHp[C] == 0)
	{
			cout << "플레이어가 사망했습니다" << endl;
			system("pause");
			PC->NowHp[C] = PC->MaxHp[C];
			PC->NowHp[M] = PC->MaxHp[M];
			Exp(C, M, 0, PC);
			return 0;
	}
	else if (PC->NowHp[M] == 0 && PC->NowHp[C] != 0)
	{
			cout << "몬스터를 처치했습니다" << endl;
			system("pause");
			Exp(C, M, 1, PC);
			PC->NowHp[M] = PC->MaxHp[M];
			return 0;
	}
	 

}

void Exp(int C, int M, int S, PCInfo PC)
{
	system("cls");
	if (S == 0)
	{
		if (PC->NowExp[C] < PC->NowExp[M])
		{
			PC->NowExp[C] = 0;
		}
		else if (PC->NowExp[C] >= PC->NowExp[M])
		{
			PC->NowExp[C] -= PC->NowExp[M];
		}
		return;
	}
	else if (S == 1)
	{
		if (PC->NowExp[C] + PC->NowExp[M] < PC->MaxExp[C])
		{
			PC->NowExp[C] += PC->NowExp[M];
		}
		else if (PC->NowExp[C] + PC->NowExp[M] >= PC->MaxExp[C])
		{
			PC->NowExp[C] = 0;
			PC->Level[C] += 1;
			PC->MaxHp[C] += 10;
			PC->Damage[C] += 5;
			PC->MaxExp[C] += 50;
			PC->NowHp[C] = PC->MaxHp[C];
			cout << "레벨업!!!" << endl;
			system("pause");
		}
		return;
	}
}






