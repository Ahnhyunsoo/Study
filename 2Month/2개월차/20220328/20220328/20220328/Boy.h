#pragma once
class CGirl;
class CBoy
{
private:
	int m_iHeight;
	int m_iWidth;

public:
	void Render(void) { cout << m_iHeight << "\t" << m_iWidth << endl; }
public:
	CBoy();
	~CBoy();
};

