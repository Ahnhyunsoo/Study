#pragma once

class CInitPage
{
public:
	CInitPage();
	~CInitPage();
public:
	void    Initialize(void);
	void    Update(void);
	void    Render();
	int        GetStart();

private:
	RECT    m_START_RECT;
	POINT    m_MouseXY;
	int        m_bStart;

};