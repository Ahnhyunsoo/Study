#include <iostream>

using namespace std;

typedef struct tagInfo
{
	char		szName[16];
	int			iAttack;
	int			iHp;
	int			iMaxHp;
	int			iLevel;
	int			iExp;
	int			iMaxExp;

}INFO;

INFO*		SelectJob(void);
void		CreateObject(INFO** ppInfo, char* pName, int _iAttack, int _iMaxHp, int _iLevel, int _iMaxExp);
bool		Save_Data(INFO* pPlayer);
bool		Load_Data(INFO** ppPlayer);

void		Progress(INFO* pPlayer);
void		Render(INFO* pInfo, bool bPlayer = false);
int			Combat(INFO* pPlayer, INFO* pMonster);
void		Level_Up(INFO* pPlayer, int _iMaxExp);


void main(void)
{
	INFO*	pPlayer = SelectJob();

	if (nullptr == pPlayer)
		return;

	Progress(pPlayer);

	if(nullptr != pPlayer)
	{
		delete pPlayer;
		pPlayer = nullptr;
	}
}

INFO* SelectJob(void)
{
	int		iInput = 0;
	INFO*	pInfo = nullptr;

	bool	bChoice = false;


	while (!bChoice)
	{
		cout << "1. ���� 2. ������ 3. ���� 4. �ҷ����� 5. ������ : " << endl;
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			CreateObject(&pInfo, "����", 10, 100, 1, 100);
			bChoice = true;
			break;

		case 2:
			CreateObject(&pInfo, "������", 10, 100, 1, 100);
			bChoice = true;
			break;

		case 3:
			CreateObject(&pInfo, "����", 10, 100, 1, 100);
			bChoice = true;
			break;

		case 4:
			bChoice = Load_Data(&pInfo);
			break;

		case 5:
			cout << "������ �����մϴ�" << endl;
			bChoice = true;
			break;

		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			break;
		}
	}
	
	return pInfo;
}
void		CreateObject(INFO** ppInfo, char* pName, int _iAttack, int _iMaxHp, int _iLevel, int _iMaxExp)
{
	*ppInfo = new INFO;
	strcpy_s((*ppInfo)->szName, sizeof((*ppInfo)->szName), pName);
	(*ppInfo)->iAttack = _iAttack;
	(*ppInfo)->iMaxHp = _iMaxHp;
	(*ppInfo)->iHp = (*ppInfo)->iMaxHp;
	(*ppInfo)->iLevel = _iLevel;
	(*ppInfo)->iMaxExp = _iMaxExp;
	(*ppInfo)->iExp = 0;

}

void Progress(INFO* pPlayer)
{
	int iInput = 0;
	INFO*	pMonster = nullptr;

	bool	bSave = false;

	while (true)
	{
		system("cls");
		Render(pPlayer, true);
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. ���� 5. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			CreateObject(&pMonster, "�ʱ�", 5, 30, 1, 20);
			break;

		case 2:
			CreateObject(&pMonster, "�߱�", 10, 50, 2, 40);
			break;

		case 3:
			CreateObject(&pMonster, "���", 20, 100, 3, 60);
			break;

		case 4:
			bSave =	Save_Data(pPlayer);
			break;

		case 5:
			cout << "������ �����մϴ�" << endl;		
			return;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
		
		if (bSave)
		{
			bSave = false;
			continue;
		}


		int iResult = Combat(pPlayer, pMonster);

		if (1 == iResult)
		{
			pPlayer->iHp = pPlayer->iMaxHp;
		}
		
		if (nullptr != pMonster)
		{
			delete pMonster;
			pMonster = nullptr;
		}
	}
}
void		Render(INFO* pInfo, bool bPlayer)
{
	cout << "�̸� : " << pInfo->szName << endl; 
	cout << "���ݷ� : " << pInfo->iAttack << endl;
	cout << "ü�� : " << pInfo->iHp << "\t / " << pInfo->iMaxHp << endl;

	if (bPlayer)
		cout << "���� : " << pInfo->iLevel << " < " << pInfo->iExp << " / " << pInfo->iMaxExp << " > " << endl;

	cout << "=================================" << endl;
}


int Combat(INFO* pPlayer, INFO* pMonster)
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		Render(pPlayer);
		Render(pMonster);

		cout << "1. ���� 2. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			pMonster->iHp -= pPlayer->iAttack;
			pPlayer->iHp  -= pMonster->iAttack;
			break;

		case 2:
			return 0;

		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}

		if (0 >= pPlayer->iHp)
		{
			cout << "�÷��̾� ���" << endl;
			system("pause");
			return 1;
		}

		if (0 >= pMonster->iHp)
		{
			cout << "��� ����" << endl;
			Level_Up(pPlayer, pMonster->iMaxExp);
			system("pause");
			return 0;
		}


	}

}
void Level_Up(INFO* pPlayer, int _iMaxExp)
{
	pPlayer->iExp += _iMaxExp;

	if (pPlayer->iExp >= pPlayer->iMaxExp)
	{
		if (!strcmp(pPlayer->szName, "����"))
		{
			pPlayer->iAttack += 10;
			pPlayer->iMaxHp += 20;
			pPlayer->iMaxExp += 50;
		}

		else if (!strcmp(pPlayer->szName, "������"))
		{
			pPlayer->iAttack += 50;
			pPlayer->iMaxHp += 5;
			pPlayer->iMaxExp += 50;
		}

		else if (!strcmp(pPlayer->szName, "����"))
		{
			pPlayer->iAttack += 20;
			pPlayer->iMaxHp += 10;
			pPlayer->iMaxExp += 50;
		}


		++pPlayer->iLevel;
		pPlayer->iHp = pPlayer->iMaxHp;
		pPlayer->iExp = 0;

		cout << "���� ��" << endl;
	} 

}
bool Save_Data(INFO* pPlayer)
{
	FILE*		pFile = nullptr;

	errno_t		err = fopen_s(&pFile, "../Data/Save.txt", "wb");

	if (0 == err)
	{
		fwrite(pPlayer, sizeof(INFO), 1, pFile);
		cout << "���� ����" << endl;
		fclose(pFile);

		system("pause");
		return true;
	}
	else
		cout << "���� ����" << endl;
	
	system("pause");

	return false;
}
bool Load_Data(INFO** ppPlayer)
{
	FILE*		pFile = nullptr;

	*ppPlayer = new INFO;

	errno_t		err = fopen_s(&pFile, "../Data/Save.txt", "rb");

	if (0 == err)
	{
		fread((*ppPlayer), sizeof(INFO), 1, pFile);
		cout << "�ҷ����� ����" << endl;
		fclose(pFile);

		system("pause");
		return true;
	}
	else
	{
		cout << "�ҷ����� ����" << endl;

		delete *ppPlayer;
		*ppPlayer = nullptr;
	}

	system("pause");

	return false;
}