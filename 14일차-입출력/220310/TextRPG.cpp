#include <iostream>

using namespace std;

typedef	struct tagInfo
{
	char		szName[16];
	int			iAttack;
	int			iHp;
	int			iMaxHp;
	bool		bLive;

}INFO;

INFO		SelectJob(void);
void		SelectJob(INFO* pPlayer);

void		Render(INFO* pInfo);
void		Field(INFO* pPlayer);
void		CreateMonster(INFO* pMonster, int _iInput);
void		Fight(INFO* pPlayer, INFO* pMonster);

void main(void)
{
	INFO	tPlayer = {""};
	INFO* Player = &tPlayer;
	INFO* IP = new INFO;
	Player = IP;
	
	

	//tPlayer = SelectJob();

	SelectJob(Player);

	if (false == Player->bLive)
		return;

	int	iInput = 0;

	while (true)
	{
		system("cls");

		Render(Player);
		cout << "1. 사냥터 2. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Field(Player);
			break;

		case 2:
			delete IP;
			IP = nullptr;
			return;

		default:
			continue;
		}

	}


}

INFO		SelectJob(void)
{
	INFO	tTemp = {""};

	int		iInput = 0;

	cout << "직업을 선택하세요(1. 전사 2.마법사 3. 도둑 4. 종료) : ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s(tTemp.szName, sizeof(tTemp.szName), "전사");
		tTemp.iAttack = 10;
		tTemp.iMaxHp = 100;
		tTemp.iHp = tTemp.iMaxHp;

		tTemp.bLive = true;
		break;

	case 2:
		strcpy_s(tTemp.szName, sizeof(tTemp.szName), "마법사");
		tTemp.iAttack = 10;
		tTemp.iMaxHp = 100;
		tTemp.iHp = tTemp.iMaxHp;

		tTemp.bLive = true;
		break;

	case 3:
		strcpy_s(tTemp.szName, sizeof(tTemp.szName), "도둑");
		tTemp.iAttack = 10;
		tTemp.iMaxHp = 100;
		tTemp.iHp = tTemp.iMaxHp;

		tTemp.bLive = true;
		break;

	case 4:
		tTemp.bLive = false;

		return tTemp;
	}


	return tTemp;
}


void SelectJob(INFO* pPlayer)
{
	int		iInput = 0;

	cout << "직업을 선택하세요(1. 전사 2.마법사 3. 도둑 4. 종료) : ";
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		strcpy_s(pPlayer->szName, sizeof(pPlayer->szName), "전사");
		pPlayer->iAttack = 10;
		pPlayer->iMaxHp = 100;
		pPlayer->iHp = pPlayer->iMaxHp;

		pPlayer->bLive = true;
		break;

	case 2:
		strcpy_s(pPlayer->szName, sizeof(pPlayer->szName), "마법사");
		pPlayer->iAttack = 10;
		pPlayer->iMaxHp = 100;
		pPlayer->iHp = pPlayer->iMaxHp;

		pPlayer->bLive = true;
		break;

	case 3:
		strcpy_s(pPlayer->szName, sizeof(pPlayer->szName), "도둑");
		pPlayer->iAttack = 10;
		pPlayer->iMaxHp = 100;
		pPlayer->iHp = pPlayer->iMaxHp;

		pPlayer->bLive = true;
		break;

	case 4:
		pPlayer->bLive = false;
		return;
	}
}



void Render(INFO* pInfo)
{
	cout << "=========================="	<< endl;
	cout << "이름	: " << pInfo->szName	<< endl;
	cout << "체력	: " << pInfo->iHp		<< endl;
	cout << "공격력	: " << pInfo->iAttack	<< endl;
}
void		Field(INFO* pPlayer)
{
	int iInput = 0;

	INFO	tMonster[3] = {};
	INFO* m = new INFO;
	INFO* Monster = &tMonster[iInput - 1];
	Monster = m;

	

	while (true)
	{
		system("cls");

		Render(pPlayer);
		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
		cin >> iInput;

		if (4 == iInput)
			return;

		else if (3 >= iInput && iInput > 0)
		{
			CreateMonster(Monster, iInput);
			Fight(pPlayer, Monster);
		}

	}
}


void CreateMonster(INFO* pMonster, int _iInput)
{
	switch (_iInput)
	{
	case 1:
		strcpy_s(pMonster->szName, sizeof(pMonster->szName), "초급");
		pMonster->iAttack = 5;
		pMonster->iHp = 30;
		break;

	case 2:
		strcpy_s(pMonster->szName, sizeof(pMonster->szName), "중급");
		pMonster->iAttack = 50;
		pMonster->iHp = 60;
		break;

	case 3:
		strcpy_s(pMonster->szName, sizeof(pMonster->szName), "고급");
		pMonster->iAttack = 90;
		pMonster->iHp = 80;
		break;
			
	}
}
void		Fight(INFO* pPlayer, INFO* pMonster)
{
	int iInput = 0;

	while (true)
	{
		system("cls");

		Render(pPlayer);
		Render(pMonster);

		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;

		if (2 == iInput)
			return;

		else 
		{
			pMonster->iHp -= pPlayer->iAttack;
			pPlayer->iHp -= pMonster->iAttack;

			if (0 >= pPlayer->iHp)
			{
				cout << "플레이어 사망" << endl;
				pPlayer->iHp = pPlayer->iMaxHp;
				break;
			}
			if (0 >= pMonster->iHp)
			{
				cout << "승리!!!!!" << endl;
				break;
			}		
		}
	}
	system("pause");
}