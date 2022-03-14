#include <iostream>
#include <stdlib.h>;

using namespace std;

typedef struct ChracterInfo
{
	char Name[15];
	int Damage;
	int MaxHp;
	int NowHp;

}CInfo , *PCInfo;

typedef struct MonsterInfo
{
	char Name[15];
	int Damage;
	int MaxHp;
	int NowHp;
}MInfo ,*PMInfo;

enum Class { 전사 = 1, 마법사 = 2, 도적 = 3 ,불러오기 = 4};

enum Location {시작 = 1 , 메뉴 = 2, 사냥터 = 3, 전투 = 4};

enum Monster {초급 = 1, 중급 = 2, 고급 = 3, 전단계 = 4};

void exe();

void Menu(int Num);

void Character(int Num, PCInfo p);

void CharacterInfo(PCInfo p);

void MonsterInfo(PMInfo m);

void SelectMenu(PCInfo p);

void Save(PCInfo p);

void Load(PCInfo p);

void Dungeon(PCInfo p);

void MonsterInfo(int Num, PMInfo m);

void Battle(PCInfo p ,PMInfo m);


void main(void)
{
	exe();
}

void exe()
{

	CInfo Info;
	PCInfo p = new CInfo;
	int Location = 시작;
	int Select = 0;
	while (true)
	{
		Menu(Location);
		cin >> Select;
		if (Select > 0 && Select <= 4)
		{
			Character(Select, p);
			SelectMenu(p);
		}
		else
		{
			cout << "잘못 입력 하셨습니다" << endl;
			system("pause");
		}
	}
}

void Menu(int Num)
{
	switch (Num)
	{
	case 시작:
		cout << "1. 전사 2. 마법사 3. 도적 4. 불러오기 : ";
		break;
	case 메뉴:
		cout << "1. 사냥터 2. 저장 3. 종료 : ";
		break;
	case 사냥터:
		cout << "1. 초급 2. 중급 3. 고급 4. 전단계 : ";
		break;
	case 전투:
		cout << "1. 전투 2. 도망 : ";
		break;
	}
}

void Character(int Num, PCInfo p)
{
	switch (Num)
	{
	case 전사 :	
		strcpy_s(p->Name, sizeof(p->Name), "전사");
		p->MaxHp = 200;
		p->NowHp = p->MaxHp;
		p->Damage = 10;
		break;
	case 마법사 :
		strcpy_s(p->Name, sizeof(p->Name), "마법사");
		p->MaxHp = 100;
		p->NowHp = p->MaxHp;
		p->Damage = 100;
		break;
	case 도적 :
		strcpy_s(p->Name, sizeof(p->Name), "도적");
		p->MaxHp = 50;
		p->NowHp = p->MaxHp;
		p->Damage = 20;
		break;
	case 불러오기:
		Load(p);
		break;
	}
	
}

void MonsterInfo(PMInfo m)
{
	cout << "직업 : " << m->Name << endl;
	cout << "공격력 : " << m->Damage << endl;
	cout << "체력 : " << m->NowHp << "  /  " << m->MaxHp << endl;
	cout << "===========================" << endl;

}

void CharacterInfo(PCInfo p)
{
	cout << "직업 : " << p->Name << endl;
	cout << "공격력 : " << p->Damage << endl;
	cout << "체력 : " << p->NowHp << "  /  " << p->MaxHp << endl;
	cout << "===========================" << endl;
	
}

void SelectMenu(PCInfo p)
{
	system("cls");
	int Location = 메뉴;
	int Select = 0;
	while (true)
	{
		system("cls");
		CharacterInfo(p);
		Menu(메뉴);
		cin >> Select;
		if (Select > 0 && Select <= 3)
		{
			if (Select == 1)
			{
				Dungeon(p);
			}
			else if (Select == 2)
			{
				Save(p);
			}
			else if (Select == 3)
			{
				cout << "프로그램을 종료합니다" << endl;
				delete p;
				p = nullptr;
				exit(0);
			}
		}
		else
		{
			cout << "잘못 입력 하셨습니다" << endl;
			system("pause");
		}
	}
}

void Save(PCInfo p)
{
	CInfo c;
	FILE* pfile = nullptr;
	errno_t err = fopen_s(&pfile, "../Save/save1.txt", "wb");
	if (err == 0)
	{
		fwrite(p, sizeof(c), 1, pfile);
		fclose(pfile);
		cout << "저장완료" << endl;
		system("pause");
	}
	else
	{
		cout << "저장실패" << endl;
		system("pause");
	}
}

void Load(PCInfo p)
{
	CInfo c;
	FILE* pfile = nullptr;
	errno_t err = fopen_s(&pfile, "../Save/save1.txt", "rb");
	
	if (err == 0)
	{
		cout << "파일개방 성공" << endl;		
		fread(p, sizeof(c), 1, pfile);
		fclose(pfile);
	}
	else
	{
		cout << "파일개방 실패";
	}
	
	strcpy_s(p->Name, sizeof(p->Name), p->Name);
	p->Damage = p->Damage;
	p->MaxHp = p->MaxHp;
	p->NowHp = p->NowHp;

}

void Dungeon(PCInfo p)
{
	system("cls");
	int Location = 사냥터;
	int Select = 0;
	
	while (true)
	{
		system("cls");
		CharacterInfo(p);
		Menu(사냥터);
		cin >> Select;
		if (Select > 0 && Select <= 4)
		{
			MInfo monster;
			PMInfo m = new MInfo;
			if (Select == 초급) {
				MonsterInfo(초급, m);
				Battle(p,m);
			}
			else if (Select == 중급) {
				MonsterInfo(중급, m);
				Battle(p,m);
			}
			else if (Select == 고급) {
				MonsterInfo(고급, m);
				Battle(p,m);
			}
			else if (Select == 전단계) {
				delete m;
				m = nullptr;
				return;			
			}
		}
		else
		{
			cout << "잘못입력하셨습니다" << endl;
			system("pause");
		}
	}
}

void MonsterInfo(int Num, PMInfo m)
{
	switch (Num)
	{
	case 초급 :
		strcpy_s(m->Name, sizeof(m->Name), "고블린");
		m->Damage = 5;
		m->MaxHp = 50;
		m->NowHp = m->MaxHp;
		break;
	case 중급 :
		strcpy_s(m->Name, sizeof(m->Name), "루가루");
		m->Damage = 10;
		m->MaxHp = 100;
		m->NowHp = m->MaxHp;
		break;
	case 고급 :
		strcpy_s(m->Name, sizeof(m->Name), "카인");
		m->Damage = 20;
		m->MaxHp = 200;
		m->NowHp = m->MaxHp;
		break;
	}
}

void Battle(PCInfo p ,PMInfo m)
{
	system("cls");
	int Location = 전투;
	int Select = 0;
	while (true)
	{
		system("cls");
		CharacterInfo(p);
		MonsterInfo(m);
		Menu(전투);
		cin >> Select;
		if (Select == 1)
		{
			if (p->NowHp <= m->Damage)
			{
				p->NowHp = 0;
			}
			else if (m->NowHp <= p->Damage)
			{
				m->NowHp = 0;
				p->NowHp -= m->Damage;
			}
			else
			{
				p->NowHp -= m->Damage;
				m->NowHp -= p->Damage;
			}
				if (p->NowHp == 0)
				{
					cout << "플레이어가 사망했습니다" << endl;
					system("pause");
					p->NowHp = p->MaxHp;
					return;
				}
				else if (m->NowHp == 0 && p->NowHp > 0)
				{
					cout << "몬스터 처치" << endl;
					system("pause");
					m->NowHp = m->MaxHp;
					return;
				}						
		}
		else if (Select == 2)
		{
			m->NowHp = m->MaxHp;
			return;
		}		
	}
}