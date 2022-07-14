#include "..\Public\Renderer.h"

#include "GameObject.h"

CRenderer::CRenderer(LPDIRECT3DDEVICE9 pGraphic_Device)
	:CComponent(pGraphic_Device) //��ġ�� ���ڷ� �޴� Renderer������ ȣ�� �� �θ��� CComponent�� �����ڸ� ȣ���ϸ鼭
	//��ġ�� ���ڷ� �Ѱ��ְ� �θ�ȿ��� ���۷���ī��Ʈ�� ������Ű�� ��ġ�� ������ ���Խ����ش�.
{
}

HRESULT CRenderer::Initialize_Prototype()
{
	return S_OK;
}

HRESULT CRenderer::Initialize(void * pArg)
{
	return S_OK;
}

			//1���� : ��� �׷쿡 �߰��Ұ��� �����ִ� eNum��, 2���� : �߰��� GameObject��ü 
HRESULT CRenderer::Add_RenderGroup(RENDERGROUP eRenderGroup, CGameObject* pGameObject)
{
	if (pGameObject == nullptr) //GameObject�� nullptr�̸� �Լ�����
		return E_FAIL;

	//���� �ִٸ� ���ڷι��� �׷쿡 ���ڷι��� ��ü�� �߰����ش�.
	m_RenderObjects[eRenderGroup].push_back(pGameObject);

	//����Ʈ�� �����͸� �����߱� ������ ������ ���̴�. ������ GameObject�� ���۷���ī���͸� ���������ش�.
	Safe_AddRef(pGameObject);

	return S_OK;
}

HRESULT CRenderer::Draw()
{
	for (_uint i = 0; i < RENDER_END; ++i)
	{
		for (auto& pRenderObject : m_RenderObjects[i])
		{
			if (pRenderObject != nullptr) //����Ʈ���� ��ü�� �ִٸ�
				pRenderObject->Render(); // �ش簴ü�� ������ ȣ�����ش�.

			Safe_Release(pRenderObject); // ���� ���۷���ī��Ʈ�� ���ҽ�Ų��. �� ���̻� ���⼭ ���������ʴ´ٴ¶�
		}
		m_RenderObjects[i].clear();// �� ���� ����Ʈ�� ����ش�.
		// �̷��� �ѹ� ������ �� �����ִ� ������ ���� �������� ��� YSorting�� ����� �����ߴٸ� ����� �����Ҽ��ִ�.
		//����Ÿ�ָ̹��� ��ü�� ���� ���ŵǱ� ������ ������ �������� �� �����Ӹ��� ���ŵ� ��ü�� ��������
		//�ٲ��� �ϱ� ������ �ѹ� ������ ������ �������ְ� �ٽ� �߰����ְ� �ϴ½����� �۵��Ѵ�.
	}
	return S_OK;
}

CRenderer* CRenderer::Create(LPDIRECT3DDEVICE9 pGraphic_Device)
{
	CRenderer* pInstance = new CRenderer(pGraphic_Device);

	if (FAILED(pInstance->Initialize_Prototype()))
	{
		MSG_BOX(TEXT("Failed To Created : CRenderer"));
		Safe_Release(pInstance);
	}

	return pInstance;
}

CComponent* CRenderer::Clone(void* pArg)
{
	AddRef(); //���縦 �� �� �纻�� ����°��� �ƴ� �ڱ� �ڽ��� �����Ѵ�. ������ �ڱ��ڽ��� ���۷��� ī��Ʈ�� ������Ų��.
	return this;
}

void CRenderer::Free()
{
	__super::Free(); //�θ��� Free�Լ��� ȣ���Ѵ�. CRenderer�� �θ�� CComponent
	//��ġ�� �θ�ü�� CComponent�� ����Ǿ� �ֱ� ������ �θ� �ִ� ��ġ�� Safe_Release������ϱ⶧���� �θ���
	//Free�� ȣ�����ش�.

	for (auto& List : m_RenderObjects) //���Ŀ� ����Ʈ�迭�� �ִ� ���� �� List = ����Ʈ
	{
		for (auto& pGameObject : List) //����Ʈ�� �ִ� ���� �� pGameObject = �����ص� GameObject��ü
		{
			Safe_Release(pGameObject); //GameObject ��� Safe_Release �Լ��� ȣ�����ش�.
		}
		List.clear(); // ���� ����Ʈ�� Ŭ�������ش�. �̰� �迭 ��� �ݺ��ϱ⶧���� ����Ʈ���� ��ü�� ��� �����ǰ�
		//����Ʈ�� Ŭ�����Ų��.
	}
}
