
// ToolView.cpp : CToolView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Tool.h"
#endif

#include "ToolDoc.h"
#include "ToolView.h"
#include "TextureMgr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

HWND		g_hWnd;


// CToolView

IMPLEMENT_DYNCREATE(CToolView, CView)

BEGIN_MESSAGE_MAP(CToolView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)


	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CToolView 생성/소멸

CToolView::CToolView()
	: m_pDevice(CDevice::Get_Instance())
	//, m_pSingle(nullptr)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CToolView::~CToolView()
{
	//Safe_Delete(m_pSingle);
	CTextureMgr::Get_Instance()->Destroy_Instance();
	m_pDevice->Destroy_Instance();
}

void CToolView::OnInitialUpdate()
{
	
	CView::OnInitialUpdate();
	
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	g_hWnd = m_hWnd;
	m_Gap = false;
	if (FAILED(m_pDevice->Initialize()))
	{
		AfxMessageBox(L"m_pDevice 생성 실패");
		return;
	}

	//m_pSingle = new CSingleTexture;
	//m_pSingle->InsertTexture(L"../Texture/Cube.png");


	if (FAILED(CTextureMgr::Get_Instance()->InsertTexture(L"../Texture/Cube.png", TEX_SINGLE, L"Cube")))
	{
		AfxMessageBox(L"Cube Image Insert failed");
		return;
	}

	if (FAILED(CTextureMgr::Get_Instance()->InsertTexture(L"../Texture/Stage/Terrain/Tile/Tile%d.png", TEX_MULTI, L"Terrain", L"Tile", 36)))
	{
		AfxMessageBox(L"Tile Image Insert failed");
		return;
	}


	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			m_iTexture[i][j] = 2;
			pTexInfo[i][j] = CTextureMgr::Get_Instance()->Get_Texture(L"Terrain", L"Tile", m_iTexture[i][j]);
			
			if (i % 2 == 1)
			{
				//m_Vec[i][j] = { 0,0,0 };
				m_Vec[i][j] = { 
					(float(j) - 10.f) * float(pTexInfo[i][j]->tImgInfo.Width),
					(float(i) - 15.f) * float(pTexInfo[i][j]->tImgInfo.Height * 0.5f),
					0.f };
			}
			else
			{
				//m_Vec[i][j] = { 0,0,0 };
				m_Vec[i][j] = { 
					(float(j) - 10.f) * float((pTexInfo[i][j]->tImgInfo.Width)) - ((pTexInfo[i][j]->tImgInfo.Width)*0.5f),
					(float(i) - 15.f) * float(pTexInfo[i][j]->tImgInfo.Height * 0.5f),
					0.f };
			}
		}
	}
}

// CToolView 그리기

void CToolView::RenderTexture()
{

	//20 30
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			pTexInfo[i][j] = CTextureMgr::Get_Instance()->Get_Texture(L"Terrain", L"Tile", m_iTexture[i][j]);

			if (nullptr == pTexInfo)
				return;

			float		fX = pTexInfo[i][j]->tImgInfo.Width / 2.f;
			float		fY = pTexInfo[i][j]->tImgInfo.Height / 2.f;
		
				m_pDevice->Get_Sprite()->Draw(pTexInfo[i][j]->pTexture,	// 그리고자 하는 텍스처
					nullptr, // 출력할 이미지 영역에 대한 rect 포인터, null인 경우 이미지의 0, 0 기준으로 출력
					&D3DXVECTOR3(fX, fY, 0.f), // 출력할 이미지 중심 축에 대한 vec3 구조체 포인터, null인 경우 0, 0이 중심 좌표
					&(m_Vec[i][j]), // 위치 좌표에 대한 vec3 구조체 포인터, null인 경우 스크린 상 0,0 좌표에 출력
					D3DCOLOR_ARGB(255, 255, 255, 255)); //출력할 원본 이미지와 섞을 색상 값, 출력 시 섞은 색상이 반영, 0xffffffff를 넘겨주면 원본 색상 유지된 상태로 출력

		}
	}
}


void CToolView::OnDraw(CDC* pDC)
{
	CToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	//pDC->Rectangle(100, 100, 200, 200);


	D3DXMATRIX		matWorld, matScale, matRotZ, matTrans;

	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(45.f));
	D3DXMatrixTranslation(&matTrans, 400.f, 300.f, 0.f);

	matWorld = matScale *  matTrans;

	CDevice::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
	m_pDevice->Render_Begin();
	RenderTexture();


	m_pDevice->Render_End();
	pDC->Rectangle(m_pt.x -5,m_pt.y-5,m_pt.x+5,m_pt.y+5);
}

#pragma region 불필요
BOOL CToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}


BOOL CToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CToolView 진단

#ifdef _DEBUG
void CToolView::AssertValid() const
{
	CView::AssertValid();
}

void CToolView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CToolDoc* CToolView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CToolDoc)));
	return (CToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CToolView 메시지 처리기
#pragma endregion 불필요

// CToolView 인쇄


void CToolView::OnLButtonDown(UINT nFlags, CPoint point)
{
	
	m_pt.x = (point.x - 400.f) ;
	m_pt.y = (point.y - 300.f) ;
	CView::OnLButtonDown(nFlags, point);

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			//기울기를 1개 구해야한다. 첫번째 기울기를 구하기 x
			D3DXVECTOR3 TempLeft = { m_Vec[i][j].x - (pTexInfo[i][j]->tImgInfo.Width * 0.5f), m_Vec[i][j].y, 0.f};
			D3DXVECTOR3 TempTop = { m_Vec[i][j].x, m_Vec[i][j].y - pTexInfo[i][j]->tImgInfo.Height * 0.5f, 0.f};
			D3DXVECTOR3 TempRight = { m_Vec[i][j].x + (pTexInfo[i][j]->tImgInfo.Width * 0.5f), m_Vec[i][j].y, 0.f};
			D3DXVECTOR3 TempBottom = { m_Vec[i][j].x, m_Vec[i][j].y + pTexInfo[i][j]->tImgInfo.Height * 0.5f, 0.f };

			float Diagonal1 = (TempLeft.y - TempTop.y) / (TempLeft.x - TempTop.x);
			float Diagonal2 = (TempTop.y - TempRight.y) / (TempTop.x - TempRight.x);
			float Diagonal3 = (TempBottom.y - TempRight.y) / (TempBottom.x - TempRight.x);
			float Diagonal4 = (TempLeft.y - TempBottom.y) / (TempLeft.x - TempBottom.x);
			
			float fB1 = TempTop.y - (Diagonal1 * TempTop.x);
			float fB2 = TempTop.y - (Diagonal2 * TempTop.x);
			float fB3 = TempBottom.y - (Diagonal3 * TempBottom.x);
			float fB4 = TempBottom.y - (Diagonal4 * TempBottom.x);

			// y = Diagonal1*x + fB1

			if (Diagonal1 * m_pt.x + fB1 < m_pt.y && Diagonal4 * m_pt.x + fB4 > m_pt.y
				&& Diagonal2 * m_pt.x + fB2 < m_pt.y && Diagonal3 * m_pt.x + fB3 > m_pt.y)
			{
				m_iTexture[i][j] += 1;
				if (m_iTexture[i][j] > 35)
					m_iTexture[i][j] = 0;
			}

		}
	}	
	
	
	Invalidate();
}
