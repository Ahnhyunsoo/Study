#include "stdafx.h"
#include "Field.h"
#include "Player.h"
#include "Monster.h"

CField::CField()
{
}


CField::~CField()
{
	Release();
}

void CField::Initialize(void)
{
}

void CField::Update(void)
{
	srand(unsigned(time(nullptr)));

	int	iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();

		cout << "1. 초급 2. 중급 3. 고급 4. 전 단계 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pMonster = new CMonster("초급", 3, 30, 1);
			m_pMonster->Initialize();
			break;

		case 2:
			m_pMonster = new CMonster("중급", 6, 60, 2);
			m_pMonster->Initialize();
			break;

		case 3:
			m_pMonster = new CMonster("고급", 15, 120, 3);
			m_pMonster->Initialize();
			break;

		case 4:
			return;

		default:
			break;
		}

		switch (Fight())
		{
		case COMBAT_WIN:
			m_pPlayer->Combat_Win(m_pMonster->Get_Info().iExp, m_pMonster->Get_Info().iMoney);
			break;

		case COMBAT_LOSE:
			m_pPlayer->Combat_Lose();
			break;

		case COMBAT_RUN:
			m_pPlayer->Combat_Run();
			break;

		default:
			continue;
		}

		Release();
	}
}

void CField::Release(void)
{
	SAFE_DELETE(m_pMonster);
}

COMBAT CField::Fight(void)
{
	int	iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pMonster->Render();

		cout << "1. 공격 2. 도망 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pMonster->Set_Damage(m_pPlayer->Get_Info().iAttack);
			m_pPlayer->Set_Damage(m_pMonster->Get_Info().iAttack);

			if (0 >= m_pPlayer->Get_Info().iHp)
			{
				cout << "플레이어 사망" << endl;
				return COMBAT_LOSE;
			}

			if (0 >= m_pMonster->Get_Info().iHp)
			{
				cout << "승리!!!!" << endl;
				return COMBAT_WIN;
			}

			break;

		case 2:
			return COMBAT_RUN;

		default:
			continue;
		}

	}
}
