#include "stdafx.h"
#include "..\Public\MainApp.h"
#include "GameInstance.h"
#include "Level_Loading.h" //오류떠도 무시 나중에 클래스 작성하면 사라짐



using namespace Client;

CMainApp::CMainApp()
	: m_pGameInstance(CGameInstance::Get_Instance())
{
	Safe_AddRef(m_pGameInstance);
}

HRESULT CMainApp::Initialize()
{
	GRAPHICDESC			GraphicDesc; //Engine_Struct에 있는 구조체를 선언
	ZeroMemory(&GraphicDesc, sizeof(GRAPHICDESC)); // 쓰레기값 방지를 위해 메모리 초기화를 해줌
	//인자를 채워줌 직관적이니 따로 설명은 안하겠음
	GraphicDesc.hWnd = g_hWnd; 
	GraphicDesc.eWinMode = GRAPHICDESC::MODE_WIN;
	GraphicDesc.iWinSizeX = g_iWinSizeX;
	GraphicDesc.iWinSizeY = g_iWinSizeY;

	//1인자 : 레벨의갯수 END를 넣어준 이유는 STATIC을 제외한 갯수이기 때문이다.
	//2인자 : 생성한 구조체
	//3인자 : 실행하는 함수내에서 생성한 디바이스를 저장할 포인터
	if (FAILED(m_pGameInstance->Initialize_Engine(LEVEL_END, GraphicDesc, &m_pGraphic_Device)))
		return E_FAIL;

	//레벨을 변경하는함수 인자로 변경할 레벨을 넣어준다.
	if (FAILED(Open_Level(LEVEL_LOGO)))
		return E_FAIL;

	return S_OK;
}

void CMainApp::Tick(_float fTimeDelta)
{
	if (nullptr == m_pGameInstance)
		return;

	m_pGameInstance->Tick_Engine(fTimeDelta); //GameInstance의 Tick을 호출 
	//GameInstance에서는 Level_Manager의 Tick을 호출하고 Level_Manager Tick에서는 해당레벨의 Tick을 호출해준다.
}

HRESULT CMainApp::Render()
{
	if (nullptr == m_pGameInstance)
		return E_FAIL;


	m_pGameInstance->Render_Begin();

	m_pGameInstance->Render_Level();

	m_pGameInstance->Render_End();

	return S_OK;
}

HRESULT CMainApp::Open_Level(LEVEL eLevelID)
{
	if (nullptr == m_pGameInstance)
		return E_FAIL;

	/* 할당한 레벨을 레벨매니져에 보관할 수 있도록 한다. 
	즉 GameInstance의 Open_Level에 해당씬의 인덱스와 생성한 Level객체를 인자로 호출하면
	GameInstance에서 받은 인자로 Level_Manger의 Open_Level을 호출해준다.
	*/
	if (FAILED(m_pGameInstance->Open_Level(LEVEL_LOADING, CLevel_Loading::Create(m_pGraphic_Device, eLevelID))))
		return E_FAIL; //오류나도 무시 클래스생성후 사라짐

	return S_OK;
}

CMainApp * CMainApp::Create()
{
	CMainApp*		pInstance = new CMainApp();

	if (FAILED(pInstance->Initialize()))
	{
		MSG_BOX(TEXT("Failed To Created : CMainApp"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CMainApp::Free()
{
	Safe_Release(m_pGameInstance);

	CGameInstance::Release_Engine();

}

/*
디자인패턴중 하나인 프로토타입패턴은 원형객체를 저장해두고
저장해놓은 원형객체를 메모리복사하여 사본객체를 생성해 이용하는 방식이다.
이 패턴의 단점은 원형객체를 저장할 때 메모리가 소비된다는 단점이 있지만
객체생성속도가 빠른 장점이 있다.
예를들어 보통 게임은 서버와 통신하는데 객체를 생성하려면 서버에서 객체의 정보를 받아와야한다.
객체를 10개 생성할 때마다 서버와 통신하면 10번 통신을 해야하기때문에 객체생성속도가 느리다.
반면에 프로토타입패턴을 적용하여 원형객체를 서버와 통신하여 저장해두고
나머지9개의 객체를 저장해둔 원형객체를 메모리복사하여 생성하면 서버와 통신을 할 필요가 없기 때문에 생성속도가 빠르다.
극단적인 예로 서버가 없는 게임의 경우에도 마찬가지로
결국에 데이터는 파일입출력으로 관리하기 때문에 프로토타입 패턴을 사용하면
10번의 파일입출력을 1번의 파일입출력으로 줄여주기 때문에 객체생성속도가 빠르다.
객체생성속도는 즉 로딩속도와 직결되기 때문에 이 패턴을 사용하는것이 좋다.
*/