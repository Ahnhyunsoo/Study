#pragma once

#include "Include.h"

class CToolView;
class CMiniView;
class CTerrain
	
{
	DECLARE_SINGLETON(CTerrain)

public:
	CTerrain();
	~CTerrain();

public:
	void		Initialize(void);
	void		Update(void);
	void		Render(void);
	void		Release(void);
	void		MiniRender(void);
	
public:
	void		Tile_Change(const D3DXVECTOR3& vPos, const BYTE& byDrawID);
	int			Get_TileIndex(const D3DXVECTOR3& vPos);
	bool		Picking(const D3DXVECTOR3& vPos, const int& iIndex);
	bool		Picking_Dot(const D3DXVECTOR3& vPos, const int& iIndex);
	

public:
	void		Set_MainView(CToolView* pMainView) { m_pMainView = pMainView; }
	void		Set_MiniView(CMiniView* pMiniView) { m_pMiniView = pMiniView; }
private:
	vector<TILE*>			m_vecTile;
	CToolView*				m_pMainView = nullptr;
	CMiniView*				m_pMiniView = nullptr;

};

