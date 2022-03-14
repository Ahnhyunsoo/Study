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

enum Class { ���� = 1, ������ = 2, ���� = 3 ,�ҷ����� = 4};

enum Location {���� = 1 , �޴� = 2, ����� = 3, ���� = 4};

enum Monster {�ʱ� = 1, �߱� = 2, ��� = 3, ���ܰ� = 4};

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
	int Location = ����;
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
			cout << "�߸� �Է� �ϼ̽��ϴ�" << endl;
			system("pause");
		}
	}
}

void Menu(int Num)
{
	switch (Num)
	{
	case ����:
		cout << "1. ���� 2. ������ 3. ���� 4. �ҷ����� : ";
		break;
	case �޴�:
		cout << "1. ����� 2. ���� 3. ���� : ";
		break;
	case �����:
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. ���ܰ� : ";
		break;
	case ����:
		cout << "1. ���� 2. ���� : ";
		break;
	}
}

void Character(int Num, PCInfo p)
{
	switch (Num)
	{
	case ���� :	
		strcpy_s(p->Name, sizeof(p->Name), "����");
		p->MaxHp = 200;
		p->NowHp = p->MaxHp;
		p->Damage = 10;
		break;
	case ������ :
		strcpy_s(p->Name, sizeof(p->Name), "������");
		p->MaxHp = 100;
		p->NowHp = p->MaxHp;
		p->Damage = 100;
		break;
	case ���� :
		strcpy_s(p->Name, sizeof(p->Name), "����");
		p->MaxHp = 50;
		p->NowHp = p->MaxHp;
		p->Damage = 20;
		break;
	case �ҷ�����:
		Load(p);
		break;
	}
	
}

void MonsterInfo(PMInfo m)
{
	cout << "���� : " << m->Name << endl;
	cout << "���ݷ� : " << m->Damage << endl;
	cout << "ü�� : " << m->NowHp << "  /  " << m->MaxHp << endl;
	cout << "===========================" << endl;

}

void CharacterInfo(PCInfo p)
{
	cout << "���� : " << p->Name << endl;
	cout << "���ݷ� : " << p->Damage << endl;
	cout << "ü�� : " << p->NowHp << "  /  " << p->MaxHp << endl;
	cout << "===========================" << endl;
	
}

void SelectMenu(PCInfo p)
{
	system("cls");
	int Location = �޴�;
	int Select = 0;
	while (true)
	{
		system("cls");
		CharacterInfo(p);
		Menu(�޴�);
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
				cout << "���α׷��� �����մϴ�" << endl;
				delete p;
				p = nullptr;
				exit(0);
			}
		}
		else
		{
			cout << "�߸� �Է� �ϼ̽��ϴ�" << endl;
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
		cout << "����Ϸ�" << endl;
		system("pause");
	}
	else
	{
		cout << "�������" << endl;
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
		cout << "���ϰ��� ����" << endl;		
		fread(p, sizeof(c), 1, pfile);
		fclose(pfile);
	}
	else
	{
		cout << "���ϰ��� ����";
	}
	
	strcpy_s(p->Name, sizeof(p->Name), p->Name);
	p->Damage = p->Damage;
	p->MaxHp = p->MaxHp;
	p->NowHp = p->NowHp;

}

void Dungeon(PCInfo p)
{
	system("cls");
	int Location = �����;
	int Select = 0;
	
	while (true)
	{
		system("cls");
		CharacterInfo(p);
		Menu(�����);
		cin >> Select;
		if (Select > 0 && Select <= 4)
		{
			MInfo monster;
			PMInfo m = new MInfo;
			if (Select == �ʱ�) {
				MonsterInfo(�ʱ�, m);
				Battle(p,m);
			}
			else if (Select == �߱�) {
				MonsterInfo(�߱�, m);
				Battle(p,m);
			}
			else if (Select == ���) {
				MonsterInfo(���, m);
				Battle(p,m);
			}
			else if (Select == ���ܰ�) {
				delete m;
				m = nullptr;
				return;			
			}
		}
		else
		{
			cout << "�߸��Է��ϼ̽��ϴ�" << endl;
			system("pause");
		}
	}
}

void MonsterInfo(int Num, PMInfo m)
{
	switch (Num)
	{
	case �ʱ� :
		strcpy_s(m->Name, sizeof(m->Name), "���");
		m->Damage = 5;
		m->MaxHp = 50;
		m->NowHp = m->MaxHp;
		break;
	case �߱� :
		strcpy_s(m->Name, sizeof(m->Name), "�簡��");
		m->Damage = 10;
		m->MaxHp = 100;
		m->NowHp = m->MaxHp;
		break;
	case ��� :
		strcpy_s(m->Name, sizeof(m->Name), "ī��");
		m->Damage = 20;
		m->MaxHp = 200;
		m->NowHp = m->MaxHp;
		break;
	}
}

void Battle(PCInfo p ,PMInfo m)
{
	system("cls");
	int Location = ����;
	int Select = 0;
	while (true)
	{
		system("cls");
		CharacterInfo(p);
		MonsterInfo(m);
		Menu(����);
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
					cout << "�÷��̾ ����߽��ϴ�" << endl;
					system("pause");
					p->NowHp = p->MaxHp;
					return;
				}
				else if (m->NowHp == 0 && p->NowHp > 0)
				{
					cout << "���� óġ" << endl;
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