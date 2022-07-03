#include "stdafx.h"
#include "..\Public\BackGround.h"
#include "GameInstance.h"

CBackGround::CBackGround(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CGameObject(pGraphic_Device), m_pRendererCom(nullptr)
{
}

CBackGround::CBackGround(const CBackGround & rhs)
	: CGameObject(rhs)
{
}

HRESULT CBackGround::Initialize_Prototype()
{
	return S_OK;
}

HRESULT CBackGround::Initialize(void * pArg)
{
	if (nullptr != pArg)
	{
		// memcpy(&m_BackDesc, pArg, sizeof(BACKDESC));
		m_BackDesc = *(BACKDESC*)pArg; //위에 코드나 이코드나 똑같은것이다.
		//인자로 받아온 pArg를 m_BackDesc에 저장함 형변환을 해준 이유는 pArg가 void포인터 이기때문이다.
		//void포인터는 어떤 자료형이든 저장할 수 있지만 사용할 때 형변환을 해줘야한다.
		//자세한건 구글링
	}

	CGameInstance* pGameInstance = CGameInstance::Get_Instance();
	Safe_AddRef(pGameInstance);
	//CComponent 즉 부모를 리턴받기때문에 형변환 해줘야함
	m_pRendererCom = (CRenderer*)pGameInstance->Clone_Component(LEVEL_STATIC, TEXT("Prototype_Component_Renderer"));
	if (m_pRendererCom == nullptr)
		return E_FAIL;

	Safe_Release(pGameInstance);

	return S_OK;
}

void CBackGround::Tick(_float fTimeDelta)
{
	
}

void CBackGround::LateTick(_float fTimeDelta)
{
	m_pRendererCom->Add_RenderGroup(CRenderer::RENDER_PRIORITY, this);
	//CRenderer 함수내에 Add_RenderGroup을 호출하여 인자로 가장먼저 그려진다는 enum값과 자기자신을 넣어준다.
}

HRESULT CBackGround::Render()
{
	return S_OK;
}

CBackGround * CBackGround::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CBackGround*		pInstance = new CBackGround(pGraphic_Device);
	//객체 생성후 원형객체를 초기화해서 리턴해준다. 지금 쌤코드에선 작성을 안해서 실패할리가 없지만 예외처리를 해준다.
	if (FAILED(pInstance->Initialize_Prototype()))
	{
		MSG_BOX(TEXT("Failed To Created : CBackGround"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CGameObject * CBackGround::Clone(void* pArg)
{
	//사본 객체를 생성해주는 함수
	CBackGround*		pInstance = new CBackGround(*this);

	if (FAILED(pInstance->Initialize(pArg)))
	{
		MSG_BOX(TEXT("Failed To Created : CBackGround"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CBackGround::Free()
{
	__super::Free();

	Safe_Release(m_pRendererCom); //삭제될 때 컴포넌트 객체도 Release해준다.
}

