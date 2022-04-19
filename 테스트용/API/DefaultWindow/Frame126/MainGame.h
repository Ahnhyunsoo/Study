#pragma once

#include "Include.h"

class CObj;
class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void		Initialize(void);	// �����͸� �ʱ�ȭ�ϴ� �Լ�
	void		Update(void);		// �� �����Ӹ��� �����ϴ� �Լ�
	void		Render(void);		// �� �����Ӹ��� ����ϴ� �Լ�
	void		Release(void);		// ��ü �ı� �� �޸� ���� �Լ�
	void		CreateBullet(RECT bl);
	void		ShotBullet(wchar_t key, RECT rc);
	list<RECT> GetBullet() { return m_myBullet; }

private:
	HDC			m_DC;
	CObj*		m_pPlayer;
	list<RECT>		m_myBullet;

};

