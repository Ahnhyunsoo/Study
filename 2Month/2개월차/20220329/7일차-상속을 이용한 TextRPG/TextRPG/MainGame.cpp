#include "stdafx.h"
#include "MainGame.h"

CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->SelectJob();
	}

	if (!m_pField)
	{
		m_pField = new CField;
		m_pField->Initialize();
	}
	
	m_pField->Set_Player(m_pPlayer);

	if (!m_pShop)
	{
		m_pShop = new CShop;
		m_pShop->Initialize();
	}

	m_pShop->Set_Player(m_pPlayer);
}

void CMainGame::Update(void)
{

	int		iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1. 사냥터 2. 상점 3. 종료 : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			if (m_pField)
				m_pField->Update();

			break;

		case 2:
			if (m_pShop)
				m_pShop->Update();
			break;

		case 3:
			return;

		default:
			break;
		}
	}

}

void CMainGame::Release(void)
{
	SAFE_DELETE(m_pShop);
	SAFE_DELETE(m_pField);
	SAFE_DELETE(m_pPlayer);
}
