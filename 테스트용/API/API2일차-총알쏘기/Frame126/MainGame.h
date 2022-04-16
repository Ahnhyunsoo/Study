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

private:
	HDC			m_DC;
	CObj*		m_pPlayer;
	list<CObj*>	m_BulletList;
};

// 1. W,A,S,D Ű�� ������ �� �������� �̻��� �߻��ϱ�
// 2. ��ü ȭ�麸�� ���η� 100, ���η� 100�� ���� �簢���� ����� ������ ����� �̻����� �޸𸮿��� ����