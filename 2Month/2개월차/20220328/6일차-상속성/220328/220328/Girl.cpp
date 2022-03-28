#include "stdafx.h"
#include "Girl.h"

#include "Boy.h"

CGirl::CGirl()
{
}


CGirl::~CGirl()
{
}
void CGirl::Show_BoyInfo(CBoy* pBoy)
{
	cout << pBoy->m_iHeight << endl;
	cout << pBoy->m_iWidth << endl;
}

void CGirl::Draw(void)
{
	CBoy	bOY(100, 200);

	bOY.Render();
}
