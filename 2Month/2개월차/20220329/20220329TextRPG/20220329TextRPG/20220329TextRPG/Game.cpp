#include "stdafx.h"
#include "Game.h"

void CGame::exe()
{
	m_pp = new CPlayer;
	m_pp->CreateObj("�׽�Ʈ", 10, 20, 30);
	m_pp->PrintObj();
	system("pause");
}

CGame::CGame()
{
}


CGame::~CGame()
{
}
