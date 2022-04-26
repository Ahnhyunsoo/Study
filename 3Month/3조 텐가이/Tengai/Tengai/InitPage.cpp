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
	m_START_RECT = { 540,550,740,630 };
	m_Mouse_Info.fCX = 20;
	m_Mouse_Info.fCY = 20;
	m_Mouse_Info.fAngle = 1.f;

	random_device rd;
	mt19937_64 rng(rd());
	uniform_int_distribution<__int64> dist1(10, 1200);
	uniform_int_distribution<__int64> dist2(10, 700);

	for (int i = 0; i < 20; ++i)
	{
		m_Random_XY.x = long(dist1(rng));
		m_Random_XY.y = long(dist2(rng));
		Random_Rect_Set(i);
	}
}

void CInitPage::Update(void)
{
	POINT    pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);
	m_MouseXY.x = (LONG)pt.x;
	m_MouseXY.y = (LONG)pt.y;
	m_Mouse_Info.fAngle += 5.f;
	Mouse_Rect_Update();
	Random_Rect_Update();
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
	Rectangle(hDC, 0, 0, WINCX, WINCY);//초기화
	for (int i = 0; i < 20; ++i)
	{
		Rectangle(hDC, m_Random_Rect[i].left, m_Random_Rect[i].top, m_Random_Rect[i].right, m_Random_Rect[i].bottom);
	}

	MoveToEx(hDC, 330, 250, nullptr);
	LineTo(hDC, 380, 200);
	MoveToEx(hDC, 380, 200, nullptr);
	LineTo(hDC, 380, 350);
	MoveToEx(hDC, 330, 350, nullptr);
	LineTo(hDC, 430, 350);
	Ellipse(hDC, 480, 200, 530, 350);
	MoveToEx(hDC, 580, 200, nullptr);
	LineTo(hDC, 680, 200);
	MoveToEx(hDC, 680, 200, nullptr);
	LineTo(hDC, 580, 350);
	MoveToEx(hDC, 700, 200, nullptr);
	LineTo(hDC, 700, 350);
	MoveToEx(hDC, 700, 250, nullptr);
	LineTo(hDC, 730, 250);
	Ellipse(hDC, 780, 200, 830, 350);
	MoveToEx(hDC, 880, 200, nullptr);
	LineTo(hDC, 880, 350);
	ShowCursor(false);

	Rectangle(hDC, m_START_RECT.left, m_START_RECT.top, m_START_RECT.right, m_START_RECT.bottom);//스타트 네모
	TextOut(hDC, 620, 585, TEXT("START"), 5);
	Ellipse(hDC, m_Mouse_Rect.left, m_Mouse_Rect.top, m_Mouse_Rect.right, m_Mouse_Rect.bottom);//마우스
}


int CInitPage::GetStart()
{
	return m_bStart;
}

void CInitPage::Mouse_Rect_Update()
{
	m_Mouse_Rect.left = long(m_MouseXY.x - m_Mouse_Info.fCX * cosf((m_Mouse_Info.fAngle * PI) / 180.f));
	m_Mouse_Rect.top = long(m_MouseXY.y - m_Mouse_Info.fCX * sinf((m_Mouse_Info.fAngle * PI) / 180.f));
	m_Mouse_Rect.right = long(m_MouseXY.x + m_Mouse_Info.fCX * cosf((m_Mouse_Info.fAngle * PI) / 180.f));
	m_Mouse_Rect.bottom = long(m_MouseXY.y + m_Mouse_Info.fCX * sinf((m_Mouse_Info.fAngle * PI) / 180.f));
}

void CInitPage::Random_Rect_Set(int iNumber)
{
	m_Random_Rect[iNumber].left = m_Random_XY.x - 10;
	m_Random_Rect[iNumber].top = m_Random_XY.y - 10;
	m_Random_Rect[iNumber].right = m_Random_XY.x + 10;
	m_Random_Rect[iNumber].bottom = m_Random_XY.y + 10;
}

void CInitPage::Random_Rect_Update()
{
	for (int i = 0; i < 20; ++i) {
		m_Random_Rect[i].left -= 3;
		m_Random_Rect[i].right -= 3;
		if (m_Random_Rect[i].left <= 0) {
			m_Random_Rect[i].left = WINCX;
			m_Random_Rect[i].right = WINCX+20;

		}
	}
}
