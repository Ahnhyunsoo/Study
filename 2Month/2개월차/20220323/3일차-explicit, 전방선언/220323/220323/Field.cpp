#include "stdafx.h"
#include "Field.h"


CField::CField()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
}

CField::~CField()
{
	Release();
}

void CField::Update(void)
{
	int		iInput = 0;

	while (true)
	{
		system("cls");
		// �÷��̾� ���� ���� ���
		m_pPlayer->Render();
		cout << "1. �ʱ� 2. �߱� 3. ��� 4. �� �ܰ� : ";
		cin >> iInput;
		
		switch (iInput)
		{
		case 1:
			m_pMonster = new CMonster("�ʱ�", 3, 30);
			break;

		case 2:
			m_pMonster = new CMonster("�߱�", 3, 30);
			break;

		case 3:
			m_pMonster = new CMonster("���", 3, 30);
			break;

		case 4:
			return;

		default:
			continue;
		}

		int iResult = Fight();

		if (1 == iResult)
		{
			m_pPlayer->Set_Hp(100);
			break;
		}
		else
		{
			SAFE_DELETE(m_pMonster);
			break;
		}
	}
}

void CField::Release(void)
{
	SAFE_DELETE(m_pMonster);
}

int CField::Fight(void)
{
	int iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pMonster->Render();
		cout << "1. ���� 2. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pMonster->Set_MinusHp(m_pPlayer->Get_Info().iAttack);
			m_pPlayer->Set_MinusHp(m_pMonster->Get_Info().iAttack);

			if (0 >= m_pPlayer->Get_Info().iHp)
			{
				cout << "�÷��̾� ���" << endl;
				return 1;
			}
			if (0 >= m_pMonster->Get_Info().iHp)
			{
				cout << "�¸�" << endl;
				return 0;
			}

			break;

		case 2:
			return 0;
		}
	}
}
