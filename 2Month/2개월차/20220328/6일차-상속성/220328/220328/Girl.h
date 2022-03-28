#pragma once

class CBoy;
class CGirl
{
private:
	int			m_iAge;

public:
	void		Show_BoyInfo(CBoy* pBoy);

	void		Draw(void);

public:
	CGirl();
	~CGirl();
};

