#pragma once

#include "Girl.h"

class CBoy
{
private:
	int		m_iHeight;
	int		m_iWidth;

	friend		class CGirl;	// CGirl 클래스에서 boy 클래스에서 선언된 private 접근을 허용하는 경우

public:
	//friend void	CGirl::Show_BoyInfo(CBoy* pBoy);// CGirl 클래스에서 boy 클래스에서 선언된 특정 함수만 private 접근을 허용하는 경우

private:
	void	Render(void);

public:
	CBoy(int _iHeight, int _iWidth);
	~CBoy();
};

