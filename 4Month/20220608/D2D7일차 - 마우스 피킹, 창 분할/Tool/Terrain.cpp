#include "stdafx.h"
#include "Terrain.h"
#include "TextureMgr.h"
#include "Device.h"
#include "ToolView.h"
#include "MiniView.h"

IMPLEMENT_SINGLETON(CTerrain)

CTerrain::CTerrain()
{
	m_vecTile.reserve(TILEX * TILEY);
}

CTerrain::~CTerrain()
{
	Release();
}

void CTerrain::Initialize(void)
{
	if (FAILED(CTextureMgr::Get_Instance()->InsertTexture(L"../Texture/Stage/Terrain/Tile/Tile%d.png", TEX_MULTI, L"Terrain", L"Tile", 36)))
	{
		AfxMessageBox(L"Tile Image Insert failed");
		return;
	}
	
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			TILE* pTile = new TILE;

			float		fX = (TILECX * j) + (i % 2) * (TILECX / 2.f);
			float		fY = (TILECY / 2.f) * i;

			pTile->vPos = { fX, fY, 0.f };
			pTile->vSize = { (float)TILECX, (float)TILECY, 0.f };
			pTile->byDrawID = 20;
			pTile->byOption = 0;

			m_vecTile.push_back(pTile);
			//m_vecTile.emplace_back()
		}
	}
}

void CTerrain::Update(void)
{
}

void CTerrain::Render(void)
{
	D3DXMATRIX		matWorld, matScale, matTrans;

	TCHAR		szBuf[MIN_STR] = L"";
	int			iIndex = 0;


	for (auto& iter : m_vecTile)
	{
		D3DXMatrixIdentity(&matWorld);
		D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
		D3DXMatrixTranslation(&matTrans, iter->vPos.x - m_pMainView->GetScrollPos(0),
										 iter->vPos.y - m_pMainView->GetScrollPos(1),
										 iter->vPos.z);

		matWorld = matScale *  matTrans;

		const TEXINFO*		pTexInfo = CTextureMgr::Get_Instance()->Get_Texture(L"Terrain", L"Tile", iter->byDrawID);

		if (nullptr == pTexInfo)
			return;

		float		fX = pTexInfo->tImgInfo.Width / 2.f;
		float		fY = pTexInfo->tImgInfo.Height / 2.f;

		CDevice::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);

		CDevice::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture,	
													nullptr,
													&D3DXVECTOR3(fX, fY, 0.f), 
													nullptr, 
													D3DCOLOR_ARGB(255, 255, 255, 255));

		swprintf_s(szBuf, L"%d", iIndex);
		
		CDevice::Get_Instance()->Get_Font()->DrawTextW(CDevice::Get_Instance()->Get_Sprite(),
			szBuf,
			lstrlen(szBuf),
			nullptr,
			0,
			D3DCOLOR_ARGB(255, 0, 0, 0));		

	
	
		/*DrawTextW : 스프라이트 객체를 이용하여 폰트를 출력하는 함수
		1. 폰트 출력에 필요한 스프라이트 객체
		2. 출력할 문자열
		3. 출력할 문자열 버퍼 크기
		4. 출력 영역에 대한 렉트 주소, NULL을 넣어주면 스프라이트 컴 객체의 행렬 값이 반영
		5. 네번 째 인자값에서 지정한 사각형 범위 안에서의 정렬 옵션 ex) DT_LEFT, DT_CENTER 등등
		6. 출력할 폰트 색상*/
	
		++iIndex;
	}	
	/*	D3DXMATRIX mat1, mat2,mat3;


	D3DXMatrixIdentity(&mat1);
	D3DXMatrixScaling(&mat2, 2.f, 2.f, 1.f);
	D3DXMatrixTranslation(&mat3, 100 - m_pMainView->GetScrollPos(0),
		100 - m_pMainView->GetScrollPos(1), 
		0.f);

	mat1 = mat2 *  mat3;
	
	TCHAR		szBuf2[MIN_STR];
	swprintf_s(szBuf2, L"영웅짱짱맨");
	CDevice::Get_Instance()->Get_Sprite()->SetTransform(&mat1); 
	CDevice::Get_Instance()->Get_Font()->DrawTextW(CDevice::Get_Instance()->Get_Sprite(),
		szBuf2,
		lstrlen(szBuf2),
		nullptr,
		0,
		D3DCOLOR_ARGB(255, 255, 0, 255));*/


}

void CTerrain::Release(void)
{
	for_each(m_vecTile.begin(), m_vecTile.end(), CDeleteObj());
	m_vecTile.clear();
	m_vecTile.shrink_to_fit();
}

void CTerrain::MiniRender(void)
{
	D3DXMATRIX		matWorld, matScale, matTrans;

	TCHAR		szBuf[MIN_STR] = L"";

	int			iIndex = 0;

	for (auto& iter : m_vecTile)
	{
		/*D3DXMatrixIdentity(&matWorld);
		D3DXMatrixScaling(&matScale, 0.306f, 0.59f, 1.f);
		D3DXMatrixTranslation(&matTrans, iter->vPos.x * 0.306f,
		iter->vPos.y * 0.59f,
		iter->vPos.z);*/
		/*D3DXMatrixIdentity(&matWorld);
		D3DXMatrixScaling(&matScale, 1.f / (TILECX*TILEX) * WINCX, 1.f / (TILECY*TILEY) * WINCY, 1.f);
		D3DXMatrixTranslation(&matTrans, iter->vPos.x / (TILECX*TILEX) * WINCX,
			iter->vPos.y / (TILECY*TILEY) * WINCY,
			iter->vPos.z);*/
		//1,f / (TILECX*TILEX) * WINCX 

		D3DXMatrixIdentity(&matWorld);
		D3DXMatrixScaling(&matScale, 0.3f , 0.6f , 1.f);
		D3DXMatrixTranslation(&matTrans, iter->vPos.x ,
			iter->vPos.y,
			iter->vPos.z);
		 
		
		matWorld =   matTrans * matScale;


		const TEXINFO*		pTexInfo = CTextureMgr::Get_Instance()->Get_Texture(L"Terrain", L"Tile", iter->byDrawID);
		
		if (nullptr == pTexInfo)
			return;

		float		fX = pTexInfo->tImgInfo.Width / 2.f;
		float		fY = pTexInfo->tImgInfo.Height / 2.f;

		CDevice::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
	
		CDevice::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture,
			nullptr,
			&D3DXVECTOR3(fX, fY, 0.f),
			nullptr,
			D3DCOLOR_ARGB(255, 255, 255, 255));

		swprintf_s(szBuf, L"%d", iIndex);

		CDevice::Get_Instance()->Get_Font()->DrawTextW(CDevice::Get_Instance()->Get_Sprite(),
			szBuf,
			lstrlen(szBuf),
			nullptr,
			0,
			D3DCOLOR_ARGB(255, 0, 0, 0));
		++iIndex;
	}



}

void CTerrain::Tile_Change(const D3DXVECTOR3 & vPos, const BYTE & byDrawID)
{
	int		iIndex = Get_TileIndex(vPos);
	
	if (-1 == iIndex)
		return;
	m_pMiniView->OnInitialUpdate();
	m_vecTile[iIndex]->byDrawID = byDrawID;
	m_vecTile[iIndex]->byOption = 1;
} 

int CTerrain::Get_TileIndex(const D3DXVECTOR3& vPos)
{
	for (size_t iIndex = 0; iIndex < m_vecTile.size(); ++iIndex)
	{
		if (Picking_Dot(vPos, iIndex))
		{
			return iIndex;
		}
	}
	// 피킹 실패 시 음수 반환
	return -1;
}

bool CTerrain::Picking(const D3DXVECTOR3 & vPos, const int & iIndex)
{
	// y = ax + b;


	// 12, 3, 6, 9 시 방향 순서로 위치를 잡음
	float	fGradient[4] = {

		(TILECY / 2.f) / (TILECX / 2.f) * -1.f, 
		(TILECY / 2.f) / (TILECX / 2.f),
		(TILECY / 2.f) / (TILECX / 2.f) * -1.f,
		(TILECY / 2.f) / (TILECX / 2.f)
	};

	D3DXVECTOR3		vPoint[4] = {

		{ m_vecTile[iIndex]->vPos.x, m_vecTile[iIndex]->vPos.y + (TILECY / 2.f), 0.f  },
		{ m_vecTile[iIndex]->vPos.x + (TILECX / 2.f), m_vecTile[iIndex]->vPos.y, 0.f },
		{ m_vecTile[iIndex]->vPos.x, m_vecTile[iIndex]->vPos.y - (TILECY / 2.f), 0.f },
		{ m_vecTile[iIndex]->vPos.x - (TILECX / 2.f), m_vecTile[iIndex]->vPos.y, 0.f }

	};

	// y = ax + b
	// -b = ax - y
	// b = y - ax		

	float	fB[4] = {

		vPoint[0].y - fGradient[0] * vPoint[0].x,
		vPoint[1].y - fGradient[1] * vPoint[1].x,
		vPoint[2].y - fGradient[2] * vPoint[2].x,
		vPoint[3].y - fGradient[3] * vPoint[3].x

	};


	//0 == ax + b - y	// 직선 상에 있는 경우
	//0 > ax + b - y  // 직선 위에 있는 경우
	//0 < ax + b - y  // 직선 아래에 있는 경우

	bool	bCheck[4] = { false };

	if (0 < fGradient[0] * vPos.x + fB[0] - vPos.y)
		bCheck[0] = true;

	if (0 > fGradient[1] * vPos.x + fB[1] - vPos.y)
		bCheck[1] = true;

	if (0 > fGradient[2] * vPos.x + fB[2] - vPos.y)
		bCheck[2] = true;

	if (0 < fGradient[3] * vPos.x + fB[3] - vPos.y)
		bCheck[3] = true;

	return bCheck[0] && bCheck[1] && bCheck[2] && bCheck[3];
}

bool CTerrain::Picking_Dot(const D3DXVECTOR3& vPos, const int& iIndex)
{
	D3DXVECTOR3		vPoint[4] = {

		{ m_vecTile[iIndex]->vPos.x, m_vecTile[iIndex]->vPos.y + (TILECY / 2.f), 0.f },
		{ m_vecTile[iIndex]->vPos.x + (TILECX / 2.f), m_vecTile[iIndex]->vPos.y, 0.f },
		{ m_vecTile[iIndex]->vPos.x, m_vecTile[iIndex]->vPos.y - (TILECY / 2.f), 0.f },
		{ m_vecTile[iIndex]->vPos.x - (TILECX / 2.f), m_vecTile[iIndex]->vPos.y, 0.f }

	};

	D3DXVECTOR3		vDir[4] = {

		vPoint[1] - vPoint[0],
		vPoint[2] - vPoint[1],
		vPoint[3] - vPoint[2],
		vPoint[0] - vPoint[3]
	};

	D3DXVECTOR3		vNormal[4] = {

		{ -vDir[0].y, vDir[0].x, 0.f },
		{ -vDir[1].y, vDir[1].x, 0.f },
		{ -vDir[2].y, vDir[2].x, 0.f },
		{ -vDir[3].y, vDir[3].x, 0.f }
	};	

	D3DXVECTOR3	vMouseDir[4] = {

		vPos - vPoint[0],
		vPos - vPoint[1],
		vPos - vPoint[2],
		vPos - vPoint[3]		
	};
	for (int i = 0; i < 4; ++i)
	{
		D3DXVec3Normalize(&vNormal[i], &vNormal[i]);
		D3DXVec3Normalize(&vMouseDir[i], &vMouseDir[i]);
	}
	
	for (int i = 0; i < 4; ++i)
	{
		// 양수인 경우 예각이어서 타일 외부에 피킹한 꼴인 셈
		if (0.f < D3DXVec3Dot(&vMouseDir[i], &vNormal[i]))
			return false;
	}

	return true;
}
