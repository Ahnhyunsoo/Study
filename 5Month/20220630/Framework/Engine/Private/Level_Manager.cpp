#include "..\Public\Level_Manager.h"
#include "Level.h"
#include "GameInstance.h" //���� ��������� ��� �����ߴٸ� ó���� ������������ ���Ŀ� GameInstanceŬ������
							//�������ָ� ������� ������ �Ű澲������!

IMPLEMENT_SINGLETON(CLevel_Manager)


CLevel_Manager::CLevel_Manager()
	:m_pCurrentLevel(nullptr),m_iCurrentLevelIndex(0)
	//�ʱ�ȭ�� ����� �ƴ� �����ڿ��� ������. ���Կ����� ���ؼ� �� ����
	//��� �̷��� ���ָ� �츮 ������ ������
{
}

HRESULT CLevel_Manager::Open_Level(_uint iLevelIndex, CLevel* pNewLevel)
{
	if (m_pCurrentLevel == nullptr) //m_pCurrentLevel = ���� ������ �ּҸ����� �׷��� nullptr�̶��?
	{								// �� ��ó�� �ʱ�ܰ� ��� �� ������� Level�� ���� �����̴�. 
		CGameInstance* pGameInstance = CGameInstance::Get_Instance();
		//���ڵ忡�� Safe_AddRef�� Safe_Release�� ������ �����ߵ��� ������ �ƴϱ⶧���� �����൵��
		//pGameInstance�� ������ �����ߴµ� ��� �����Ҽ��������� ���� �Լ���. �� ���ÿ����̱⶧���� �Լ������� ������
		pGameInstance->Clear(m_iCurrentLevelIndex);//���߿� GameInstance�� ������ �� �����ϰ���
	}
	Safe_Release(m_pCurrentLevel); //���緹���� Safe_Release�� ȣ������ ���۷���ī���Ͱ� 0�̴� ������ �� �̴�.

	m_pCurrentLevel = pNewLevel; //���� ������ ������ �� ���ڷ� ���� ������ ������ ����

	m_iCurrentLevelIndex = iLevelIndex; // ���� ����

	return S_OK; //Graphic_Device���� ������ HRESULT�� �����ǵ� ���ϰ�. S_OK�� ������ �ǹ�
}

void CLevel_Manager::Tick(_float fTimeDelta)
{
	if (m_pCurrentLevel == nullptr) //���� ���� ������ ���ٸ� �Լ��� �����Ų��.
		return;
	//���� ������ �ִٸ� ���緹���� Tick�Լ��� ȣ���Ѵ�.
	m_pCurrentLevel->Tick(fTimeDelta);
	//���⼭ ���ڷι��� fTimeDelta�� MainApp���� ���� fTimeDelta�̴�.
	//�ѽ������� ���� �ð����� ���ڷ� �Ѱ��ָ鼭 ����ϱ� ������ ��� Tick�Լ����� 
	//�����ð����� ����� �� �ִ�. ������ ���� �����ϴ�.

}

HRESULT CLevel_Manager::Render()
{
	if (m_pCurrentLevel == nullptr)
		return E_FAIL; // E_FAIL	�۾��� ������ �� �����ϴ�.

	return m_pCurrentLevel->Render(); 
}

void CLevel_Manager::Free()
{
	Safe_Release(m_pCurrentLevel);
	//������ �� ���� ������ Release�� ȣ������
}


