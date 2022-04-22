#include "stdafx.h"
#include "InitPage.h"


CInitPage::CInitPage()
{
	Initialize();
}


CInitPage::~CInitPage()
{

}

void CInitPage::Initialize(void)
{
	m_bStart = 0;
	m_START_RECT = { 440,500,840,680 };
}

void CInitPage::Update(void)
{
	POINT    pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);
	m_MouseXY.x = (LONG)pt.x;
	m_MouseXY.y = (LONG)pt.y;
	if (GetAsyncKeyState(VK_LBUTTON)) {
		if ((m_MouseXY.x > m_START_RECT.left) && (m_MouseXY.x < m_START_RECT.right) && (m_MouseXY.y > m_START_RECT.top) && (m_MouseXY.y < m_START_RECT.bottom))
		{//맞게 누른것
			m_bStart = 1;
		}
	}
}

void CInitPage::Render()
{
	HDC hDC = GetDC(g_hWnd);

	MoveToEx(hDC, 250, 250, nullptr);
	LineTo(hDC, 300, 200);
	MoveToEx(hDC, 300, 200, nullptr);
	LineTo(hDC, 300, 350);
	MoveToEx(hDC, 250, 350, nullptr);
	LineTo(hDC, 350, 350);
	Ellipse(hDC, 400, 200, 450, 350);
	MoveToEx(hDC, 500, 200, nullptr);
	LineTo(hDC, 600, 200);
	MoveToEx(hDC, 600, 200, nullptr);
	LineTo(hDC, 500, 350);
	MoveToEx(hDC, 620, 200, nullptr);
	LineTo(hDC, 620, 350);
	MoveToEx(hDC, 620, 250, nullptr);
	LineTo(hDC, 650, 250);
	Ellipse(hDC, 700, 200, 750, 350);
	MoveToEx(hDC, 800, 200, nullptr);
	LineTo(hDC, 800, 350);


	Rectangle(hDC, m_START_RECT.left, m_START_RECT.top, m_START_RECT.right, m_START_RECT.bottom);
	TextOut(hDC, 620, 590, TEXT("START"), 5);
}


int CInitPage::GetStart()
{
	return m_bStart;
}