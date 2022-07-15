#include "..\Public\Camera.h"

CCamera::CCamera(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CGameObject(pGraphic_Device) //������ü ������
{
}

CCamera::CCamera(const CCamera & rhs, CTransform::TRANSFORMDESC* pArg)
	: CGameObject(rhs) //������ ����
	, m_pTransformCom((CTransform*)rhs.m_pTransformCom->Clone(pArg)) // �� �� Transform*������ ������ü�� Transform*�� �����ؼ� �������ش�.
{

}

HRESULT CCamera::Initialize_Prototype()
{
	m_pTransformCom = CTransform::Create(m_pGraphic_Device); //Transform������Ʈ�� �����ؼ� ������ �������ش�.
	if (nullptr == m_pTransformCom)
		return E_FAIL;

	return S_OK;
}

HRESULT CCamera::Initialize(void * pArg)
{
	memcpy(&m_CameraDesc, pArg, sizeof(CAMERADESC)); // ���ڷ� ���� ī�޶� ���� ����ü�� ������ �������ش�.

	m_pTransformCom->Set_State(CTransform::STATE_POSITION, m_CameraDesc.vEye); // ����ü �ȿ� �ִ� ������ Transform�� �������ش�.
	m_pTransformCom->LookAt(m_CameraDesc.vAt); // ���������� �������ش�.

	return S_OK;
}

void CCamera::Tick(_float fTimeDelta)
{
	_float4x4		ViewMatrix, ProjMatrix; //����İ� ��������� ����

	ViewMatrix = m_pTransformCom->Get_WorldMatrixInverse();	//��������� ������� ���Ѵ�.
	D3DXMatrixPerspectiveFovLH(&ProjMatrix, m_CameraDesc.fFovy, m_CameraDesc.fAspect, m_CameraDesc.fNear, m_CameraDesc.fFar);
	//������Ŀ� �ʿ��ѿ�Ҹ� ���ڷ� �־ ��������� �����ش�.

	m_pGraphic_Device->SetTransform(D3DTS_VIEW, &ViewMatrix); //����İ��Ѵ�.
	m_pGraphic_Device->SetTransform(D3DTS_PROJECTION, &ProjMatrix); //������İ��Ѵ�.
}

void CCamera::LateTick(_float fTimeDelta)
{
}

HRESULT CCamera::Render()
{
	return S_OK;
}

void CCamera::Free()
{
	__super::Free();

	Safe_Release(m_pTransformCom);
}
