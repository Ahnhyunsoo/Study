#pragma once

#include "Girl.h"

class CBoy
{
private:
	int		m_iHeight;
	int		m_iWidth;

	friend		class CGirl;	// CGirl Ŭ�������� boy Ŭ�������� ����� private ������ ����ϴ� ���

public:
	//friend void	CGirl::Show_BoyInfo(CBoy* pBoy);// CGirl Ŭ�������� boy Ŭ�������� ����� Ư�� �Լ��� private ������ ����ϴ� ���

private:
	void	Render(void);

public:
	CBoy(int _iHeight, int _iWidth);
	~CBoy();
};

