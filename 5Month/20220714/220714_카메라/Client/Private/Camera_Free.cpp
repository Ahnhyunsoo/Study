#include "stdafx.h"
#include "..\Public\Camera_Free.h"

CCamera_Free::CCamera_Free(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CCamera(pGraphic_Device)
{
}

CCamera_Free::CCamera_Free(const CCamera_Free & rhs, CTransform::TRANSFORMDESC * pArg)
	: CCamera(rhs, pArg)
{

}

HRESULT CCamera_Free::Initialize_Prototype()
{
	if (FAILED(__super::Initialize_Prototype())) //부모의 원형초기화함수호출
		return E_FAIL;

	return S_OK;
}

HRESULT CCamera_Free::Initialize(void * pArg)
{
	if (FAILED(__super::Initialize(pArg))) // 부모의 사본초기화함수호출
		return E_FAIL;

	

	return S_OK;
}

void CCamera_Free::Tick(_float fTimeDelta)
{
	if (GetKeyState('W') & 0x8000)
	{
		m_pTransformCom->Go_Straight(fTimeDelta);
	}

	if (GetKeyState('S') & 0x8000)
	{
		m_pTransformCom->Go_Backward(fTimeDelta);
	}

	if (GetKeyState('A') & 0x8000)
	{
		m_pTransformCom->Go_Left(fTimeDelta);
	}

	if (GetKeyState('D') & 0x8000)
	{
		m_pTransformCom->Go_Right(fTimeDelta);
	}

	__super::Tick(fTimeDelta);

}

void CCamera_Free::LateTick(_float fTimeDelta)
{
}

HRESULT CCamera_Free::Render()
{
	return S_OK;
}

CCamera_Free * CCamera_Free::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CCamera_Free*		pInstance = new CCamera_Free(pGraphic_Device);

	if (FAILED(pInstance->Initialize_Prototype()))
	{
		MSG_BOX(TEXT("Failed To Created : CCamera_Free"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CGameObject * CCamera_Free::Clone(void* pArg)
{
	CCamera::CAMERADESC*		pCameraDesc = (CCamera::CAMERADESC*)pArg; //인자로 받은 카메라정보구조체 변수생성

	CCamera_Free*		pInstance = new CCamera_Free(*this, &pCameraDesc->TransformDesc); // 생성한 변수에 있는 트랜스폼구조체를 인자로 넣는다

	if (FAILED(pInstance->Initialize(pArg))) // 생성한 카메라정보 구조체를 초기화함수에 인자로 넣어준다
		//이 클론함수는 ObjManager에서 호출해주고 
		//여기서 초기화함수를 호출하면 부모의 초기화함수를 호출해서 부모함수에서 인자로받은 데이터를 저장해준다.
	{
		MSG_BOX(TEXT("Failed To Created : CTerrain"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

void CCamera_Free::Free()
{
	__super::Free();


}
