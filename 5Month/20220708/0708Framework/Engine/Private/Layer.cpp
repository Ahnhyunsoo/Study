#include "..\Public\Layer.h"
#include "GameObject.h"


CLayer::CLayer()
{
}

HRESULT CLayer::Add_GameObject(CGameObject* pGameObject)
{
	if (pGameObject == nullptr)
		return E_FAIL;

	m_GameObjects.push_back(pGameObject);

	return S_OK;
}

HRESULT CLayer::Initialize()
{

	return S_OK;
}

void CLayer::Tick(_float fTimeDelta)
{
	//������� for�� ���� for���� �޸� �������� ���κ��� �˷������ʾƵ� ó������ ������ ��ȸ���ִ� for��
	//1���� ��ȸ�ѿ��Ҹ� ������ ���� , 2���� ��ȸ�� �����̳� vector �Ǵ� list��� ���⼱ list�̴�.
	//auto = ��ڷ����̵� �����Ϸ��� �˾Ƽ� �Ǵ�����
	//auto�� &(���۷���)�� ���� ���� = ���۷����� �Ⱥ����� ��� ���簡 �Ͼ �׸��� ������ ���� ������ �� ����
	//������ ��ó�� ����� �� Swap�ϸ鼭 ��� ����� ��� ���纻�� ���������ص� ���������Ⱥ���
	for (auto& pGameObject : m_GameObjects)
	{
		if (nullptr != pGameObject) //���� ���Ұ� �ִٸ�
			pGameObject->Tick(fTimeDelta); //�ش� ������ Tick�� ȣ�� 
		//�츮�� m_GameObjects��� ����Ʈ�� ������Ʈ�� �����߱⶧���� ������Ʈ�� Tick�Լ��� ��������
	}
}
//���� ����
void CLayer::LateTick(_float fTimeDelta)
{
	for (auto& pGameObject : m_GameObjects)
	{
		if (nullptr != pGameObject)
			pGameObject->LateTick(fTimeDelta);
	}
}

CLayer* CLayer::Create()
{
	CLayer* pInstance = new CLayer();
	
	if (FAILED(pInstance->Initialize())) //����ó���� ���� ���� �ʱ�ȭ�� �����ߴٸ� �̶�� ������ �ɰ�
	{
		MSG_BOX(TEXT("Failed To Created : CLayer")); // ��ũ�η� �������� �޼����ڽ��� ���� ��۾��� �����ߴ��� �˷��ش�.
		Safe_Release(pInstance); //�׸��� �Ҵ��� ��ü�� �ʱ�ȭ�� ���������� �������ش�.
	}
	return pInstance; //�������� �ʱ�ȭ ������ ����
}

void CLayer::Free()
{
	for (auto& pGameObject : m_GameObjects)
		Safe_Release(pGameObject); //���ҵ��� ���� ��������
	m_GameObjects.clear(); //����Ʈ�� ���ҵ��� �����
}