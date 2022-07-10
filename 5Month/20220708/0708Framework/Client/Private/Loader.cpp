#include "stdafx.h"
#include "..\Public\Loader.h"

#include "GameInstance.h"
#include "BackGround.h"

CLoader::CLoader(LPDIRECT3DDEVICE9 pGraphic_Device)
	: m_pGraphic_Device(pGraphic_Device)
{
	Safe_AddRef(m_pGraphic_Device);
}

_uint APIENTRY LoadingMain(void* pArg) //쓰레드에서 작업해줄 코드
{
	CLoader*		pLoader = (CLoader*)pArg;

	EnterCriticalSection(&pLoader->Get_CS()); 
	/* 여기서 CriticalSection 이란
	임계구역을 의미한다. 이건 제한을 둔다는 의미인데
	예상치못한 결과를 방지하기위해 예외처리를 해주는것이다.
	예를들어 10개의 쓰레드가 있는데 10개의 쓰레드가 동시에 같은 함수를 실행한다고 가정하자.
	그러면 내가 원하는 결과는 1초에 1씩 증가하는것인데 동시에 10개의 쓰레드가 실행하기때문에
	1초에 10씩 증가하는 결과를 초래할 수 있다.
	때문에 하나의 쓰레드가 작업중이면 다른쓰레드가 접근하지 못하게 예외처리하는것을 임계구역(Critical Section이라고한다)
	이것 때문에 교착상태(DeadLock)라는 문제가 발생하는데 궁금하면 구글링 하길 바랍니다.
	*/
	switch (pLoader->Get_NextLevelID()) //스위치문에 따라서 함수실행
	{
	case LEVEL_LOGO:
		pLoader->Loading_ForLogoLevel();
		break;
	case LEVEL_GAMEPLAY:
		pLoader->Loading_ForGamePlayLevel();
		break;
	}

	LeaveCriticalSection(&pLoader->Get_CS());

	return 0;
}

HRESULT CLoader::Initialize(LEVEL eNextLevelID)
{
	m_eNextLevelID = eNextLevelID;

	InitializeCriticalSection(&m_CriticalSection);

	m_hThread = (HANDLE)_beginthreadex(nullptr, 0, LoadingMain, this, 0, nullptr); 
	//_beginthreadex쓰레드를 초기화 및 실행해주는 함수

	if (0 == m_hThread)
		return E_FAIL;

	return S_OK;
}

HRESULT CLoader::Loading_ForLogoLevel()
{
	lstrcpy(m_szLoadingText, TEXT("객체원형을 로딩중입니다. "));

	CGameInstance*		pGameInstance = CGameInstance::Get_Instance();
	Safe_AddRef(pGameInstance);

	/* 객체원형을 추가한다. */
	if (FAILED(pGameInstance->Add_Prototype(TEXT("Prototype_GameObject_BackGround"), CBackGround::Create(m_pGraphic_Device))))
		return E_FAIL;

	lstrcpy(m_szLoadingText, TEXT("텍스쳐를 로딩중입니다. "));
	/* 텍스쳐를 로드한다. */
	for (_uint i = 0; i < 999999999; ++i) //로딩이 너무 짧기때문에 테스트용으로 선언해둔 코드
		_uint a = 10;

	lstrcpy(m_szLoadingText, TEXT("모델을 로딩중입니다. "));
	/* 모델를 로드한다. */
	for (_uint i = 0; i < 999999999; ++i)
		_uint a = 10;

	lstrcpy(m_szLoadingText, TEXT("로딩이 완료되었습니다.  "));

	Safe_Release(pGameInstance);

	m_isFinished = true;

	return S_OK;
}

HRESULT CLoader::Loading_ForGamePlayLevel()
{
	lstrcpy(m_szLoadingText, TEXT("객체원형을 로딩중입니다. "));
	/* 개ㅑㄱ체원형 로드한다. */
	for (_uint i = 0; i < 999999999; ++i)
		_uint a = 10;


	lstrcpy(m_szLoadingText, TEXT("텍스쳐를 로딩중입니다. "));
	/* 텍스쳐를 로드한다. */
	for (_uint i = 0; i < 999999999; ++i)
		_uint a = 10;

	lstrcpy(m_szLoadingText, TEXT("모델을 로딩중입니다. "));
	/* 모델를 로드한다. */
	for (_uint i = 0; i < 999999999; ++i)
		_uint a = 10;

	lstrcpy(m_szLoadingText, TEXT("로딩이 완료되었습니ㅏㄷ.  "));

	m_isFinished = true;

	return S_OK;
}

CLoader * CLoader::Create(LPDIRECT3DDEVICE9 pGraphic_Device, LEVEL eNextLevelID)
{
	CLoader*		pInstance = new CLoader(pGraphic_Device);

	if (FAILED(pInstance->Initialize(eNextLevelID)))
	{
		MSG_BOX(TEXT("Failed To Created : CLoader"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CLoader::Free()
{
	//쓰레드를 삭제해주는 함수들
	WaitForSingleObject(m_hThread, INFINITE);

	DeleteCriticalSection(&m_CriticalSection);

	CloseHandle(m_hThread);

	Safe_Release(m_pGraphic_Device);


}
