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
		cout << "1. 전사, 2. 마법사, 3. 저장, 4. 종료 : ";
		cin >> Input;

		switch (Input)
		{
		case 1:
			m_pp->Create("전사", 1, 20, 200, 100, 100);
			break;
		case 2:
			m_pp->Create("마법사", 1, 50, 100, 100, 100);
			break;

		case 3:
			break;

		case 4:
			cout << "게임을 종료합니다" << endl;
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
				cout << "게임을 종료합니다" << endl;
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
