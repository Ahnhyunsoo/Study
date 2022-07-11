#include "..\Public\GameObject.h"



CGameObject::CGameObject(LPDIRECT3DDEVICE9 pGraphic_Device)
	:m_pGraphic_Device(pGraphic_Device)
{
	Safe_AddRef(m_pGraphic_Device);
}


CGameObject::CGameObject(const CGameObject & rhs)
	:m_pGraphic_Device(rhs.m_pGraphic_Device) //인자로 받은 원형객체의 디바이스를 사본객체의 디바이스에 대입해줌
{
	Safe_AddRef(m_pGraphic_Device);//마찬가지로 참조했기 때문에 래퍼런스카운트 증가
}

HRESULT CGameObject::Initialize_Prototype()
{
	return S_OK;
}

HRESULT CGameObject::Initialize(void * pArg)
{
	return S_OK;
}

void CGameObject::Tick(_float fTimeDelta)
{
}

void CGameObject::LateTick(_float fTimeDelta)
{
}

HRESULT CGameObject::Render()
{
	return S_OK;
}

void CGameObject::Free()
{
	Safe_Release(m_pGraphic_Device);
}
