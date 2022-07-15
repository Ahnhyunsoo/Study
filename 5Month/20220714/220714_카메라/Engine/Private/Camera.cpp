#include "..\Public\Camera.h"

CCamera::CCamera(LPDIRECT3DDEVICE9 pGraphic_Device)
	: CGameObject(pGraphic_Device) //원형객체 생성자
{
}

CCamera::CCamera(const CCamera & rhs, CTransform::TRANSFORMDESC* pArg)
	: CGameObject(rhs) //원형을 복사
	, m_pTransformCom((CTransform*)rhs.m_pTransformCom->Clone(pArg)) // 이 때 Transform*변수에 원형객체의 Transform*를 복사해서 대입해준다.
{

}

HRESULT CCamera::Initialize_Prototype()
{
	m_pTransformCom = CTransform::Create(m_pGraphic_Device); //Transform컴포넌트를 생성해서 변수에 대입해준다.
	if (nullptr == m_pTransformCom)
		return E_FAIL;

	return S_OK;
}

HRESULT CCamera::Initialize(void * pArg)
{
	memcpy(&m_CameraDesc, pArg, sizeof(CAMERADESC)); // 인자로 받은 카메라 정보 구조체를 변수에 복사해준다.

	m_pTransformCom->Set_State(CTransform::STATE_POSITION, m_CameraDesc.vEye); // 구조체 안에 있는 정보를 Transform에 셋팅해준다.
	m_pTransformCom->LookAt(m_CameraDesc.vAt); // 마찬가지로 셋팅해준다.

	return S_OK;
}

void CCamera::Tick(_float fTimeDelta)
{
	_float4x4		ViewMatrix, ProjMatrix; //뷰행렬과 투영행렬을 선언

	ViewMatrix = m_pTransformCom->Get_WorldMatrixInverse();	//월드행렬의 역행렬을 구한다.
	D3DXMatrixPerspectiveFovLH(&ProjMatrix, m_CameraDesc.fFovy, m_CameraDesc.fAspect, m_CameraDesc.fNear, m_CameraDesc.fFar);
	//투영행렬에 필요한요소를 인자로 넣어서 투영행렬을 구해준다.

	m_pGraphic_Device->SetTransform(D3DTS_VIEW, &ViewMatrix); //뷰행렬곱한다.
	m_pGraphic_Device->SetTransform(D3DTS_PROJECTION, &ProjMatrix); //투영행렬곱한다.
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
