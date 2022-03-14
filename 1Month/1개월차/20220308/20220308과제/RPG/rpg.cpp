#include <iostream>
#include <stdlib.h>

using namespace std;


typedef struct CharacterInfo
{
	char Character[7][10] = {"����", "������", "����", "���", "�簡��", "Ÿ��" ,""};
	int Damage[7] = { 10,100,20,5,10,20,0 };
	unsigned int MaxHp[7] = {200,100,50,50,100,200,0};
	unsigned int NowHp[7] = { 200,100,50,50,100,200,0 };
	int Level[7] = { 1,1,1,1,3,5,1 };
	int MaxExp[4] = { 50,50,50,0 };
	int NowExp[7] = { 0,0,0,5,10,20,0 };
}CInfo, *PCInfo;

enum Character  {���� = 0, ������ = 1, ���� = 2, �ʱ� = 3, �߱� = 4, ��� = 5 };

enum Menu {����� = 1, ���� = 2, ���ܰ� = 4, �ҷ����� = 4 , ���� = 5};

enum Fight { ���� = 1, ���� = 2 , Hpȸ�� = 3 };

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
		if (Cnum == ���� + 1)
		{
			Game(����, PC);
		}
		else if (Cnum == ������ + 1)
		{
			Game(������, PC);
		}
		else if (Cnum == ���� + 1)
		{
			Game(����, PC);
		}
		else if (Cnum == �ҷ�����)
		{
			cout << "�ҷ����� �Ϸ�" << endl;
		}
		else if (Cnum == ����)
		{
			cout << "������ �����մϴ�" << endl;
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
	cout << "1. ���� 2. ������ 3. ���� 4. �ҷ����� 5. ���� : ";
	cin >> iClass;
	return iClass;
}

int Menu()
{
	int iMenu = 0;
	cout << "1.����� 2. ���� 3. ���� : ";
	cin >> iMenu;
	return iMenu;
}

int StageSelect()
{
	int Stage = 0;
	cout << "1.�ʱ� 2.�߱� 3.��� 4.���ܰ� : ";
	cin >> Stage;
	return Stage;
}

int Fight()
{
	int Choice = 0;
	cout << "1. ���� 2. ���� 3. Hpȸ��" << endl;
	cout << "================================" << endl;
	cout << "�Է� : ";
	cin >> Choice;
	return Choice;
}



void InfoPrint(int Class, PCInfo PC)
{
	cout << "���� : " << PC->Character[Class] << endl;
	cout << "���ݷ� : " << PC->Damage[Class] << endl;
	cout << "ü�� : " << PC->NowHp[Class] << "\t" << PC->MaxHp[Class] << endl;
	cout << "���� : " << PC->Level[Class] << " ( " << PC->NowExp[Class] << " / " << PC->MaxExp[Class] << " )" << endl;
	cout << "================================" << endl;
}

void MonsterInfo(int Class, PCInfo PC)
{
	cout << "�̸� : " << PC->Character[Class] << endl;
	cout << "���ݷ� : " << PC->Damage[Class] << endl;
	cout << "ü�� : " << PC->NowHp[Class] << "\t" << PC->MaxHp[Class] << endl;
	cout << "���� : " << PC->Level[Class] << endl;
	cout << "����ġ : " << PC->NowExp[Class] << endl;
	cout << "================================" << endl;
}

void Game(int Cnum, PCInfo PC)
{
	while (true)
	{
		system("cls");
		InfoPrint(Cnum, PC);
		int Mnum = Menu();
		if (Mnum == �����)
		{
			Dungeon(Cnum, PC);

			//����͸� ������ �Լ� �尡�� ���� �ѷ��ָ鼭 �Է¹ް�
			//�Է¹����� �Լ� ȣ���ϸ鼭 �װſ� �ش��ϴ� ���� �ϰ�
		}
		else if (Mnum == ����)
		{
			cout << "������ �Ϸ��߽��ϴ�" << endl;
			system("pause");
		}
		else if (Mnum == ���� - 2)
		{
			cout << "������ �����մϴ�" << endl;
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
		if (Snum == �ʱ� - 2)
		{
			Battle(Class, �ʱ�, PC);
		}
		else if (Snum == �߱� - 2)
		{
			Battle(Class, �߱�, PC);
		}
		else if (Snum == ��� - 2)
		{
			Battle(Class, ���, PC);
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
		if (Choice == ����)
		{	
			if (0 == Hp(Cnum, Mnum, PC))
			{
				return;
			}
		}
		else if (Choice == ����)
		{
			PC->NowHp[Mnum] = PC->MaxHp[Mnum];
			return;
		}
		else if (Choice == Hpȸ��)
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
			cout << "�÷��̾ ����߽��ϴ�" << endl;
			system("pause");
			PC->NowHp[C] = PC->MaxHp[C];
			PC->NowHp[M] = PC->MaxHp[M];
			Exp(C, M, 0, PC);
			return 0;
	}
	else if (PC->NowHp[M] == 0 && PC->NowHp[C] != 0)
	{
			cout << "���͸� óġ�߽��ϴ�" << endl;
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
			cout << "������!!!" << endl;
			system("pause");
		}
		return;
	}
}






