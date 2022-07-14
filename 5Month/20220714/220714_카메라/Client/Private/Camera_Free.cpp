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
	if (FAILED(__super::Initialize_Prototype())) //�θ��� �����ʱ�ȭ�Լ�ȣ��
		return E_FAIL;

	return S_OK;
}

HRESULT CCamera_Free::Initialize(void * pArg)
{
	if (FAILED(__super::Initialize(pArg))) // �θ��� �纻�ʱ�ȭ�Լ�ȣ��
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
	CCamera::CAMERADESC*		pCameraDesc = (CCamera::CAMERADESC*)pArg; //���ڷ� ���� ī�޶���������ü ��������

	CCamera_Free*		pInstance = new CCamera_Free(*this, &pCameraDesc->TransformDesc); // ������ ������ �ִ� Ʈ����������ü�� ���ڷ� �ִ´�

	if (FAILED(pInstance->Initialize(pArg))) // ������ ī�޶����� ����ü�� �ʱ�ȭ�Լ��� ���ڷ� �־��ش�
		//�� Ŭ���Լ��� ObjManager���� ȣ�����ְ� 
		//���⼭ �ʱ�ȭ�Լ��� ȣ���ϸ� �θ��� �ʱ�ȭ�Լ��� ȣ���ؼ� �θ��Լ����� ���ڷι��� �����͸� �������ش�.
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
