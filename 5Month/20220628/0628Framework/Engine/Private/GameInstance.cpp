#include "..\Public\GameInstance.h"

IMPLEMENT_SINGLETON(CGameInstance)

CGameInstance::CGameInstance()
	:m_pGraphic_Device(CGraphic_Device::Get_Instance())
	,m_pLevel_Manager(CLevel_Manager::Get_Instance())
{
	Safe_AddRef(m_pGraphic_Device); // 싱글톤을 공유받으면 꼭 래퍼런스카운트를 증가시켜줘야한다.
	Safe_AddRef(m_pLevel_Manager);
}


HRESULT CGameInstance::Initialize_Engine(const GRAPHICDESC & GraphicDesc, IDirect3DDevice9 ** pOut)
{
	if (m_pGraphic_Device == nullptr)
		return E_FAIL;

	if (FAILED(m_pGraphic_Device->InitDevice(GraphicDesc.hWnd, GraphicDesc.iWinSizeX, GraphicDesc.iWinSizeY, GraphicDesc.eWinMode, pOut)))
		return E_FAIL;
	return S_OK;
}

void CGameInstance::Tick_Engine(_float fTimeDelta)
{
	if (m_pLevel_Manager == nullptr)
		return;
	m_pLevel_Manager->Tick(fTimeDelta);
}

void CGameInstance::Render_Begin(void)
{
	if (m_pGraphic_Device == nullptr)
		return;
	m_pGraphic_Device->Render_Begin();
}

void CGameInstance::Render_End(HWND hWnd)
{
	if (m_pGraphic_Device == nullptr)
		return;
	m_pGraphic_Device->Render_End(hWnd);
}

HRESULT CGameInstance::Open_Level(CLevel * pNewLevel)
{
	if (m_pLevel_Manager == nullptr)
		return E_FAIL;

	return m_pLevel_Manager->Open_Level(pNewLevel);
}

HRESULT CGameInstance::Render_Level()
{
	if (m_pLevel_Manager == nullptr)
		return E_FAIL;
	return m_pLevel_Manager->Render();
}

void CGameInstance::Release_Engine()
{
	CGameInstance::Get_Instance()->Destroy_Instance();

	CLevel_Manager::Get_Instance()->Destroy_Instance();

	CGraphic_Device::Get_Instance()->Destroy_Instance();
}

void CGameInstance::Free()
{
	Safe_Release(m_pLevel_Manager);
	Safe_Release(m_pGraphic_Device);
}
