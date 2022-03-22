
#include "stdafx.h"
#include "MainGame.h"

void CMainGame::Initialize(void)
{
	m_pStudent = nullptr;

	m_pStudent = new CStudent;		// �����Ҵ��� �� �� c������ malloc, calloc�� ����� ���� �ִ�.
									// �׷��� ���� Ŭ���� �����͸� malloc, calloc �����Ҵ��ϴ� ��� ������ ȣ���� �Ͼ�� �ʴ´�.
	m_pStudent->Initialize();

	CStudent	Student;
	
}

void CMainGame::Update(void)
{
	int iInput = 0;


	while (true)
	{
	
		cout << "1. �Է� 2. ��� 3. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			m_pStudent->Input_Data();
			break;

		case 2:
			m_pStudent->Output_Data();
			break;

		case 3:
			return;

		default:
			continue;

		}

	}

}
CStudent st;

void CMainGame::Release(void)
{
	if (nullptr != m_pStudent)
	{
		//m_pStudent->Release();
		SAFE_DELETE(m_pStudent);
	}

}

CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	Release();
}



