#include "stdafx.h"
#include "Maingame.h"

Player* Maingame::m_pp = NULL;

void Maingame::exe()
{	
	
	if (m_pp->CreatePlayer() == 1)
	{
		SAVE_DELETE(m_pp);
		SAVE_DELETE(m_fp);
		return;
	}
	while (true)
	{
		if (m_fp->Menu() == 1)
		{
			SAVE_DELETE(m_pp);
			SAVE_DELETE(m_fp);
			return;
		}
	}
	
}

int Maingame::GetRandom(int m_mini, int m_max)
{

	random_device random;
	mt19937 rd(random());
	uniform_int_distribution<int> range(m_mini, m_max);

	return range(rd);
}

Maingame::Maingame()
{
	m_pp = new Player;
	m_fp = new Field;

}


Maingame::~Maingame()
{
}
