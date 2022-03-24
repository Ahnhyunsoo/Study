#include "stdafx.h"
#include "Maingame.h"



void Maingame::exe()
{
	Player* m_cp = new Player;
	Field* m_pf = new Field;
	

	while (true)
	{
		int place = m_pf->GetPlace();
		switch (place)
		{
		case 1:
			m_cp->Input();
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			break;

		case 5:
			break;
		}
		
	}
	
}

Maingame::Maingame()
{
	
}


Maingame::~Maingame()
{
}
