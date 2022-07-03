#include "..\Public\GameInstance.h"

IMPLEMENT_SINGLETON(CGameInstance)


CGameInstance::CGameInstance()
	: m_pGraphic_Device(CGraphic_Device::Get_Instance())
	, m_pLevel_Manager(CLevel_Manager::Get_Instance())
	, m_pObject_Manager(CObject_Manager::Get_Instance())
	, m_pComponent_Manager(CComponent_Manager::Get_Instance())
{
	//���������� ���۷���ī���� ���������ش�.
	Safe_AddRef(m_pObject_Manager);
	Safe_AddRef(m_pLevel_Manager);
	Safe_AddRef(m_pGraphic_Device);
	Safe_AddRef(m_pComponent_Manager);
}

HRESULT CGameInstance::Initialize_Engine(_uint iNumLevels, const GRAPHICDESC& GraphicDesc, IDirect3DDevice9** ppOut)
{
	//������ �����ϱ����� �ʱ�ȭ�۾��� ������
	if (m_pGraphic_Device == nullptr)//����̽� ��ü�� ���ٸ� �Լ�����
		return E_FAIL;
	//1���� : �ڵ�, 2���� : ����â������, 3���� : ����â������, 4���� : â������� ��ü�������, 5���� : ����̽��� ������ ������
	//Graphic_Device�� InitDevice�Լ��ȿ����� ���ڷγ��� ppOut�� ����̽��� �������ִ� �ڵ尡 ����
	if (FAILED(m_pGraphic_Device->InitDevice(GraphicDesc.hWnd, GraphicDesc.iWinSizeX, GraphicDesc.iWinSizeY, GraphicDesc.eWinMode, ppOut)))
		return E_FAIL; //�ʱ�ȭ�� ���������� �Լ�����

	//���ڷ� ���� ������ ������ŭ map�� �����Ҵ�����
	if (FAILED(m_pObject_Manager->Reserve_Container(iNumLevels)))
		return E_FAIL;

	return S_OK;
}

void CGameInstance::Tick_Engine(_float fTimeDelta)
{
	if (nullptr == m_pLevel_Manager || //Level�Ŵ����� Object�Ŵ��� ���� �ϳ��� nullptr�̸� �Լ�����
		nullptr == m_pObject_Manager)
		return;

	m_pObject_Manager->Tick(fTimeDelta); //���� ������Ʈ�� Tick�� ȣ��



	m_pObject_Manager->LateTick(fTimeDelta); // Tick�� �� ������ LateTick ȣ��

	m_pLevel_Manager->Tick(fTimeDelta); // ������ Tick�� ȣ��
}

void CGameInstance::Clear(_uint iLevelIndex)
{
	if (nullptr == m_pObject_Manager)
		return;

	m_pObject_Manager->Clear(iLevelIndex);  //Object_Manager�� Clear�� ȣ��
	//�̿Ͱ��� GameInstance���� �Լ����� ���ڷ� �����ִ� ��ü�ȿ� �ִ� �Լ����� ȣ�����ִ� ����ٸ���������.
	//�׸��� ȣ�����ִ� �Լ����� Ŭ���̾�Ʈ���� ����ϴ� �Լ�����
	//���� ���� �ľ������״� ���Ŀ� ȣ�⸸���ִ� �Լ����� �������� �ʰ���
}

void CGameInstance::Render_Begin(void)
{
	if (nullptr == m_pGraphic_Device)
		return;

	m_pGraphic_Device->Render_Begin();
}

void CGameInstance::Render_End(HWND hWnd)
{
	if (nullptr == m_pGraphic_Device)
		return;

	m_pGraphic_Device->Render_End(hWnd);
}

HRESULT CGameInstance::Open_Level(_uint iLevelIndex, CLevel * pNewLevel)
{
	if (nullptr == m_pLevel_Manager)
		return E_FAIL;

	return m_pLevel_Manager->Open_Level(iLevelIndex, pNewLevel);
}

HRESULT CGameInstance::Render_Level()
{
	if (nullptr == m_pLevel_Manager)
		return E_FAIL;

	return m_pLevel_Manager->Render();
}

HRESULT CGameInstance::Add_Prototype(const _tchar * pPrototypeTag, CGameObject * pPrototype)
{
	if (nullptr == m_pObject_Manager)
		return E_FAIL;

	return m_pObject_Manager->Add_Prototype(pPrototypeTag, pPrototype);
}

HRESULT CGameInstance::Add_GameObjectToLayer(const _tchar * pPrototypeTag, _uint iLevelIndex, const _tchar * pLayerTag, void * pArg)
{
	if (nullptr == m_pObject_Manager)
		return E_FAIL;

	return m_pObject_Manager->Add_GameObjectToLayer(pPrototypeTag, iLevelIndex, pLayerTag, pArg);
}

HRESULT CGameInstance::Add_Prototype(_uint iLevelIndex, const _tchar * pPrototypeTag, CComponent * pPrototype)
{
	if (nullptr == m_pComponent_Manager)
		return E_FAIL;

	return m_pComponent_Manager->Add_Prototype(iLevelIndex, pPrototypeTag, pPrototype);
}

CComponent * CGameInstance::Clone_Component(_uint iLevelIndex, const _tchar * pPrototypeTag, void * pArg)
{
	if (nullptr == m_pComponent_Manager)
		return nullptr;

	return m_pComponent_Manager->Clone_Component(iLevelIndex, pPrototypeTag, pArg);
}

void CGameInstance::Release_Engine()
{
	//���� �����ؼ� �� ���ñ� �ٶ��ϴ�.

	/*
	Release_Engine�Լ��� ���� ���� ������ �̱��水ü�� �ּҸ� �����޾ұ� ������ �������� �ش� �̱��水ü�� ���۷���ī��Ʈ�� 1�̴�.
	������ Free�Լ����� Release�� ȣ���Ѵ��ص� ���۷���ī��Ʈ�� �����һ� ������ ���� �ʴ´�.
	������ ��ũ�η� �����ص� �����Լ��� Destroy_Instance�� ȣ���ϸ� �ذ�ȴ�. �� ������ Destroy_Instance�� Release�� ȣ���ϱ� �����̴�.
	Free�Լ������� Release�� ȣ���ؼ� �̱��水ü���� ���۷���ī��Ʈ�� 0���� ������� �� Release_Engine�� ȣ���ϸ�
	���۷���ī��Ʈ��0�̱� ������ ��ü���� �����ȴ�.

	�ڡڡ� ���ذ� �ȵƴٸ� �Ʒ� ������ Client���� MainApp�� ������ �� �ٽÿͼ� ���ֽñ� �ٶ��ϴ�.�ڡڡ�

	MainApp���� �켱 GameInstance�� Safe_Release�� ȣ�����ش�. ������ �����ڿ��� Safe_AddRef�� ����� ������
	���۷���ī��Ʈ�� 1���� �پ����� ��ü�� �������� �ʴ´�. ������ Safe_Release���� Release_Engine�� ȣ�����ش�.
	Release_Engine���� �켱 ������� GameInstance�� Destroy_Instance�� ȣ�����ش�. Destroy_Instance��
	Engine_Macro�� ������ Release�� ȣ�����ִ°� Ȯ���� �� �ִ�.
	������ ���۷���ī���Ͱ� 0�� GameInstance�� Release�� ȣ���ϱ� ������ �����ϱ����� GameInstance�� Free�Լ��� ȣ��ȴ�.
	�� Free�Լ����� ���۷���ī��Ʈ�� 1�� Object_Manager, Level_Manager, Graphic_Device�� 
	Release�� ȣ���Ͽ� ���۷���ī��Ʈ�� ���ҽ�Ű�� ���۷���ī��Ʈ�� 0���� ������ش�.
	�� �۾��� ��ģ �� �ٽ� Release_Engine���� ���ƿ� �ٷ� CObject_Manager�� Destroy_Instance�� ȣ�����ش�.
	��������� GameInstance���� ����� ȣ���Ͽ� ���۷���ī��Ʈ�� 0���� �������⶧����
	���۷���ī��Ʈ�� 0�ΰ�ü�� Destroy_Instance�� ȣ���ϸ� ��ü�� �����ȴ�.
	*/

	CGameInstance::Get_Instance()->Destroy_Instance();

	CComponent_Manager::Get_Instance()->Destroy_Instance(); //������Ʈ���� �������ִ� ������ �ٸ� �Ŵ�������
	//������Ʈ�� �����ϰ� ���� ���ɼ��� ���� �����̴�.

	CObject_Manager::Get_Instance()->Destroy_Instance();

	CLevel_Manager::Get_Instance()->Destroy_Instance();

	CGraphic_Device::Get_Instance()->Destroy_Instance();
}

void CGameInstance::Free()
{
	Safe_Release(m_pComponent_Manager);
	Safe_Release(m_pObject_Manager);
	Safe_Release(m_pLevel_Manager);
	Safe_Release(m_pGraphic_Device);

}