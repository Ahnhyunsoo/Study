#pragma once

#include "Client_Defines.h"
#include "Base.h"

//GameInstance는 Engine안에 구현되어있기때문에 네임스페이스를 Engine으로 지정해줘야함.
BEGIN(Engine)
class CRenderer;
class CGameInstance; //전방선언
END

//GameInstance를 전방선언해줬으면 다시 Client로 namespace를 지정해준다.
BEGIN(Client)

class CMainApp final : public CBase
{
private:
	CMainApp();
	virtual ~CMainApp() = default;

public:
	HRESULT Initialize();
	void Tick(_float fTimeDelta);
	HRESULT Render();

private:
	CGameInstance*				m_pGameInstance = nullptr;
	CRenderer*					m_pRenderer = nullptr;

private:
	LPDIRECT3DDEVICE9			m_pGraphic_Device = nullptr;

private:
	HRESULT Open_Level(LEVEL eLevelID);

private:  /* For.Static */
	HRESULT Ready_Prototype_Component();
	HRESULT Ready_Prototype_GameObject();


public:
	static CMainApp* Create();
	virtual void Free();
};


END