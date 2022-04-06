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
	for (int i = 0; i < 3; ++i)
	{
		CStudent*	pStudent = new CStudent;
		pStudent->Input_Data();

		m_vecStu.push_back(pStudent);
	}
}

void CMainGame::Update(void)
{
	int	iInput = 0;

	while (true)
	{
		system("cls");
		cout << "1. �Է� 2. ��� 3. �˻� 4. ���� 5. ���� : ";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			Add_Data();
			break;

		case 2:
			Render_Data();
			break;

		case 3:
			Search_Data();
			break;

		case 4:
			Delete_Data();
			break;

		case 5:
			return;

		default:
			continue;
		}

		system("pause");
	}

}

void CMainGame::Release(void)
{
	/*for (size_t i = 0; i < m_vecStu.size(); ++i)
			Safe_Delete<CStudent*>(m_vecStu[i]);
	
	m_vecStu.clear();*/

	//for_each(m_vecStu.begin(), m_vecStu.end(), Safe_Delete<CStudent*>);
	for_each(m_vecStu.begin(), m_vecStu.end(), CDeleteObj()); 
	
}


void CMainGame::Add_Data()
{
	int	iInput = 0;

	cout << "�߰��� �л� ���� �Է��ϼ��� : ";
	cin >> iInput;

	for (int i = 0; i < iInput; ++i)
	{
		CStudent*	pStudent = new CStudent;
		pStudent->Input_Data();

		m_vecStu.push_back(pStudent);
	}

}

void CMainGame::Render_Data(void)
{
	for (size_t i = 0; i < m_vecStu.size(); ++i)
	{
		m_vecStu[i]->Output_Data();
	}
}

void CMainGame::Search_Data(void)
{
	string	strFindName = "";

	cout << "ã�� �л��� �̸��� �Է��ϼ��� : ";
	cin >> strFindName;

	for (vector<CStudent*>::iterator iter = m_vecStu.begin();
		iter != m_vecStu.end(); ++iter)
	{
		if (strFindName == (*iter)->Get_Info().strName)
		{
			(*iter)->Output_Data();
			break;
		}
	}
}

void CMainGame::Delete_Data(void)
{
	string	strFindName = "";

	cout << "������ �л��� �̸��� �Է��ϼ��� : ";
	cin >> strFindName;

	for (vector<CStudent*>::iterator iter = m_vecStu.begin();
		iter != m_vecStu.end(); )
	{
		if (strFindName == (*iter)->Get_Info().strName)
		{
			Safe_Delete(*iter);
			iter = m_vecStu.erase(iter);
		}
		else
			++iter;
	}
}
