#include "..\Public\Component_Manager.h"
#include "Component.h"

IMPLEMENT_SINGLETON(CComponent_Manager)


CComponent_Manager::CComponent_Manager()
	:m_iNumLevels(0)
{
}

HRESULT CComponent_Manager::Reserve_Container(_uint iNumLevels)
{
	if (m_pPrototypes != nullptr) //nullptr�� �ƴ϶�� �̹� �Ҵ�ƴٴ� ��
		return S_OK;

	m_iNumLevels = iNumLevels;

	m_pPrototypes = new PROTOTYPES[iNumLevels]; //���ٸ� �����Ҵ�

	return S_OK;
}

HRESULT CComponent_Manager::Add_Prototype(_uint iLevelIndex, const _tchar * pPrototypeTag, CComponent * pPrototype)
{
	if (iLevelIndex >= m_iNumLevels) //���ڷ� ���� iLevelIndex�� m_iNumLevels �̻��̶�� �Լ����� 
		//m_iNumLevels�� �ε����⶧���� ��ǻ� 1�� ������ iLevelIndex�� m_iNumLevels�̻��̶�°� 1��ũ�ٴ¶� �� ���������
		return E_FAIL; 

	if (Find_Component(iLevelIndex, pPrototypeTag) != nullptr) //�ش��ϴ� ������Ʈ�� ã�����ߴٸ� �Լ�����
		return E_FAIL;

	m_pPrototypes[iLevelIndex].emplace(pPrototypeTag, pPrototype); // ã�Ҵٸ� map�� �ش��±׿� ������Ʈ�� �߰�
	return S_OK;
}

CComponent * CComponent_Manager::Clone_Component(_uint iLevelIndex, const _tchar * pPrototypeTag, void * pArg)
{
	CComponent* pPrototype = Find_Component(iLevelIndex, pPrototypeTag);// ������Ʈ�� ã���Լ������� ���� ������Ʈ�� ����
	if (pPrototype == nullptr)
		return nullptr;

	return pPrototype->Clone(pArg); //���� ������Ʈ�� �ִٸ� �ش� ������Ʈ�� Clone�Լ��� ������ ���� ������� ����
}

CComponent * CComponent_Manager::Find_Component(_uint iLevelIndex, const _tchar * pPrototypeTag)
{
	auto iter = find_if(m_pPrototypes[iLevelIndex].begin(), m_pPrototypes[iLevelIndex].end(), CTag_Finder(pPrototypeTag));
	//Tag_Finder�� ���� ��ü�� ã�� ã�Ҵٸ� iter�� ���� iter = Pair

	if (iter == m_pPrototypes[iLevelIndex].end()) //Pair�� ����Ű�°� map�� end��� �� ������Ʈ�� ã�����ߴٸ�
		return nullptr; // nullptr ����

	return iter->second; // ã�Ҵٸ� ã�� ��ü�� value���� ���� ���⼭ value���� ������Ʈ��ü�̴�.
}

void CComponent_Manager::Free()
{
	for (_uint i = 0; i < m_iNumLevels; ++i)
	{
		for (auto& Pair : m_pPrototypes[i])
			Safe_Release(Pair.second); //����Ʈ���� ������Ʈ ��ü���� ���۷���ī���͸� ����

		m_pPrototypes[i].clear(); // ���� map�� Ŭ�������ش�. Pair.First �� �±װ� �����ֱ� ����.
	}

	Safe_Delete_Array(m_pPrototypes); //��� �۾��� ��ģ �� �����迭�̱� ������ ����Ʈ�� ����
}
