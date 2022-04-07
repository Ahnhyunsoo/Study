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

	if (!m_pInven)
	{
		m_pInven = new CInven;
		m_pInven->Initialize();
	}
	m_pInven->Set_Player(m_pPlayer);

	m_pShop->Set_Inven(m_pInven);	
}

void CMainGame::Update(void)
{
	int		iInput = 0;

	while (true)
	{
		system("cls");

		m_pPlayer->Render();
		cout << "1. 사냥터 2. 상점 3. 인벤토리 4. 저장하기 5. 종료 : ";
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
			if (m_pInven)
				m_pInven->Update();
			break;

		case 4:
			Save_Data();
			break;

		case 5:
			return;

		default:
			break;
		}
	}

}

void CMainGame::Release(void)
{
	SAFE_DELETE(m_pInven);
	SAFE_DELETE(m_pShop);
	SAFE_DELETE(m_pField);
	SAFE_DELETE(m_pPlayer);
}

void CMainGame::Save_Data(void)
{
	FILE*		fp = nullptr;

	errno_t		err = fopen_s(&fp, "../Data/Save.dat", "wb");

	if (0 == err)
	{
		fwrite(&m_pPlayer->Get_Info(), sizeof(INFO), 1, fp);
		cout << "저장성공" << endl;
		fclose(fp);
	}
	else
		cout << "저장실패" << endl;

	system("pause");
}
