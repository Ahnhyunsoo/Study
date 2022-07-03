#include "..\Public\GameInstance.h"

IMPLEMENT_SINGLETON(CGameInstance)


CGameInstance::CGameInstance()
	: m_pGraphic_Device(CGraphic_Device::Get_Instance())
	, m_pLevel_Manager(CLevel_Manager::Get_Instance())
	, m_pObject_Manager(CObject_Manager::Get_Instance())
	, m_pComponent_Manager(CComponent_Manager::Get_Instance())
{
	//참조했으니 래퍼런스카운터 증가시켜준다.
	Safe_AddRef(m_pObject_Manager);
	Safe_AddRef(m_pLevel_Manager);
	Safe_AddRef(m_pGraphic_Device);
	Safe_AddRef(m_pComponent_Manager);
}

HRESULT CGameInstance::Initialize_Engine(_uint iNumLevels, const GRAPHICDESC& GraphicDesc, IDirect3DDevice9** ppOut)
{
	//엔진을 구동하기위한 초기화작업을 진행함
	if (m_pGraphic_Device == nullptr)//디바이스 객체가 없다면 함수종료
		return E_FAIL;
	//1인자 : 핸들, 2인자 : 가로창사이즈, 3인자 : 세로창사이즈, 4인자 : 창모드인지 전체모드인지, 5인자 : 디바이스를 저장할 포인터
	//Graphic_Device에 InitDevice함수안에보면 인자로넣은 ppOut에 디바이스를 대입해주는 코드가 있음
	if (FAILED(m_pGraphic_Device->InitDevice(GraphicDesc.hWnd, GraphicDesc.iWinSizeX, GraphicDesc.iWinSizeY, GraphicDesc.eWinMode, ppOut)))
		return E_FAIL; //초기화에 실패했으면 함수종료

	//인자로 받은 레벨의 갯수만큼 map을 동적할당해줌
	if (FAILED(m_pObject_Manager->Reserve_Container(iNumLevels)))
		return E_FAIL;

	return S_OK;
}

void CGameInstance::Tick_Engine(_float fTimeDelta)
{
	if (nullptr == m_pLevel_Manager || //Level매니저나 Object매니저 둘중 하나라도 nullptr이면 함수종료
		nullptr == m_pObject_Manager)
		return;

	m_pObject_Manager->Tick(fTimeDelta); //먼저 오브젝트의 Tick을 호출



	m_pObject_Manager->LateTick(fTimeDelta); // Tick이 다 끝난후 LateTick 호출

	m_pLevel_Manager->Tick(fTimeDelta); // 레벨의 Tick을 호출
}

void CGameInstance::Clear(_uint iLevelIndex)
{
	if (nullptr == m_pObject_Manager)
		return;

	m_pObject_Manager->Clear(iLevelIndex);  //Object_Manager의 Clear를 호출
	//이와같이 GameInstance내의 함수들은 인자로 갖고있는 객체안에 있는 함수들을 호출해주는 연결다리역할을함.
	//그리고 호출해주는 함수들은 클라이언트에서 사용하는 함수들임
	//이제 대충 파악했을테니 이후에 호출만해주는 함수들은 설명하지 않겠음
}

void CGameInstance::Render_Begin(void)
{
	if (nullptr == m_pGraphic_Device)
		return;

	m_pGraphic_Device->Render_Begin();
}

void CGameInstance::Render_End(HWND hWnd)
{
	if (nullptr == m_pGraphic_Device)
		return;

	m_pGraphic_Device->Render_End(hWnd);
}

HRESULT CGameInstance::Open_Level(_uint iLevelIndex, CLevel * pNewLevel)
{
	if (nullptr == m_pLevel_Manager)
		return E_FAIL;

	return m_pLevel_Manager->Open_Level(iLevelIndex, pNewLevel);
}

HRESULT CGameInstance::Render_Level()
{
	if (nullptr == m_pLevel_Manager)
		return E_FAIL;

	return m_pLevel_Manager->Render();
}

HRESULT CGameInstance::Add_Prototype(const _tchar * pPrototypeTag, CGameObject * pPrototype)
{
	if (nullptr == m_pObject_Manager)
		return E_FAIL;

	return m_pObject_Manager->Add_Prototype(pPrototypeTag, pPrototype);
}

HRESULT CGameInstance::Add_GameObjectToLayer(const _tchar * pPrototypeTag, _uint iLevelIndex, const _tchar * pLayerTag, void * pArg)
{
	if (nullptr == m_pObject_Manager)
		return E_FAIL;

	return m_pObject_Manager->Add_GameObjectToLayer(pPrototypeTag, iLevelIndex, pLayerTag, pArg);
}

HRESULT CGameInstance::Add_Prototype(_uint iLevelIndex, const _tchar * pPrototypeTag, CComponent * pPrototype)
{
	if (nullptr == m_pComponent_Manager)
		return E_FAIL;

	return m_pComponent_Manager->Add_Prototype(iLevelIndex, pPrototypeTag, pPrototype);
}

CComponent * CGameInstance::Clone_Component(_uint iLevelIndex, const _tchar * pPrototypeTag, void * pArg)
{
	if (nullptr == m_pComponent_Manager)
		return nullptr;

	return m_pComponent_Manager->Clone_Component(iLevelIndex, pPrototypeTag, pArg);
}

void CGameInstance::Release_Engine()
{
	//여기 집중해서 잘 보시길 바랍니다.

	/*
	Release_Engine함수를 따로 만든 이유는 싱글톤객체의 주소를 공유받았기 때문에 공유해준 해당 싱글톤객체의 래퍼런스카운트는 1이다.
	때문에 Free함수에서 Release를 호출한다해도 래퍼런스카운트가 감소할뿐 삭제가 되지 않는다.
	하지만 매크로로 구성해둔 전역함수인 Destroy_Instance를 호출하면 해결된다. 그 이유는 Destroy_Instance도 Release를 호출하기 때문이다.
	Free함수를통해 Release를 호출해서 싱글톤객체들의 래퍼런스카운트를 0으로 만들어준 후 Release_Engine을 호출하면
	래퍼런스카운트가0이기 때문에 객체들이 삭제된다.

	★★★ 이해가 안됐다면 아래 설명은 Client에서 MainApp을 구현한 후 다시와서 봐주시길 바랍니다.★★★

	MainApp에서 우선 GameInstance의 Safe_Release를 호출해준다. 하지만 생성자에서 Safe_AddRef를 해줬기 때문에
	래퍼런스카운트가 1에서 줄었을뿐 객체가 삭제되지 않는다. 하지만 Safe_Release이후 Release_Engine을 호출해준다.
	Release_Engine에서 우선 가장먼저 GameInstance의 Destroy_Instance를 호출해준다. Destroy_Instance는
	Engine_Macro에 가보면 Release를 호출해주는걸 확인할 수 있다.
	때문에 래퍼런스카운터가 0인 GameInstance의 Release를 호출하기 때문에 삭제하기전에 GameInstance의 Free함수가 호출된다.
	이 Free함수에서 래퍼런스카운트가 1인 Object_Manager, Level_Manager, Graphic_Device의 
	Release를 호출하여 래퍼런스카운트를 감소시키고 래퍼런스카운트를 0으로 만들어준다.
	이 작업을 마친 후 다시 Release_Engine으로 돌아와 바로 CObject_Manager의 Destroy_Instance를 호출해준다.
	결과적으로 GameInstance에서 릴리즈를 호출하여 래퍼런스카운트를 0으로 만들어줬기때문에
	래퍼런스카운트의 0인객체의 Destroy_Instance를 호출하면 객체가 삭제된다.
	*/

	CGameInstance::Get_Instance()->Destroy_Instance();

	CComponent_Manager::Get_Instance()->Destroy_Instance(); //컴포넌트부터 삭제해주는 이유는 다른 매니저들이
	//컴포넌트를 포함하고 있을 가능성이 높기 때문이다.

	CObject_Manager::Get_Instance()->Destroy_Instance();

	CLevel_Manager::Get_Instance()->Destroy_Instance();

	CGraphic_Device::Get_Instance()->Destroy_Instance();
}

void CGameInstance::Free()
{
	Safe_Release(m_pComponent_Manager);
	Safe_Release(m_pObject_Manager);
	Safe_Release(m_pLevel_Manager);
	Safe_Release(m_pGraphic_Device);

}