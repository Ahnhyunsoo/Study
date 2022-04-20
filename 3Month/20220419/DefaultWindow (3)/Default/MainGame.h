#pragma once

#include "Include.h"

#include "Player.h"
#include "Monster.h"

class CMainGame
{
public:				// ������, �Ҹ���
	CMainGame();
	~CMainGame();

// public, protected, private �Լ�
public:
	void	Initialize(void);		// �ʱ�ȭ �Լ�
	void	Update(void);			// �� �����Ӹ��� ���ŵǴ� �����͸� ����� �Լ�
	void	Render(void);			// �� �����Ӹ��� ����ϴ� �Լ�
	void	Release(void);			// �����Ҵ��� �����͸� �����ϴ� �Լ�
	void	SetTime() { m_Time += 1; }

// public, protected, private ����
private:
	int m_Time;
	int m_Score;
	int Gen = 0;

	HDC		m_hDC;
	CObj*	m_pPlayer;
	RECT	m1;
	RECT	m2;
	RECT	boss;

	list<CMonster> MyMonster;


};

