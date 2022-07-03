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
		m_BackDesc = *(BACKDESC*)pArg; //���� �ڵ峪 ���ڵ峪 �Ȱ������̴�.
		//���ڷ� �޾ƿ� pArg�� m_BackDesc�� ������ ����ȯ�� ���� ������ pArg�� void������ �̱⶧���̴�.
		//void�����ʹ� � �ڷ����̵� ������ �� ������ ����� �� ����ȯ�� ������Ѵ�.
		//�ڼ��Ѱ� ���۸�
	}

	CGameInstance* pGameInstance = CGameInstance::Get_Instance();
	Safe_AddRef(pGameInstance);
	//CComponent �� �θ� ���Ϲޱ⶧���� ����ȯ �������
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
	//CRenderer �Լ����� Add_RenderGroup�� ȣ���Ͽ� ���ڷ� ������� �׷����ٴ� enum���� �ڱ��ڽ��� �־��ش�.
}

HRESULT CBackGround::Render()
{
	return S_OK;
}

CBackGround * CBackGround::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CBackGround*		pInstance = new CBackGround(pGraphic_Device);
	//��ü ������ ������ü�� �ʱ�ȭ�ؼ� �������ش�. ���� ���ڵ忡�� �ۼ��� ���ؼ� �����Ҹ��� ������ ����ó���� ���ش�.
	if (FAILED(pInstance->Initialize_Prototype()))
	{
		MSG_BOX(TEXT("Failed To Created : CBackGround"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CGameObject * CBackGround::Clone(void* pArg)
{
	//�纻 ��ü�� �������ִ� �Լ�
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

	Safe_Release(m_pRendererCom); //������ �� ������Ʈ ��ü�� Release���ش�.
}

