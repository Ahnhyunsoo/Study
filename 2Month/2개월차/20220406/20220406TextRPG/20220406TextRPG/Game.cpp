#include "stdafx.h"
#include "Game.h"

Player* Game::m_pp = new Player;

void Game::exe()
{
	if (m_pp->Create() == 1)
	{
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
			return;
		}
	}
}

Game::Game()
{
	m_fp = new Field;
}


Game::~Game()
{
}
