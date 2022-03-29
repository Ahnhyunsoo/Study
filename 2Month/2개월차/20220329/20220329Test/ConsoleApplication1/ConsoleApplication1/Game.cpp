#include "stdafx.h"
#include "Game.h"

void CGame::exe()
{
	m_pp = new CPlayer;
	m_mp = new CMonster;

	m_mp->Test();
}

CGame::CGame()
{
}


CGame::~CGame()
{
}
