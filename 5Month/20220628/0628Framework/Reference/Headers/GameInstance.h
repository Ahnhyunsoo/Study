#pragma once
#include "Graphic_Device.h"
#include "Level_Manager.h"

BEGIN(Engine)

class ENGINE_DLL CGameInstance final : public CBase
{
	DECLARE_SINGLETON(CGameInstance)
private:
	CGameInstance();
	virtual ~CGameInstance() = default;

public:// 엔진의 함수를 호출하기위한 함수
	HRESULT Initialize_Engine(const GRAPHICDESC& GraphicDesc, IDirect3DDevice9** pOut); // IDirect3DDevice9** = LPDIRECT3DDEVICE
	void Tick_Engine(_float fTimeDelta);

public: // 디바이스의 함수를 호출하기위한 함수
	void Render_Begin(void);
	void Render_End(HWND hWnd = 0);

public: // 레벨매니저의 함수를 호출하기위한 함수
	HRESULT Open_Level(class CLevel* pNewLevel);
	HRESULT Render_Level();

private: // 디바이스와 레벨매니저의 포인터를 저장하기위한 변수
	CGraphic_Device* m_pGraphic_Device = nullptr; 
	CLevel_Manager* m_pLevel_Manager = nullptr;

public:
	static void Release_Engine();
	virtual void Free() override;
};

END
