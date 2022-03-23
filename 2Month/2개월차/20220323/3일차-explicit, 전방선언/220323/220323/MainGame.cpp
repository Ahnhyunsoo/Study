#include "stdafx.h"
#include "MainGame.h"


CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
	m_pField = nullptr;
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	if (!m_pPlayer)	// �÷��̾ �Ҵ���� �ʾ��� ��
	{
		m_pPlayer = new CPlayer;
		m_pPlayer->SelectJob();
	}

}

void CMainGame::Update(void)
{
	int		iInput = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1. ����� 2. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			if (!m_pField)	// field �����Ͱ� null�� ���
			{
				m_pField = new CField;
				
			}
			m_pField->Set_Player(m_pPlayer);
			m_pField->Update();

			break;

		case 2:
			return;

		default:
			continue;
		}
	}

}

void CMainGame::Release(void)
{
	SAFE_DELETE(m_pField);
	SAFE_DELETE(m_pPlayer);
}
