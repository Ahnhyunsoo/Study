#pragma once

#include "Include.h"

#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "Barrel.h"


class CMainGame
{
public:				// ������, �Ҹ���
	CMainGame();
	~CMainGame();

// public, protected, private �Լ�
public:
	void	Initialize(void);		// �ʱ�ȭ �Լ�
	void	Update(void);			// �� �����Ӹ��� ���ŵǴ� �����͸� ����� �Լ�
	void	Late_Update(void);
	void	Render(void);			// �� �����Ӹ��� ����ϴ� �Լ�
	void	Release(void);			// �����Ҵ��� �����͸� �����ϴ� �Լ�
	void	Key_Input(void);
// public, protected, private ����
private:
	HDC		m_hDC;
	RECT rc = {};
	list<CObj*> OBJ_LIST[OBJ_END];
	

};

