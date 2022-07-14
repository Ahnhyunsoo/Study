#include "..\Public\Object_Manager.h"
#include "GameObject.h"
#include "Layer.h"

IMPLEMENT_SINGLETON(CObject_Manager)

CObject_Manager::CObject_Manager()
	:m_iNumLevels(0), m_pLayers(nullptr)
{
}


HRESULT CObject_Manager::Reserve_Container(_uint iNumLevels)
{
	if (m_pLayers != nullptr) //�纻��ü�� ������map�����̳ʰ� �̹� �ִٸ�
		return S_OK; //�̹� ������ �����ߴٰ� ����

	m_pLayers = new LAYERS[iNumLevels];//�������̳ʸ� �����迭�� �����Ѵ�. ���ڷ� ���� ������ ������ŭ �Ҵ�����

	m_iNumLevels = iNumLevels; //�ɹ������� ���ڷι��� ���������� ��������

	return S_OK; 
}

HRESULT CObject_Manager::Add_Prototype(const _tchar* pPrototypeTag, CGameObject* pPrototype)
{
	if (Find_Prototype(pPrototypeTag) != nullptr) //���ڷ� ���� �±׸� ���� map���� ������ü�� �ִ��� �˻���
		return E_FAIL;					//���� ��ü�� �Ѱ��� �����ؾ� �ϹǷ� �˻��Ǹ� �Լ��� �����Ų��.

	m_Prototypes.emplace(pPrototypeTag, pPrototype); //���� ������ü�� ���ٸ� map�����̳� ���ڷι��� ������ü�� �߰��Ѵ�.
	//�𸦸� �������� Ȥ�ó��ؼ� emplace�� map�����̳��� ���������� �����߰������ �ϳ��ε� ���尣���ؼ� ���̾�

	return S_OK;
}

									//const�� ���������� : ���� ����Ǹ� �ȵǱ� ������ ���ٲٰ� ���ȭ ��Ű�°� 
									//���� ��� �˻��� key���ε� �̰� �����ع�����... �˻������ �̻�������.
HRESULT CObject_Manager::Add_GameObjectToLayer(const _tchar* pPrototypeTag, _uint iLevelIndex, const _tchar* pLayerTag, void* pArg)
{
	CGameObject* pPrototype = Find_Prototype(pPrototypeTag); //���ڷ� ���� �±׷� ������ü�� Ž���ؼ� ���� ����� ������ ����

	if (pPrototype == nullptr) //���� �±׿� �ش��ϴ� ������ü�� ���ٸ� �Լ�����
		return E_FAIL;

	CGameObject* pGameObject = pPrototype->Clone(pArg); //������ü Ŭ���Լ��� ���ϰ��� ���°���� ������ ����
	//Ŭ�� �Լ� ����� �纻��ü�� ��������. 
	if (pGameObject == nullptr) // ���� Clone�Լ��� ����� ������� �ʾ����� �Լ��������Ŵ
		return E_FAIL;

	CLayer* pLayer = Find_Layer(iLevelIndex, pLayerTag); //���ڷ� ���� ������ �±׸� ���� ���̾ �˻��ؼ� ������ ����

	if (pLayer == nullptr) // ���� map�� ���ڷι��� ���� �ش��ϴ� ���̾ ���ٸ�
	{
		pLayer = CLayer::Create(); // ���̾ ���� �����Ѵ�.
		if (pLayer == nullptr) // ���� ���̾������ �����ߴٸ� �Լ�����
			return E_FAIL;

		pLayer->Add_GameObject(pGameObject); // ������ ���̾ ������ �����ص� �纻��ü�� ���̾ �߰����ش�.

		m_pLayers[iLevelIndex].emplace(pLayerTag, pLayer); // �׸��� Object_Manager�����迭map�� ���� ������ ���̾ �߰����ش�.
	}
	else // ���� ���̾ map���� �����Ѵٸ�
		pLayer->Add_GameObject(pGameObject); // �ش緹�̾ �����ص� �纻��ü�� ���̾ �߰����ش�.

	return S_OK;
}

void CObject_Manager::Tick(_float fTimeDelta)
{
	for (_uint i = 0; i < m_iNumLevels; ++i) //��ü ������ ������ŭ for���� �ݺ��Ѵ�.
	{
		for (auto& Pair : m_pLayers[i]) //�����Ҵ��� map�����̳��� i��°�� ������� for���� �����Ѵ�. 		
		{								//	(map�� ���Ҵ� key���� value�� ���� Pair��� ��ü)
			if (Pair.second != nullptr) //���� Pair�� value �� ������Ʈ�� �����Ѵٸ�
			{
				Pair.second->Tick(fTimeDelta); // �ش������Ʈ�� Tick�Լ��� ��������ش�.
			}
		}
	}
}

//���� ����
void CObject_Manager::LateTick(_float fTimeDelta)
{
	for (_uint i = 0; i < m_iNumLevels; ++i)
	{
		for (auto& Pair : m_pLayers[i])
		{
			if (nullptr != Pair.second)
				Pair.second->LateTick(fTimeDelta);
		}
	}
}

void CObject_Manager::Clear(_uint iLevelIndex)
{
	for (auto& Pair : m_pLayers[iLevelIndex])//���ڷι��� ������ ���̾ ��ȸ
	{
		Safe_Release(Pair.second); // �ش� ���̾��� ��ü���� ��������
	}
	m_pLayers[iLevelIndex].clear(); // ���� �ٽ� �ش緹���� ���ƿ� �� ������ ���� �����ϴ°��� �ƴ� clear�� ���ش�.
}

CGameObject* CObject_Manager::Find_Prototype(const _tchar* pPrototypeTag)
{
	auto iter = find_if(m_Prototypes.begin(), m_Prototypes.end(), CTag_Finder(pPrototypeTag));
	/*find_if�Լ��� ���� ���Ϲ��� ������� iter�� ����

	���� �κ��� ������ �����ѵ� �����ؼ� �� ���� �ٶ��ϴ�!��

	�켱 Engine_Functor�� ������ CTag_Finder��� �Լ���ü�� ��������ֽ��ϴ�. �ѹ� ���������
	�Լ���ü�� ��ü�� �޸𸮿� �Ҵ����� �ʰ� �ӽø޸𸮿� �÷��� �Լ�ó�� ����ϴ� ����
	�� 3��° ���ڿ� CTag_Finder(pPrototypeTag)�� �Ѽ��� 
	pPrototypetag�� ���ڷ� �޴� CTag_Finder�� �����ڰ� ȣ��Ǿ� �ӽø޸𸮿� �ö󰣴�.
	�׸��� �� �ӽø޸𸮿� ������ �Լ���ü�� find_if�� ���ڷ� �־��ش�.
	�� find_if�� F12�� Ÿ����� �����ϱ� ���絥 ���� �������ڸ�
	find_if�Լ��� 3��° ���� ���ڿ� ��ȸ�ϰ��ִ� ���Ҹ� �־� �� ���� True��� �ش� ���Ҹ� ��ȯ�Ѵ�.
	CTag_Finder���� ()�����ڰ� �����ε��Ǿ��ְ� ���ڷι��� Piar.first�� 
	�����س��� ���ڿ��� ���ؼ� True or false�� �����ϴµ�
	������ m_Prototypes�� ó������ ������ �����ϴ� ���ҵ��� ���� CTag_Finder��� �Լ���ü�� ���ڷ� �־
	CTag_Finder�ȿ� �����ڿ����ε��� �Լ��� �����ϰ� �װ��� True�� ��쿡 ���Ҹ� ��ȯ���ش�.
	�ѹ��� �������ڸ�
	�� find_if���� 3��° ���ڷ� CTag_Finder(pPrototypeTag)�� �ϴ¼��� �����ڰ�ȣ��Ǿ�
	���ڷ� ���� pPrototypeTag�� CTag_Finder��ü�ȿ��ִ� ������ ������ �� �ӽø޸𸮿� �ö󰡰�
	�ӽø޸𸮿� �ִ� �� �±׸� ������ ��ü�� find_if������ m_Prototypes�� ó������ ������ ��ȸ�ϸ鼭
	��ȸ�ϰ��ִ� ����(Pair)�� CTag_Finder(Pair)�� ȣ���Ͽ� �� ������� True�� ��쿡 ���ڷ� ���� Pair�� �������ش�.
	*/

	if (iter == m_Prototypes.end())//���� ������ ���� map�� end�� ����Ų�ٸ� �ش��±׷� Ž���� ���� ���ٴ°�
		return nullptr; //nullptr�� ��ȯ

	return iter->second; // iter�� second �� ������ü�� ��ȯ
}


CLayer* CObject_Manager::Find_Layer(_uint iLevelIndex, const _tchar * pLayerTag)
{
	//���ڷ� ���� �����ε����� �±׿� �ش��ϴ� ���̾ �˻�
	auto	iter = find_if(m_pLayers[iLevelIndex].begin(), m_pLayers[iLevelIndex].end(), CTag_Finder(pLayerTag));
	//���Լ��� ����
	if (iter == m_pLayers[iLevelIndex].end())
		return nullptr;

	return iter->second;
}

void CObject_Manager::Free()
{
	for (_uint i = 0; i < m_iNumLevels; ++i) //������ ������ŭ ��ȸ�Ѵ�
	{
		for (auto& Pair : m_pLayers[i]) 
			Safe_Release(Pair.second); // �ش��ϴ� ������ ��ü�� �����Ѵ�.

		m_pLayers[i].clear(); // ���� �� �����̳ʸ� clear���ش�.
	}

	Safe_Delete_Array(m_pLayers); // ���� �迭�� �������ش�. �����迭 �߱� ������ ����������Ѵ�.

	for (auto& Pair : m_Prototypes)	 
		Safe_Release(Pair.second); // ��ü�� �������ش�.

	m_Prototypes.clear(); //map�����̳ʸ� clear���ش�.
	
}