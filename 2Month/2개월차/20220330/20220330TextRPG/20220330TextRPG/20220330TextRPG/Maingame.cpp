#include "stdafx.h"
#include "Maingame.h"

CObj* Maingame::m_pp = NULL;

void Maingame::exe()
{
	if (m_pp == NULL)
	{
		m_pp = new CPlayer;
		m_fp = new CField;

		int Input = 0;
		cout << "1. ����, 2. ������, 3. ����, 4. ���� : ";
		cin >> Input;

		switch (Input)
		{
		case 1:
			m_pp->Create("����", 1, 20, 200, 100, 100);
			break;
		case 2:
			m_pp->Create("������", 1, 50, 100, 100, 100);
			break;

		case 3:
			break;

		case 4:
			cout << "������ �����մϴ�" << endl;
			SAVE_DELETE(m_pp);
			SAVE_DELETE(m_fp);
			return;

		}
		while (true)
		{
			if (m_fp->Update() == 1)
			{
				SAVE_DELETE(m_pp);
				SAVE_DELETE(m_fp);
				cout << "������ �����մϴ�" << endl;
				return;
			}
		}

	}
}

Maingame::Maingame()
{
	
}


Maingame::~Maingame()
{
}
