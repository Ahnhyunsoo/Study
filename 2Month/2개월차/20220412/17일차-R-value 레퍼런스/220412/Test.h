#pragma once

#include "stdafx.h"

class CTest
{
private:
	int					m_iTemp = 10;
public:
	static		int		m_iTest;		// ��� ������ �ƴ�(���� ���� : �����, �޸� : ����� �ƴ�)

public:
	void		Render(void);

	static		void	Print();

public:
	CTest();
	~CTest();
};

