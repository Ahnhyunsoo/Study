#include "stdafx.h"
#include "..\Public\Level_Loading.h"
#include "GameInstance.h"

#include "Level_Logo.h"
#include "Level_GamePlay.h"

#include "Loader.h"


CLevel_Loading::CLevel_Loading(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CLevel(pGraphic_Device)
{
}

HRESULT CLevel_Loading::Initialize(LEVEL eNextLevel)
{
	if (FAILED(__super::Initialize()))
		return E_FAIL;

	m_eNextLevel = eNextLevel; //인자로 받은 레벨을 변수에 저장

	m_pLoader = CLoader::Create(m_pGraphic_Device, eNextLevel); 
	if (nullptr == m_pLoader)
		return E_FAIL;

	return S_OK;
}

void CLevel_Loading::Tick(_float fTimeDelta)
{
	__super::Tick(fTimeDelta);

	if (true == m_pLoader->Get_Finished()) // 로딩이 끝났는지 확인
	{
		if (GetKeyState(VK_RETURN) & 0x8000) // 로딩이 끝나고 엔터를 누른다면 0x8000 = 키가 이전에 눌린적이 없고 키가 눌린상태
		{
			//로딩이 끝난상태에서 엔터를 누르면 레벨전환
			CGameInstance*		pGameInstance = CGameInstance::Get_Instance();
			Safe_AddRef(pGameInstance);

			CLevel*		pNewLevel = nullptr;

			switch (m_eNextLevel)
			{
			case LEVEL_LOGO:
				pNewLevel = CLevel_Logo::Create(m_pGraphic_Device);
				break;
			case LEVEL_GAMEPLAY:
				pNewLevel = CLevel_GamePlay::Create(m_pGraphic_Device);
				break;
			}

			if (nullptr == pNewLevel)//만약 레벨이 nullptr였다면 except 구문으로 강제이동
				goto except;

			if (FAILED(pGameInstance->Open_Level(m_eNextLevel, pNewLevel))) // 레벨 전환에 실패했다면
				goto except;


		except: 
			Safe_Release(pGameInstance); // GameInstance의 래퍼런스카운트를 감소시켜준다.
		}
	}
}

HRESULT CLevel_Loading::Render()
{
	if (FAILED(__super::Render()))
		return E_FAIL;

	SetWindowText(g_hWnd, m_pLoader->Get_LoadingText());

	return S_OK;
}

CLevel_Loading * CLevel_Loading::Create(LPDIRECT3DDEVICE9 pGraphic_Device, LEVEL eNextLevelID)
{
	CLevel_Loading*		pInstance = new CLevel_Loading(pGraphic_Device);

	if (FAILED(pInstance->Initialize(eNextLevelID)))
	{
		MSG_BOX(TEXT("Failed To Created : CMainApp"));
		Safe_Release(pInstance);
	}

	return pInstance;

}


void CLevel_Loading::Free()
{
	__super::Free();

	Safe_Release(m_pLoader);

}


