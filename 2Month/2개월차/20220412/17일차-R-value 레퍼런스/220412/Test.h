#pragma once

#include "stdafx.h"

class CTest
{
private:
	int					m_iTemp = 10;
public:
	static		int		m_iTest;		// ¸â¹ö º¯¼ö°¡ ¾Æ´Ô(Á¢±Ù ±ÇÇÑ : ¸â¹öÀÓ, ¸Þ¸ð¸® : ¸â¹ö°¡ ¾Æ´Ô)

public:
	void		Render(void);

	static		void	Print();

public:
	CTest();
	~CTest();
};

