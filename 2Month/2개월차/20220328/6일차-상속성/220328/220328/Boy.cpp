#include "stdafx.h"
#include "Boy.h"
#include "Girl.h"

void CBoy::Render(void)
{
	 cout << m_iHeight << "\t" << m_iWidth << endl; 
}

CBoy::CBoy(int _iHeight, int _iWidth)
	: m_iHeight(_iHeight),
	  m_iWidth(_iWidth)
{
}


CBoy::~CBoy()
{
}
