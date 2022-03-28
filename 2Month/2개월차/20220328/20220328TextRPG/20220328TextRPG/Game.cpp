#include "stdafx.h"
#include "Game.h"

CPlayer* CGame::m_pp = NULL;

void CGame::exe()
{
	while (true)
	{
		if (m_pp == NULL)
		{
			m_pp = new CPlayer;
			if (m_pp->CreatePlayer() == 1)
			{
				SAVE_DELETE(m_pp);
				return;
			}
		}

		if (m_fp == NULL)
		{
			m_fp = new CField;
		}

		if (m_fp->Game() == 1)
		{
			SAVE_DELETE(m_pp);
			SAVE_DELETE(m_fp);
			return;
		}
	}
}


CGame::CGame()
{
	

}


CGame::~CGame()
{

}
