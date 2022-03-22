
#include "stdafx.h"
#include "MainGame.h"

void CMainGame::Initialize(void)
{
	m_pStudent = nullptr;

	m_pStudent = new CStudent;		// 동적할당을 할 때 c시절에 malloc, calloc을 사용할 수도 있다.
									// 그러나 만약 클래스 포인터를 malloc, calloc 동적할당하는 경우 생성자 호출이 일어나지 않는다.
	m_pStudent->Initialize();

	CStudent	Student;
	
}

void CMainGame::Update(void)
{
	int iInput = 0;


	while (true)
	{
	
		cout << "1. 입력 2. 출력 3. 종료 : ";
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



